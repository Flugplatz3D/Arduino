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
F 1 "Conn_01x06_Male" V 5650 5500 50  0000 R CNN
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
NoConn ~ 6000 4950
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
P 5450 4650
F 0 "C1" H 5565 4696 50  0000 L CNN
F 1 "C" H 5565 4605 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D4.3mm_W1.9mm_P5.00mm" H 5488 4500 50  0001 C CNN
F 3 "~" H 5450 4650 50  0001 C CNN
	1    5450 4650
	1    0    0    -1  
$EndComp
Wire Wire Line
	5450 3250 5450 4500
Wire Wire Line
	5450 4800 5450 4900
Wire Wire Line
	5450 4900 5600 4900
Wire Wire Line
	5600 4900 5600 4950
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
Wire Wire Line
	4150 3250 5450 3250
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
F 1 "SW_Push" H 6000 3444 50  0000 C CNN
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
	5800 3250 5450 3250
Connection ~ 5450 3250
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
F 1 "Screw_Terminal_01x02" H 7218 4716 50  0000 C CNN
F 2 "TerminalBlock_MetzConnect:TerminalBlock_MetzConnect_Type059_RT06302HBWC_1x02_P3.50mm_Horizontal" H 7300 4950 50  0001 C CNN
F 3 "~" H 7300 4950 50  0001 C CNN
	1    7300 4950
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR0101
U 1 1 5CB7D70C
P 8600 5250
F 0 "#PWR0101" H 8600 5000 50  0001 C CNN
F 1 "GND" H 8605 5077 50  0000 C CNN
F 2 "" H 8600 5250 50  0001 C CNN
F 3 "" H 8600 5250 50  0001 C CNN
	1    8600 5250
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
F 1 "SW_SPDT" H 7950 5044 50  0000 C CNN
F 2 "MiLib:EG1218" H 7950 4850 50  0001 C CNN
F 3 "~" H 7950 4850 50  0001 C CNN
	1    7950 4850
	1    0    0    -1  
$EndComp
Wire Wire Line
	7500 4850 7750 4850
Wire Wire Line
	8150 4950 8300 4950
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
P 5600 1550
F 0 "D1" V 5639 1433 50  0000 R CNN
F 1 "LED" V 5548 1433 50  0000 R CNN
F 2 "LED_THT:LED_D3.0mm" H 5600 1550 50  0001 C CNN
F 3 "~" H 5600 1550 50  0001 C CNN
	1    5600 1550
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R1
U 1 1 5CB8BF62
P 5600 1850
F 0 "R1" H 5670 1896 50  0000 L CNN
F 1 "R" H 5670 1805 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 5530 1850 50  0001 C CNN
F 3 "~" H 5600 1850 50  0001 C CNN
	1    5600 1850
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR06
U 1 1 5CB8C74D
P 5600 2000
F 0 "#PWR06" H 5600 1750 50  0001 C CNN
F 1 "GND" H 5605 1827 50  0000 C CNN
F 2 "" H 5600 2000 50  0001 C CNN
F 3 "" H 5600 2000 50  0001 C CNN
	1    5600 2000
	1    0    0    -1  
$EndComp
$Comp
L Device:Crystal_Small Y1
U 1 1 5CB975FD
P 4900 1750
F 0 "Y1" H 4900 1975 50  0000 C CNN
F 1 "Crystal_Small" H 4900 1884 50  0000 C CNN
F 2 "Crystal:Crystal_HC18-U_Vertical" H 4900 1750 50  0001 C CNN
F 3 "~" H 4900 1750 50  0001 C CNN
	1    4900 1750
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C2
U 1 1 5CB99E74
P 4800 1850
F 0 "C2" H 4892 1896 50  0000 L CNN
F 1 "C_Small" H 4892 1805 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D4.3mm_W1.9mm_P5.00mm" H 4800 1850 50  0001 C CNN
F 3 "~" H 4800 1850 50  0001 C CNN
	1    4800 1850
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C3
U 1 1 5CB9B3E9
P 5000 1850
F 0 "C3" H 5092 1896 50  0000 L CNN
F 1 "C_Small" H 5092 1805 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D4.3mm_W1.9mm_P5.00mm" H 5000 1850 50  0001 C CNN
F 3 "~" H 5000 1850 50  0001 C CNN
	1    5000 1850
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR07
U 1 1 5CB9B8B0
P 5000 2100
F 0 "#PWR07" H 5000 1850 50  0001 C CNN
F 1 "GND" H 5005 1927 50  0000 C CNN
F 2 "" H 5000 2100 50  0001 C CNN
F 3 "" H 5000 2100 50  0001 C CNN
	1    5000 2100
	1    0    0    -1  
$EndComp
Wire Wire Line
	4800 1950 5000 1950
Wire Wire Line
	5000 2100 5000 1950
Connection ~ 5000 1950
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
	4150 2250 4350 2250
Wire Wire Line
	4350 2250 4350 1400
Wire Wire Line
	4350 1400 5600 1400
Wire Wire Line
	4150 2350 4450 2350
Wire Wire Line
	4450 2350 4450 1550
Wire Wire Line
	4450 1550 5000 1550
Wire Wire Line
	5000 1550 5000 1750
Connection ~ 5000 1750
Wire Wire Line
	4550 2450 4550 1750
Wire Wire Line
	4550 1750 4800 1750
Wire Wire Line
	4150 2450 4550 2450
Connection ~ 4800 1750
$Comp
L Connector:Conn_01x06_Male J3
U 1 1 5CB94ED1
P 4350 2950
F 0 "J3" H 4322 2832 50  0000 R CNN
F 1 "Conn_01x06_Male" H 4322 2923 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x06_P2.54mm_Vertical" H 4350 2950 50  0001 C CNN
F 3 "~" H 4350 2950 50  0001 C CNN
	1    4350 2950
	-1   0    0    1   
$EndComp
$EndSCHEMATC
