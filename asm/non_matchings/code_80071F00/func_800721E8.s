glabel func_800721E8
/* 072DE8 800721E8 000470C0 */  sll   $t6, $a0, 3
/* 072DEC 800721EC 01C47023 */  subu  $t6, $t6, $a0
/* 072DF0 800721F0 3C0F8016 */  lui   $t7, %hi(D_80165C18) # $t7, 0x8016
/* 072DF4 800721F4 25EF5C18 */  addiu $t7, %lo(D_80165C18) # addiu $t7, $t7, 0x5c18
/* 072DF8 800721F8 000E7140 */  sll   $t6, $t6, 5
/* 072DFC 800721FC 01CF1021 */  addu  $v0, $t6, $t7
/* 072E00 80072200 8C580054 */  lw    $t8, 0x54($v0)
/* 072E04 80072204 00A0C827 */  not   $t9, $a1
/* 072E08 80072208 03194024 */  and   $t0, $t8, $t9
/* 072E0C 8007220C 03E00008 */  jr    $ra
/* 072E10 80072210 AC480054 */   sw    $t0, 0x54($v0)

/* 072E14 80072214 000470C0 */  sll   $t6, $a0, 3
/* 072E18 80072218 01C47023 */  subu  $t6, $t6, $a0
/* 072E1C 8007221C 3C0F8016 */  lui   $t7, %hi(D_80165C18) # $t7, 0x8016
/* 072E20 80072220 25EF5C18 */  addiu $t7, %lo(D_80165C18) # addiu $t7, $t7, 0x5c18
/* 072E24 80072224 000E7140 */  sll   $t6, $t6, 5
/* 072E28 80072228 01CF1021 */  addu  $v0, $t6, $t7
/* 072E2C 8007222C 8C580054 */  lw    $t8, 0x54($v0)
/* 072E30 80072230 0305C826 */  xor   $t9, $t8, $a1
/* 072E34 80072234 03E00008 */  jr    $ra
/* 072E38 80072238 AC590054 */   sw    $t9, 0x54($v0)