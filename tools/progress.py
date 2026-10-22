#!/usr/bin/env python3
"""Draw the README progress bars from build/usa/report.json (run `ninja report` first).

Writes docs/progress.svg (overall) and docs/progress_modules.svg (per module), and
refreshes the stats text between the progress markers in README.md.
"""

import json
import os
import re
import sys
from datetime import datetime, timezone

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
REPORT = os.path.join(ROOT, "build", "usa", "report.json")

BG = "#16161f"
TRACK = "#2a2a38"
TEXT = "#f2f2f7"
SUBTLE = "#9a9ab0"
RED = ("#ff5a5f", "#d7263d")     # Red's scarf
BLUE = ("#5ec8ff", "#2f7fd8")    # the sky above Shepherd Republic
GOLD = ("#ffd166", "#f4a524")    # 100% modules


def module_of(name):
    m = re.match(r"_dsd_gap@(\w+?)_\d+$", name)
    if m:
        mod = m.group(1)
    elif name.startswith("src/ov"):
        mod = name.split("/")[1]
    else:
        mod = "main"
    return "main" if mod in ("main", "itcm", "dtcm") else mod


def load():
    report = json.load(open(REPORT))
    mods = {}
    for unit in report["units"]:
        m = unit["measures"]
        agg = mods.setdefault(module_of(unit["name"]), [0, 0, 0, 0])
        agg[0] += int(m.get("matched_code", 0))
        agg[1] += int(m.get("total_code", 0))
        agg[2] += int(m.get("matched_functions", 0))
        agg[3] += int(m.get("total_functions", 0))
    mods = {k: v for k, v in mods.items() if v[1] > 0}
    return report["measures"], mods


def esc(s):
    return s.replace("&", "&amp;").replace("<", "&lt;").replace(">", "&gt;")


def gradient(gid, colors):
    return (f'<linearGradient id="{gid}" x1="0" x2="1" y1="0" y2="0">'
            f'<stop offset="0" stop-color="{colors[0]}"/><stop offset="1" stop-color="{colors[1]}"/>'
            f'</linearGradient>')


def bar(x, y, w, h, frac, fill):
    fw = max(0.0, min(1.0, frac)) * w
    r = h / 2
    out = f'<rect x="{x}" y="{y}" width="{w}" height="{h}" rx="{r}" fill="{TRACK}"/>'
    if fw > 0:
        out += f'<rect x="{x}" y="{y}" width="{max(fw, h):.1f}" height="{h}" rx="{r}" fill="url(#{fill})"/>'
    return out


def svg_doc(w, h, body, defs):
    return (f'<svg xmlns="http://www.w3.org/2000/svg" width="{w}" height="{h}" viewBox="0 0 {w} {h}" '
            f'font-family="Segoe UI, Helvetica, Arial, sans-serif">'
            f'<defs>{defs}</defs>'
            f'<rect width="{w}" height="{h}" rx="14" fill="{BG}"/>{body}</svg>\n')


def overall_svg(meas):
    code = float(meas["matched_code_percent"])
    funcs = (meas["matched_functions"], meas["total_functions"])
    w, h = 720, 196
    body = (f'<text x="28" y="44" fill="{TEXT}" font-size="22" font-weight="700">Decompilation progress</text>'
            f'<text x="{w - 28}" y="44" fill="{SUBTLE}" font-size="13" text-anchor="end">'
            f'Solatorobo: Red the Hunter (USA)</text>')
    rows = [
        ("Code", code / 100, f"{code:.1f}%", f"{int(meas['matched_code']):,} / {int(meas['total_code']):,} bytes", "red"),
        ("Functions", funcs[0] / funcs[1], f"{100 * funcs[0] / funcs[1]:.1f}%", f"{funcs[0]:,} / {funcs[1]:,}", "blue"),
    ]
    y = 78
    for label, frac, pct, detail, fill in rows:
        body += (f'<text x="28" y="{y}" fill="{TEXT}" font-size="15" font-weight="600">{label}</text>'
                 f'<text x="{w - 28}" y="{y}" fill="{TEXT}" font-size="15" font-weight="700" text-anchor="end">{pct}</text>'
                 f'<text x="{w - 92}" y="{y}" fill="{SUBTLE}" font-size="13" text-anchor="end">{detail}</text>')
        body += bar(28, y + 10, w - 56, 18, frac, fill)
        y += 58
    defs = gradient("red", RED) + gradient("blue", BLUE)
    return svg_doc(w, h, body, defs)


def label_of(mod):
    return "ARM9 + libraries" if mod == "main" else "Overlay " + str(int(mod[2:]))


def modules_svg(mods):
    order = sorted(mods, key=lambda k: (k != "main", k))
    w = 720
    row = 34
    h = 70 + row * len(order)
    body = f'<text x="28" y="40" fill="{TEXT}" font-size="18" font-weight="700">Code matched by module</text>'
    y = 66
    for mod in order:
        mc, tc, mf, tf = mods[mod]
        frac = mc / tc
        fill = "gold" if mc == tc else "red"
        body += (f'<text x="28" y="{y + 13}" fill="{TEXT}" font-size="13">{esc(label_of(mod))}</text>'
                 f'<text x="{w - 28}" y="{y + 13}" fill="{TEXT}" font-size="13" font-weight="600" '
                 f'text-anchor="end">{100 * frac:.1f}%</text>')
        body += bar(170, y + 2, w - 170 - 92, 14, frac, fill)
        y += row
    defs = gradient("red", RED) + gradient("gold", GOLD)
    return svg_doc(w, h, body, defs)


def update_readme(meas, mods):
    path = os.path.join(ROOT, "README.md")
    text = open(path, encoding="utf-8").read()
    done = sorted(label_of(k) for k, v in mods.items() if v[0] == v[1])
    date = datetime.now(timezone.utc).strftime("%Y-%m-%d")
    block = (f"**{float(meas['matched_code_percent']):.1f}%** of the code and "
             f"**{meas['matched_functions']:,} / {meas['total_functions']:,}** functions match the original game "
             f"(updated {date}).")
    if done:
        block += " Fully matched: " + ", ".join(done) + "."
    new = re.sub(r"(<!-- progress:start -->).*?(<!-- progress:end -->)",
                 lambda m: m.group(1) + "\n" + block + "\n" + m.group(2), text, flags=re.S)
    if new != text:
        open(path, "w", encoding="utf-8").write(new)


def main():
    if not os.path.exists(REPORT):
        sys.exit("no build/usa/report.json, run `ninja report` first")
    meas, mods = load()
    docs = os.path.join(ROOT, "docs")
    open(os.path.join(docs, "progress.svg"), "w").write(overall_svg(meas))
    open(os.path.join(docs, "progress_modules.svg"), "w").write(modules_svg(mods))
    update_readme(meas, mods)


if __name__ == "__main__":
    main()
