glabel func_800B6014
/* 0B6C14 800B6014 3C0E800F */  lui   $t6, %hi(sControllerPak2State) # $t6, 0x800f
/* 0B6C18 800B6018 81CE86FC */  lb    $t6, %lo(sControllerPak2State)($t6)
/* 0B6C1C 800B601C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0B6C20 800B6020 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0B6C24 800B6024 11C00003 */  beqz  $t6, .L800B6034
/* 0B6C28 800B6028 00000000 */   nop   
/* 0B6C2C 800B602C 10000012 */  b     .L800B6078
/* 0B6C30 800B6030 2402FFFC */   li    $v0, -4
.L800B6034:
/* 0B6C34 800B6034 0C02D6CB */  jal   check_for_controller_pak
/* 0B6C38 800B6038 24040001 */   li    $a0, 1
/* 0B6C3C 800B603C 1040000D */  beqz  $v0, .L800B6074
/* 0B6C40 800B6040 3C048015 */   lui   $a0, %hi(gSIEventMesgQueue) # $a0, 0x8015
/* 0B6C44 800B6044 3C058019 */  lui   $a1, %hi(D_8018E8D0) # $a1, 0x8019
/* 0B6C48 800B6048 24A5E8D0 */  addiu $a1, %lo(D_8018E8D0) # addiu $a1, $a1, -0x1730
/* 0B6C4C 800B604C 2484F0B8 */  addiu $a0, %lo(gSIEventMesgQueue) # addiu $a0, $a0, -0xf48
/* 0B6C50 800B6050 0C0339C8 */  jal   osPfsInit
/* 0B6C54 800B6054 24060001 */   li    $a2, 1
/* 0B6C58 800B6058 14400004 */  bnez  $v0, .L800B606C
/* 0B6C5C 800B605C 00401825 */   move  $v1, $v0
/* 0B6C60 800B6060 240F0001 */  li    $t7, 1
/* 0B6C64 800B6064 3C01800F */  lui   $at, %hi(sControllerPak2State) # $at, 0x800f
/* 0B6C68 800B6068 A02F86FC */  sb    $t7, %lo(sControllerPak2State)($at)
.L800B606C:
/* 0B6C6C 800B606C 10000002 */  b     .L800B6078
/* 0B6C70 800B6070 00601025 */   move  $v0, $v1
.L800B6074:
/* 0B6C74 800B6074 2402FFFF */  li    $v0, -1
.L800B6078:
/* 0B6C78 800B6078 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0B6C7C 800B607C 27BD0018 */  addiu $sp, $sp, 0x18
/* 0B6C80 800B6080 03E00008 */  jr    $ra
/* 0B6C84 800B6084 00000000 */   nop   