glabel func_80092604
/* 093204 80092604 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 093208 80092608 AFBF0014 */  sw    $ra, 0x14($sp)
/* 09320C 8009260C 240400B0 */  li    $a0, 176
/* 093210 80092610 00002825 */  move  $a1, $zero
/* 093214 80092614 00003025 */  move  $a2, $zero
/* 093218 80092618 0C027994 */  jal   func_8009E650
/* 09321C 8009261C 00003825 */   move  $a3, $zero
/* 093220 80092620 8FBF0014 */  lw    $ra, 0x14($sp)
/* 093224 80092624 27BD0018 */  addiu $sp, $sp, 0x18
/* 093228 80092628 03E00008 */  jr    $ra
/* 09322C 8009262C 00000000 */   nop   