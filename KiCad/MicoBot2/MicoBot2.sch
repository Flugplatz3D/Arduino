EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L power:GND #PWR03
U 1 1 5CB7BD64
P 6450 5400
F 0 "#PWR03" H 6450 5150 50  0001 C CNN
F 1 "GND" H 6455 5227 50  0000 C CNN
F 2 "" H 6450 5400 50  0001 C CNN
F 3 "" H 6450 5400 50  0001 C CNN
	1    6450 5400
	1    0    0    -1  
$EndComp
Wire Wire Line
	6100 5550 6100 5250
Wire Wire Line
	6100 5250 6450 5250
Wire Wire Line
	6450 5250 6450 5400
Wire Wire Line
	5900 5550 5900 5150
$Comp
L power:VCC #PWR02
U 1 1 5CB7DAF3
P 6450 5150
F 0 "#PWR02" H 6450 5000 50  0001 C CNN
F 1 "VCC" H 6467 5323 50  0000 C CNN
F 2 "" H 6450 5150 50  0001 C CNN
F 3 "" H 6450 5150 50  0001 C CNN
	1    6450 5150
	1    0    0    -1  
$EndComp
Wire Wire Line
	5900 5150 6450 5150
$Comp
L power:VCC #PWR01
U 1 1 5CB7E24C
P 3600 1200
F 0 "#PWR01" H 3600 1050 50  0001 C CNN
F 1 "VCC" H 3617 1373 50  0000 C CNN
F 2 "" H 3600 1200 50  0001 C CNN
F 3 "" H 3600 1200 50  0001 C CNN
	1    3600 1200
	1    0    0    -1  
$EndComp
$Comp
L Device:C C1
U 1 1 5CB7FCE1
P 5350 4800
F 0 "C1" H 5465 4846 50  0000 L CNN
F 1 "100n" H 5465 4755 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D4.3mm_W1.9mm_P5.00mm" H 5388 4650 50  0001 C CNN
F 3 "~" H 5350 4800 50  0001 C CNN
	1    5350 4800
	1    0    0    -1  
$EndComp
$Comp
L Driver_Motor:L293D U2
U 1 1 5CB8339E
P 7600 2650
F 0 "U2" H 7600 3831 50  0000 C CNN
F 1 "L293D" H 7600 3740 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm" H 7850 1900 50  0001 L CNN
F 3 "http://www.ti.com/lit/ds/symlink/l293.pdf" H 7300 3350 50  0001 C CNN
	1    7600 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	4150 3550 4400 3550
Wire Wire Line
	4150 3450 4500 3450
$Comp
L power:GND #PWR04
U 1 1 5CB94DFC
P 8000 3550
F 0 "#PWR04" H 8000 3300 50  0001 C CNN
F 1 "GND" H 8005 3377 50  0000 C CNN
F 2 "" H 8000 3550 50  0001 C CNN
F 3 "" H 8000 3550 50  0001 C CNN
	1    8000 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	7800 3450 7800 3500
Wire Wire Line
	7800 3500 8000 3500
Wire Wire Line
	8000 3500 8000 3550
Wire Wire Line
	7700 3450 7700 3500
Wire Wire Line
	7700 3500 7800 3500
Connection ~ 7800 3500
Wire Wire Line
	7500 3450 7500 3500
Wire Wire Line
	7500 3500 7700 3500
Connection ~ 7700 3500
Wire Wire Line
	7400 3450 7400 3500
Wire Wire Line
	7400 3500 7500 3500
Connection ~ 7500 3500
$Comp
L Switch:SW_Push SW1
U 1 1 5CB995FB
P 6100 4400
F 0 "SW1" H 6100 4685 50  0000 C CNN
F 1 "Rst" H 6100 4594 50  0000 C CNN
F 2 "MiLib:Pulsador_Cuadrado_6" H 6100 4600 50  0001 C CNN
F 3 "~" H 6100 4600 50  0001 C CNN
	1    6100 4400
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR05
U 1 1 5CB9A211
P 6450 4500
F 0 "#PWR05" H 6450 4250 50  0001 C CNN
F 1 "GND" H 6455 4327 50  0000 C CNN
F 2 "" H 6450 4500 50  0001 C CNN
F 3 "" H 6450 4500 50  0001 C CNN
	1    6450 4500
	1    0    0    -1  
$EndComp
Wire Wire Line
	6450 4400 6450 4500
$Comp
L Regulator_Linear:AMS1117-5.0 U3
U 1 1 5CB78A01
P 8600 4950
F 0 "U3" H 8600 5192 50  0000 C CNN
F 1 "AMS1117-5.0" H 8600 5101 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-223-3_TabPin2" H 8600 5150 50  0001 C CNN
F 3 "http://www.advanced-monolithic.com/pdf/ds1117.pdf" H 8700 4700 50  0001 C CNN
	1    8600 4950
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0101
U 1 1 5CB7D70C
P 8600 5450
F 0 "#PWR0101" H 8600 5200 50  0001 C CNN
F 1 "GND" H 8605 5277 50  0000 C CNN
F 2 "" H 8600 5450 50  0001 C CNN
F 3 "" H 8600 5450 50  0001 C CNN
	1    8600 5450
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0102
U 1 1 5CB7DDB2
P 7500 5150
F 0 "#PWR0102" H 7500 4900 50  0001 C CNN
F 1 "GND" H 7505 4977 50  0000 C CNN
F 2 "" H 7500 5150 50  0001 C CNN
F 3 "" H 7500 5150 50  0001 C CNN
	1    7500 5150
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0103
U 1 1 5CB7EFF0
P 9050 4850
F 0 "#PWR0103" H 9050 4700 50  0001 C CNN
F 1 "VCC" H 9067 5023 50  0000 C CNN
F 2 "" H 9050 4850 50  0001 C CNN
F 3 "" H 9050 4850 50  0001 C CNN
	1    9050 4850
	1    0    0    -1  
$EndComp
Wire Wire Line
	8900 4950 9050 4950
Wire Wire Line
	9050 4950 9050 4850
Wire Wire Line
	7500 4950 7500 5150
$Comp
L Switch:SW_SPDT SW2
U 1 1 5CB86777
P 7950 4850
F 0 "SW2" H 7950 5135 50  0000 C CNN
F 1 "On" H 7950 5044 50  0000 C CNN
F 2 "MiLib:EG1218" H 7950 4850 50  0001 C CNN
F 3 "~" H 7950 4850 50  0001 C CNN
	1    7950 4850
	1    0    0    -1  
$EndComp
Wire Wire Line
	7500 4850 7750 4850
Wire Wire Line
	8150 4950 8250 4950
Wire Wire Line
	3550 1450 3550 1350
Wire Wire Line
	3550 1350 3600 1350
Wire Wire Line
	3650 1350 3650 1450
Wire Wire Line
	3600 1350 3600 1200
Connection ~ 3600 1350
Wire Wire Line
	3600 1350 3650 1350
$Comp
L Device:LED D1
U 1 1 5CB896AF
P 5850 2450
F 0 "D1" V 5889 2333 50  0000 R CNN
F 1 "LED" V 5798 2333 50  0000 R CNN
F 2 "LED_THT:LED_D3.0mm" H 5850 2450 50  0001 C CNN
F 3 "~" H 5850 2450 50  0001 C CNN
	1    5850 2450
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R1
U 1 1 5CB8BF62
P 5850 2750
F 0 "R1" H 5920 2796 50  0000 L CNN
F 1 "330" H 5920 2705 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 5780 2750 50  0001 C CNN
F 3 "~" H 5850 2750 50  0001 C CNN
	1    5850 2750
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR06
U 1 1 5CB8C74D
P 5850 2900
F 0 "#PWR06" H 5850 2650 50  0001 C CNN
F 1 "GND" H 5855 2727 50  0000 C CNN
F 2 "" H 5850 2900 50  0001 C CNN
F 3 "" H 5850 2900 50  0001 C CNN
	1    5850 2900
	1    0    0    -1  
$EndComp
$Comp
L Device:Crystal_Small Y1
U 1 1 5CB975FD
P 5450 2550
F 0 "Y1" H 5450 2775 50  0000 C CNN
F 1 "16Mhz" H 5450 2684 50  0000 C CNN
F 2 "Crystal:Crystal_HC49-4H_Vertical" H 5450 2550 50  0001 C CNN
F 3 "~" H 5450 2550 50  0001 C CNN
	1    5450 2550
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C2
U 1 1 5CB99E74
P 5350 2650
F 0 "C2" H 5442 2696 50  0000 L CNN
F 1 "22p" H 5442 2605 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D4.3mm_W1.9mm_P5.00mm" H 5350 2650 50  0001 C CNN
F 3 "~" H 5350 2650 50  0001 C CNN
	1    5350 2650
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C3
U 1 1 5CB9B3E9
P 5550 2650
F 0 "C3" H 5642 2696 50  0000 L CNN
F 1 "22p" H 5642 2605 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D4.3mm_W1.9mm_P5.00mm" H 5550 2650 50  0001 C CNN
F 3 "~" H 5550 2650 50  0001 C CNN
	1    5550 2650
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR07
U 1 1 5CB9B8B0
P 5550 2900
F 0 "#PWR07" H 5550 2650 50  0001 C CNN
F 1 "GND" H 5555 2727 50  0000 C CNN
F 2 "" H 5550 2900 50  0001 C CNN
F 3 "" H 5550 2900 50  0001 C CNN
	1    5550 2900
	1    0    0    -1  
$EndComp
Wire Wire Line
	5350 2750 5550 2750
Wire Wire Line
	5550 2900 5550 2750
Connection ~ 5550 2750
$Comp
L power:GND #PWR08
U 1 1 5CBA6363
P 3550 4450
F 0 "#PWR08" H 3550 4200 50  0001 C CNN
F 1 "GND" H 3375 4400 50  0000 C CNN
F 2 "" H 3550 4450 50  0001 C CNN
F 3 "" H 3550 4450 50  0001 C CNN
	1    3550 4450
	1    0    0    -1  
$EndComp
Wire Wire Line
	5550 2350 5550 2550
Connection ~ 5550 2550
Connection ~ 5350 2550
$Comp
L Connector:Screw_Terminal_01x02 M2
U 1 1 5D447C03
P 8800 2100
F 0 "M2" H 8718 1775 50  0000 C CNN
F 1 "Motor2" H 8718 1866 50  0000 C CNN
F 2 "TerminalBlock_Phoenix:TerminalBlock_Phoenix_PT-1,5-2-3.5-H_1x02_P3.50mm_Horizontal" H 8800 2100 50  0001 C CNN
F 3 "~" H 8800 2100 50  0001 C CNN
	1    8800 2100
	1    0    0    -1  
$EndComp
$Comp
L Connector:Screw_Terminal_01x02 M1
U 1 1 5D4495C2
P 8800 2700
F 0 "M1" H 8718 2375 50  0000 C CNN
F 1 "Motor1" H 8718 2466 50  0000 C CNN
F 2 "TerminalBlock_Phoenix:TerminalBlock_Phoenix_PT-1,5-2-3.5-H_1x02_P3.50mm_Horizontal" H 8800 2700 50  0001 C CNN
F 3 "~" H 8800 2700 50  0001 C CNN
	1    8800 2700
	1    0    0    -1  
$EndComp
Wire Wire Line
	8100 2050 8350 2050
Wire Wire Line
	8350 2050 8350 2100
Wire Wire Line
	8350 2100 8600 2100
Wire Wire Line
	8100 2250 8350 2250
Wire Wire Line
	8350 2250 8350 2200
Wire Wire Line
	8350 2200 8600 2200
Wire Wire Line
	8100 2650 8350 2650
Wire Wire Line
	8350 2650 8350 2700
Wire Wire Line
	8350 2700 8600 2700
Wire Wire Line
	8100 2850 8350 2850
Wire Wire Line
	8350 2850 8350 2800
Wire Wire Line
	8350 2800 8600 2800
$Comp
L power:VSS #PWR010
U 1 1 5D451D4C
P 7700 1300
F 0 "#PWR010" H 7700 1150 50  0001 C CNN
F 1 "VSS" H 7717 1473 50  0000 C CNN
F 2 "" H 7700 1300 50  0001 C CNN
F 3 "" H 7700 1300 50  0001 C CNN
	1    7700 1300
	1    0    0    -1  
$EndComp
$Comp
L power:VSS #PWR011
U 1 1 5D45262C
P 8250 4500
F 0 "#PWR011" H 8250 4350 50  0001 C CNN
F 1 "VSS" H 8267 4673 50  0000 C CNN
F 2 "" H 8250 4500 50  0001 C CNN
F 3 "" H 8250 4500 50  0001 C CNN
	1    8250 4500
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR09
U 1 1 5D452E01
P 7500 1300
F 0 "#PWR09" H 7500 1150 50  0001 C CNN
F 1 "VCC" H 7517 1473 50  0000 C CNN
F 2 "" H 7500 1300 50  0001 C CNN
F 3 "" H 7500 1300 50  0001 C CNN
	1    7500 1300
	1    0    0    -1  
$EndComp
Wire Wire Line
	7700 1300 7700 1650
Wire Wire Line
	7500 1300 7500 1650
Wire Wire Line
	8250 4500 8250 4950
Connection ~ 8250 4950
Wire Wire Line
	8250 4950 8300 4950
Wire Wire Line
	6400 3050 7100 3050
Wire Wire Line
	4150 1950 6400 1950
Wire Wire Line
	6400 1950 6400 3050
$Comp
L power:GND #PWR013
U 1 1 5D4663B9
P 4000 5700
F 0 "#PWR013" H 4000 5450 50  0001 C CNN
F 1 "GND" H 4005 5527 50  0000 C CNN
F 2 "" H 4000 5700 50  0001 C CNN
F 3 "" H 4000 5700 50  0001 C CNN
	1    4000 5700
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR012
U 1 1 5D46A5E7
P 3300 5050
F 0 "#PWR012" H 3300 4900 50  0001 C CNN
F 1 "VCC" H 3317 5223 50  0000 C CNN
F 2 "" H 3300 5050 50  0001 C CNN
F 3 "" H 3300 5050 50  0001 C CNN
	1    3300 5050
	1    0    0    -1  
$EndComp
$Comp
L Device:R R2
U 1 1 5D4A63EF
P 4850 4600
F 0 "R2" H 4920 4646 50  0000 L CNN
F 1 "10k" H 4920 4555 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 4780 4600 50  0001 C CNN
F 3 "~" H 4850 4600 50  0001 C CNN
	1    4850 4600
	1    0    0    -1  
$EndComp
Wire Wire Line
	4150 3250 4600 3250
$Comp
L power:VCC #PWR014
U 1 1 5D4B6E93
P 4850 4450
F 0 "#PWR014" H 4850 4300 50  0001 C CNN
F 1 "VCC" H 4867 4623 50  0000 C CNN
F 2 "" H 4850 4450 50  0001 C CNN
F 3 "" H 4850 4450 50  0001 C CNN
	1    4850 4450
	1    0    0    -1  
$EndComp
Wire Wire Line
	8600 5250 8600 5350
$Comp
L Device:CP_Small C4
U 1 1 5D4DC0CB
P 9050 5200
F 0 "C4" H 9138 5246 50  0000 L CNN
F 1 "10uF" H 9138 5155 50  0000 L CNN
F 2 "Capacitor_THT:C_Radial_D5.0mm_H5.0mm_P2.00mm" H 9050 5200 50  0001 C CNN
F 3 "~" H 9050 5200 50  0001 C CNN
	1    9050 5200
	1    0    0    -1  
$EndComp
Wire Wire Line
	9050 4950 9050 5100
Connection ~ 9050 4950
Wire Wire Line
	9050 5300 9050 5350
Wire Wire Line
	9050 5350 8600 5350
Connection ~ 8600 5350
Wire Wire Line
	8600 5350 8600 5450
Wire Wire Line
	6950 2050 7100 2050
Wire Wire Line
	4150 2150 6100 2150
Wire Wire Line
	4150 2050 6250 2050
Wire Wire Line
	5200 2550 5350 2550
Wire Wire Line
	5850 2300 5850 2250
Wire Wire Line
	6100 2650 6100 2150
Wire Wire Line
	6100 2650 7100 2650
Wire Wire Line
	6250 2850 6250 2050
Wire Wire Line
	6250 2850 7100 2850
Wire Wire Line
	6550 1850 6550 2450
Wire Wire Line
	4150 1850 6550 1850
Wire Wire Line
	6550 2450 7100 2450
Wire Wire Line
	6700 1750 6700 2250
Wire Wire Line
	4150 1750 6700 1750
Wire Wire Line
	6700 2250 7100 2250
Wire Wire Line
	5350 4400 5900 4400
Wire Wire Line
	6950 2050 6950 4150
Wire Wire Line
	4150 4150 6950 4150
Wire Wire Line
	4400 3550 4400 4000
Wire Wire Line
	4400 4000 5700 4000
Wire Wire Line
	5700 4000 5700 5550
Wire Wire Line
	4500 3450 4500 3900
Wire Wire Line
	4500 3900 5800 3900
Wire Wire Line
	5800 3900 5800 5550
Connection ~ 5350 4400
Wire Wire Line
	5350 4400 5350 4650
Wire Wire Line
	6300 4400 6450 4400
Wire Wire Line
	4600 3250 4600 3800
Wire Wire Line
	4600 3800 5350 3800
Wire Wire Line
	5350 3800 5350 4400
Wire Wire Line
	4150 2250 5850 2250
Wire Wire Line
	4150 2350 5550 2350
Wire Wire Line
	5200 2450 5200 2550
Wire Wire Line
	4150 2450 5200 2450
Wire Wire Line
	4150 3650 4700 3650
Wire Wire Line
	4700 3650 4700 3350
Wire Wire Line
	4150 3750 4800 3750
Wire Wire Line
	4800 3750 4800 3450
Wire Wire Line
	4150 3850 4900 3850
Wire Wire Line
	4900 3850 4900 3550
Wire Wire Line
	4600 2650 4600 3150
Wire Wire Line
	4150 2650 4600 2650
Wire Wire Line
	4150 2750 4700 2750
Wire Wire Line
	4700 2750 4700 3050
Wire Wire Line
	4150 2850 4800 2850
Wire Wire Line
	4800 2850 4800 2950
Wire Wire Line
	4150 2950 4500 2950
Wire Wire Line
	4500 2950 4500 2900
Wire Wire Line
	4500 2900 4850 2900
Wire Wire Line
	4150 3050 4400 3050
Wire Wire Line
	4400 3050 4400 2800
Wire Wire Line
	4400 2800 4850 2800
Wire Wire Line
	4850 2800 4850 2750
Wire Wire Line
	4150 3150 4300 3150
Wire Wire Line
	4300 3150 4300 2700
Wire Wire Line
	4300 2700 4800 2700
Wire Wire Line
	4800 2700 4800 2650
Wire Wire Line
	4800 2650 4900 2650
Wire Wire Line
	4850 2750 4900 2750
Wire Wire Line
	4850 2900 4850 2850
Wire Wire Line
	4850 2850 4900 2850
Wire Wire Line
	4800 2950 4900 2950
Wire Wire Line
	4700 3050 4900 3050
Wire Wire Line
	4600 3150 4900 3150
Wire Wire Line
	4800 3450 4900 3450
Wire Wire Line
	4700 3350 4900 3350
$Comp
L Connector:Conn_01x06_Male J8
U 1 1 5D6D7C3B
P 5900 5750
F 0 "J8" V 6054 5994 50  0000 L CNN
F 1 "Serial" V 5963 5994 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x06_P2.54mm_Vertical" H 5900 5750 50  0001 C CNN
F 3 "~" H 5900 5750 50  0001 C CNN
	1    5900 5750
	0    1    -1   0   
$EndComp
$Comp
L Connector:Conn_01x03_Male J7
U 1 1 5D6E1400
P 5100 3450
F 0 "J7" H 5072 3474 50  0000 R CNN
F 1 "DIGITAL" H 5072 3383 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 5100 3450 50  0001 C CNN
F 3 "~" H 5100 3450 50  0001 C CNN
	1    5100 3450
	-1   0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x06_Male J6
U 1 1 5D6E1CB5
P 5100 2850
F 0 "J6" H 5072 2824 50  0000 R CNN
F 1 "ANALOG" H 5072 2733 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x06_P2.54mm_Vertical" H 5100 2850 50  0001 C CNN
F 3 "~" H 5100 2850 50  0001 C CNN
	1    5100 2850
	-1   0    0    -1  
$EndComp
Wire Wire Line
	3300 5050 3300 5250
Wire Wire Line
	4000 5150 4000 5250
$Comp
L Connector:Conn_01x06_Male Vcc1
U 1 1 5D566BB2
P 3600 5450
F 0 "Vcc1" H 3572 5424 50  0000 R CNN
F 1 "+5v" H 3572 5333 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x06_P2.54mm_Vertical" H 3600 5450 50  0001 C CNN
F 3 "~" H 3600 5450 50  0001 C CNN
	1    3600 5450
	-1   0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x06_Male Gnd1
U 1 1 5D5683CC
P 4400 5150
F 0 "Gnd1" H 4372 5124 50  0000 R CNN
F 1 "GND" H 4372 5033 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x06_P2.54mm_Vertical" H 4400 5150 50  0001 C CNN
F 3 "~" H 4400 5150 50  0001 C CNN
	1    4400 5150
	-1   0    0    -1  
$EndComp
Wire Wire Line
	3400 5250 3300 5250
Connection ~ 3300 5250
Wire Wire Line
	3300 5250 3300 5350
Wire Wire Line
	3400 5350 3300 5350
Connection ~ 3300 5350
Wire Wire Line
	3300 5350 3300 5450
Wire Wire Line
	3300 5450 3400 5450
Wire Wire Line
	3400 5550 3300 5550
Wire Wire Line
	3300 5550 3300 5450
Connection ~ 3300 5450
Wire Wire Line
	3400 5650 3300 5650
Wire Wire Line
	3300 5650 3300 5550
Connection ~ 3300 5550
Wire Wire Line
	3400 5750 3300 5750
Wire Wire Line
	3300 5750 3300 5650
Connection ~ 3300 5650
Wire Wire Line
	4000 5150 4200 5150
Wire Wire Line
	4000 5150 4000 5050
Wire Wire Line
	4000 5050 4200 5050
Connection ~ 4000 5150
Wire Wire Line
	4000 5050 4000 4950
Wire Wire Line
	4000 4950 4200 4950
Connection ~ 4000 5050
Wire Wire Line
	4000 5250 4200 5250
Connection ~ 4000 5250
Wire Wire Line
	4000 5250 4000 5350
Wire Wire Line
	4000 5350 4200 5350
Connection ~ 4000 5350
Wire Wire Line
	4000 5350 4000 5450
Wire Wire Line
	4000 5450 4200 5450
Connection ~ 4000 5450
Wire Wire Line
	4000 5450 4000 5700
Wire Wire Line
	5350 4950 5350 5050
Wire Wire Line
	5350 5050 5600 5050
Wire Wire Line
	5600 5050 5600 5550
Wire Wire Line
	4850 4750 4850 4900
Wire Wire Line
	4850 4900 5100 4900
Wire Wire Line
	5100 4900 5100 4400
Wire Wire Line
	5100 4400 5350 4400
$Comp
L Device:C C5
U 1 1 6058D708
P 2450 3950
F 0 "C5" H 2565 3996 50  0000 L CNN
F 1 "100n" H 2565 3905 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric" H 2488 3800 50  0001 C CNN
F 3 "~" H 2450 3950 50  0001 C CNN
	1    2450 3950
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR016
U 1 1 6058F85D
P 2450 4200
F 0 "#PWR016" H 2450 3950 50  0001 C CNN
F 1 "GND" H 2455 4027 50  0000 C CNN
F 2 "" H 2450 4200 50  0001 C CNN
F 3 "" H 2450 4200 50  0001 C CNN
	1    2450 4200
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR015
U 1 1 60590959
P 2450 3650
F 0 "#PWR015" H 2450 3500 50  0001 C CNN
F 1 "VCC" H 2465 3823 50  0000 C CNN
F 2 "" H 2450 3650 50  0001 C CNN
F 3 "" H 2450 3650 50  0001 C CNN
	1    2450 3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	2450 3800 2450 3650
Wire Wire Line
	2450 4200 2450 4100
$Comp
L Connector:Screw_Terminal_01x02 J2
U 1 1 5CB7B471
P 7300 4950
F 0 "J2" H 7218 4625 50  0000 C CNN
F 1 "Bat" H 7218 4716 50  0000 C CNN
F 2 "TerminalBlock_Phoenix:TerminalBlock_Phoenix_PT-1,5-2-3.5-H_1x02_P3.50mm_Horizontal" H 7300 4950 50  0001 C CNN
F 3 "~" H 7300 4950 50  0001 C CNN
	1    7300 4950
	-1   0    0    1   
$EndComp
$Comp
L MCU_Microchip_ATmega:ATmega328P-AU U101
U 1 1 605AE32D
P 3550 2950
F 0 "U101" H 3550 1361 50  0000 C CNN
F 1 "ATmega328P-AU" H 3550 1270 50  0000 C CNN
F 2 "Package_QFP:TQFP-32_7x7mm_P0.8mm" H 3550 2950 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/ATmega328_P%20AVR%20MCU%20with%20picoPower%20Technology%20Data%20Sheet%2040001984A.pdf" H 3550 2950 50  0001 C CNN
	1    3550 2950
	1    0    0    -1  
$EndComp
$EndSCHEMATC
