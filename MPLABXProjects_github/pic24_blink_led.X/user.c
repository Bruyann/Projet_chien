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

#include <stdint.h>          /* For uint32_t definition */
#include <stdbool.h>         /* For true/false definition */

#include "user.h"            /* variables/params used by user.c */
#include "system.h"
/******************************************************************************/
/* User Functions                                                             */
/******************************************************************************/

/* <Initialize variables in user.h and insert code for user algorithms.> */

/* TODO Initialize User Ports/Peripherals/Project here */

void InitApp(void)
{
    /* Setup analog functionality and port direction */

    /* Initialize peripherals */
    TRISAbits.TRISA0=0; //led clignote
    
    // COM
    /*
    TRISEbits.TRISE3=0; // RE3_COM
    TRISEbits.TRISE2=0; // RE2_COM
    TRISEbits.TRISE1=0; // RE1_COM
    TRISEbits.TRISE0=0; // RE0_COM
    TRISFbits.TRISF1=0; // RF1_COM
    TRISBbits.TRISB10=0; // RB10_COM
    TRISBbits.TRISB9=0; //  RB9_COM
    TRISBbits.TRISB8=0; //  TB8_COM
    
    // SEG
    TRISFbits.TRISF0=0; // RF0_SEG27
    TRISGbits.TRISG1=0; // RG1_SEG46
    TRISGbits.TRISG0=0; // RG0_SEG50
    TRISAbits.TRISA6=0; // RA6_SEG58
    TRISAbits.TRISA7=0; // RA7_SEG59
    TRISGbits.TRISG12=0; // RG12_SEG61
    TRISGbits.TRISG13=0; // RG13_SEG62
    */
    
}
void delay_ms(unsigned int milliseconds) {
    unsigned long count;
    for (count = 0; count < milliseconds; count++) {
        unsigned long cycles = FCY / 1000 / 2; // Calcul des cycles pour 1 ms
        while (cycles--) {
            asm("nop"); // No operation (attente d'une instruction)
        }
    }
}

void delay_us(unsigned int microseconds) {
    unsigned long cycles;
    while (microseconds--) {
        cycles = FCY / 1000000 / 2; // Calcul des cycles pour 1 µs
        while (cycles--) {
            asm("nop"); // No operation (attente d'une instruction)
        }
    }
}
