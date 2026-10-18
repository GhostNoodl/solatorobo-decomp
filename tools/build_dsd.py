#!/usr/bin/env python3

# Builds dsd from source with the patches this project needs for DSi-enhanced ROMs.
# Requires git and a Rust toolchain (https://rustup.rs).

from pathlib import Path
import argparse
import io
import os
import shutil
import subprocess
import sys
import tarfile
import urllib.request

root_path = Path(__file__).parent.parent
patches_path = root_path / "tools" / "dsd-patches"
work_path = root_path / "build" / "dsd-src"

DS_DECOMP_REPO = "https://github.com/AetiasHax/ds-decomp"
DS_ROM_VERSION = "0.8.0"

parser = argparse.ArgumentParser(description="Builds the patched dsd CLI")
parser.add_argument("--path", type=Path, required=True, help="Where to put the dsd executable")
args = parser.parse_args()


def run(*cmd, cwd=None):
    print(" ".join(str(c) for c in cmd))
    subprocess.run(cmd, cwd=cwd, check=True)


base_commit = (patches_path / "ds-decomp.base-commit").read_text().strip()
ds_decomp_path = work_path / "ds-decomp"
ds_rom_path = work_path / "ds-rom"

if not ds_decomp_path.is_dir():
    run("git", "clone", DS_DECOMP_REPO, ds_decomp_path)
run("git", "fetch", "origin", base_commit, cwd=ds_decomp_path)
run("git", "checkout", "--force", base_commit, cwd=ds_decomp_path)
run("git", "apply", (patches_path / "ds-decomp.patch").resolve(), cwd=ds_decomp_path)

# ds-rom comes from crates.io, so unpack the published crate and patch it
if ds_rom_path.is_dir():
    shutil.rmtree(ds_rom_path)
crate_url = f"https://static.crates.io/crates/ds-rom/ds-rom-{DS_ROM_VERSION}.crate"
print(f"Downloading {crate_url}")
with urllib.request.urlopen(crate_url) as response:
    crate_data = response.read()
with tarfile.open(fileobj=io.BytesIO(crate_data), mode="r:gz") as crate:
    crate.extractall(work_path, filter="data")
(work_path / f"ds-rom-{DS_ROM_VERSION}").rename(ds_rom_path)
# Keep git from finding this project's repository, or it would skip the patch since ds-rom isn't tracked by it
subprocess.run(
    ["git", "apply", "--verbose", (patches_path / f"ds-rom-{DS_ROM_VERSION}.patch").resolve()],
    cwd=ds_rom_path,
    env={**os.environ, "GIT_CEILING_DIRECTORIES": str(work_path.resolve())},
    check=True,
)

run("cargo", "build", "--release", "--manifest-path", ds_decomp_path / "cli" / "Cargo.toml")

exe = ".exe" if sys.platform == "win32" else ""
shutil.copy2(ds_decomp_path / "target" / "release" / f"dsd{exe}", args.path)
print(f"Built {args.path}")
