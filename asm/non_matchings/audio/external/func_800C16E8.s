glabel func_800C16E8
/* 0C22E8 800C16E8 27ADFFE8 */  addiu $t5, $sp, -0x18
/* 0C22EC 800C16EC F5B40010 */  sdc1  $f20, 0x10($t5)
/* 0C22F0 800C16F0 E5AE001C */  swc1  $f14, 0x1c($t5)
/* 0C22F4 800C16F4 ADA60020 */  sw    $a2, 0x20($t5)
/* 0C22F8 800C16F8 3C0F800F */  lui   $t7, %hi(D_800EA1C0) # $t7, 0x800f
/* 0C22FC 800C16FC 91EFA1C0 */  lbu   $t7, %lo(D_800EA1C0)($t7)
/* 0C2300 800C1700 30CE00FF */  andi  $t6, $a2, 0xff
/* 0C2304 800C1704 01C03025 */  move  $a2, $t6
/* 0C2308 800C1708 15E00082 */  bnez  $t7, .L800C1914
/* 0C230C 800C170C 01A0E825 */   move  $sp, $t5
/* 0C2310 800C1710 3C18800F */  lui   $t8, %hi(D_800EA0F4) # $t8, 0x800f
/* 0C2314 800C1714 9318A0F4 */  lbu   $t8, %lo(D_800EA0F4)($t8)
/* 0C2318 800C1718 44802000 */  mtc1  $zero, $f4
/* 0C231C 800C171C 44804000 */  mtc1  $zero, $f8
/* 0C2320 800C1720 44805000 */  mtc1  $zero, $f10
/* 0C2324 800C1724 13000009 */  beqz  $t8, .L800C174C
/* 0C2328 800C1728 3C0142C8 */   li    $at, 0x42C80000 # 100.000000
/* 0C232C 800C172C 3C014120 */  li    $at, 0x41200000 # 10.000000
/* 0C2330 800C1730 44818000 */  mtc1  $at, $f16
/* 0C2334 800C1734 3C0141A0 */  li    $at, 0x41A00000 # 20.000000
/* 0C2338 800C1738 44817000 */  mtc1  $at, $f14
/* 0C233C 800C173C 3C014020 */  li    $at, 0x40200000 # 2.500000
/* 0C2340 800C1740 44819000 */  mtc1  $at, $f18
/* 0C2344 800C1744 10000008 */  b     .L800C1768
/* 0C2348 800C1748 46008086 */   mov.s $f2, $f16
.L800C174C:
/* 0C234C 800C174C 44811000 */  mtc1  $at, $f2
/* 0C2350 800C1750 3C014348 */  li    $at, 0x43480000 # 200.000000
/* 0C2354 800C1754 44817000 */  mtc1  $at, $f14
/* 0C2358 800C1758 3C0140A0 */  li    $at, 0x40A00000 # 5.000000
/* 0C235C 800C175C 44818000 */  mtc1  $at, $f16
/* 0C2360 800C1760 3C01800F */  lui   $at, %hi(D_800F35C0) # $at, 0x800f
/* 0C2364 800C1764 C43235C0 */  lwc1  $f18, %lo(D_800F35C0)($at)
.L800C1768:
/* 0C2368 800C1768 4604603C */  c.lt.s $f12, $f4
/* 0C236C 800C176C 00000000 */  nop   
/* 0C2370 800C1770 45020004 */  bc1fl .L800C1784
/* 0C2374 800C1774 46006506 */   mov.s $f20, $f12
/* 0C2378 800C1778 10000002 */  b     .L800C1784
/* 0C237C 800C177C 46006507 */   neg.s $f20, $f12
/* 0C2380 800C1780 46006506 */  mov.s $f20, $f12
.L800C1784:
/* 0C2384 800C1784 4614103C */  c.lt.s $f2, $f20
/* 0C2388 800C1788 00000000 */  nop   
/* 0C238C 800C178C 45020003 */  bc1fl .L800C179C
/* 0C2390 800C1790 C5A6001C */   lwc1  $f6, 0x1c($t5)
/* 0C2394 800C1794 46001506 */  mov.s $f20, $f2
/* 0C2398 800C1798 C5A6001C */  lwc1  $f6, 0x1c($t5)
.L800C179C:
/* 0C239C 800C179C 4608303C */  c.lt.s $f6, $f8
/* 0C23A0 800C17A0 00000000 */  nop   
/* 0C23A4 800C17A4 45020004 */  bc1fl .L800C17B8
/* 0C23A8 800C17A8 C5A0001C */   lwc1  $f0, 0x1c($t5)
/* 0C23AC 800C17AC 10000002 */  b     .L800C17B8
/* 0C23B0 800C17B0 46003007 */   neg.s $f0, $f6
/* 0C23B4 800C17B4 C5A0001C */  lwc1  $f0, 0x1c($t5)
.L800C17B8:
/* 0C23B8 800C17B8 4600103C */  c.lt.s $f2, $f0
/* 0C23BC 800C17BC 00000000 */  nop   
/* 0C23C0 800C17C0 45020003 */  bc1fl .L800C17D0
/* 0C23C4 800C17C4 460A6032 */   c.eq.s $f12, $f10
/* 0C23C8 800C17C8 46001006 */  mov.s $f0, $f2
/* 0C23CC 800C17CC 460A6032 */  c.eq.s $f12, $f10
.L800C17D0:
/* 0C23D0 800C17D0 00000000 */  nop   
/* 0C23D4 800C17D4 4502000E */  bc1fl .L800C1810
/* 0C23D8 800C17D8 44803000 */   mtc1  $zero, $f6
/* 0C23DC 800C17DC C5A4001C */  lwc1  $f4, 0x1c($t5)
/* 0C23E0 800C17E0 44804000 */  mtc1  $zero, $f8
/* 0C23E4 800C17E4 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0C23E8 800C17E8 46082032 */  c.eq.s $f4, $f8
/* 0C23EC 800C17EC 00000000 */  nop   
/* 0C23F0 800C17F0 45020007 */  bc1fl .L800C1810
/* 0C23F4 800C17F4 44803000 */   mtc1  $zero, $f6
/* 0C23F8 800C17F8 44811000 */  mtc1  $at, $f2
/* 0C23FC 800C17FC 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C2400 800C1800 44816000 */  mtc1  $at, $f12
/* 0C2404 800C1804 1000002C */  b     .L800C18B8
/* 0C2408 800C1808 4602603C */   c.lt.s $f12, $f2
/* 0C240C 800C180C 44803000 */  mtc1  $zero, $f6
.L800C1810:
/* 0C2410 800C1810 00000000 */  nop   
/* 0C2414 800C1814 460C303E */  c.le.s $f6, $f12
/* 0C2418 800C1818 00000000 */  nop   
/* 0C241C 800C181C 4502000E */  bc1fl .L800C1858
/* 0C2420 800C1820 44802000 */   mtc1  $zero, $f4
/* 0C2424 800C1824 4614003E */  c.le.s $f0, $f20
/* 0C2428 800C1828 00000000 */  nop   
/* 0C242C 800C182C 4502000A */  bc1fl .L800C1858
/* 0C2430 800C1830 44802000 */   mtc1  $zero, $f4
/* 0C2434 800C1834 46007101 */  sub.s $f4, $f14, $f0
/* 0C2438 800C1838 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C243C 800C183C 44816000 */  mtc1  $at, $f12
/* 0C2440 800C1840 46147281 */  sub.s $f10, $f14, $f20
/* 0C2444 800C1844 46048202 */  mul.s $f8, $f16, $f4
/* 0C2448 800C1848 46085183 */  div.s $f6, $f10, $f8
/* 0C244C 800C184C 10000019 */  b     .L800C18B4
/* 0C2450 800C1850 46066081 */   sub.s $f2, $f12, $f6
/* 0C2454 800C1854 44802000 */  mtc1  $zero, $f4
.L800C1858:
/* 0C2458 800C1858 00000000 */  nop   
/* 0C245C 800C185C 4604603C */  c.lt.s $f12, $f4
/* 0C2460 800C1860 00000000 */  nop   
/* 0C2464 800C1864 4500000C */  bc1f  .L800C1898
/* 0C2468 800C1868 00000000 */   nop   
/* 0C246C 800C186C 4614003E */  c.le.s $f0, $f20
/* 0C2470 800C1870 00000000 */  nop   
/* 0C2474 800C1874 45000008 */  bc1f  .L800C1898
/* 0C2478 800C1878 00000000 */   nop   
/* 0C247C 800C187C 46007201 */  sub.s $f8, $f14, $f0
/* 0C2480 800C1880 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C2484 800C1884 44816000 */  mtc1  $at, $f12
/* 0C2488 800C1888 46147281 */  sub.s $f10, $f14, $f20
/* 0C248C 800C188C 46088182 */  mul.s $f6, $f16, $f8
/* 0C2490 800C1890 10000008 */  b     .L800C18B4
/* 0C2494 800C1894 46065083 */   div.s $f2, $f10, $f6
.L800C1898:
/* 0C2498 800C1898 46009102 */  mul.s $f4, $f18, $f0
/* 0C249C 800C189C 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0C24A0 800C18A0 44815000 */  mtc1  $at, $f10
/* 0C24A4 800C18A4 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C24A8 800C18A8 46046203 */  div.s $f8, $f12, $f4
/* 0C24AC 800C18AC 44816000 */  mtc1  $at, $f12
/* 0C24B0 800C18B0 460A4080 */  add.s $f2, $f8, $f10
.L800C18B4:
/* 0C24B4 800C18B4 4602603C */  c.lt.s $f12, $f2
.L800C18B8:
/* 0C24B8 800C18B8 3C0142FE */  li    $at, 0x42FE0000 # 127.000000
/* 0C24BC 800C18BC 44803000 */  mtc1  $zero, $f6
/* 0C24C0 800C18C0 44812000 */  mtc1  $at, $f4
/* 0C24C4 800C18C4 45020003 */  bc1fl .L800C18D4
/* 0C24C8 800C18C8 4606103C */   c.lt.s $f2, $f6
/* 0C24CC 800C18CC 46006086 */  mov.s $f2, $f12
/* 0C24D0 800C18D0 4606103C */  c.lt.s $f2, $f6
.L800C18D4:
/* 0C24D4 800C18D4 00000000 */  nop   
/* 0C24D8 800C18D8 45000003 */  bc1f  .L800C18E8
/* 0C24DC 800C18DC 00000000 */   nop   
/* 0C24E0 800C18E0 44801000 */  mtc1  $zero, $f2
/* 0C24E4 800C18E4 00000000 */  nop   
.L800C18E8:
/* 0C24E8 800C18E8 46041202 */  mul.s $f8, $f2, $f4
/* 0C24EC 800C18EC 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0C24F0 800C18F0 44815000 */  mtc1  $at, $f10
/* 0C24F4 800C18F4 00000000 */  nop   
/* 0C24F8 800C18F8 460A4180 */  add.s $f6, $f8, $f10
/* 0C24FC 800C18FC 4600310D */  trunc.w.s $f4, $f6
/* 0C2500 800C1900 44022000 */  mfc1  $v0, $f4
/* 0C2504 800C1904 00000000 */  nop   
/* 0C2508 800C1908 00024600 */  sll   $t0, $v0, 0x18
/* 0C250C 800C190C 10000006 */  b     .L800C1928
/* 0C2510 800C1910 00081603 */   sra   $v0, $t0, 0x18
.L800C1914:
/* 0C2514 800C1914 30C20001 */  andi  $v0, $a2, 1
/* 0C2518 800C1918 000251C0 */  sll   $t2, $v0, 7
/* 0C251C 800C191C 01425023 */  subu  $t2, $t2, $v0
/* 0C2520 800C1920 000A5E00 */  sll   $t3, $t2, 0x18
/* 0C2524 800C1924 000B1603 */  sra   $v0, $t3, 0x18
.L800C1928:
/* 0C2528 800C1928 D5B40010 */  ldc1  $f20, 0x10($t5)
/* 0C252C 800C192C 03E00008 */  jr    $ra
/* 0C2530 800C1930 25BD0018 */   addiu $sp, $t5, 0x18