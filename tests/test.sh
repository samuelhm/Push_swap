#!/bin/bash
cp ../push_swap ./
cp ../checker_linux ./

echo "Comenzando Comprobaciones, las siguientes instrucciones no deben mostrar instrucciones:"
echo "./push_swap 42"
./push_swap 42
echo "./push_swap 2 3"
./push_swap 2 3
echo "./push_swap 0 1 2 3"
./push_swap 0 1 2 3
echo "./push_swap 0 1 2 3 4 5 6 7 8 9"
./push_swap 0 1 2 3 4 5 6 7 8 9
echo "./push_swap -200 -100 -50 0 25 50"
./push_swap -200 -100 -50 0 25 50
echo "pulsa para continuar"
read
clear

echo "El siguiente comando, no debe usar mas de 12 instrucciones para lograr el orden:"
echo "Comprobando Checker:"
./push_swap 1 5 2 4 3 | ./checker_linux 1 5 2 4 3
echo "comprobando instrucciones:"
./push_swap 1 5 2 4 3
echo "se han usado las siguientes instrucciones, 8 o menos es excelente, 12 permitido, mas prohibido:"
./push_swap 1 5 2 4 3 | wc -l
echo "pulsa para continuar"
read
clear

ARG="-2000 400 23 500 -3"
echo "Realizando la misma comprobación con otros 5 numeros aleatorios:"
echo "Comprobando Checker:"
./push_swap $ARG | ./checker_linux $ARG
echo "comprobando instrucciones:"
./push_swap $ARG
echo "se han usado las siguientes instrucciones, 8 o menos es excelente, 12 permitido, mas prohibido:"
./push_swap $ARG | wc -l
echo "pulsa para continuar"
read
clear

ARG="-2 1 0"
echo "Comprobando 2 1 0"
echo "Comprobando Checker:"
./push_swap $ARG | ./checker_linux $ARG
echo "comprobando instrucciones:"
./push_swap $ARG
echo "si usa mas de 3 instrucciones, el test falla:"
./push_swap $ARG | wc -l
echo "pulsa para continuar"
read
clear


echo "Ordenando 2 numeros"
./push_swap 7 2
echo "Comprobando el resultado de 2 numeros:"
./push_swap 7 2 | ./checker_linux 7 2
echo "Comprobando cantidad de movimientos:"
./push_swap 7 2 | wc -l
echo "Pulsa para siguiente comprobacion:"
read
clear

echo "Ordenando 3 numeros"
./push_swap 7 2 24
echo "Comprobando el resultado de 3 numeros:"
./push_swap 7 2 24 | ./checker_linux 7 2 24
echo "Comprobando cantidad de movimientos:"
./push_swap 7 2 24 | wc -l
echo "Pulsa para siguiente comprobacion:"
read
clear

export ARG="-4 23 -543 3245 3"
echo "Ordenando 5 numeros"
./push_swap $ARG
echo "Comprobando el resultado de 5 numeros:"
./push_swap $ARG | ./checker_linux $ARG
echo "Pulsa para siguiente comprobacion:"
read
clear

export ARG="114239 381176 245564 359344 191897 114438 233180 499640 263701 343150 462122 261271 185643 471180 206454 107086 201621 250269 413979 124638 154402 120101 380422 381574 362017 488688 251635 458336 499791 158047 -7205 290263 474635 428950 136301 403860 123327 470308 445467 197717 249261 174678 295547 251179 412781 242381 316273 134338 469799 210399"

echo "Ordenando 50 numeros"
./push_swap $ARG
echo "Comprobando el resultado de 50 numeros:"
./push_swap $ARG | ./checker_linux $ARG
echo "Comprobando cantidad de movimientos:"
./push_swap $ARG | wc -l
echo "Pulsa para siguiente comprobacion:"
read
clear

export ARG="265859 376477 314066 343450 5658 463842 499988 213854 229306 94374 35244 362920 305657 230036 339123 239451 280898 469577 433067 328142 28538 377812 43981 451045 233585 274048 62878 217225 80928 6853 172180 61805 429185 237799 59596 398594 18600 190887 351859 294175 407598 120454 361857 382016 87427 -808 176993 341251 207223 461874 12712 435430 142745 404628 26175 215492 241642 19320 172263 64995 295597 338048 357766 135315 377454 269052 73612 478856 45129 195353 244770 454430 150918 187813 325718 239285 216036 44596 397270 419850 178796 102208 139650 87455 366095 221359 238800 242941 88996 209442 264268 241838 233694 389232 475952 429740 416638 263141 261303 173107"

echo "Ordenando 100 numeros"
./push_swap $ARG
echo "Comprobando el resultado de 100 numeros:"
./push_swap $ARG | ./checker_linux $ARG
echo "Comprobando cantidad de movimientos en 100 numeros:"
./push_swap $ARG | wc -l
echo "Pulsa para siguiente comprobacion:"
read
clear

export ARG="-4834 -265 1184 3087 -771 4142 1455 -1561 2104 2673 2669 1775 2332 -4373 1658 4043 1054 122 2557 680 -1265 -4338 1857 -2174 -2906 -4286 4139 3008 3581 4813 1810 -1419 1956 -1779 -4812 -4625 1476 2680 -124 2874 -1564 4089 -640 2242 2710 -636 2280 3517 139 -3124 3211 -4444 -4902 -2054 -4503 1156 -4725 -1317 -580 2677 1846 -1182 4992 2103 1425 -33 2316 825 754 -515 4433 -1828 919 -1517 -1966 1671 -2921 3056 662 -1211 4482 2783 3193 -3807 3600 664 -2895 -4998 2794 2837 3048 3813 -1903 -996 857 3769 -1934 -2958 -2544 3492 -3853 -3508 1785 -3353 2559 1264 -397 -2823 -1310 -2075 4896 -2710 -2631 1976 4068 3155 1630 3280 -1522 3543 -1768 562 -3459 4756 -626 -2730 -2379 2150 3566 -1725 33 -241 1368 -2808 3454 373 3427 -320 -1682 -3516 3722 -3010 2769 -2908 3138 3807 -3025 -4642 2747 -1369 -1775 -66 3329 3621 1892 -2101 -4172 4145 4990 -4640 -4892 -3227 2256 -3679 -3826 -4128 -3407 -175 3676 -3198 2879 4790 -4549 -3240 1533 -790 -2868 -1983 3673 2592 -1792 -495 -4448 1034 -1774 -1746 1674 -2810 -2270 -4253 -3655 -2139 -2245 -616 3983 909 1428 -2470 2813 164 -3335 4038 -3360 -2293 -3544 -238 2310 3662 1427 1014 4076 1066 -2839 2573 -4924 -314 -2244 935 -4478 790 2014 149 4855 2525 2917 -2661 -3267 1406 2304 -2556 4567 -2365 -1323 2654 -560 1405 1186 524 2070 4194 1486 -1004 -1110 -4863 3496 2828 -548 -2176 -758 -1020 4752 -379 4917 -1955 2322 -1902 -4797 -3187 -2904 -4244 -4066 -1990 -4582 -340 4146 -4835 1257 4804 1508 1323 3705 1136 4032 3191 212 3872 1207 2843 -1091 2816 -1704 1305 1702 2439 -1469 3935 -1201 -2944 -619 -2097 533 -4065 4826 3817 -4282 -760 1149 4274 2196 -2713 422 -4051 -3307 -4665 -2913 -254 -49 -4396 -163 -525 -4087 2013 -1203 -4604 4817 -905 4103 2936 -1221 -2445 -4643 -4783 2009 572 -2869 313 1362 -4991 4947 -2196 4930 -3692 -4521 -1299 902 -1128 4159 238 -2121 -1568 296 2001 -4476 2183 1675 -4943 -502 -660 498 -2945 -4030 3383 -488 2057 -424 -1210 -4873 -3242 23 4778 -3162 2532 3433 3213 4157 438 -156 2501 -2541 -2147 -1344 -1396 -603 -3759 1057 -4013 185 -3870 757 -1346 -1771 -4764 1130 3587 395 1637 2977 -3922 2325 3007 -2430 646 -2943 -2016 -110 -1933 1746 -4967 3840 -4410 -722 1580 -2994 -3268 2058 -2653 -1433 976 -3872 -3928 1481 -1669 4945 4847 4229 -1423 4085 964 -2321 610 -290 -4565 -3946 2901 -2871 3249 1485 1878 -333 -3390 -4846 -1462 -967 -4223 -2363 4542 3994 -1243 -1810 67 1540 -1763 -1466 2364 -1587 2094 -272 2010 4776 -4461 -1818 -3828 1673 4104 1190 -2844 -3306 -2930 3712 4175 405 1866 106 3150 -3859 -2050 -1603 -2797 3701 1635 2566 2735 -3297 -1480 2579 -460 2718 -481 -1614 1704 -1824 921 4716 -3116 638 -1174 -1949 4109 4959 -41 -2410 -612 -4021 620 -1893 -1002 3870 -3122 3477 -4137"

echo "Ordenando 500 numeros"
./push_swap $ARG
echo "Comprobando el resultado de 500 numeros:"
./push_swap $ARG | ./checker_linux $ARG
echo "Comprobando cantidad de movimientos en 500 numeros:"
./push_swap $ARG | wc -l
echo "Pulsa para siguiente comprobacion:"
read
clear
