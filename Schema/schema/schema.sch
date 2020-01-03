EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "STM32 Value Line Discovery - Shiled board"
Date "20 oct 2012"
Rev "1.0"
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Connector_Generic:Conn_01x28 P1
U 1 1 50827277
P 10700 1900
F 0 "P1" H 10850 3200 60  0000 C CNN
F 1 "CONN28" V 10800 1900 60  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x28_P2.54mm_Vertical" V 10900 1900 30  0000 C CNN
F 3 "" H 10700 1900 60  0001 C CNN
	1    10700 1900
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x28 P2
U 1 1 50827286
P 10700 4900
F 0 "P2" H 10850 3450 60  0000 C CNN
F 1 "CONN28" V 10800 4900 60  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x28_P2.54mm_Vertical" V 10900 4900 30  0000 C CNN
F 3 "" H 10700 4900 60  0001 C CNN
	1    10700 4900
	1    0    0    1   
$EndComp
$Comp
L Connector_Generic:Conn_01x06 P3
U 1 1 50827295
P 8900 800
F 0 "P3" H 8900 400 60  0000 C CNN
F 1 "CONN6" V 9000 800 60  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x06_P2.54mm_Vertical" V 9100 800 30  0000 C CNN
F 3 "" H 8900 800 60  0001 C CNN
	1    8900 800 
	1    0    0    -1  
$EndComp
Wire Wire Line
	10500 600  10400 600 
Wire Wire Line
	10500 800  10200 800 
Wire Wire Line
	10500 900  10200 900 
Wire Wire Line
	10500 1000 10200 1000
Wire Wire Line
	10500 1100 10200 1100
Wire Wire Line
	10500 1200 10200 1200
Wire Wire Line
	10500 1300 10200 1300
Wire Wire Line
	10500 1400 10200 1400
Wire Wire Line
	10500 1500 10200 1500
Wire Wire Line
	10500 1600 10200 1600
Wire Wire Line
	10500 1700 10200 1700
Wire Wire Line
	10500 1800 10200 1800
Wire Wire Line
	10500 1900 10200 1900
Wire Wire Line
	10500 2200 10200 2200
Wire Wire Line
	10500 2300 10200 2300
Wire Wire Line
	10500 2500 10200 2500
Wire Wire Line
	10500 2600 10200 2600
Wire Wire Line
	10500 2700 10200 2700
Wire Wire Line
	10500 2800 10200 2800
Wire Wire Line
	10500 2900 10200 2900
Wire Wire Line
	10500 3200 10200 3200
Wire Wire Line
	10500 3800 10200 3800
Wire Wire Line
	10500 3900 10200 3900
Wire Wire Line
	10500 4000 10200 4000
Wire Wire Line
	10500 4400 10200 4400
Wire Wire Line
	10500 4500 10200 4500
Wire Wire Line
	10500 4600 10200 4600
Wire Wire Line
	10500 4700 10200 4700
Wire Wire Line
	10500 4800 10200 4800
Wire Wire Line
	10500 4900 10200 4900
Wire Wire Line
	10500 5000 10200 5000
Wire Wire Line
	10500 5100 10200 5100
Wire Wire Line
	10500 5200 10200 5200
Wire Wire Line
	10500 5300 10200 5300
Wire Wire Line
	10500 5400 10200 5400
Wire Wire Line
	10500 5500 10200 5500
Wire Wire Line
	10500 5600 10200 5600
Wire Wire Line
	10500 5700 10200 5700
Wire Wire Line
	10500 5800 10200 5800
Wire Wire Line
	10500 5900 10200 5900
Wire Wire Line
	10500 6000 10200 6000
Wire Wire Line
	10500 6100 10200 6100
Wire Wire Line
	10500 6200 10200 6200
Wire Wire Line
	8700 600  8400 600 
Wire Wire Line
	8700 700  8400 700 
Wire Wire Line
	8700 800  8400 800 
Wire Wire Line
	8700 900  8400 900 
Wire Wire Line
	8700 1000 8400 1000
Wire Wire Line
	8700 1100 8400 1100
Text Label 8400 600  0    40   ~ 0
PB10
Text Label 8400 700  0    40   ~ 0
PB11
Text Label 8400 800  0    40   ~ 0
PB12
Text Label 8400 900  0    40   ~ 0
PB13
Text Label 8400 1000 0    40   ~ 0
PB14
Text Label 8400 1100 0    40   ~ 0
PB15
NoConn ~ 10500 700 
NoConn ~ 10500 3600
$Comp
L power:GND #PWR01
U 1 1 50827354
P 10400 600
F 0 "#PWR01" H 10400 350 50  0001 C CNN
F 1 "GND" H 10400 450 50  0000 C CNN
F 2 "" H 10400 600 50  0000 C CNN
F 3 "" H 10400 600 50  0000 C CNN
	1    10400 600 
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR02
U 1 1 50827361
P 10200 3300
F 0 "#PWR02" H 10200 3050 50  0001 C CNN
F 1 "GND" H 10200 3150 50  0000 C CNN
F 2 "" H 10200 3300 50  0000 C CNN
F 3 "" H 10200 3300 50  0000 C CNN
	1    10200 3300
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR03
U 1 1 50827367
P 10200 3500
F 0 "#PWR03" H 10200 3250 50  0001 C CNN
F 1 "GND" H 10200 3350 50  0000 C CNN
F 2 "" H 10200 3500 50  0000 C CNN
F 3 "" H 10200 3500 50  0000 C CNN
	1    10200 3500
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR04
U 1 1 5082736D
P 10200 6200
F 0 "#PWR04" H 10200 5950 50  0001 C CNN
F 1 "GND" H 10200 6050 50  0000 C CNN
F 2 "" H 10200 6200 50  0000 C CNN
F 3 "" H 10200 6200 50  0000 C CNN
	1    10200 6200
	0    1    1    0   
$EndComp
$Comp
L power:+3.3V #PWR05
U 1 1 50827375
P 10200 800
F 0 "#PWR05" H 10200 650 50  0001 C CNN
F 1 "+3.3V" H 10200 940 50  0000 C CNN
F 2 "" H 10200 800 50  0000 C CNN
F 3 "" H 10200 800 50  0000 C CNN
	1    10200 800 
	0    -1   -1   0   
$EndComp
$Comp
L power:+5V #PWR06
U 1 1 50827384
P 10200 3700
F 0 "#PWR06" H 10200 3550 50  0001 C CNN
F 1 "+5V" H 10200 3840 50  0000 C CNN
F 2 "" H 10200 3700 50  0000 C CNN
F 3 "" H 10200 3700 50  0000 C CNN
	1    10200 3700
	0    -1   -1   0   
$EndComp
Text Label 10200 900  0    40   ~ 0
VBAT
Text Label 10200 1000 0    40   ~ 0
PC13
Text Label 10200 1100 0    40   ~ 0
PC14
Text Label 10200 1200 0    40   ~ 0
PC15
Text Label 10200 1300 0    40   ~ 0
PD0
Text Label 10200 1400 0    40   ~ 0
PD1
Text Label 10200 1500 0    40   ~ 0
RST
Text Label 10200 1600 0    40   ~ 0
PC0
Text Label 10200 1700 0    40   ~ 0
PC1
Text Label 10200 1800 0    40   ~ 0
PC2
Text Label 10200 1900 0    40   ~ 0
PC3
Text Label 10200 2000 0    40   ~ 0
PA0
Text Label 10200 2100 0    40   ~ 0
PA1
Text Label 10200 2200 0    40   ~ 0
PA2
Text Label 10200 2300 0    40   ~ 0
PA3
Text Label 10200 2400 0    40   ~ 0
PA4
Text Label 10200 2500 0    40   ~ 0
PA5
Text Label 10200 2600 0    40   ~ 0
PA6
Text Label 10200 2700 0    40   ~ 0
PA7
Text Label 10200 2800 0    40   ~ 0
PC4
Text Label 10200 2900 0    40   ~ 0
PC5
Text Label 10200 3000 0    40   ~ 0
PB0
Text Label 10200 3100 0    40   ~ 0
PB1
Text Label 10200 3200 0    40   ~ 0
PB2
Text Label 10200 3800 0    40   ~ 0
PB9
Text Label 10200 3900 0    40   ~ 0
PB8
Text Label 10200 4000 0    40   ~ 0
BOOT
Text Label 10200 4100 0    40   ~ 0
PB7
Text Label 10200 4200 0    40   ~ 0
PB6
Text Label 10200 4300 0    40   ~ 0
PB5
Text Label 10200 4400 0    40   ~ 0
PB4
Text Label 10200 4500 0    40   ~ 0
PB3
Text Label 10200 4600 0    40   ~ 0
PD2
Text Label 10200 4700 0    40   ~ 0
PC12
Text Label 10200 4800 0    40   ~ 0
PC11
Text Label 10200 4900 0    40   ~ 0
PC10
Text Label 10200 5000 0    40   ~ 0
PA15
Text Label 10200 5100 0    40   ~ 0
PA14
Text Label 10200 5200 0    40   ~ 0
PA13
Text Label 10200 5300 0    40   ~ 0
PA12
Text Label 10200 5400 0    40   ~ 0
PA11
Text Label 10200 5500 0    40   ~ 0
PA10
Text Label 10200 5700 0    40   ~ 0
PA8
Text Label 10200 5600 0    40   ~ 0
PA9
Text Label 10200 5800 0    40   ~ 0
PC9
Text Label 10200 5900 0    40   ~ 0
PC8
Text Label 10200 6000 0    40   ~ 0
PC7
Text Label 10200 6100 0    40   ~ 0
PC6
$Comp
L Device:R R?
U 1 1 5E0AC7E4
P 7200 2500
F 0 "R?" H 7270 2546 50  0000 L CNN
F 1 "R" H 7270 2455 50  0000 L CNN
F 2 "" V 7130 2500 50  0001 C CNN
F 3 "~" H 7200 2500 50  0001 C CNN
	1    7200 2500
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5E0AEDF3
P 7200 2900
F 0 "R?" H 7270 2946 50  0000 L CNN
F 1 "R" H 7270 2855 50  0000 L CNN
F 2 "" V 7130 2900 50  0001 C CNN
F 3 "~" H 7200 2900 50  0001 C CNN
	1    7200 2900
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5E0AF979
P 7200 3300
F 0 "R?" H 7270 3346 50  0000 L CNN
F 1 "R" H 7270 3255 50  0000 L CNN
F 2 "" V 7130 3300 50  0001 C CNN
F 3 "~" H 7200 3300 50  0001 C CNN
	1    7200 3300
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5E0B0023
P 7200 3700
F 0 "R?" H 7270 3746 50  0000 L CNN
F 1 "R" H 7270 3655 50  0000 L CNN
F 2 "" V 7130 3700 50  0001 C CNN
F 3 "~" H 7200 3700 50  0001 C CNN
	1    7200 3700
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5E0B06E1
P 7200 4400
F 0 "R?" H 7270 4446 50  0000 L CNN
F 1 "R" H 7270 4355 50  0000 L CNN
F 2 "" V 7130 4400 50  0001 C CNN
F 3 "~" H 7200 4400 50  0001 C CNN
	1    7200 4400
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5E0B0D79
P 7200 4850
F 0 "R?" H 7270 4896 50  0000 L CNN
F 1 "R" H 7270 4805 50  0000 L CNN
F 2 "" V 7130 4850 50  0001 C CNN
F 3 "~" H 7200 4850 50  0001 C CNN
	1    7200 4850
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5E0B137A
P 7200 5300
F 0 "R?" H 7270 5346 50  0000 L CNN
F 1 "R" H 7270 5255 50  0000 L CNN
F 2 "" V 7130 5300 50  0001 C CNN
F 3 "~" H 7200 5300 50  0001 C CNN
	1    7200 5300
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5E0B1B11
P 7200 5700
F 0 "R?" H 7270 5746 50  0000 L CNN
F 1 "R" H 7270 5655 50  0000 L CNN
F 2 "" V 7130 5700 50  0001 C CNN
F 3 "~" H 7200 5700 50  0001 C CNN
	1    7200 5700
	1    0    0    -1  
$EndComp
Wire Wire Line
	7200 2650 7200 2700
Wire Wire Line
	7200 3050 7200 3150
Wire Wire Line
	7200 4550 7200 4700
Wire Wire Line
	7200 5150 7200 5100
Wire Wire Line
	10500 3500 10200 3500
Wire Wire Line
	10400 4300 10500 4300
Wire Wire Line
	10200 3700 10500 3700
Wire Wire Line
	7200 5450 7200 5500
Wire Wire Line
	7200 5500 9250 5500
Wire Wire Line
	9250 5500 9250 3650
Connection ~ 7200 5500
Wire Wire Line
	7200 5500 7200 5550
$Comp
L power:GND #PWR?
U 1 1 5E0ED834
P 7200 5900
F 0 "#PWR?" H 7200 5650 50  0001 C CNN
F 1 "GND" H 7205 5727 50  0000 C CNN
F 2 "" H 7200 5900 50  0001 C CNN
F 3 "" H 7200 5900 50  0001 C CNN
	1    7200 5900
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5E0EDF01
P 7200 3850
F 0 "#PWR?" H 7200 3600 50  0001 C CNN
F 1 "GND" H 7205 3677 50  0000 C CNN
F 2 "" H 7200 3850 50  0001 C CNN
F 3 "" H 7200 3850 50  0001 C CNN
	1    7200 3850
	1    0    0    -1  
$EndComp
Wire Wire Line
	7200 5900 7200 5850
$Comp
L additional_libs:az822 U?
U 1 1 5E105335
P 7950 2400
F 0 "U?" H 7712 2379 50  0000 R CNN
F 1 "az822" H 7712 2470 50  0000 R CNN
F 2 "" H 7900 2550 50  0001 C CNN
F 3 "" H 7900 2550 50  0001 C CNN
	1    7950 2400
	-1   0    0    1   
$EndComp
$Comp
L additional_libs:az822 U?
U 1 1 5E106474
P 8800 2400
F 0 "U?" H 8562 2379 50  0000 R CNN
F 1 "az822" H 8562 2470 50  0000 R CNN
F 2 "" H 8750 2550 50  0001 C CNN
F 3 "" H 8750 2550 50  0001 C CNN
	1    8800 2400
	-1   0    0    1   
$EndComp
$Comp
L additional_libs:az822 U?
U 1 1 5E106E00
P 7850 4400
F 0 "U?" H 7612 4379 50  0000 R CNN
F 1 "az822" H 7612 4470 50  0000 R CNN
F 2 "" H 7800 4550 50  0001 C CNN
F 3 "" H 7800 4550 50  0001 C CNN
	1    7850 4400
	-1   0    0    1   
$EndComp
$Comp
L additional_libs:az822 U?
U 1 1 5E1076B7
P 8650 4400
F 0 "U?" H 8412 4379 50  0000 R CNN
F 1 "az822" H 8412 4470 50  0000 R CNN
F 2 "" H 8600 4550 50  0001 C CNN
F 3 "" H 8600 4550 50  0001 C CNN
	1    8650 4400
	-1   0    0    1   
$EndComp
Wire Wire Line
	7200 4250 7650 4250
Wire Wire Line
	7650 3850 8450 3850
Wire Wire Line
	8450 3850 8450 4250
Wire Wire Line
	7650 3850 7650 4250
Connection ~ 7650 4250
Wire Wire Line
	7850 4250 7850 3950
Wire Wire Line
	7850 3950 8200 3950
Wire Wire Line
	8200 3950 8200 4700
Wire Wire Line
	8200 4700 7200 4700
Connection ~ 7200 4700
Wire Wire Line
	8650 4250 8650 3850
Wire Wire Line
	8650 3850 9100 3850
Wire Wire Line
	9100 3850 9100 5100
Wire Wire Line
	9100 5100 7200 5100
Connection ~ 7200 5100
Wire Wire Line
	7200 5100 7200 5000
$Comp
L power:GND #PWR?
U 1 1 5E12BDDE
P 8000 4600
F 0 "#PWR?" H 8000 4350 50  0001 C CNN
F 1 "GND" H 8005 4427 50  0000 C CNN
F 2 "" H 8000 4600 50  0001 C CNN
F 3 "" H 8000 4600 50  0001 C CNN
	1    8000 4600
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5E12C41F
P 8800 4600
F 0 "#PWR?" H 8800 4350 50  0001 C CNN
F 1 "GND" H 8805 4427 50  0000 C CNN
F 2 "" H 8800 4600 50  0001 C CNN
F 3 "" H 8800 4600 50  0001 C CNN
	1    8800 4600
	1    0    0    -1  
$EndComp
Wire Wire Line
	7750 1800 8600 1800
Wire Wire Line
	7950 1950 8350 1950
Wire Wire Line
	8350 1950 8350 2700
Wire Wire Line
	8350 2700 7200 2700
Connection ~ 7200 2700
Wire Wire Line
	7200 2700 7200 2750
Wire Wire Line
	7750 2250 7200 2250
Wire Wire Line
	7200 2250 7200 2350
Wire Wire Line
	7750 2250 7750 1800
Connection ~ 7750 2250
Wire Wire Line
	7950 2250 7950 1950
Wire Wire Line
	8600 2250 8600 1800
Wire Wire Line
	8800 2250 8800 1800
Wire Wire Line
	8800 1800 9450 1800
Wire Wire Line
	9450 1800 9450 3050
Wire Wire Line
	9450 3050 7200 3050
Connection ~ 7200 3050
$Comp
L power:GND #PWR?
U 1 1 5E15C55F
P 8100 2600
F 0 "#PWR?" H 8100 2350 50  0001 C CNN
F 1 "GND" H 8105 2427 50  0000 C CNN
F 2 "" H 8100 2600 50  0001 C CNN
F 3 "" H 8100 2600 50  0001 C CNN
	1    8100 2600
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5E15D198
P 8950 2600
F 0 "#PWR?" H 8950 2350 50  0001 C CNN
F 1 "GND" H 8955 2427 50  0000 C CNN
F 2 "" H 8950 2600 50  0001 C CNN
F 3 "" H 8950 2600 50  0001 C CNN
	1    8950 2600
	1    0    0    -1  
$EndComp
Wire Wire Line
	8000 4250 8000 4200
Wire Wire Line
	10200 3300 10500 3300
Wire Wire Line
	7200 2250 7200 2200
$Comp
L power:+VDC #PWR?
U 1 1 5E1BB0C0
P 7200 2200
F 0 "#PWR?" H 7200 2100 50  0001 C CNN
F 1 "+VDC" H 7200 2475 50  0000 C CNN
F 2 "" H 7200 2200 50  0001 C CNN
F 3 "" H 7200 2200 50  0001 C CNN
	1    7200 2200
	1    0    0    -1  
$EndComp
$Comp
L power:+VDC GND
U 1 1 5E1BB867
P 7200 4250
F 0 "GND" H 7305 4384 50  0001 L CNN
F 1 "+VDC" H 7305 4338 50  0000 L CNN
F 2 "" H 7200 4250 50  0001 C CNN
F 3 "" H 7200 4250 50  0001 C CNN
	1    7200 4250
	1    0    0    -1  
$EndComp
Connection ~ 7200 2250
Connection ~ 7200 4250
Wire Wire Line
	7200 3450 7200 3500
Wire Wire Line
	8100 2100 8100 2250
Wire Wire Line
	10500 4100 8800 4100
Wire Wire Line
	8800 4100 8800 4250
Wire Wire Line
	10500 4200 8000 4200
Wire Wire Line
	9950 3000 9950 2250
Wire Wire Line
	9950 2250 8950 2250
Wire Wire Line
	9950 3000 10500 3000
Wire Wire Line
	10500 3100 9800 3100
Wire Wire Line
	9800 3100 9800 2100
Wire Wire Line
	9800 2100 8100 2100
Wire Wire Line
	7200 3500 9550 3500
Wire Wire Line
	9550 3500 9550 2000
Wire Wire Line
	9550 2000 10500 2000
Connection ~ 7200 3500
Wire Wire Line
	7200 3500 7200 3550
Wire Wire Line
	10500 2400 9700 2400
Wire Wire Line
	9700 2400 9700 3650
Wire Wire Line
	9700 3650 9250 3650
$EndSCHEMATC