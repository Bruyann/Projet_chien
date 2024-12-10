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
#include <libpic30.h>      // Pour __delay_ms
#include "system.h"        /* System funct/params, like osc/peripheral config */
#include "user.h"          /* User funct/params, such as InitApp              */

/******************************************************************************/
/* Global Variable Declaration                                                */
/******************************************************************************/

/* i.e. uint16_t <variable_name>; */


/******************************************************************************/
/* Main Program                                                               */
/******************************************************************************/
#define RA0 LATAbits.LATA0

void delay_ms(unsigned int milliseconds) {
    unsigned long count;
    for (count = 0; count < milliseconds; count++) {
        unsigned long cycles = FCY / 1000 / 2; // Calcul des cycles pour 1 ms
        while (cycles--) {
            asm("nop"); // No operation (attente d'une instruction)
        }
    }
}

int16_t main(void)
{

    /* Configure the oscillator for the device */
    ConfigureOscillator();

    /* Initialize IO ports and peripherals */
    InitApp();

    /* TODO <INSERT USER APPLICATION CODE HERE> */

    while(1)
    {
        //Nop();
        RA0 = 0;
        delay_ms(10000);
        RA0 = 1;
        delay_ms(1000);
        //Nop();
    }
}
