glabel text_draw
/* 0945FC 800939FC 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 094600 80093A00 C7A40038 */  lwc1  $f4, 0x38($sp)
/* 094604 80093A04 C7A6003C */  lwc1  $f6, 0x3c($sp)
/* 094608 80093A08 AFBF0024 */  sw    $ra, 0x24($sp)
/* 09460C 80093A0C 240E0002 */  li    $t6, 2
/* 094610 80093A10 AFAE0018 */  sw    $t6, 0x18($sp)
/* 094614 80093A14 E7A40010 */  swc1  $f4, 0x10($sp)
/* 094618 80093A18 0C024DE2 */  jal   print_text2
/* 09461C 80093A1C E7A60014 */   swc1  $f6, 0x14($sp)
/* 094620 80093A20 8FBF0024 */  lw    $ra, 0x24($sp)
/* 094624 80093A24 27BD0028 */  addiu $sp, $sp, 0x28
/* 094628 80093A28 03E00008 */  jr    $ra
/* 09462C 80093A2C 00000000 */   nop   