glabel func_8004F020
/* 04FC20 8004F020 00041040 */  sll   $v0, $a0, 1
/* 04FC24 8004F024 3C0E8019 */  lui   $t6, %hi(D_8018D2C0) # 0x8019
/* 04FC28 8004F028 01C27021 */  addu  $t6, $t6, $v0
/* 04FC2C 8004F02C 3C0F8019 */  lui   $t7, %hi(D_8018D2F0) # $t7, 0x8019
/* 04FC30 8004F030 85EFD2F0 */  lh    $t7, %lo(D_8018D2F0)($t7)
/* 04FC34 8004F034 85CED2C0 */  lh    $t6, %lo(D_8018D2C0)($t6) # -0x2d40($t6)
/* 04FC38 8004F038 3C198019 */  lui   $t9, %hi(D_8018D2B0) # $t9, 0x8019
/* 04FC3C 8004F03C 8739D2B0 */  lh    $t9, %lo(D_8018D2B0)($t9)
/* 04FC40 8004F040 3C0C8019 */  lui   $t4, %hi(D_8018D2D8) # 0x8019
/* 04FC44 8004F044 01CFC021 */  addu  $t8, $t6, $t7
/* 04FC48 8004F048 3C0A8019 */  lui   $t2, %hi(D_8018D2E0) # $t2, 0x8019
/* 04FC4C 8004F04C 3C0F8019 */  lui   $t7, %hi(D_8018D2B8) # $t7, 0x8019
/* 04FC50 8004F050 01826021 */  addu  $t4, $t4, $v0
/* 04FC54 8004F054 3C0D8019 */  lui   $t5, %hi(D_8018D2F8) # $t5, 0x8019
/* 04FC58 8004F058 854AD2E0 */  lh    $t2, %lo(D_8018D2E0)($t2)
/* 04FC5C 8004F05C 85ADD2F8 */  lh    $t5, %lo(D_8018D2F8)($t5)
/* 04FC60 8004F060 858CD2D8 */  lh    $t4, %lo(D_8018D2D8)($t4) # -0x2d28($t4)
/* 04FC64 8004F064 85EFD2B8 */  lh    $t7, %lo(D_8018D2B8)($t7)
/* 04FC68 8004F068 3C03800E */  lui   $v1, %hi(gCurrentCourseId) # $v1, 0x800e
/* 04FC6C 8004F06C 018D7021 */  addu  $t6, $t4, $t5
/* 04FC70 8004F070 8463C5A0 */  lh    $v1, %lo(gCurrentCourseId)($v1)
/* 04FC74 8004F074 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 04FC78 8004F078 AFBF0014 */  sw    $ra, 0x14($sp)
/* 04FC7C 8004F07C 07210003 */  bgez  $t9, .L8004F08C
/* 04FC80 8004F080 00194043 */   sra   $t0, $t9, 1
/* 04FC84 8004F084 27210001 */  addiu $at, $t9, 1
/* 04FC88 8004F088 00014043 */  sra   $t0, $at, 1
.L8004F08C:
/* 04FC8C 8004F08C 03084823 */  subu  $t1, $t8, $t0
/* 04FC90 8004F090 3C088019 */  lui   $t0, %hi(D_8018D2E8) # $t0, 0x8019
/* 04FC94 8004F094 8508D2E8 */  lh    $t0, %lo(D_8018D2E8)($t0)
/* 04FC98 8004F098 012A5821 */  addu  $t3, $t1, $t2
/* 04FC9C 8004F09C 448B2000 */  mtc1  $t3, $f4
/* 04FCA0 8004F0A0 00000000 */  nop   
/* 04FCA4 8004F0A4 468020A0 */  cvt.s.w $f2, $f4
/* 04FCA8 8004F0A8 05E10003 */  bgez  $t7, .L8004F0B8
/* 04FCAC 8004F0AC 000FC843 */   sra   $t9, $t7, 1
/* 04FCB0 8004F0B0 25E10001 */  addiu $at, $t7, 1
/* 04FCB4 8004F0B4 0001C843 */  sra   $t9, $at, 1
.L8004F0B8:
/* 04FCB8 8004F0B8 01D9C023 */  subu  $t8, $t6, $t9
/* 04FCBC 8004F0BC 03084821 */  addu  $t1, $t8, $t0
/* 04FCC0 8004F0C0 44893000 */  mtc1  $t1, $f6
/* 04FCC4 8004F0C4 3C014000 */  lui   $at, 0x4000
/* 04FCC8 8004F0C8 10600008 */  beqz  $v1, .L8004F0EC
/* 04FCCC 8004F0CC 46803020 */   cvt.s.w $f0, $f6
/* 04FCD0 8004F0D0 24010001 */  li    $at, 1
/* 04FCD4 8004F0D4 1061000B */  beq   $v1, $at, .L8004F104
/* 04FCD8 8004F0D8 2401000B */   li    $at, 11
/* 04FCDC 8004F0DC 50610011 */  beql  $v1, $at, .L8004F124
/* 04FCE0 8004F0E0 3C014010 */   li    $at, 0x40100000 # 2.250000
/* 04FCE4 8004F0E4 10000015 */  b     .L8004F13C
/* 04FCE8 8004F0E8 4600148D */   trunc.w.s $f18, $f2
.L8004F0EC:
/* 04FCEC 8004F0EC 44815800 */  mtc1  $at, $f11
/* 04FCF0 8004F0F0 44805000 */  mtc1  $zero, $f10
/* 04FCF4 8004F0F4 46000221 */  cvt.d.s $f8, $f0
/* 04FCF8 8004F0F8 462A4401 */  sub.d $f16, $f8, $f10
/* 04FCFC 8004F0FC 1000000E */  b     .L8004F138
/* 04FD00 8004F100 46208020 */   cvt.s.d $f0, $f16
.L8004F104:
/* 04FD04 8004F104 3C014030 */  li    $at, 0x40300000 # 2.750000
/* 04FD08 8004F108 44812800 */  mtc1  $at, $f5
/* 04FD0C 8004F10C 44802000 */  mtc1  $zero, $f4
/* 04FD10 8004F110 460004A1 */  cvt.d.s $f18, $f0
/* 04FD14 8004F114 46249181 */  sub.d $f6, $f18, $f4
/* 04FD18 8004F118 10000007 */  b     .L8004F138
/* 04FD1C 8004F11C 46203020 */   cvt.s.d $f0, $f6
/* 04FD20 8004F120 3C014010 */  li    $at, 0x40100000 # 2.250000
.L8004F124:
/* 04FD24 8004F124 44815800 */  mtc1  $at, $f11
/* 04FD28 8004F128 44805000 */  mtc1  $zero, $f10
/* 04FD2C 8004F12C 46000221 */  cvt.d.s $f8, $f0
/* 04FD30 8004F130 462A4400 */  add.d $f16, $f8, $f10
/* 04FD34 8004F134 46208020 */  cvt.s.d $f0, $f16
.L8004F138:
/* 04FD38 8004F138 4600148D */  trunc.w.s $f18, $f2
.L8004F13C:
/* 04FD3C 8004F13C 3C060D03 */  lui   $a2, %hi(D_0D02CC58) # $a2, 0xd03
/* 04FD40 8004F140 24C6CC58 */  addiu $a2, %lo(D_0D02CC58) # addiu $a2, $a2, -0x33a8
/* 04FD44 8004F144 4600010D */  trunc.w.s $f4, $f0
/* 04FD48 8004F148 44049000 */  mfc1  $a0, $f18
/* 04FD4C 8004F14C 44052000 */  mfc1  $a1, $f4
/* 04FD50 8004F150 0C0132B4 */  jal   func_8004CAD0
/* 04FD54 8004F154 00000000 */   nop   
/* 04FD58 8004F158 8FBF0014 */  lw    $ra, 0x14($sp)
/* 04FD5C 8004F15C 27BD0018 */  addiu $sp, $sp, 0x18
/* 04FD60 8004F160 03E00008 */  jr    $ra
/* 04FD64 8004F164 00000000 */   nop   