#include "ov006/ov006.h"
#include "ov000/UiObj.h"

extern "C" {

extern void *gTaskHost;
void *TaskHost_RequestSwitch(void *a, int b, int c);
void TaskList_DeleteAll(void);
void *Param_Get(u32 id);
void GfxSys_StartFadeIn(s32 a, int b, int c);
void ov006_SetupDefaultSlots(void);
void ov006_Manager_Mode00(int type, UiList *obj, int arg);

void ov006_Manager_Mode08(int type, UiList *obj, int arg) {
    switch (type) {
    case 2:
        ov006_SetupDefaultSlots();
        TaskHost_RequestSwitch(gTaskHost, 0x29, 0);
        break;
    case 3:
        ov006_Manager_Mode00(type, obj, arg);
        GfxSys_StartFadeIn(0x1e000, 0, 0);
        GfxSys_StartFadeIn(0x1e000, 0, 1);
        break;
    case 4:
        if (obj != NULL) {
            TaskHost_RequestSwitch(gTaskHost, 0x2a, arg);
        } else {
            TaskList_DeleteAll();
        }
        break;
    case 5:
        obj->vfunc_74(Param_Get(0xb005), 0xb005, 0xffff, 0xffff);
        obj->vfunc_74(Param_Get(0xb006), 0xb006, 0xffff, 0xffff);
        obj->vfunc_74(Param_Get(0xb007), 0xb007, 0xffff, 0xffff);
        obj->vfunc_74(Param_Get(0xb008), 0xb008, 0xffff, 0xffff);
        obj->vfunc_74(Param_Get(0xb009), 0xb009, 0xffff, 0xffff);
        obj->vfunc_74(Param_Get(0xb00a), 0xb00a, 0xffff, 0xffff);
        break;
    default:
        ov006_Manager_Mode00(type, obj, arg);
        break;
    }
}

}
