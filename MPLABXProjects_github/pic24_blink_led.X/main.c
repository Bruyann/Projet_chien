/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

/* Device header file */
#if defined(__XC16__)
    #include <xc.h>
#elif defined(__C30__)
    #if defined(__PIC24E__)
    	#include <p24Exxxx.h>
    #elif defined (__PIC24F__)||defined (__PIC24FK__)
	#include <p24Fxxxx.h>
    #elif defined(__PIC24H__)
	#include <p24Hxxxx.h>
    #endif
#endif

#include <stdint.h>        /* Includes uint16_t definition                    */
#include <stdbool.h>       /* Includes true/false definition                  */
#include <libpic30.h>
#include <stdio.h>      // Pour __delay_ms
#include "system.h"        /* System funct/params, like osc/peripheral config */
#include "user.h"          /* User funct/params, such as InitApp              */
#include "LCD.h"
#include "LCD_7seg.h"
/******************************************************************************/
/* Global Variable Declaration                                                */
/******************************************************************************/

/* i.e. uint16_t <variable_name>; */

/******************************************************************************/
/* Main Program                                                               */
/******************************************************************************/
#define RA0 LATAbits.LATA0
    // COM
#define RE3 LATEbits.LATE3 // RE3_COM
#define RE2 LATEbits.LATE2 // RE2_COM
#define RE1 LATEbits.LATE1 // RE1_COM
#define RE0 LATEbits.LATE0 // RE0_COM
#define RF1 LATFbits.LATF1 // RF1_COM
#define RB10 LATBbits.LATB10 // RB10_COM
#define RB9 LATBbits.LATB9 //  RB9_COM
#define RB8 LATBbits.LATB8 //  TB8_COM
    // SEG
#define RF0 LATFbits.LATF0 // RF0_SEG27
#define RG1 LATGbits.LATG1 // RG1_SEG46
#define RG0 LATGbits.LATG0 // RG0_SEG50
#define RA6 LATAbits.LATA6 // RA6_SEG58
#define RA7 LATAbits.LATA7 // RA7_SEG59
#define RG12 LATGbits.LATG12 // RG12_SEG61
#define RG13 LATGbits.LATG13 // RG13_SEG62

char val1='0';
char val2='0';
char val3='0';
char val4='0';
char val5='0';



int16_t main(void)
{

    /* Configure the oscillator for the device */
    ConfigureOscillator();

    /* Initialize IO ports and peripherals */
    InitApp();
    
    /* TODO <INSERT USER APPLICATION CODE HERE> */
    //LCD_CLEAR();
    //LCD_Init(); // Initialisation du LCD
    //COM
    /*
    RE3 = 1;
    RE1 = 0;
    RE0 = 0;
    RF1 = 0;
    RB10 = 0;
    RB9 = 0;
    RB8 = 0;
    //segment
    RF0 = 1;
    RG1 = 1;
    RG0 = 1;
    RA6 = 1;
    RA7 = 1;
    RG12 = 1;
    RG13 = 1;*/
    // microchip
    LCD_Initialize();
    LCD_SetPowerMode(LCD_POWER_MODE_HIGH);
    LCD_CLEAR();
    LCD_MICROCHIP1_On();
    
    LCD_CHAR1_Print(val1);
    LCD_CHAR2_Print(val2);
    LCD_CHAR3_Print(val3);
    LCD_CHAR4_Print(val4);
    LCD_CHAR5_Print(val5);
    //LCD_DOT1_On();
    //LCD_DOT2_On();
    //LCD_DOT3_On();
    
    
    LCD_ModeSet(LCD_MODE_NORMAL);
    LCD_MICROCHIP1_AltOn();
    
    int num=0;
    
    while(1)
    {
        //Nop();
        //led
        
        delay_ms(1000);
        RA0 = 1;
        
        num++;
        if (num > 12) num = 1;  // Limiter le cycle à 3 cas
        alterne_val(num, &val1, &val2, &val3, &val4, &val5);
        LCD_ECRITURE(num, val1, val2, val3, val4, val5);
        
        delay_ms(1000);
        //led
        RA0 = 0;
    }

}


void alterne_val(int num, char *val1, char *val2, char *val3, char *val4, char *val5) { 
    // Gestion des différents cas
    switch (num) {
        
        case 1:
            *val1 = 'S'; 
            *val2 = 'T'; 
            *val3 = 'A';      
            *val4 = 'R'; 
            *val5 = 'T'; 
            break;
        case 2:
            *val1 = '-'; 
            *val2 = 'C'; 
            *val3 = 'O'; 
            *val4 = '-'; 
            *val5 = '-'; 
            break;

        case 3:
            *val1 = '_'; 
            *val2 = '_'; 
            *val3 = '_';      
            *val4 = '_'; 
            *val5 = '%'; 
            break;

        case 4:
            *val1 = '-'; 
            *val2 = '0'; 
            *val3 = '2';      
            *val4 = '-'; 
            *val5 = '-'; 
            break;
            
        case 5:
            *val1 = '_'; 
            *val2 = '_'; 
            *val3 = '_';      
            *val4 = '_'; 
            *val5 = '%'; 
            break;

        case 6:
            *val1 = '-'; 
            *val2 = 'N'; 
            *val3 = 'O';      
            *val4 = '2'; 
            *val5 = '-'; 
            break;

        case 7:
            *val1 = '2'; 
            *val2 = '0'; 
            *val3 = '2';      
            *val4 = '4'; 
            *val5 = '%'; 
            break;
            
        case 8:
            *val1 = '-'; 
            *val2 = 'N'; 
            *val3 = 'H'; 
            *val4 = '3'; 
            *val5 = '-'; 
            break;

        case 9:
            *val1 = '_'; 
            *val2 = '_'; 
            *val3 = '_';      
            *val4 = '_'; 
            *val5 = '%'; 
            break; 

        case 10:
            *val1 = '-'; 
            *val2 = 'H'; 
            *val3 = '2';      
            *val4 = 'S'; 
            *val5 = '-'; 
            break;
            
        case 11:
            *val1 = '_'; 
            *val2 = '_'; 
            *val3 = '_';      
            *val4 = '_'; 
            *val5 = '%'; 
            break; 

        case 12:
            *val1 = '_'; 
            *val2 = 'F'; 
            *val3 = 'I';      
            *val4 = 'N'; 
            *val5 = '_'; 
            break;

        default:
            *val1 = *val2 = *val3 = *val4 = *val5 = '?';
            break;
    }
}

void LCD_ECRITURE(int num, char val1, char val2, char val3, char val4, char val5){
    
    if (num%2==1){
        LCD_CLEAR();
        LCD_MICROCHIP1_On();

        LCD_CHAR1_Print(val1);
        LCD_CHAR2_Print(val2);
        LCD_DOT2_On();
        LCD_CHAR3_Print(val3);
        LCD_CHAR4_Print(val4);
        LCD_CHAR5_Print(val5);

        LCD_ModeSet(LCD_MODE_NORMAL);
        LCD_MICROCHIP1_AltOn();
    }else{
        LCD_CLEAR();
        LCD_MICROCHIP1_On();

        LCD_CHAR1_Print(val1);
        LCD_CHAR2_Print(val2);
        LCD_CHAR3_Print(val3);
        LCD_CHAR4_Print(val4);
        LCD_CHAR5_Print(val5);

        LCD_ModeSet(LCD_MODE_NORMAL);
        LCD_MICROCHIP1_AltOn();
    }
    if (num==1)(LCD_DOT2_Off());

}


