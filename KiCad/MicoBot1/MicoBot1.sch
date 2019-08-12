EESchema Schematic File Version 4
LIBS:MicoBot1-cache
EELAYER 29 0
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
L Connector:Conn_01x06_Male J1
U 1 1 5CB77726
P 5800 5150
F 0 "J1" V 5954 4762 50  0000 R CNN
F 1 "Prog" V 5700 5250 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x06_P2.54mm_Vertical" H 5800 5150 50  0001 C CNN
F 3 "~" H 5800 5150 50  0001 C CNN
	1    5800 5150
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR03
U 1 1 5CB7BD64
P 6450 4800
F 0 "#PWR03" H 6450 4550 50  0001 C CNN
F 1 "GND" H 6455 4627 50  0000 C CNN
F 2 "" H 6450 4800 50  0001 C CNN
F 3 "" H 6450 4800 50  0001 C CNN
	1    6450 4800
	1    0    0    -1  
$EndComp
Wire Wire Line
	6100 4950 6100 4650
Wire Wire Line
	6100 4650 6450 4650
Wire Wire Line
	6450 4650 6450 4800
Wire Wire Line
	5900 4950 5900 4550
$Comp
L power:VCC #PWR02
U 1 1 5CB7DAF3
P 6450 4550
F 0 "#PWR02" H 6450 4400 50  0001 C CNN
F 1 "VCC" H 6467 4723 50  0000 C CNN
F 2 "" H 6450 4550 50  0001 C CNN
F 3 "" H 6450 4550 50  0001 C CNN
	1    6450 4550
	1    0    0    -1  
$EndComp
Wire Wire Line
	5900 4550 6450 4550
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
Wire Wire Line
	5800 3450 5800 4950
Wire Wire Line
	5700 3550 5700 4950
$Comp
L Device:C C1
U 1 1 5CB7FCE1
P 5350 4200
F 0 "C1" H 5465 4246 50  0000 L CNN
F 1 "C" H 5465 4155 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D4.3mm_W1.9mm_P5.00mm" H 5388 4050 50  0001 C CNN
F 3 "~" H 5350 4200 50  0001 C CNN
	1    5350 4200
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
	4150 3550 5700 3550
Wire Wire Line
	4150 3450 5800 3450
$Comp
L MCU_Microchip_ATmega:ATmega328P-PU U1
U 1 1 5CB743B3
P 3550 2950
F 0 "U1" H 2906 2996 50  0000 R CNN
F 1 "ATmega328P-PU" H 2906 2905 50  0000 R CNN
F 2 "Package_DIP:DIP-28_W7.62mm" H 3550 2950 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/ATmega328_P%20AVR%20MCU%20with%20picoPower%20Technology%20Data%20Sheet%2040001984A.pdf" H 3550 2950 50  0001 C CNN
	1    3550 2950
	1    0    0    -1  
$EndComp
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
P 6000 3250
F 0 "SW1" H 6000 3535 50  0000 C CNN
F 1 "Rst" H 6000 3444 50  0000 C CNN
F 2 "MiLib:Pulsador_Cuadrado_6" H 6000 3450 50  0001 C CNN
F 3 "~" H 6000 3450 50  0001 C CNN
	1    6000 3250
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR05
U 1 1 5CB9A211
P 6300 3350
F 0 "#PWR05" H 6300 3100 50  0001 C CNN
F 1 "GND" H 6305 3177 50  0000 C CNN
F 2 "" H 6300 3350 50  0001 C CNN
F 3 "" H 6300 3350 50  0001 C CNN
	1    6300 3350
	1    0    0    -1  
$EndComp
Wire Wire Line
	6200 3250 6300 3250
Wire Wire Line
	6300 3250 6300 3350
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
P 5350 2450
F 0 "D1" V 5389 2333 50  0000 R CNN
F 1 "LED" V 5298 2333 50  0000 R CNN
F 2 "LED_THT:LED_D3.0mm" H 5350 2450 50  0001 C CNN
F 3 "~" H 5350 2450 50  0001 C CNN
	1    5350 2450
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R1
U 1 1 5CB8BF62
P 5350 2750
F 0 "R1" H 5420 2796 50  0000 L CNN
F 1 "R" H 5420 2705 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 5280 2750 50  0001 C CNN
F 3 "~" H 5350 2750 50  0001 C CNN
	1    5350 2750
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR06
U 1 1 5CB8C74D
P 5350 2900
F 0 "#PWR06" H 5350 2650 50  0001 C CNN
F 1 "GND" H 5355 2727 50  0000 C CNN
F 2 "" H 5350 2900 50  0001 C CNN
F 3 "" H 5350 2900 50  0001 C CNN
	1    5350 2900
	1    0    0    -1  
$EndComp
$Comp
L Device:Crystal_Small Y1
U 1 1 5CB975FD
P 4950 2550
F 0 "Y1" H 4950 2775 50  0000 C CNN
F 1 "Crystal" H 4950 2684 50  0000 C CNN
F 2 "Crystal:Crystal_HC49-4H_Vertical" H 4950 2550 50  0001 C CNN
F 3 "~" H 4950 2550 50  0001 C CNN
	1    4950 2550
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C2
U 1 1 5CB99E74
P 4850 2650
F 0 "C2" H 4942 2696 50  0000 L CNN
F 1 "C" H 4942 2605 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D4.3mm_W1.9mm_P5.00mm" H 4850 2650 50  0001 C CNN
F 3 "~" H 4850 2650 50  0001 C CNN
	1    4850 2650
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C3
U 1 1 5CB9B3E9
P 5050 2650
F 0 "C3" H 5142 2696 50  0000 L CNN
F 1 "C" H 5142 2605 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D4.3mm_W1.9mm_P5.00mm" H 5050 2650 50  0001 C CNN
F 3 "~" H 5050 2650 50  0001 C CNN
	1    5050 2650
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR07
U 1 1 5CB9B8B0
P 5050 2900
F 0 "#PWR07" H 5050 2650 50  0001 C CNN
F 1 "GND" H 5055 2727 50  0000 C CNN
F 2 "" H 5050 2900 50  0001 C CNN
F 3 "" H 5050 2900 50  0001 C CNN
	1    5050 2900
	1    0    0    -1  
$EndComp
Wire Wire Line
	4850 2750 5050 2750
Wire Wire Line
	5050 2900 5050 2750
Connection ~ 5050 2750
$Comp
L power:GND #PWR08
U 1 1 5CBA6363
P 3550 4450
F 0 "#PWR08" H 3550 4200 50  0001 C CNN
F 1 "GND" H 3555 4277 50  0000 C CNN
F 2 "" H 3550 4450 50  0001 C CNN
F 3 "" H 3550 4450 50  0001 C CNN
	1    3550 4450
	1    0    0    -1  
$EndComp
Wire Wire Line
	5050 2350 5050 2550
Connection ~ 5050 2550
Connection ~ 4850 2550
$Comp
L Connector:Screw_Terminal_01x02 J3
U 1 1 5D447C03
P 8800 2100
F 0 "J3" H 8718 1775 50  0000 C CNN
F 1 "Motor2" H 8718 1866 50  0000 C CNN
F 2 "TerminalBlock_Phoenix:TerminalBlock_Phoenix_PT-1,5-2-3.5-H_1x02_P3.50mm_Horizontal" H 8800 2100 50  0001 C CNN
F 3 "~" H 8800 2100 50  0001 C CNN
	1    8800 2100
	1    0    0    -1  
$EndComp
$Comp
L Connector:Screw_Terminal_01x02 J4
U 1 1 5D4495C2
P 8800 2700
F 0 "J4" H 8718 2375 50  0000 C CNN
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
L Connector:Conn_01x06_Male J5
U 1 1 5D496C2D
P 4350 2950
F 0 "J5" V 4504 2562 50  0000 R CNN
F 1 "Datos" V 4250 3000 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x06_P2.54mm_Vertical" H 4350 2950 50  0001 C CNN
F 3 "~" H 4350 2950 50  0001 C CNN
	1    4350 2950
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x06_Male J6
U 1 1 5D46526B
P 4350 5600
F 0 "J6" V 4504 5212 50  0000 R CNN
F 1 "Vcc" V 4250 5600 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x06_P2.54mm_Vertical" H 4350 5600 50  0001 C CNN
F 3 "~" H 4350 5600 50  0001 C CNN
	1    4350 5600
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x06_Male J7
U 1 1 5D465A5B
P 5050 5600
F 0 "J7" V 5204 5212 50  0000 R CNN
F 1 "Gnd" V 4950 5650 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x06_P2.54mm_Vertical" H 5050 5600 50  0001 C CNN
F 3 "~" H 5050 5600 50  0001 C CNN
	1    5050 5600
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR013
U 1 1 5D4663B9
P 4800 5950
F 0 "#PWR013" H 4800 5700 50  0001 C CNN
F 1 "GND" H 4805 5777 50  0000 C CNN
F 2 "" H 4800 5950 50  0001 C CNN
F 3 "" H 4800 5950 50  0001 C CNN
	1    4800 5950
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR012
U 1 1 5D46A5E7
P 4100 5200
F 0 "#PWR012" H 4100 5050 50  0001 C CNN
F 1 "VCC" H 4117 5373 50  0000 C CNN
F 2 "" H 4100 5200 50  0001 C CNN
F 3 "" H 4100 5200 50  0001 C CNN
	1    4100 5200
	1    0    0    -1  
$EndComp
Wire Wire Line
	4100 5200 4100 5300
Wire Wire Line
	4100 5300 4150 5300
Wire Wire Line
	4100 5300 4100 5400
Wire Wire Line
	4100 5400 4150 5400
Connection ~ 4100 5300
Wire Wire Line
	4100 5400 4100 5500
Wire Wire Line
	4100 5500 4150 5500
Connection ~ 4100 5400
Wire Wire Line
	4100 5500 4100 5600
Wire Wire Line
	4100 5600 4150 5600
Connection ~ 4100 5500
Wire Wire Line
	4100 5600 4100 5700
Wire Wire Line
	4100 5700 4150 5700
Connection ~ 4100 5600
Wire Wire Line
	4100 5700 4100 5800
Wire Wire Line
	4100 5800 4150 5800
Connection ~ 4100 5700
Wire Wire Line
	4850 5800 4800 5800
Wire Wire Line
	4800 5800 4800 5950
Wire Wire Line
	4850 5700 4800 5700
Wire Wire Line
	4800 5700 4800 5800
Connection ~ 4800 5800
Wire Wire Line
	4850 5600 4800 5600
Wire Wire Line
	4800 5600 4800 5700
Connection ~ 4800 5700
Wire Wire Line
	4850 5500 4800 5500
Wire Wire Line
	4800 5500 4800 5600
Connection ~ 4800 5600
Wire Wire Line
	4850 5400 4800 5400
Wire Wire Line
	4800 5400 4800 5500
Connection ~ 4800 5500
Wire Wire Line
	4850 5300 4800 5300
Wire Wire Line
	4800 5300 4800 5400
Connection ~ 4800 5400
$Comp
L Device:R R2
U 1 1 5D4A63EF
P 5350 4600
F 0 "R2" H 5420 4646 50  0000 L CNN
F 1 "R" H 5420 4555 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 5280 4600 50  0001 C CNN
F 3 "~" H 5350 4600 50  0001 C CNN
	1    5350 4600
	1    0    0    -1  
$EndComp
Wire Wire Line
	4150 3250 5350 3250
Wire Wire Line
	5350 3250 5350 4050
Connection ~ 5350 3250
Wire Wire Line
	5350 3250 5800 3250
Wire Wire Line
	5350 4350 5350 4400
Wire Wire Line
	5350 4400 5600 4400
Wire Wire Line
	5600 4400 5600 4950
Connection ~ 5350 4400
Wire Wire Line
	5350 4400 5350 4450
$Comp
L power:VCC #PWR014
U 1 1 5D4B6E93
P 5150 4750
F 0 "#PWR014" H 5150 4600 50  0001 C CNN
F 1 "VCC" H 5167 4923 50  0000 C CNN
F 2 "" H 5150 4750 50  0001 C CNN
F 3 "" H 5150 4750 50  0001 C CNN
	1    5150 4750
	1    0    0    -1  
$EndComp
Wire Wire Line
	5150 4750 5150 4850
Wire Wire Line
	5150 4850 5350 4850
Wire Wire Line
	5350 4850 5350 4750
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
	4150 3650 6000 3650
Wire Wire Line
	6000 3650 6000 4950
Wire Wire Line
	4150 4150 4600 4150
Wire Wire Line
	4600 4150 4600 3850
Wire Wire Line
	4600 3850 6950 3850
Wire Wire Line
	6950 3850 6950 2050
Wire Wire Line
	6950 2050 7100 2050
Wire Wire Line
	4150 2150 6100 2150
Wire Wire Line
	4150 2050 6250 2050
Wire Wire Line
	4700 2550 4850 2550
Wire Wire Line
	4150 2350 5050 2350
Wire Wire Line
	4700 2450 4700 2550
Wire Wire Line
	4150 2450 4700 2450
Wire Wire Line
	5350 2300 5350 2250
Wire Wire Line
	4150 2250 5350 2250
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
$EndSCHEMATC
