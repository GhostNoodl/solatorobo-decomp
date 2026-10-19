
typedef struct VObj VObj;
typedef int s32;
typedef long long s64;
typedef unsigned char u8;
typedef struct Vec
{
  s32 x;
  s32 y;
  s32 z;
} Vec;
typedef struct Fx Fx;
typedef struct FxVt
{
  void *f[8];
  void (*v20)(Fx *, Vec *);
} FxVt;
struct Fx
{
  FxVt *vt;
  s32 timer;
  s32 scale;
};
extern u8 data_ov010_0220fe30[];
inline static s32 FxMul(s32 a, s32 b)
{
  return (s32) (((((s64) a) * b) + 0x800) >> 12);
}

inline static s32 Clamp(s32 v, s32 lo, s32 hi)
{
  if (v > hi)
    return hi;
  if (v < lo)
    return lo;
  return v;
}

void func_ov010_02203f08(Fx *fx)
{
  Vec v;
  int new_var;
  Fx *new_var2;
  if (fx == 0)
  {
    return;
  }
  if (fx->timer < 0x14)
  {
    fx->scale += 0x20;
    fx->scale = Clamp(fx->scale, 0, 0x600);
  }
  else
  {
    new_var = 0x100;
    new_var2 = fx;
    new_var2->scale += new_var;
    fx->scale = Clamp(fx->scale, 0, 0x2000);
  }
  v.x = FxMul(*((s32 *) (data_ov010_0220fe30 + 8)), fx->scale);
  v.y = FxMul(*((s32 *) (data_ov010_0220fe30 + 0xc)), fx->scale);
  v.z = FxMul(*((s32 *) (data_ov010_0220fe30 + 0x10)), new_var2->scale);
  new_var2->vt->v20(fx, &v);
  fx->timer++;
}
