/* 
 * File:   LCD.c
 * Author: brub9
 *
 * Created on 5 décembre 2024, 17:43
 */

#include <stdio.h>
#include <stdlib.h>
# include "p24FJ512GU410.h"
#include <string.h>
#include <ctype.h>
#include "system.h"
#include "user.h"
#include "LCD.h"
#include "lcd_7seg.h"
#include "lcd_16seg.h"
#include <xc.h>
/*
 * 
 */

// Initialisation du module LCD
#include <xc.h>
#include "lcd.h"

/**
 Section: Driver Interface Function Definitions
*/



//------------------------------------------------------------------------------
//Application related definitions
//------------------------------------------------------------------------------
#define LCD_CHAR_LOCATION_ONE   (uint8_t)1
#define LCD_CHAR_LOCATION_TWO   (uint8_t)2
#define LCD_CHAR_LOCATION_THREE (uint8_t)3
#define LCD_CHAR_LOCATION_FOUR  (uint8_t)4 
#define LCD_CHAR_LOCATION_FIVE  (uint8_t)5

#define TWELVE_HOUR_FORMAT     12
#define TWENTY_FOUR_HOUR_FORMAT 24

#define FAHRENHEIT_RATIO        (double)9/5
#define FAHRENHEIT_CORRECTION_VALUE		(double)0x20


static void LCD_PrintChar(char c, uint8_t location);
static void LCD_PrintCharAlternate(char c, uint8_t location);

static char print_buffer[10];







void LCD_Initialize()
{

    // Disable LCD module before configuring
    LCDCONbits.LCDEN = 0;

    //BIASMD 1/3 Bias mode; LP 1:1; WFT Type-A waveform; 
    LCDPS = 0x00;	
    //LRLAP High-Power mode; LRLBP High-Power mode; VLCD1PE Bias 1 level is internal; LCDCST Max contrast (Min Resistance); VLCD2PE Bias 2 level is internal; VLCD3PE Bias 3 level is internal; LRLAT Internal LCD reference ladder is always in B Power mode; LCDIRE enabled; 
    LCDREF = 0x80F0;	
    //CPEN disabled; CLKSEL disabled; 
    LCDREG = 0x00;	
    //SE04 disabled; SE15 disabled; SE05 disabled; SE02 disabled; SE13 disabled; SE03 enabled; SE14 disabled; SE00 disabled; SE11 disabled; SE01 disabled; SE12 disabled; SE10 disabled; SE08 disabled; SE09 disabled; SE06 disabled; SE07 disabled; 
    LCDSE0 = 0x08;	
    //SE30 disabled; SE26 disabled; SE16 disabled; SE27 enabled; SE24 disabled; SE25 disabled; SE22 disabled; SE23 disabled; SE20 disabled; SE31 disabled; SE21 disabled; SE19 disabled; SE17 disabled; SE18 disabled; SE29 disabled; 
    LCDSE1 = 0x800;	
    //SE40 disabled; SE41 disabled; SE37 disabled; SE38 disabled; SE35 disabled; SE46 enabled; SE36 disabled; SE33 disabled; SE44 disabled; SE34 disabled; SE45 disabled; SE42 disabled; SE32 disabled; SE43 disabled; SE39 disabled; 
    LCDSE2 = 0x4000;	
    //SE51 disabled; SE62 enabled; SE52 disabled; SE63 disabled; SE60 disabled; SE50 enabled; SE61 enabled; SE48 disabled; SE59 enabled; SE49 disabled; SE57 disabled; SE58 enabled; SE55 disabled; SE56 disabled; SE53 disabled; SE54 disabled; 
    LCDSE3 = 0x6C04;	
    //CS LPRC; SLPEN enabled; WERR disabled; LMUX 1/8 COM[7:0]; LCDSIDL continues to operate in CPU Idle mode; LCDEN disabled; 
    LCDCON = 0x0F;	

    //Enable memory clear
    LCDASTATbits.PMCLEAR = 1;
    LCDASTATbits.SMCLEAR = 1;

    //Disable memory clear
    LCDASTATbits.PMCLEAR = 0;
    LCDASTATbits.SMCLEAR = 0;

    //Enable secondary memory
    LCDASTATbits.SMEMEN = 1;

    // Enable LCD module
    LCDCONbits.LCDEN = 1;
}

void LCD_SetPowerMode(enum LCD_POWER_MODE powerMode)
{
    LCDREFbits.LRLBP = powerMode;
}

void LCD_ModeSet(enum LCD_MODE mode)
{
    switch(mode)
    {
        case LCD_MODE_NORMAL:
                    LCDACTRLbits.ELCDEN = 0;//Disable LCD enhanced Mode
                    break;

        //Blink All Pixels in Primary Memory            
        case LCD_BLINK_PRIMARY_MEMORY:
                    LCDACTRLbits.BLINKMODE = 0x0002;//Enable Blink Mode with all pixels
                    LCDASTATbits.DMSEL = 0x0000;//Primary memory as Display Memory 
                    LCDACTRLbits.BLINKFCS= 0x0001;
                    LCDFC1 = 0x0975;
                    LCDACTRLbits.ELCDEN = 1;//Enable LCD enhanced Mode
                    break;

        //Blink All Pixels in Secondary Memory
        case LCD_BLINK_SECONDARY_MEMORY_2:
                    LCDACTRLbits.BLINKMODE = 0x0002;//Enable Blink Mode with all pixels
                    LCDASTATbits.DMSEL = 0x0001;//Secondary memory as Display Memory 
                    LCDACTRLbits.BLINKFCS= 0x0001;
                    LCDFC1 = 0x0975;
                    LCDACTRLbits.ELCDEN = 1;//Enable LCD enhanced Mode
                    break;

        //Alternate With Continuous Switch Over 
        case LCD_MODE_ALTERNATE:
                    LCDACTRLbits.BLINKMODE = 0x0000;//Disable Blink Mode
                    LCDASTATbits.DMSEL = 0x0003;//Continuous switch over between primary and secondary memory
                    LCDACTRLbits.SMFCS = 0x0001;
                    LCDFC0 = 0x0975;
                    LCDACTRLbits.ELCDEN = 1;//Enable LCD enhanced Mode
                    break;

        //Blink Selected Pixels in Secondary Memory
        case LCD_COLON_BLINK:
                    LCDACTRLbits.BLINKMODE = 0x0001;//Enable Blink Mode with selected pixels
                    LCDASTATbits.DMSEL = 0x0000;//Primary memory as Display Memory 
                    LCDACTRLbits.BLINKFCS= 0x0001;
                    LCDFC1 = 0x0975;
                    LCDACTRLbits.ELCDEN = 1;//Enable LCD enhanced Mode
                    break;

        default:
                    break;
    }
}


void LCD_DEMO_PrintPot(uint16_t value) {
    
    memset(print_buffer, ' ', sizeof (print_buffer));
    sprintf(print_buffer, "%04i", value);
    LCD_CHAR1_Print(print_buffer[0]);
    LCD_CHAR2_Print(print_buffer[1]);
    LCD_CHAR3_Print(print_buffer[2]);
    LCD_CHAR4_Print(print_buffer[3]);
    LCD_CHAR5_Print(' ');
    LCD_ModeSet(LCD_MODE_NORMAL);
}

void LCD_DEMO_PrintTime(uint8_t hour, uint8_t minute) 
{  
    LCD_CLEAR();
    LCD_COLON1_On();
    LCD_MICROCHIP1_On();
    
    LCD_CHAR1_AltPrint(' ');   // 
    LCD_CHAR2_AltPrint(' ');   // 
    LCD_CHAR3_AltPrint(' ');   // 
    LCD_CHAR4_AltPrint(' ');   // 
    LCD_CHAR5_AltPrint(' '); // 
    
    LCD_MICROCHIP1_AltOff();
    
    memset(print_buffer, ' ', sizeof (print_buffer));
    if(hour > 12)
    {
        hour -= 12;
        LCD_CHAR5_Print('P');
    }
    else if(hour == 0)
    {
        hour = 12;
        LCD_CHAR5_Print('A');
    }
    else if(hour == 12)
    {
        LCD_CHAR5_Print('P');
    }
    else
    {
        LCD_CHAR5_Print('A');
    }
    sprintf(print_buffer, "%2i", hour);
    LCD_CHAR1_Print(print_buffer[0]);
    LCD_CHAR2_Print(print_buffer[1]);
    memset(print_buffer, ' ', sizeof (print_buffer));
    sprintf(print_buffer, "%02i", minute);
    LCD_CHAR3_Print(print_buffer[0]);
    LCD_CHAR4_Print(print_buffer[1]);
    
    LCD_COLON1_AltOn();
    LCD_ModeSet(LCD_COLON_BLINK);
}

void LCD_DEMO_PrintVoltage(double voltage) 
{
	LCD_ModeSet(LCD_MODE_NORMAL);
    
    memset(print_buffer, ' ', sizeof (print_buffer));

    sprintf(print_buffer, "%.3f", voltage);

    LCD_CLEAR();
    LCD_COLON1_Off();
    LCD_DOT1_Off();
    LCD_DOT2_Off();
    LCD_DOT3_Off();
    LCD_DOT4_Off();
    LCD_DOT5_Off();
    LCD_DOT6_Off();

    LCD_CHAR1_Print(print_buffer[0]);
    LCD_DOT1_On();
    LCD_CHAR2_Print(print_buffer[2]);
    LCD_CHAR3_Print(print_buffer[3]);
    LCD_CHAR4_Print(print_buffer[4]);
    LCD_CHAR5_Print('V');
}

void LCD_DEMO_SetBatteryStatus(enum BATTERY_STATUS status) 
{
    switch (status) {
        case BATTERY_STATUS_UNKNOWN:
            BATTERY1_A_Off();
            BATTERY1_B_Off();
            BATTERY1_C_Off();
            BATTERY1_D_Off();
            BATTERY1_A_AltOff();
            break;
            
        case BATTERY_STATUS_FULL:
            BATTERY1_A_On();
            BATTERY1_B_On();
            BATTERY1_C_On();
            BATTERY1_D_On();
            BATTERY1_A_AltOff();
            break;

        case BATTERY_STATUS_MEDIUM:
            BATTERY1_A_On();
            BATTERY1_B_Off();
            BATTERY1_C_On();
            BATTERY1_D_Off();
            BATTERY1_A_AltOff();
            break;

        case BATTERY_STATUS_LOW:
            BATTERY1_A_On();
            BATTERY1_B_Off();
            BATTERY1_C_Off();
            BATTERY1_D_Off();
            BATTERY1_A_AltOff();
            break;

        case BATTERY_STATUS_CRITICAL:
            BATTERY1_A_On();
            BATTERY1_B_Off();
            BATTERY1_C_Off();
            BATTERY1_D_Off();
            BATTERY1_B_AltOn();
            break;
        default:
            break;
    }
}

void LCD_DEMO_PrintTemperature(double temp) 
{
    unsigned int i;
    unsigned int character;

    /* Print the Celsius temperature */
    LCD_COLON1_Off();
    LCD_DOT5_On();
    LCD_DOT2_Off();
    memset(print_buffer, ' ', sizeof (print_buffer));
    sprintf(print_buffer, "%.3f", temp);
    character = 0;
    for (i = 0; i<sizeof (print_buffer); i++) {
        if (print_buffer[i] == '.') {
            switch (character) {
                case 1:
                    LCD_DOT1_On();
                    LCD_DOT2_Off();
                    LCD_DOT3_Off();
                    LCD_DOT4_Off();
                    break;
                case 2:
                    LCD_DOT1_Off();
                    LCD_DOT2_On();
                    LCD_DOT3_Off();
                    LCD_DOT4_Off();
                    break;
                case 3:
                    LCD_DOT1_Off();
                    LCD_DOT2_Off();
                    LCD_DOT3_On();
                    LCD_DOT4_Off();
                    break;
                default:
                    break;
            }
        } else {
            LCD_PrintChar(print_buffer[i], (character + LCD_CHAR_LOCATION_ONE));
            character++;
        }

        if (character >= LCD_CHAR_LOCATION_FOUR) {
            break;
        }
    }
    
    LCD_CHAR5_Print('C');
    
    /* Print the Fahrenheit temperature */
    LCD_COLON1_AltOff();
    LCD_DOT5_AltOff();
    LCD_DOT6_AltOff();
    LCD_MICROCHIP1_AltOn();
    
    /* convert C to F */
    temp = ((temp * FAHRENHEIT_RATIO) + FAHRENHEIT_CORRECTION_VALUE);
            
    memset(print_buffer, ' ', sizeof (print_buffer));

    sprintf(print_buffer, "%.3f", temp);

    character = 0;
    for (i = 0; i<sizeof (print_buffer); i++) {
        if (print_buffer[i] == '.') {
            switch (character) {
                case 1:
                    LCD_DOT1_AltOn();
                    LCD_DOT2_AltOff();
                    LCD_DOT3_AltOff();
                    LCD_DOT4_AltOff();
                    break;
                case 2:
                    LCD_DOT1_AltOff();
                    LCD_DOT2_AltOn();
                    LCD_DOT3_AltOff();
                    LCD_DOT4_AltOff();
                    break;
                case 3:
                    LCD_DOT1_AltOff();
                    LCD_DOT2_AltOff();
                    LCD_DOT3_AltOn();
                    LCD_DOT4_AltOff();
                    break;
                default:
                    break;
            }
        } else {
            LCD_PrintCharAlternate(print_buffer[i], (character + LCD_CHAR_LOCATION_ONE));
            character++;
        }

        if (character >= LCD_CHAR_LOCATION_FOUR) {
            break;
        }
    }
    
    LCD_CHAR5_AltPrint('F');
    LCD_ModeSet(LCD_MODE_ALTERNATE);
}

static void LCD_PrintChar(char data, uint8_t location) 
{
    switch (location) {
        case 1:
            LCD_CHAR1_Print(data);
            break;

        case 2:
            LCD_CHAR2_Print(data);
            break;

        case 3:
            LCD_CHAR3_Print(data);
            break;

        case 4:
            LCD_CHAR4_Print(data);
            break;

        default:
            break;
    }
}

static void LCD_PrintCharAlternate(char data, uint8_t location) 
{
    switch (location) {
        case 1:
            LCD_CHAR1_AltPrint(data);
            break;

        case 2:
            LCD_CHAR2_AltPrint(data);
            break;

        case 3:
            LCD_CHAR3_AltPrint(data);
            break;

        case 4:
            LCD_CHAR4_AltPrint(data);
            break;

        default:
            break;
    }
}

void LCD_CLEAR(void)
{
    LCD_LOW_POWER_Off();
    LCD_LOW_POWER_AltOff();
    BATTERY1_A_Off();
    BATTERY1_B_Off();
    BATTERY1_C_Off();
    BATTERY1_D_Off();
    
    BATTERY1_A_AltOff();
    BATTERY1_B_AltOff();
    BATTERY1_C_AltOff();
    BATTERY1_D_AltOff();
    
    LCD_COLON1_AltOff();
    LCD_COLON1_Off();
    LCD_DOT1_AltOff();
    LCD_DOT2_AltOff();
    LCD_DOT3_AltOff();
    LCD_DOT4_AltOff();
    LCD_DOT5_AltOff();
    LCD_DOT6_AltOff();
    
    LCD_DOT1_Off();
    LCD_DOT2_Off();
    LCD_DOT3_Off();
    LCD_DOT4_Off();
    LCD_DOT5_Off();
    LCD_DOT6_Off();
}