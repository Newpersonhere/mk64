glabel func_80058F78
/* 059B78 80058F78 3C0E8016 */  lui   $t6, %hi(D_801657B0) # $t6, 0x8016
/* 059B7C 80058F7C 81CE57B0 */  lb    $t6, %lo(D_801657B0)($t6)
/* 059B80 80058F80 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 059B84 80058F84 AFBF0014 */  sw    $ra, 0x14($sp)
/* 059B88 80058F88 55C00023 */  bnel  $t6, $zero, .L80059018
/* 059B8C 80058F8C 8FBF0014 */   lw    $ra, 0x14($sp)
/* 059B90 80058F90 0C0107BD */  jal   func_80041EF4
/* 059B94 80058F94 00000000 */   nop   
/* 059B98 80058F98 3C0F800E */  lui   $t7, %hi(D_800DC51C) # $t7, 0x800e
/* 059B9C 80058F9C 95EFC51C */  lhu   $t7, %lo(D_800DC51C)($t7)
/* 059BA0 80058FA0 3C188019 */  lui   $t8, %hi(D_8018D188) # $t8, 0x8019
/* 059BA4 80058FA4 55E0001C */  bnel  $t7, $zero, .L80059018
/* 059BA8 80058FA8 8FBF0014 */   lw    $ra, 0x14($sp)
/* 059BAC 80058FAC 8F18D188 */  lw    $t8, %lo(D_8018D188)($t8)
/* 059BB0 80058FB0 3C198016 */  lui   $t9, %hi(D_801657D8) # $t9, 0x8016
/* 059BB4 80058FB4 53000018 */  beql  $t8, $zero, .L80059018
/* 059BB8 80058FB8 8FBF0014 */   lw    $ra, 0x14($sp)
/* 059BBC 80058FBC 833957D8 */  lb    $t9, %lo(D_801657D8)($t9)
/* 059BC0 80058FC0 57200015 */  bnel  $t9, $zero, .L80059018
/* 059BC4 80058FC4 8FBF0014 */   lw    $ra, 0x14($sp)
/* 059BC8 80058FC8 0C01398E */  jal   func_8004E638
/* 059BCC 80058FCC 00002025 */   move  $a0, $zero
/* 059BD0 80058FD0 3C088016 */  lui   $t0, %hi(D_801657E4) # $t0, 0x8016
/* 059BD4 80058FD4 810857E4 */  lb    $t0, %lo(D_801657E4)($t0)
/* 059BD8 80058FD8 24010002 */  li    $at, 2
/* 059BDC 80058FDC 5101000E */  beql  $t0, $at, .L80059018
/* 059BE0 80058FE0 8FBF0014 */   lw    $ra, 0x14($sp)
/* 059BE4 80058FE4 0C013E9E */  jal   func_8004FA78
/* 059BE8 80058FE8 00002025 */   move  $a0, $zero
/* 059BEC 80058FEC 0C0139E3 */  jal   func_8004E78C
/* 059BF0 80058FF0 00002025 */   move  $a0, $zero
/* 059BF4 80058FF4 0C013ACE */  jal   func_8004EB38
/* 059BF8 80058FF8 00002025 */   move  $a0, $zero
/* 059BFC 80058FFC 3C098016 */  lui   $t1, %hi(D_801657E6) # $t1, 0x8016
/* 059C00 80059000 812957E6 */  lb    $t1, %lo(D_801657E6)($t1)
/* 059C04 80059004 51200004 */  beql  $t1, $zero, .L80059018
/* 059C08 80059008 8FBF0014 */   lw    $ra, 0x14($sp)
/* 059C0C 8005900C 0C013B50 */  jal   func_8004ED40
/* 059C10 80059010 00002025 */   move  $a0, $zero
/* 059C14 80059014 8FBF0014 */  lw    $ra, 0x14($sp)
.L80059018:
/* 059C18 80059018 27BD0018 */  addiu $sp, $sp, 0x18
/* 059C1C 8005901C 03E00008 */  jr    $ra
/* 059C20 80059020 00000000 */   nop   

/* 059C24 80059024 03E00008 */  jr    $ra
/* 059C28 80059028 00000000 */   nop   