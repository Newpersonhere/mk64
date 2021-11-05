#include <ultra64.h>
#include <macros.h>

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
? vec3f_copy(void *, void *, void *, void *); // extern

void func_802B0210(void *arg0, void *arg1) {
    void *temp_a0;
    void *temp_a2;
    void *temp_a3;

    temp_a3 = arg0;
    temp_a2 = arg1;
    arg1->unk0 = arg0->unk0;
    arg1->unk2 = arg0->unk2;
    arg1->unk4 = arg0->unk4;
    arg1->unk6 = arg0->unk6;
    arg1->unk8 = arg0->unk8;
    arg1->unkA = arg0->unkA;
    arg1->unkC = arg0->unkC;
    arg1->unk10 = arg0->unk10;
    temp_a0 = arg1 + 0x18;
    arg1->unk14 = arg0->unk14;
    arg0 = temp_a3;
    arg1 = temp_a2;
    vec3f_copy(temp_a0, temp_a3 + 0x18, temp_a2, temp_a3);
    vec3f_copy(arg1 + 0x24, arg0 + 0x24, arg1, arg0);
    vec3f_copy(arg1 + 0x30, arg0 + 0x30, arg1, arg0);
}
#else
GLOBAL_ASM("asm/non_matchings/code_802B0210/func_802B0210.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
extern ? D_8015F9B8;

void func_802B02B4(void *arg0, s32 arg1) {
    s32 temp_f6;
    void *temp_v0;

    temp_v0 = (arg0->unk4 * 0x70) + &D_8015F9B8;
    temp_v0->unk4 = temp_v0->unk4 - 1;
    temp_f6 = arg0->unk8;
    if (temp_f6 != 0) {
        if (temp_f6 != 1) {
            if (temp_f6 != 2) {

            } else {
                temp_v0->unk2C = -1.0f;
            }
        } else {
            temp_v0->unk28 = -1.0f;
        }
    } else {
        temp_v0->unk24 = -1.0f;
    }
    arg0->unk2 = -0x8000;
    arg0->unk12 = 0;
    arg0->unk4 = 0x3C;
    arg0->unk28 = 3.0f;
    if (arg1 != 7) {
        if (arg1 != 8) {
            return;
        }
        arg0->unk6 = 7;
        return;
    }
    arg0->unk6 = 5;
}
#else
GLOBAL_ASM("asm/non_matchings/code_802B0210/func_802B02B4.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
extern f64 D_802B9E80;
extern f64 D_802B9E88;
extern f64 D_802B9E90;

void func_802B039C(void *arg0) {
    f32 temp_f6;
    s32 temp_v0;
    f32 phi_f6;

    arg0->unk6 = 1;
    arg0->unk4 = 0xB4;
    arg0->unk24 = (random_int(0xC8) - 0x64) * D_802B9E80;
    temp_v0 = random_int(0xC8);
    temp_f6 = temp_v0;
    phi_f6 = temp_f6;
    if (temp_v0 < 0) {
        phi_f6 = temp_f6 + 4294967296.0f;
    }
    arg0->unk28 = phi_f6 * D_802B9E88;
    arg0->unk2C = (random_int(0xC8) - 0x64) * D_802B9E90;
}
#else
GLOBAL_ASM("asm/non_matchings/code_802B0210/func_802B039C.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
? func_802B039C(void *); // extern
extern ? D_8015F9B8;

void func_802B0464(s16 arg0) {
    s16 temp_s0;
    void *temp_a0;
    s16 phi_s0;

    phi_s0 = arg0;
    if (arg0 != -1) {
        do {
            temp_a0 = &D_8015F9B8 + (phi_s0 * 0x70);
            func_802B039C(temp_a0);
            temp_s0 = temp_a0->unk14;
            phi_s0 = temp_s0;
        } while (temp_s0 != -1);
    }
}
#else
GLOBAL_ASM("asm/non_matchings/code_802B0210/func_802B0464.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
? func_802B039C(void *); // extern
extern ? D_8015F9B8;

void func_802B04E8(s32 arg0, s16 arg1) {
    s16 temp_s0;
    void *temp_a0;
    s16 phi_s0;

    phi_s0 = arg1;
    if (arg1 != -1) {
        do {
            temp_a0 = &D_8015F9B8 + (phi_s0 * 0x70);
            func_802B039C(temp_a0);
            temp_s0 = temp_a0->unk12;
            phi_s0 = temp_s0;
        } while (temp_s0 != -1);
    }
}
#else
GLOBAL_ASM("asm/non_matchings/code_802B0210/func_802B04E8.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
? func_800C9060(s32, ?); // extern
? func_802B0464(s16); // extern
? func_802B04E8(void *, s16); // extern
extern ? D_8015F9B8;
extern ? gPlayers;

void func_802B0570(void *arg0) {
    s16 temp_v0;
    void *temp_v0_2;

    func_802B0464(arg0->unk14);
    func_802B04E8(arg0, arg0->unk12);
    temp_v0 = arg0->unk10;
    if ((*(&gPlayers + (temp_v0 * 0xDD8)) & 0x4000) != 0) {
        func_800C9060(temp_v0 & 0xFF, 0x19019053);
    }
    arg0->unk2 = -0x8000;
    arg0->unk4 = 0x3C;
    arg0->unk6 = 5;
    temp_v0_2 = (arg0->unk8 * 0x70) + &D_8015F9B8;
    arg0->unk28 = 3.0f;
    temp_v0_2->unk12 = -1;
    temp_v0_2->unk14 = -1;
    temp_v0_2->unk16 = -1;
    temp_v0_2->unk18 = -1;
    temp_v0_2->unk1A = -1;
}
#else
GLOBAL_ASM("asm/non_matchings/code_802B0210/func_802B0570.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
extern ? D_8015F9B8;

void func_802B0648(void *arg0) {
    s16 temp_v0;
    s16 temp_v0_2;
    s16 temp_v0_3;
    s16 temp_v0_4;
    s16 temp_v0_5;
    s16 temp_v0_6;
    s32 temp_lo;
    s32 temp_lo_2;
    s32 temp_lo_3;
    s32 temp_lo_4;
    s32 temp_lo_5;
    void *phi_v1;

    temp_v0 = arg0->unk1A;
    arg0->unk1C = arg0->unk1C - 1;
    if (temp_v0 != -1) {
        temp_lo = temp_v0 * 0x70;
        arg0->unk1A = -1;
        phi_v1 = &D_8015F9B8 + temp_lo;
        goto block_10;
    }
    temp_v0_2 = arg0->unk18;
    if (temp_v0_2 != -1) {
        temp_lo_2 = temp_v0_2 * 0x70;
        arg0->unk18 = -1;
        phi_v1 = &D_8015F9B8 + temp_lo_2;
        goto block_10;
    }
    temp_v0_3 = arg0->unk16;
    if (temp_v0_3 != -1) {
        temp_lo_3 = temp_v0_3 * 0x70;
        arg0->unk16 = -1;
        phi_v1 = &D_8015F9B8 + temp_lo_3;
        goto block_10;
    }
    temp_v0_4 = arg0->unk14;
    if (temp_v0_4 != -1) {
        temp_lo_4 = temp_v0_4 * 0x70;
        arg0->unk14 = -1;
        phi_v1 = &D_8015F9B8 + temp_lo_4;
        goto block_10;
    }
    temp_v0_5 = arg0->unk12;
    if (temp_v0_5 != -1) {
        temp_lo_5 = temp_v0_5 * 0x70;
        arg0->unk12 = -1;
        phi_v1 = &D_8015F9B8 + temp_lo_5;
block_10:
        temp_v0_6 = phi_v1->unk12;
        phi_v1->unk6 = 1;
        phi_v1->unk4 = 0xB4;
        phi_v1->unk24 = 0.0f;
        phi_v1->unk2C = 0.0f;
        phi_v1->unk28 = 1.5f;
        if (temp_v0_6 != -1) {
            (&D_8015F9B8 + (temp_v0_6 * 0x70))->unk14 = -1;
        }
    }
}
#else
GLOBAL_ASM("asm/non_matchings/code_802B0210/func_802B0648.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
? func_802B64C4(f32 *, s16); // extern
? load_giant_egg(f32, f32 *, ?, f32, f32); // extern
extern ? D_8015F9B8;

void func_802B0788(s16 arg0, void *arg1, void *arg2) {
    f32 sp34;
    void *sp30;
    f32 temp_f0;
    f32 temp_f2;
    s16 temp_a0;
    s16 temp_a0_2;
    s16 temp_a0_3;
    s16 temp_a0_4;
    s16 temp_a1;
    s16 temp_a3;
    s32 temp_lo;
    s32 temp_lo_2;
    s32 temp_lo_3;
    s32 temp_lo_4;
    s32 temp_lo_5;
    void *phi_v0;
    f32 phi_f12;
    f32 phi_f0;

    temp_a3 = arg1->unk1A;
    arg1->unk1C = arg1->unk1C - 1;
    if (temp_a3 != -1) {
        temp_lo = temp_a3 * 0x70;
        arg1->unk1A = -1;
        phi_v0 = &D_8015F9B8 + temp_lo;
        goto block_10;
    }
    temp_a0 = arg1->unk18;
    if (temp_a0 != -1) {
        temp_lo_2 = temp_a0 * 0x70;
        arg1->unk18 = -1;
        phi_v0 = &D_8015F9B8 + temp_lo_2;
        goto block_10;
    }
    temp_a0_2 = arg1->unk16;
    if (temp_a0_2 != -1) {
        temp_lo_3 = temp_a0_2 * 0x70;
        arg1->unk16 = -1;
        phi_v0 = &D_8015F9B8 + temp_lo_3;
        goto block_10;
    }
    temp_a0_3 = arg1->unk14;
    if (temp_a0_3 != -1) {
        temp_lo_4 = temp_a0_3 * 0x70;
        arg1->unk14 = -1;
        phi_v0 = &D_8015F9B8 + temp_lo_4;
        goto block_10;
    }
    temp_a0_4 = arg1->unk12;
    if (temp_a0_4 != -1) {
        temp_lo_5 = temp_a0_4 * 0x70;
        arg1->unk12 = -1;
        phi_v0 = &D_8015F9B8 + temp_lo_5;
block_10:
        temp_a1 = phi_v0->unk12;
        phi_v0->unk6 = 1;
        phi_v0->unk4 = 0x1E;
        if (temp_a1 != -1) {
            (&D_8015F9B8 + (temp_a1 * 0x70))->unk14 = -1;
        }
        temp_f2 = arg2->unk94;
        if (temp_f2 < 2.0f) {
            phi_f12 = 4.0f;
            phi_f0 = ((arg0 - 30.0f) / 20.0f) + 1.5f;
        } else {
            temp_f0 = ((arg0 - 30.0f) / 20.0f) + 1.5f;
            phi_f12 = (temp_f2 * 0.75f) + 4.5f + temp_f0;
            phi_f0 = temp_f0;
        }
        sp30 = phi_v0;
        load_giant_egg(phi_f12, &sp34, 0, phi_f0, phi_f12);
        func_802B64C4(&sp34, arg2->unk2E + arg2->unkC0);
        phi_v0->unk24 = sp34;
        phi_v0->unk28 = sp38;
        phi_v0->unk2C = sp3C;
    }
}
#else
GLOBAL_ASM("asm/non_matchings/code_802B0210/func_802B0788.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
extern s16 D_8015F9BE[];

s32 func_802B09C0(s16 arg0) {
    s16 temp_v0;

    if (arg0 == -1) {
        return 0;
    }
    temp_v0 = &D_8015F9BE[arg0];
    if (temp_v0 == 2) {
        return 1;
    }
    if (temp_v0 == 3) {
        return 1;
    }
    return 0;
}
#else
GLOBAL_ASM("asm/non_matchings/code_802B0210/func_802B09C0.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
/*
Failed to decompile function update_obj_banana_bunch:

Unable to determine jump table for jr instruction at update_obj_banana_bunch.s line 24.

There must be a read of a variable in the same block as
the instruction, which has a name starting with "jtbl"/"jpt_".
*/
#else
GLOBAL_ASM("asm/non_matchings/code_802B0210/update_obj_banana_bunch.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
extern ? D_8015F9B8;

? func_802B0E14(s16 arg0) {
    void *temp_v0;

    if (arg0 < 0) {
        return 0;
    }
    temp_v0 = (arg0 * 0x70) + &D_8015F9B8;
    if (temp_v0->unk0 == 7) {
        if (temp_v0->unk6 == 4) {
            return 1;
        }
        return 0;
    }
    if (temp_v0->unk6 == 6) {
        return 1;
    }
    return 0;
}
#else
GLOBAL_ASM("asm/non_matchings/code_802B0210/func_802B0E14.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
/*
Failed to decompile function update_obj_triple_shell:

Unable to determine jump table for jr instruction at update_obj_triple_shell.s line 23.

There must be a read of a variable in the same block as
the instruction, which has a name starting with "jtbl"/"jpt_".
*/
#else
GLOBAL_ASM("asm/non_matchings/code_802B0210/update_obj_triple_shell.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
s16 func_8029EC88(? *, ? *, ? *, ?); // extern
extern ? D_8015F9B8;
extern ? D_802B9140;
extern ? D_802B914C;
extern ? D_802B9154;

s16 func_802B17F4(void *arg0) {
    ? sp34;
    ? sp2C;
    ? sp20;
    s16 temp_v0;
    void *temp_v1;

    sp34.unk0 = D_802B9140.unk0;
    sp34.unk4 = D_802B9140.unk4;
    sp34.unk8 = D_802B9140.unk8;
    sp2C.unk0 = D_802B914C.unk0;
    sp2C.unk4 = D_802B914C.unk4;
    sp20.unk0 = D_802B9154.unk0;
    sp20.unk4 = D_802B9154.unk4;
    sp20.unk8 = D_802B9154.unk8;
    temp_v0 = func_8029EC88(&sp20, &sp2C, &sp34, 0xE);
    if (temp_v0 < 0) {
        return temp_v0;
    }
    temp_v1 = (temp_v0 * 0x70) + &D_8015F9B8;
    temp_v1->unk6 = 0;
    temp_v1->unk10 = (arg0 - D_800DC4DC) / 0xDD8;
    arg0->unkC = arg0->unkC | 0x40000;
    return temp_v0;
}
#else
GLOBAL_ASM("asm/non_matchings/code_802B0210/func_802B17F4.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
s16 func_8029EC88(? *, ? *, ? *, s16); // extern
extern ? D_8015F9B8;
extern ? D_802B9160;
extern ? D_802B916C;
extern ? D_802B9174;

s16 func_802B18E4(s32 arg0, s16 arg1) {
    ? sp34;
    ? sp2C;
    ? sp20;
    s16 temp_v0;
    void *temp_v1;

    sp34.unk0 = D_802B9160.unk0;
    sp34.unk4 = D_802B9160.unk4;
    sp34.unk8 = D_802B9160.unk8;
    sp2C.unk0 = D_802B916C.unk0;
    sp2C.unk4 = D_802B916C.unk4;
    sp20.unk0 = D_802B9174.unk0;
    sp20.unk4 = D_802B9174.unk4;
    sp20.unk8 = D_802B9174.unk8;
    temp_v0 = func_8029EC88(&sp20, &sp2C, &sp34, arg1);
    if (temp_v0 < 0) {
        return temp_v0;
    }
    temp_v1 = (temp_v0 * 0x70) + &D_8015F9B8;
    temp_v1->unk6 = 0;
    temp_v1->unk10 = 0x5B0;
    temp_v1->unk12 = -0x8000;
    temp_v1->unk14 = (arg0 - D_800DC4DC) / 0xDD8;
    temp_v1->unk4 = 0;
    temp_v1->unk8 = 0.0f;
    return temp_v0;
}
#else
GLOBAL_ASM("asm/non_matchings/code_802B0210/func_802B18E4.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
s16 func_8029EC88(f32 *, ? *, ? *, s16); // extern
? func_802AD950(void *, f32, s32, s32, f32, f32, f32, f32); // extern
? func_802B4E30(void *); // extern
? func_802B63B8(f32 *, void *); // extern
extern ? D_8015F9B8;
extern ? D_802B9180;
extern ? D_802B918C;

? func_802B19EC(s32 arg0, void *arg1, s16 arg2, u16 arg3) {
    ? sp54;
    ? sp4C;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 *temp_a0;
    f32 *temp_a0_2;
    s16 temp_v0;
    s32 temp_t3;
    void *temp_a1;
    void *temp_s0;

    sp54.unk0 = D_802B9180.unk0;
    sp54.unk4 = D_802B9180.unk4;
    sp54.unk8 = D_802B9180.unk8;
    temp_a1 = arg1 + 0x174;
    temp_a0 = &sp40;
    sp4C.unk0 = D_802B918C.unk0;
    sp4C.unk4 = D_802B918C.unk4;
    sp40 = 0.0f;
    sp44 = -temp_a1->unk-104;
    sp48 = temp_a1->unk-104 - 4.0f;
    func_802B63B8(temp_a0, temp_a1);
    temp_a0_2 = &sp40;
    sp40 = 0.0f + arg1->unk14;
    sp44 += arg1->unk18;
    sp48 += arg1->unk1C;
    temp_v0 = func_8029EC88(temp_a0_2, &sp4C, &sp54, arg2);
    if (temp_v0 < 0) {
        (arg0 + (arg3 * 4))->unk24 = -1.0f;
        return -1;
    }
    temp_t3 = temp_v0 * 7;
    sp40 = arg1->unk14;
    temp_s0 = (temp_t3 * 0x10) + &D_8015F9B8;
    sp44 = arg1->unk18;
    sp48 = arg1->unk1C;
    func_802AD950(temp_s0 + 0x30, temp_s0->unkC + 1.0f, temp_s0->unk18, temp_s0->unk1C, temp_s0->unk20, sp40, sp44, sp48);
    func_802B4E30(temp_s0);
    temp_s0->unk2 = -0x7000;
    if (arg2 != 7) {
        if (arg2 != 8) {

        } else {
            temp_s0->unk6 = 6;
        }
    } else {
        temp_s0->unk6 = 4;
    }
    temp_s0->unk10 = 0;
    temp_s0->unk12 = -0x8000;
    temp_s0->unk14 = (arg1 - D_800DC4DC) / 0xDD8;
    temp_s0->unk4 = (arg0 - &D_8015F9B8) / 0x70;
    temp_s0->unk8 = arg3;
    (arg0 + (arg3 * 4))->unk24 = (temp_s0 - &D_8015F9B8) / 0x70;
    return 1;
}
#else
GLOBAL_ASM("asm/non_matchings/code_802B0210/func_802B19EC.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
s16 func_8029EC88(f32 *, ? *, ? *, ?); // extern
? func_802AD950(void *, f32, s32, s32, f32, f32, f32, f32); // extern
? func_802B4E30(void *); // extern
? func_802B63B8(f32 *, s32); // extern
extern ? D_8015F9B8;
extern ? D_802B9194;
extern ? D_802B91A0;

s16 func_802B1C9C(void *arg0) {
    ? sp54;
    ? sp4C;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    s16 sp3E;
    f32 *temp_a0;
    s16 temp_v0;
    s16 temp_v1;
    s32 temp_t8;
    void *temp_s0;

    sp54.unk0 = D_802B9194.unk0;
    sp54.unk4 = D_802B9194.unk4;
    sp54.unk8 = D_802B9194.unk8;
    sp4C.unk0 = D_802B91A0.unk0;
    sp4C.unk4 = D_802B91A0.unk4;
    sp40 = 0.0f;
    sp44 = -arg0->unk70;
    sp48 = arg0->unk70 - 4.0f;
    func_802B63B8(&sp40, arg0 + 0x174);
    temp_a0 = &sp40;
    sp40 = 0.0f + arg0->unk14;
    sp44 += arg0->unk18;
    sp48 += arg0->unk1C;
    temp_v0 = func_8029EC88(temp_a0, &sp4C, &sp54, 7);
    temp_v1 = temp_v0;
    if (temp_v0 < 0) {
        return temp_v0;
    }
    temp_t8 = temp_v1 * 7;
    sp40 = arg0->unk14;
    temp_s0 = (temp_t8 * 0x10) + &D_8015F9B8;
    sp44 = arg0->unk18;
    sp48 = arg0->unk1C;
    sp3E = temp_v1;
    func_802AD950(temp_s0 + 0x30, temp_s0->unkC + 1.0f, temp_s0->unk18, temp_s0->unk1C, temp_s0->unk20, sp40, sp44, sp48);
    func_802B4E30(temp_s0);
    temp_s0->unk6 = 0;
    temp_s0->unk10 = 0;
    temp_s0->unk12 = -0x8000;
    temp_s0->unk14 = (arg0 - D_800DC4DC) / 0xDD8;
    return sp3E;
}
#else
GLOBAL_ASM("asm/non_matchings/code_802B0210/func_802B1C9C.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
s16 func_8029EC88(f32 *, ? *, ? *, ?); // extern
? func_802AD950(void *, f32, s32, s32, f32, f32, f32, f32); // extern
? func_802B4E30(void *); // extern
? func_802B63B8(f32 *, s32); // extern
extern ? D_8015F9B8;
extern ? D_802B91A8;
extern ? D_802B91B4;

s16 func_802B1E48(void *arg0) {
    ? sp54;
    ? sp4C;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    s16 sp3E;
    f32 *temp_a0;
    s16 temp_v0;
    s16 temp_v1;
    s32 temp_t8;
    void *temp_s0;

    sp54.unk0 = D_802B91A8.unk0;
    sp54.unk4 = D_802B91A8.unk4;
    sp54.unk8 = D_802B91A8.unk8;
    sp4C.unk0 = D_802B91B4.unk0;
    sp4C.unk4 = D_802B91B4.unk4;
    sp40 = 0.0f;
    sp44 = -arg0->unk70;
    sp48 = arg0->unk70 - 4.0f;
    func_802B63B8(&sp40, arg0 + 0x174);
    temp_a0 = &sp40;
    sp40 = 0.0f + arg0->unk14;
    sp44 += arg0->unk18;
    sp48 += arg0->unk1C;
    temp_v0 = func_8029EC88(temp_a0, &sp4C, &sp54, 8);
    temp_v1 = temp_v0;
    if (temp_v0 < 0) {
        return temp_v0;
    }
    temp_t8 = temp_v1 * 7;
    sp40 = arg0->unk14;
    temp_s0 = (temp_t8 * 0x10) + &D_8015F9B8;
    sp44 = arg0->unk18;
    sp48 = arg0->unk1C;
    sp3E = temp_v1;
    func_802AD950(temp_s0 + 0x30, temp_s0->unkC + 1.0f, temp_s0->unk18, temp_s0->unk1C, temp_s0->unk20, sp40, sp44, sp48);
    func_802B4E30(temp_s0);
    temp_s0->unk6 = 0;
    temp_s0->unk10 = 0;
    temp_s0->unk12 = arg0->unk2E - 0x8000;
    temp_s0->unk14 = (arg0 - D_800DC4DC) / 0xDD8;
    return sp3E;
}
#else
GLOBAL_ASM("asm/non_matchings/code_802B0210/func_802B1E48.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
s32 func_802B1E48(); // extern
extern ? D_8015F9B8;

void func_802B1FFC(void) {
    *(&D_8015F9B8 + (func_802B1E48() * 0x70)) = 0x2A;
}
#else
GLOBAL_ASM("asm/non_matchings/code_802B0210/func_802B1FFC.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
/*
Failed to decompile function update_obj_banana:

Unable to determine jump table for jr instruction at update_obj_banana.s line 24.

There must be a read of a variable in the same block as
the instruction, which has a name starting with "jtbl"/"jpt_".
*/
#else
GLOBAL_ASM("asm/non_matchings/code_802B0210/update_obj_banana.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
/*
Failed to decompile function func_802B2914:

Unable to determine jump table for jr instruction at func_802B2914.s line 128.

There must be a read of a variable in the same block as
the instruction, which has a name starting with "jtbl"/"jpt_".
*/
#else
GLOBAL_ASM("asm/non_matchings/code_802B0210/func_802B2914.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
s16 func_8029EC88(f32 *, s16 *, f32 *, ?); // extern
? func_802B63B8(f32 *, void *); // extern
extern ? D_8015F9B8;

s16 func_802B2C40(void *arg0) {
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    s16 sp34;
    s16 sp32;
    s16 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 *temp_a0;
    f32 *temp_a2;
    s16 *temp_a1;
    s16 temp_v0;
    void *temp_v1;

    sp24 = 0.0f;
    sp28 = -arg0->unk70;
    sp2C = -(arg0->unk70 + 4.0f);
    func_802B63B8(&sp24, arg0 + 0x174);
    temp_a0 = &sp24;
    temp_a1 = &sp30;
    temp_a2 = &sp38;
    sp24 += arg0->unk14;
    sp28 += arg0->unk18;
    sp2C += arg0->unk1C;
    sp38 = arg0->unk34;
    sp3C = arg0->unk38;
    sp30 = 0;
    sp32 = 0;
    sp34 = 0;
    sp40 = arg0->unk3C;
    temp_v0 = func_8029EC88(temp_a0, temp_a1, temp_a2, 0xD);
    if (temp_v0 < 0) {
        return temp_v0;
    }
    temp_v1 = (temp_v0 * 0x70) + &D_8015F9B8;
    temp_v1->unk6 = 0;
    temp_v1->unk24 = (arg0 - D_800DC4DC) / 0xDD8;
    arg0->unkC = arg0->unkC | 0x40000;
    return temp_v0;
}
#else
GLOBAL_ASM("asm/non_matchings/code_802B0210/func_802B2C40.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
s16 func_8029EC88(f32 *, s16 *, f32 *, ?); // extern
? func_802B63B8(f32 *, void *); // extern
extern ? D_8015F9B8;

s16 func_802B2D70(void *arg0) {
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    s16 sp38;
    s16 sp36;
    s16 sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    s32 sp20;
    f32 *temp_a0;
    f32 *temp_a2;
    s16 *temp_a1;
    s16 temp_v0;
    s32 temp_t0;
    void *temp_v1;

    temp_t0 = ((arg0 - D_800DC4DC) / 0xDD8) & 0xFFFF;
    if (temp_t0 >= 8) {
        return -1;
    }
    sp28 = 0.0f;
    sp2C = -arg0->unk70;
    sp20 = temp_t0;
    sp30 = -(arg0->unk70 + 4.0f);
    func_802B63B8(&sp28, arg0 + 0x174);
    temp_a0 = &sp28;
    temp_a1 = &sp34;
    temp_a2 = &sp3C;
    sp28 += arg0->unk14;
    sp2C += arg0->unk18;
    sp30 += arg0->unk1C;
    sp3C = arg0->unk34;
    sp40 = arg0->unk38;
    sp34 = 0;
    sp36 = 0;
    sp38 = 0;
    sp44 = arg0->unk3C;
    temp_v0 = func_8029EC88(temp_a0, temp_a1, temp_a2, 6);
    if (temp_v0 < 0) {
        return temp_v0;
    }
    temp_v1 = (temp_v0 * 0x70) + &D_8015F9B8;
    temp_v1->unk10 = temp_t0;
    temp_v1->unk6 = 0;
    temp_v1->unk4 = 0x14;
    arg0->unkC = arg0->unkC | 0x40000;
    return temp_v0;
}
#else
GLOBAL_ASM("asm/non_matchings/code_802B0210/func_802B2D70.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
? func_8009E5BC(); // extern
? func_800CAB4C(s32); // extern
extern ? gGfxPools;
extern ? gPlayers;

void func_802B2EBC(u16 *arg0) {
    u16 *temp_a2;
    void *temp_v0;
    u16 *phi_a2;
    ? *phi_v1;
    void *phi_a0;
    void *phi_a1;
    void *phi_v0;

    func_8009E5BC();
    temp_a2 = arg0;
    phi_a2 = temp_a2;
    if ((*temp_a2 & 0x4000) != 0) {
        arg0 = temp_a2;
        func_800CAB4C(((temp_a2 - D_800DC4DC) / 0xDD8) & 0xFF);
        phi_a2 = arg0;
    }
    phi_v1 = &gPlayers;
    phi_a0 = &gPlayers + 0xDD8;
    phi_a1 = &gPlayers + 0x1BB0;
    phi_v0 = &gPlayers + 0x2988;
    do {
        if (phi_a2 != phi_v1) {
            phi_v1->unkC = phi_v1->unkC | 0x4000;
        }
        phi_v1 += 0x3760;
        if (phi_a2 != phi_a0) {
            phi_a0->unkC = phi_a0->unkC | 0x4000;
        }
        phi_a0 += 0x3760;
        if (phi_a2 != phi_a1) {
            phi_a1->unkC = phi_a1->unkC | 0x4000;
        }
        if (phi_a2 != phi_v0) {
            phi_v0->unkC = phi_v0->unkC | 0x4000;
        }
        temp_v0 = phi_v0 + 0x3760;
        phi_a1 += 0x3760;
        phi_v0 = temp_v0;
    } while (temp_v0 != (&gGfxPools + 0x2978));
}
#else
GLOBAL_ASM("asm/non_matchings/code_802B0210/func_802B2EBC.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
/*
Failed to decompile function func_802B2FA0:

Unable to determine jump table for jr instruction at func_802B2FA0.s line 19.

There must be a read of a variable in the same block as
the instruction, which has a name starting with "jtbl"/"jpt_".
*/
#else
GLOBAL_ASM("asm/non_matchings/code_802B0210/func_802B2FA0.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
s32 func_800910E4(? *); // extern
? func_802B2FA0(? *); // extern
extern ? *D_800DC4D0;
extern ? *D_800DC4D4;
extern ? *D_800DC4D8;
extern ? gControllers;
extern ? gPlayers;

void func_802B30EC(void) {
    ? *temp_s2;
    u16 temp_v0;
    u16 temp_v0_2;
    ? *phi_s0;
    ? *phi_s1;
    ? *phi_s2;

    phi_s0 = &gPlayers;
    phi_s2 = &gControllers;
    do {
        phi_s1 = phi_s2;
        if (func_800910E4(phi_s0) == 0) {
            temp_v0 = phi_s0->unk0;
            if ((temp_v0 & 0x100) != 0) {
                if (((phi_s0 - D_800DC4E0) / 0xDD8) == 0) {
                    phi_s1 = D_800DC4D0;
                } else if (((phi_s0 - D_800DC4E4) / 0xDD8) == 0) {
                    phi_s1 = D_800DC4D4;
                } else if (((phi_s0 - D_800DC4DC) / 0xDD8) == 0) {
                    phi_s1 = D_800DC4D8;
                }
            }
            if (((temp_v0 & 0x4000) != 0) && (phi_s0->unk10 != 0) && ((temp_v0 & 0x2000) == 0)) {
                temp_v0_2 = phi_s1->unk6;
                if ((temp_v0_2 & 0x2000) != 0) {
                    phi_s1->unk6 = temp_v0_2 & ~0x2000;
                    func_802B2FA0(phi_s0);
                }
            }
        }
        temp_s2 = phi_s2 + 0x10;
        phi_s0 += 0xDD8;
        phi_s2 = temp_s2;
    } while (temp_s2 != (&gControllers + 0x40));
}
#else
GLOBAL_ASM("asm/non_matchings/code_802B0210/func_802B30EC.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
/*
Failed to decompile function update_obj_green_shell:

Unable to determine jump table for jr instruction at update_obj_green_shell.s line 68.

There must be a read of a variable in the same block as
the instruction, which has a name starting with "jtbl"/"jpt_".
*/
#else
GLOBAL_ASM("asm/non_matchings/code_802B0210/update_obj_green_shell.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
? func_802AD950(void *, f32, f32, f32, f32, f32, f32, f32); // extern
? func_802B4E30(void *); // extern
extern u16 D_80164430;
extern s32 D_80164490;

void func_802B3B44(void *arg0) {
    f32 spAC;
    f32 spA8;
    f32 spA4;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f10;
    f32 temp_f12;
    f32 temp_f12_2;
    f32 temp_f12_3;
    f32 temp_f14;
    f32 temp_f14_2;
    f32 temp_f16;
    f32 temp_f16_2;
    f32 temp_f16_3;
    f32 temp_f18;
    f32 temp_f18_2;
    f32 temp_f18_3;
    f32 temp_f20;
    f32 temp_f22;
    f32 temp_f22_2;
    f32 temp_f24;
    f32 temp_f26;
    f32 temp_f28;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f2_3;
    s32 temp_a1;
    s32 temp_a3;
    s32 temp_t1;
    u16 temp_t0;
    u16 temp_v1;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;
    u16 phi_a2;
    f32 phi_f2;
    f32 phi_f14;
    f32 phi_f16;

    temp_v1 = arg0->unk12;
    temp_t1 = D_80164490;
    temp_v0 = temp_t1 + (temp_v1 * 8);
    temp_t0 = D_80164430;
    temp_a1 = temp_v1 + 1;
    temp_a3 = temp_a1 & 0xFFFF;
    temp_f2 = temp_v0->unk0;
    temp_f12 = temp_v0->unk2;
    temp_f28 = temp_v0->unk4;
    phi_a2 = temp_a1 & 0xFFFF;
    if (temp_a3 >= temp_t0) {
        phi_a2 = (temp_a3 - temp_t0) & 0xFFFF;
    }
    temp_f0 = arg0->unk18;
    temp_f16 = arg0->unk1C;
    temp_f18 = arg0->unk20;
    temp_f20 = temp_f2 - temp_f0;
    temp_f22 = temp_f12 - temp_f16;
    temp_v0_2 = temp_t1 + (phi_a2 * 8);
    temp_f24 = temp_f28 - temp_f18;
    sp60 = temp_f0;
    sp5C = temp_f16;
    sp58 = temp_f18;
    temp_f14 = (temp_f20 * temp_f20) + (temp_f22 * temp_f22) + (temp_f24 * temp_f24);
    if (temp_f14 > 400.0f) {
        temp_f0_2 = temp_v0_2->unk0 - sp60;
        temp_f2_2 = temp_v0_2->unk2 - sp5C;
        temp_f12_2 = temp_v0_2->unk4 - sp58;
        if (((temp_f0_2 * temp_f0_2) + (temp_f2_2 * temp_f2_2) + (temp_f12_2 * temp_f12_2)) < temp_f14) {
            arg0->unk12 = phi_a2;
            return;
        }
        temp_f18_2 = sqrtf(temp_f14) * 4.0f;
        temp_f22_2 = temp_f22 / temp_f18_2;
        temp_f2_3 = arg0->unk24 + (temp_f20 / temp_f18_2);
        temp_f10 = temp_f2_3 * temp_f2_3;
        spAC = temp_f2_3;
        temp_f14_2 = arg0->unk28 + temp_f22_2;
        spA8 = temp_f14_2;
        temp_f16_2 = arg0->unk2C + (temp_f24 / temp_f18_2);
        spA4 = temp_f16_2;
        temp_f0_3 = sqrtf(temp_f10 + (temp_f14_2 * temp_f14_2) + (temp_f16_2 * temp_f16_2));
        phi_f2 = temp_f2_3;
        phi_f14 = temp_f14_2;
        phi_f16 = temp_f16_2;
        if (temp_f0_3 > 6.0f) {
            temp_f12_3 = temp_f0_3 / 6.0f;
            phi_f2 = temp_f2_3 / temp_f12_3;
            phi_f14 = temp_f14_2 / temp_f12_3;
            phi_f16 = temp_f16_2 / temp_f12_3;
        }
        arg0->unk24 = phi_f2;
        arg0->unk28 = phi_f14;
        arg0->unk2C = phi_f16;
        sp68 = arg0->unk18;
        sp6C = arg0->unk1C;
        sp70 = arg0->unk20;
        arg0->unk18 = arg0->unk18 + phi_f2;
        arg0->unk1C = arg0->unk1C + phi_f14;
        arg0->unk20 = arg0->unk20 + phi_f16;
        func_802AD950(arg0 + 0x30, 4.0f, arg0->unk18, arg0->unk1C, arg0->unk20, sp68, sp6C, sp70);
        func_802B4E30(arg0);
        return;
    }
    temp_v0_3 = temp_t1 + (phi_a2 * 8);
    if (temp_f14 > 5.0f) {
        arg0->unk18 = temp_f2;
        arg0->unk20 = temp_f28;
        arg0->unk12 = phi_a2;
        arg0->unk1C = arg0->unkC + temp_f12;
        return;
    }
    temp_f16_3 = temp_v0_3->unk0;
    temp_f18_3 = temp_v0_3->unk2;
    temp_f26 = temp_v0_3->unk4;
    arg0->unk18 = (temp_f2 + temp_f16_3) * 0.5f;
    arg0->unk1C = ((temp_f12 + temp_f18_3) * 0.5f) + arg0->unkC;
    arg0->unk20 = (temp_f28 + temp_f26) * 0.5f;
    arg0->unk24 = (temp_f16_3 - temp_f2) * 0.5f;
    arg0->unk28 = (temp_f18_3 - temp_f12) * 0.5f;
    arg0->unk2C = (temp_f26 - temp_f28) * 0.5f;
}
#else
GLOBAL_ASM("asm/non_matchings/code_802B0210/func_802B3B44.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
? func_8029FDC8(f32, f32, void *, ?); // extern
? func_802AD950(f32, f32, void *, ?, f32, f32, f32, f32, f32, f32); // extern
? func_802B4104(void *); // extern
? func_802B4E30(void *); // extern

void func_802B3E7C(void *arg0, void *arg1) {
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 temp_f12;
    f32 temp_f14;
    f32 temp_f2;
    f32 phi_f2;
    f32 phi_f14;

    temp_f2 = arg1->unk14 - arg0->unk18;
    temp_f14 = arg1->unk1C - arg0->unk20;
    sp44 = temp_f2;
    sp40 = temp_f14;
    temp_f12 = sqrtf((temp_f2 * temp_f2) + (temp_f14 * temp_f14)) / 8.0f;
    if (temp_f12 == 0.0f) {
        phi_f2 = 0.0f;
        phi_f14 = 0.0f;
    } else {
        phi_f2 = temp_f2 / temp_f12;
        phi_f14 = temp_f14 / temp_f12;
    }
    sp30 = arg0->unk18;
    sp34 = arg0->unk1C;
    sp38 = arg0->unk20;
    arg0->unk24 = phi_f2;
    arg0->unk2C = phi_f14;
    arg0->unk18 = arg0->unk18 + phi_f2;
    arg0->unk1C = arg0->unk1C - 2.0f;
    arg0->unk28 = -2.0f;
    arg0->unk20 = arg0->unk20 + phi_f14;
    if (arg1->unkBC & 0x80000000) {
        func_8029FDC8(temp_f12, phi_f14, arg0, 0x40800000);
        return;
    }
    func_802AD950(temp_f12, phi_f14, arg0 + 0x30, 0x40800000, arg0->unk18, arg0->unk1C, arg0->unk20, sp30, sp34, sp38);
    func_802B4E30(arg0);
    func_802B4104(arg0);
}
#else
GLOBAL_ASM("asm/non_matchings/code_802B0210/func_802B3E7C.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
f32 func_802B51E8(void *, s32); // extern
extern ? D_8018D8C0;
extern f32 D_802B9F68;
extern u16 gPlayers;

s16 func_802B3FD0(s32 arg0, s32 arg1) {
    f32 temp_f0;
    s32 temp_s1;
    u16 *phi_s0;
    s32 phi_s1;
    f32 phi_f20;
    s16 phi_fp;

    phi_s0 = &gPlayers;
    phi_s1 = 0;
    phi_f20 = D_802B9F68;
    phi_fp = -1;
    do {
        if (((*phi_s0 & 0x8000) != 0) && (phi_s0 != arg0) && (*(&D_8018D8C0 + (phi_s1 * 2)) >= 0)) {
            temp_f0 = func_802B51E8(phi_s0 + 0x14, arg1 + 0x18);
            if (temp_f0 < phi_f20) {
                phi_fp = (phi_s0 - D_800DC4DC) / 0xDD8;
                phi_f20 = temp_f0;
            }
        }
        temp_s1 = phi_s1 + 1;
        phi_s0 += 0xDD8;
        phi_s1 = temp_s1;
    } while (temp_s1 != 4);
    return phi_fp;
}
#else
GLOBAL_ASM("asm/non_matchings/code_802B0210/func_802B3FD0.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
? func_800C98B8(void *, void *, ?); // extern
? func_8029FDC8(void *); // extern

void func_802B4104(void *arg0) {
    f32 temp_f0;
    f32 temp_f0_2;

    if ((arg0->unk3C < 0.0f) && ((temp_f0 = arg0->unk4C, (temp_f0 < 0.25f)) || (temp_f0 > -0.25f))) {
        func_8029FDC8(arg0);
        func_800C98B8(arg0 + 0x18, arg0 + 0x24, 0x19008054);
        arg0->unk2 = arg0->unk2 | 0x80;
        return;
    }
    if ((arg0->unk40 < 0.0f) && ((temp_f0_2 = arg0->unk58, (temp_f0_2 < 0.25f)) || (temp_f0_2 < -0.25f))) {
        func_8029FDC8(arg0);
        func_800C98B8(arg0 + 0x18, arg0 + 0x24, 0x19008054);
        arg0->unk2 = arg0->unk2 | 0x80;
    }
}
#else
GLOBAL_ASM("asm/non_matchings/code_802B0210/func_802B4104.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
/*
Failed to decompile function update_obj_red_blue_shell:

Unable to determine jump table for jr instruction at update_obj_red_blue_shell.s line 69.

There must be a read of a variable in the same block as
the instruction, which has a name starting with "jtbl"/"jpt_".
*/
#else
GLOBAL_ASM("asm/non_matchings/code_802B0210/update_obj_red_blue_shell.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
void func_802B4E30(void *arg0) {
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;

    temp_f0 = arg0->unk44;
    if ((temp_f0 < 0.0f) && (arg0->unk34 == 1)) {
        arg0->unk18 = arg0->unk18 - (arg0->unk60 * temp_f0);
        arg0->unk1C = arg0->unk1C - (arg0->unk64 * temp_f0);
        arg0->unk20 = arg0->unk20 - (arg0->unk68 * temp_f0);
    }
    temp_f0_2 = arg0->unk3C;
    if ((temp_f0_2 < 0.0f) && (arg0->unk30 == 1)) {
        arg0->unk18 = arg0->unk18 - (arg0->unk48 * temp_f0_2);
        arg0->unk1C = arg0->unk1C - (arg0->unk4C * temp_f0_2);
        arg0->unk20 = arg0->unk20 - (arg0->unk50 * temp_f0_2);
    }
    temp_f0_3 = arg0->unk40;
    if ((temp_f0_3 < 0.0f) && (arg0->unk32 == 1)) {
        arg0->unk18 = arg0->unk18 - (arg0->unk54 * temp_f0_3);
        arg0->unk1C = arg0->unk1C - (arg0->unk58 * temp_f0_3);
        arg0->unk20 = arg0->unk20 - (arg0->unk5C * temp_f0_3);
    }
}
#else
GLOBAL_ASM("asm/non_matchings/code_802B0210/func_802B4E30.s")
#endif