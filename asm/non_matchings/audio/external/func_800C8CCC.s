glabel func_800C8CCC
/* 0C98CC 800C8CCC 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0C98D0 800C8CD0 AFB10024 */  sw    $s1, 0x24($sp)
/* 0C98D4 800C8CD4 3C11800F */  lui   $s1, %hi(D_800EA1C0) # $s1, 0x800f
/* 0C98D8 800C8CD8 2631A1C0 */  addiu $s1, %lo(D_800EA1C0) # addiu $s1, $s1, -0x5e40
/* 0C98DC 800C8CDC 92220000 */  lbu   $v0, ($s1)
/* 0C98E0 800C8CE0 AFBE0028 */  sw    $fp, 0x28($sp)
/* 0C98E4 800C8CE4 AFB00020 */  sw    $s0, 0x20($sp)
/* 0C98E8 800C8CE8 24420001 */  addiu $v0, $v0, 1
/* 0C98EC 800C8CEC 03A0F025 */  move  $fp, $sp
/* 0C98F0 800C8CF0 AFBF002C */  sw    $ra, 0x2c($sp)
/* 0C98F4 800C8CF4 1840001D */  blez  $v0, .L800C8D6C
/* 0C98F8 800C8CF8 00008025 */   move  $s0, $zero
.L800C8CFC:
/* 0C98FC 800C8CFC 0C031741 */  jal   func_800C5D04
/* 0C9900 800C8D00 320400FF */   andi  $a0, $s0, 0xff
/* 0C9904 800C8D04 0C03178E */  jal   func_800C5E38
/* 0C9908 800C8D08 320400FF */   andi  $a0, $s0, 0xff
/* 0C990C 800C8D0C 0C031842 */  jal   func_800C6108
/* 0C9910 800C8D10 320400FF */   andi  $a0, $s0, 0xff
/* 0C9914 800C8D14 0C031928 */  jal   func_800C64A0
/* 0C9918 800C8D18 320400FF */   andi  $a0, $s0, 0xff
/* 0C991C 800C8D1C 0C0319D6 */  jal   func_800C6758
/* 0C9920 800C8D20 320400FF */   andi  $a0, $s0, 0xff
/* 0C9924 800C8D24 0C031A0F */  jal   func_800C683C
/* 0C9928 800C8D28 320400FF */   andi  $a0, $s0, 0xff
/* 0C992C 800C8D2C 0C031C2A */  jal   func_800C70A8
/* 0C9930 800C8D30 320400FF */   andi  $a0, $s0, 0xff
/* 0C9934 800C8D34 0C031DB0 */  jal   func_800C76C0
/* 0C9938 800C8D38 320400FF */   andi  $a0, $s0, 0xff
/* 0C993C 800C8D3C 0C03211F */  jal   func_800C847C
/* 0C9940 800C8D40 320400FF */   andi  $a0, $s0, 0xff
/* 0C9944 800C8D44 0C0321B6 */  jal   func_800C86D8
/* 0C9948 800C8D48 320400FF */   andi  $a0, $s0, 0xff
/* 0C994C 800C8D4C 92220000 */  lbu   $v0, ($s1)
/* 0C9950 800C8D50 26100001 */  addiu $s0, $s0, 1
/* 0C9954 800C8D54 320E00FF */  andi  $t6, $s0, 0xff
/* 0C9958 800C8D58 24420001 */  addiu $v0, $v0, 1
/* 0C995C 800C8D5C 01C2082A */  slt   $at, $t6, $v0
/* 0C9960 800C8D60 1420FFE6 */  bnez  $at, .L800C8CFC
/* 0C9964 800C8D64 01C08025 */   move  $s0, $t6
/* 0C9968 800C8D68 00008025 */  move  $s0, $zero
.L800C8D6C:
/* 0C996C 800C8D6C 3C0F800E */  lui   $t7, %hi(gModeSelection) # $t7, 0x800e
/* 0C9970 800C8D70 8DEFC53C */  lw    $t7, %lo(gModeSelection)($t7)
/* 0C9974 800C8D74 15E0000C */  bnez  $t7, .L800C8DA8
/* 0C9978 800C8D78 00000000 */   nop   
.L800C8D7C:
/* 0C997C 800C8D7C 0C0321DC */  jal   func_800C8770
/* 0C9980 800C8D80 320400FF */   andi  $a0, $s0, 0xff
/* 0C9984 800C8D84 0C03231F */  jal   func_800C8C7C
/* 0C9988 800C8D88 320400FF */   andi  $a0, $s0, 0xff
/* 0C998C 800C8D8C 26100001 */  addiu $s0, $s0, 1
/* 0C9990 800C8D90 321800FF */  andi  $t8, $s0, 0xff
/* 0C9994 800C8D94 2B010008 */  slti  $at, $t8, 8
/* 0C9998 800C8D98 1420FFF8 */  bnez  $at, .L800C8D7C
/* 0C999C 800C8D9C 03008025 */   move  $s0, $t8
/* 0C99A0 800C8DA0 1000000E */  b     .L800C8DDC
/* 0C99A4 800C8DA4 00000000 */   nop   
.L800C8DA8:
/* 0C99A8 800C8DA8 1840000C */  blez  $v0, .L800C8DDC
/* 0C99AC 800C8DAC 00000000 */   nop   
.L800C8DB0:
/* 0C99B0 800C8DB0 0C0321DC */  jal   func_800C8770
/* 0C99B4 800C8DB4 320400FF */   andi  $a0, $s0, 0xff
/* 0C99B8 800C8DB8 0C03231F */  jal   func_800C8C7C
/* 0C99BC 800C8DBC 320400FF */   andi  $a0, $s0, 0xff
/* 0C99C0 800C8DC0 92280000 */  lbu   $t0, ($s1)
/* 0C99C4 800C8DC4 26100001 */  addiu $s0, $s0, 1
/* 0C99C8 800C8DC8 321900FF */  andi  $t9, $s0, 0xff
/* 0C99CC 800C8DCC 25090001 */  addiu $t1, $t0, 1
/* 0C99D0 800C8DD0 0329082A */  slt   $at, $t9, $t1
/* 0C99D4 800C8DD4 1420FFF6 */  bnez  $at, .L800C8DB0
/* 0C99D8 800C8DD8 03208025 */   move  $s0, $t9
.L800C8DDC:
/* 0C99DC 800C8DDC 0C032248 */  jal   func_800C8920
/* 0C99E0 800C8DE0 00000000 */   nop   
/* 0C99E4 800C8DE4 0C032279 */  jal   func_800C89E4
/* 0C99E8 800C8DE8 00000000 */   nop   
/* 0C99EC 800C8DEC 0C0322B9 */  jal   func_800C8AE4
/* 0C99F0 800C8DF0 00000000 */   nop   
/* 0C99F4 800C8DF4 8FDF002C */  lw    $ra, 0x2c($fp)
/* 0C99F8 800C8DF8 03C0E825 */  move  $sp, $fp
/* 0C99FC 800C8DFC 8FD00020 */  lw    $s0, 0x20($fp)
/* 0C9A00 800C8E00 8FD10024 */  lw    $s1, 0x24($fp)
/* 0C9A04 800C8E04 8FDE0028 */  lw    $fp, 0x28($fp)
/* 0C9A08 800C8E08 03E00008 */  jr    $ra
/* 0C9A0C 800C8E0C 27BD0030 */   addiu $sp, $sp, 0x30