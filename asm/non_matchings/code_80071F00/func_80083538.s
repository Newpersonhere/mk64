glabel func_80083538
/* 084138 80083538 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 08413C 8008353C AFBF001C */  sw    $ra, 0x1c($sp)
/* 084140 80083540 AFA50024 */  sw    $a1, 0x24($sp)
/* 084144 80083544 AFB00018 */  sw    $s0, 0x18($sp)
/* 084148 80083548 AFA40020 */  sw    $a0, 0x20($sp)
/* 08414C 8008354C AFA60028 */  sw    $a2, 0x28($sp)
/* 084150 80083550 AFA7002C */  sw    $a3, 0x2c($sp)
/* 084154 80083554 0C01C8E9 */  jal   func_800723A4
/* 084158 80083558 00002825 */   move  $a1, $zero
/* 08415C 8008355C 8FAE0020 */  lw    $t6, 0x20($sp)
/* 084160 80083560 3C188016 */  lui   $t8, %hi(D_80165C18) # $t8, 0x8016
/* 084164 80083564 27185C18 */  addiu $t8, %lo(D_80165C18) # addiu $t8, $t8, 0x5c18
/* 084168 80083568 000E78C0 */  sll   $t7, $t6, 3
/* 08416C 8008356C 01EE7823 */  subu  $t7, $t7, $t6
/* 084170 80083570 000F7940 */  sll   $t7, $t7, 5
/* 084174 80083574 01F88021 */  addu  $s0, $t7, $t8
/* 084178 80083578 3C020600 */  lui   $v0, %hi(D_06006F20) # $v0, 0x600
/* 08417C 8008357C 3C030600 */  lui   $v1, %hi(D_06006D20) # $v1, 0x600
/* 084180 80083580 24636D20 */  addiu $v1, %lo(D_06006D20) # addiu $v1, $v1, 0x6d20
/* 084184 80083584 24426F20 */  addiu $v0, %lo(D_06006F20) # addiu $v0, $v0, 0x6f20
/* 084188 80083588 AE020064 */  sw    $v0, 0x64($s0)
/* 08418C 8008358C AE02006C */  sw    $v0, 0x6c($s0)
/* 084190 80083590 AE030060 */  sw    $v1, 0x60($s0)
/* 084194 80083594 AE030068 */  sw    $v1, 0x68($s0)
/* 084198 80083598 0C0ADF8D */  jal   random_int
/* 08419C 8008359C 24040064 */   li    $a0, 100
/* 0841A0 800835A0 44822000 */  mtc1  $v0, $f4
/* 0841A4 800835A4 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0841A8 800835A8 04410004 */  bgez  $v0, .L800835BC
/* 0841AC 800835AC 468021A0 */   cvt.s.w $f6, $f4
/* 0841B0 800835B0 44814000 */  mtc1  $at, $f8
/* 0841B4 800835B4 00000000 */  nop   
/* 0841B8 800835B8 46083180 */  add.s $f6, $f6, $f8
.L800835BC:
/* 0841BC 800835BC 3C01800F */  lui   $at, %hi(D_800EF1E8)
/* 0841C0 800835C0 D430F1E8 */  ldc1  $f16, %lo(D_800EF1E8)($at)
/* 0841C4 800835C4 460032A1 */  cvt.d.s $f10, $f6
/* 0841C8 800835C8 3C01800F */  lui   $at, %hi(D_800EF1F0)
/* 0841CC 800835CC 46305482 */  mul.d $f18, $f10, $f16
/* 0841D0 800835D0 D424F1F0 */  ldc1  $f4, %lo(D_800EF1F0)($at)
/* 0841D4 800835D4 24040014 */  li    $a0, 20
/* 0841D8 800835D8 46249200 */  add.d $f8, $f18, $f4
/* 0841DC 800835DC 462041A0 */  cvt.s.d $f6, $f8
/* 0841E0 800835E0 0C0ADF8D */  jal   random_int
/* 0841E4 800835E4 E6060000 */   swc1  $f6, ($s0)
/* 0841E8 800835E8 44825000 */  mtc1  $v0, $f10
/* 0841EC 800835EC 44804000 */  mtc1  $zero, $f8
/* 0841F0 800835F0 04410005 */  bgez  $v0, .L80083608
/* 0841F4 800835F4 46805420 */   cvt.s.w $f16, $f10
/* 0841F8 800835F8 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0841FC 800835FC 44819000 */  mtc1  $at, $f18
/* 084200 80083600 00000000 */  nop   
/* 084204 80083604 46128400 */  add.s $f16, $f16, $f18
.L80083608:
/* 084208 80083608 3C013FE0 */  li    $at, 0x3FE00000 # 1.750000
/* 08420C 8008360C 44814800 */  mtc1  $at, $f9
/* 084210 80083610 46008121 */  cvt.d.s $f4, $f16
/* 084214 80083614 3C01800F */  lui   $at, %hi(D_800EF1F8)
/* 084218 80083618 46282182 */  mul.d $f6, $f4, $f8
/* 08421C 8008361C D42AF1F8 */  ldc1  $f10, %lo(D_800EF1F8)($at)
/* 084220 80083620 2404000A */  li    $a0, 10
/* 084224 80083624 462A3480 */  add.d $f18, $f6, $f10
/* 084228 80083628 46209420 */  cvt.s.d $f16, $f18
/* 08422C 8008362C 0C0ADF8D */  jal   random_int
/* 084230 80083630 E610003C */   swc1  $f16, 0x3c($s0)
/* 084234 80083634 44822000 */  mtc1  $v0, $f4
/* 084238 80083638 8FA30024 */  lw    $v1, 0x24($sp)
/* 08423C 8008363C 04410005 */  bgez  $v0, .L80083654
/* 084240 80083640 46802220 */   cvt.s.w $f8, $f4
/* 084244 80083644 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 084248 80083648 44813000 */  mtc1  $at, $f6
/* 08424C 8008364C 00000000 */  nop   
/* 084250 80083650 46064200 */  add.s $f8, $f8, $f6
.L80083654:
/* 084254 80083654 8FB90028 */  lw    $t9, 0x28($sp)
/* 084258 80083658 8FA9002C */  lw    $t1, 0x2c($sp)
/* 08425C 8008365C 3C01800F */  lui   $at, %hi(D_800EF200)
/* 084260 80083660 00194400 */  sll   $t0, $t9, 0x10
/* 084264 80083664 0109001A */  div   $zero, $t0, $t1
/* 084268 80083668 D432F200 */  ldc1  $f18, %lo(D_800EF200)($at)
/* 08426C 8008366C 460042A1 */  cvt.d.s $f10, $f8
/* 084270 80083670 3C014012 */  li    $at, 0x40120000 # 2.281250
/* 084274 80083674 46325402 */  mul.d $f16, $f10, $f18
/* 084278 80083678 44812800 */  mtc1  $at, $f5
/* 08427C 8008367C 44802000 */  mtc1  $zero, $f4
/* 084280 80083680 00005012 */  mflo  $t2
/* 084284 80083684 A60A00C0 */  sh    $t2, 0xc0($s0)
/* 084288 80083688 24044000 */  li    $a0, 16384
/* 08428C 8008368C 46248180 */  add.d $f6, $f16, $f4
/* 084290 80083690 46203220 */  cvt.s.d $f8, $f6
/* 084294 80083694 E6080034 */  swc1  $f8, 0x34($s0)
/* 084298 80083698 C46A0000 */  lwc1  $f10, ($v1)
/* 08429C 8008369C 15200002 */  bnez  $t1, .L800836A8
/* 0842A0 800836A0 00000000 */   nop   
/* 0842A4 800836A4 0007000D */  break 7
.L800836A8:
/* 0842A8 800836A8 2401FFFF */  li    $at, -1
/* 0842AC 800836AC 15210004 */  bne   $t1, $at, .L800836C0
/* 0842B0 800836B0 3C018000 */   lui   $at, 0x8000
/* 0842B4 800836B4 15010002 */  bne   $t0, $at, .L800836C0
/* 0842B8 800836B8 00000000 */   nop   
/* 0842BC 800836BC 0006000D */  break 6
.L800836C0:
/* 0842C0 800836C0 E60A0010 */  swc1  $f10, 0x10($s0)
/* 0842C4 800836C4 C4720004 */  lwc1  $f18, 4($v1)
/* 0842C8 800836C8 E6120014 */  swc1  $f18, 0x14($s0)
/* 0842CC 800836CC C4700008 */  lwc1  $f16, 8($v1)
/* 0842D0 800836D0 0C0ADF8D */  jal   random_int
/* 0842D4 800836D4 E6100018 */   swc1  $f16, 0x18($s0)
/* 0842D8 800836D8 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0842DC 800836DC 244B1000 */  addiu $t3, $v0, 0x1000
/* 0842E0 800836E0 A60B00A0 */  sh    $t3, 0xa0($s0)
/* 0842E4 800836E4 8FB00018 */  lw    $s0, 0x18($sp)
/* 0842E8 800836E8 03E00008 */  jr    $ra
/* 0842EC 800836EC 27BD0020 */   addiu $sp, $sp, 0x20