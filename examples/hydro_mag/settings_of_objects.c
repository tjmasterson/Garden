/*
* @file CoreSettings.h
* Copyright (C) 2015 Cory J. Potter - All Rights Reserved
* You may use, distribute and modify this code under the
* terms of the LICENSE.txt
* NOT INTENDED FOR COMMERCIAL USE!
* You should have received a copy of the LICENSE.txt with
* this file. If not, please write to: <bitsandbots@gmail.com>
*/

#ifndef __CORESETTINGS_H__
#define __CORESETTINGS_H__

#ifdef ARDUINO

// RX_PIN 3 in use by Dallas Temperature Probe
#define RX_PIN 103
#define TONE_PIN 104
#define TX_PIN 8

// What is our address 1 or 2
uint8_t node_address = 1;
uint8_t totalNodes = 3;
unsigned long lastRxTimeStamp = 0;

const uint64_t nRFbaseAddress = 1034834473100;
uint8_t nRFaddress = 0; // 00 - 255

// NOTE: the "LL" at the end of the constant is "LongLong" type
// 1034834473185, 1034834473170
// const uint64_t tx_pipes[5] = { 0xF0F0F0F0E1LL, 0xF0F0F0F0D2LL, 0xF0F0F0F141LL, 0xF0F0F0F1B0LL, 0xF0F0F0F1BBLL };
// const uint64_t rx_pipes[5] =  { 0xF0F0F0F22ALL, 0xF0F0F0F299LL, 0xF0F0F0F308LL, 0xF0F0F0F377LL, 0xF0F0F0F3E6LL };

// uint64_t tx_pipes[3] = { 0xF0F0F0F0E8LL, 0xF0F0F0F0E7LL, 0xF0F0F0F0E6LL };
// uint64_t rx_pipes[3] =  {0xF0F0F0F0E1LL, 0xF0F0F0F0E2LL, 0xF0F0F0F0E3LL };

uint64_t tx_pipes[3] =  { 0xF0F0F0F0F8LL, 0xF0F0F0F0F7LL, 0xF0F0F0F0F6LL };
uint64_t rx_pipes[3] =  { 0xF0F0F0F0F1LL, 0xF0F0F0F0F2LL, 0xF0F0F0F0F3LL };

/************************************************************************/
// Wirelessly Controlled Outlet Switches
/************************************************************************/
// ETEKCITY #1401
// unsigned long mySwitchOn[] = { 24, 1398067,1398211,1398531 };
// unsigned long mySwitchOff[] = { 24, 1398076,1398220,1398540 };
// ETEKCITY #1405
// unsigned long mySwitchOn[] = { 24,1135923,1136067,1136387 };
// unsigned long mySwitchOff[] = { 24,1135932,1136076,1136396 };
// ETEKCITY #1406
// unsigned long mySwitchOn[] = { 24,4281651,4281795,4282115 };
// unsigned long mySwitchOff[] = { 24,4281660,4281804,4282124 };
// ETEKCITY #1407
// unsigned long mySwitchOn[] = { 24,87347,87491,87811 };
// unsigned long mySwitchOff[] = { 24,87356,87500,87820 };
// ETEKCITY #1411
// unsigned long mySwitchOn[] = { 24,283955,284099,284419 };
// unsigned long mySwitchOff[] = { 24,283964,284108,284428 };
// ETEKCITY #1415
// unsigned long mySwitchOn[] = { 24,21811,21955,22275,23811,29955 };
// unsigned long mySwitchOff[] = { 24,21820,21964,22284,23820,29964 };
// ETEKCITY #1419
// unsigned long mySwitchOn[] = {24,333107,333251,333571,335107,341251};
// unsigned long mySwitchOff[] = {24,333116,333260,333580,335116,341260};
// ETEKCITY #0319
uint8_t totalSwitches = 5;
unsigned long mySwitchOn[] = {24,333107,333251,333571,335107,341251};
unsigned long mySwitchOff[] = {24,333116,333260,333580,335116,341260};

/************************************************************************/
/*	I2C Communications                                                  */
/************************************************************************/
const int MY_ADDRESS = 42;
const int SEND_TO_ADDRESS = 22;
/************************************************************************/
/*  Timers			                                            		*/
/************************************************************************/
//Timer Object = { (type), (interval in millis), ready, triggered, timestamp, (pointer to next object)
Timer Timer_txData 			= { TIMER_TX_DATA, 30000UL, true, false, 0, NULL };
// Timer Timer_Lcd 			= { TIMER_LCD, 12000UL, true, false, 0, &Timer_Log };
// Timer Timer_Lcd_Cycle 		= {	TIMER_LCD_CYCLE, 6000UL, true, false, 0, &Timer_Lcd };
// Timer Timer_Lcd_Scroller 	= { TIMER_LCD_SCROLLER, 500UL, true, false, 0, &Timer_Lcd_Cycle };
//Timer Timer_Ping			= { TIMER_SENSOR_READINGS, 10UL, true, false, 0, &Timer_Log };
//Timer Timer_Lite			= { TIMER_LITE, 180000UL, true, false, 0, &Timer_Ping };
Timer Timer_Save_Settings 	= {	TIMER_SAVE_SETTINGS, 3600000UL, true, false,  0, &Timer_txData };
//Timer Timer_Sensor_Read		= { TIMER_SENSOR_READINGS, 7000UL, true, false,  0, &Timer_Save_Settings };
//Timer Timer_Alerts			= { TIMER_ALERTS, 45000UL, true, false,  0, &Timer_Sensor_Read };
Timer Timer_rxData			= { TIMER_RX_DATA, 6000UL, true, false, 0, &Timer_Save_Settings };

/************************************************************************/
//  Initialize Appliances
/************************************************************************/
Appliance Appliance_Light_1		= {101, 1, APPLIANCE_LIGHT, DEFAULT_TIME, true, false, OFF, NULL };
// Appliance Appliance_Light_2		= {102, 0, APPLIANCE_LIGHT, DEFAULT_TIME, true, false, OFF, &Appliance_Light_1 };
// Appliance Appliance_Light_3		= {103, 0, APPLIANCE_LIGHT, DEFAULT_TIME, true, false, OFF, &Appliance_Light_2 };
Appliance Appliance_IntakeFan   = {104, 1, APPLIANCE_INTAKE_FAN, DEFAULT_TIME, true, false, OFF, &Appliance_Light_1 };
Appliance Appliance_ExhaustFan  = {103, 1, APPLIANCE_EXHAUST_FAN, DEFAULT_TIME, true, false, OFF, &Appliance_IntakeFan };
Appliance Appliance_Humidifier  = {102, 0, APPLIANCE_HUMIDIFIER, DEFAULT_TIME, true, false, OFF, &Appliance_ExhaustFan };
Appliance Appliance_Heater		= {101, 0, APPLIANCE_HEATER, DEFAULT_TIME, true, false, OFF, &Appliance_Humidifier };
//Appliance Appliance_AirPump		= {PIN4, 2, APPLIANCE_PUMP, DEFAULT_TIME, true, false, OFF,  &Appliance_Heater };
Appliance Appliance_FeedPump	= {105, 1, APPLIANCE_PUMP, DEFAULT_TIME, true, false, OFF,  &Appliance_Heater };
uint8_t totalAppliances = 6;

/************************************************************************/
// Initialize Sensors
/************************************************************************/
//Sensor: = { pin; node_address; SENSOR_TYPE; freq; minVal; maxVal; UL timestamp; float value; struct Sensor *next; }
// NULL for the first - We cannot point to an object hasn't been created yet.
Sensor Sensor_Photocell		= { PIN_A0, 1, SENSOR_PHOTO, 100, 50, 100, 0, 25, NULL };
Sensor Sensor_Temp			= { PIN7, 1, SENSOR_TEMPF, 50, 70, 80, 0, 75, &Sensor_Photocell };
Sensor Sensor_Humidity		= {PIN7, 1, SENSOR_HUMIDITY, 50, 40, 70, 0, 50, &Sensor_Temp };
Sensor Sensor_WaterTemp		= {PIN3_INT1, 1, SENSOR_WATER_TEMPF, 100, 50, 70, 0, 65, &Sensor_Humidity };
Sensor Sensor_Flow			= {PIN2_INT0, 2, SENSOR_FLOW, 100, 50, 50, 0, 75, &Sensor_WaterTemp };
//Sensor Sensor_Microphone	= {PIN_A1, 0, SENSOR_SOUND, 60, 10, 100, 0, 75, &Sensor_Flow };
//Sensor Sensor_Ultrasonic	= {PIN_A2, 0, SENSOR_ULTRASONIC, 60, 10, 100, 0, 75, &Sensor_Microphone };
//Sensor Sensor_PIR			= {PIN_A2, 0, SENSOR_PHOTO, 60, 10, 100, 0, 75, &Sensor_Microphone };
//Sensor Sensor_Moisture	= {PIN_A2, 0, SENSOR_MOISTURE, 60, 10, 100, 0, 75, &Sensor_Flow };
Sensor Sensor_Float			= {PIN_A2, 1, SENSOR_FLOAT, 100, 0, 1, 0, 1, &Sensor_Flow };
Sensor Sensor_Voltage		= {PIN1_TX, 1, SENSOR_VOLTAGE, 100, 0, 100, 0, 50, &Sensor_Float };
uint8_t totalSensors = 7;

/************************************************************************/
