glabel func_800557B4
/* 0563B4 800557B4 000470C0 */  sll   $t6, $a0, 3
/* 0563B8 800557B8 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 0563BC 800557BC 01C47023 */  subu  $t6, $t6, $a0
/* 0563C0 800557C0 3C0F8016 */  lui   $t7, %hi(D_80165C18) # $t7, 0x8016
/* 0563C4 800557C4 AFB00018 */  sw    $s0, 0x18($sp)
/* 0563C8 800557C8 25EF5C18 */  addiu $t7, %lo(D_80165C18) # addiu $t7, $t7, 0x5c18
/* 0563CC 800557CC 000E7140 */  sll   $t6, $t6, 5
/* 0563D0 800557D0 01CF8021 */  addu  $s0, $t6, $t7
/* 0563D4 800557D4 861800A6 */  lh    $t8, 0xa6($s0)
/* 0563D8 800557D8 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0563DC 800557DC AFA50044 */  sw    $a1, 0x44($sp)
/* 0563E0 800557E0 2B010002 */  slti  $at, $t8, 2
/* 0563E4 800557E4 1420004C */  bnez  $at, .L80055918
/* 0563E8 800557E8 AFA60048 */   sw    $a2, 0x48($sp)
/* 0563EC 800557EC 24050020 */  li    $a1, 32
/* 0563F0 800557F0 0C01C88F */  jal   func_8007223C
/* 0563F4 800557F4 AFA40040 */   sw    $a0, 0x40($sp)
/* 0563F8 800557F8 10400032 */  beqz  $v0, .L800558C4
/* 0563FC 800557FC 8FA40040 */   lw    $a0, 0x40($sp)
/* 056400 80055800 0C01C8C8 */  jal   func_80072320
/* 056404 80055804 24050004 */   li    $a1, 4
/* 056408 80055808 10400027 */  beqz  $v0, .L800558A8
/* 05640C 8005580C 8FAD0044 */   lw    $t5, 0x44($sp)
/* 056410 80055810 8FB90048 */  lw    $t9, 0x48($sp)
/* 056414 80055814 8FA90044 */  lw    $t1, 0x44($sp)
/* 056418 80055818 27A40034 */  addiu $a0, $sp, 0x34
/* 05641C 8005581C 0329082B */  sltu  $at, $t9, $t1
/* 056420 80055820 14200028 */  bnez  $at, .L800558C4
/* 056424 80055824 00000000 */   nop   
/* 056428 80055828 C6060008 */  lwc1  $f6, 8($s0)
/* 05642C 8005582C 3C013FF0 */  li    $at, 0x3FF00000 # 1.875000
/* 056430 80055830 44815800 */  mtc1  $at, $f11
/* 056434 80055834 44805000 */  mtc1  $zero, $f10
/* 056438 80055838 46003221 */  cvt.d.s $f8, $f6
/* 05643C 8005583C C6040004 */  lwc1  $f4, 4($s0)
/* 056440 80055840 462A4401 */  sub.d $f16, $f8, $f10
/* 056444 80055844 260500B2 */  addiu $a1, $s0, 0xb2
/* 056448 80055848 E7A40034 */  swc1  $f4, 0x34($sp)
/* 05644C 8005584C C604000C */  lwc1  $f4, 0xc($s0)
/* 056450 80055850 462084A0 */  cvt.s.d $f18, $f16
/* 056454 80055854 8E060000 */  lw    $a2, ($s0)
/* 056458 80055858 E7A4003C */  swc1  $f4, 0x3c($sp)
/* 05645C 8005585C 0C010BDC */  jal   func_80042F70
/* 056460 80055860 E7B20038 */   swc1  $f18, 0x38($sp)
/* 056464 80055864 3C088015 */  lui   $t0, %hi(gDisplayListHead) # $t0, 0x8015
/* 056468 80055868 25080298 */  addiu $t0, %lo(gDisplayListHead) # addiu $t0, $t0, 0x298
/* 05646C 8005586C 8D030000 */  lw    $v1, ($t0)
/* 056470 80055870 3C0C0D00 */  lui   $t4, %hi(D_0D0077D0) # $t4, 0xd00
/* 056474 80055874 258C77D0 */  addiu $t4, %lo(D_0D0077D0) # addiu $t4, $t4, 0x77d0
/* 056478 80055878 246A0008 */  addiu $t2, $v1, 8
/* 05647C 8005587C AD0A0000 */  sw    $t2, ($t0)
/* 056480 80055880 3C0B0600 */  lui   $t3, 0x600
/* 056484 80055884 AC6B0000 */  sw    $t3, ($v1)
/* 056488 80055888 AC6C0004 */  sw    $t4, 4($v1)
/* 05648C 8005588C 820700D2 */  lb    $a3, 0xd2($s0)
/* 056490 80055890 920600D8 */  lbu   $a2, 0xd8($s0)
/* 056494 80055894 8E050074 */  lw    $a1, 0x74($s0)
/* 056498 80055898 0C00137F */  jal   func_80004DFC
/* 05649C 8005589C 8E040070 */   lw    $a0, 0x70($s0)
/* 0564A0 800558A0 10000008 */  b     .L800558C4
/* 0564A4 800558A4 00000000 */   nop   
.L800558A8:
/* 0564A8 800558A8 3C010001 */  lui   $at, (0x00015F91 >> 16) # lui $at, 1
/* 0564AC 800558AC 34215F91 */  ori   $at, (0x00015F91 & 0xFFFF) # ori $at, $at, 0x5f91
/* 0564B0 800558B0 01A1082B */  sltu  $at, $t5, $at
/* 0564B4 800558B4 10200003 */  beqz  $at, .L800558C4
/* 0564B8 800558B8 8FA40040 */   lw    $a0, 0x40($sp)
/* 0564BC 800558BC 0C0129EB */  jal   func_8004A7AC
/* 0564C0 800558C0 3C053FC0 */   lui   $a1, 0x3fc0
.L800558C4:
/* 0564C4 800558C4 3C0E0D00 */  lui   $t6, %hi(D_0D0077D0) # $t6, 0xd00
/* 0564C8 800558C8 25CE77D0 */  addiu $t6, %lo(D_0D0077D0) # addiu $t6, $t6, 0x77d0
/* 0564CC 800558CC AFAE0020 */  sw    $t6, 0x20($sp)
/* 0564D0 800558D0 26040004 */  addiu $a0, $s0, 4
/* 0564D4 800558D4 260500B2 */  addiu $a1, $s0, 0xb2
/* 0564D8 800558D8 0C010B80 */  jal   func_80042E00
/* 0564DC 800558DC 8E060000 */   lw    $a2, ($s0)
/* 0564E0 800558E0 3C038015 */  lui   $v1, %hi(gDisplayListHead) # $v1, 0x8015
/* 0564E4 800558E4 8C630298 */  lw    $v1, %lo(gDisplayListHead)($v1)
/* 0564E8 800558E8 3C018015 */  lui   $at, %hi(gDisplayListHead) # $at, 0x8015
/* 0564EC 800558EC 3C180600 */  lui   $t8, 0x600
/* 0564F0 800558F0 246F0008 */  addiu $t7, $v1, 8
/* 0564F4 800558F4 AC2F0298 */  sw    $t7, %lo(gDisplayListHead)($at)
/* 0564F8 800558F8 AC780000 */  sw    $t8, ($v1)
/* 0564FC 800558FC 8FB90020 */  lw    $t9, 0x20($sp)
/* 056500 80055900 AC790004 */  sw    $t9, 4($v1)
/* 056504 80055904 820700D2 */  lb    $a3, 0xd2($s0)
/* 056508 80055908 920600D8 */  lbu   $a2, 0xd8($s0)
/* 05650C 8005590C 8E050074 */  lw    $a1, 0x74($s0)
/* 056510 80055910 0C00137F */  jal   func_80004DFC
/* 056514 80055914 8E040070 */   lw    $a0, 0x70($s0)
.L80055918:
/* 056518 80055918 8FBF001C */  lw    $ra, 0x1c($sp)
/* 05651C 8005591C 8FB00018 */  lw    $s0, 0x18($sp)
/* 056520 80055920 27BD0040 */  addiu $sp, $sp, 0x40
/* 056524 80055924 03E00008 */  jr    $ra
/* 056528 80055928 00000000 */   nop   