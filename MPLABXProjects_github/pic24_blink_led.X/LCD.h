/* 
 * File:   LCD.h
 * Author: brub9
 *
 * Created on 5 décembre 2024, 17:45
 */

#ifndef LCD_H
#define LCD_H

/**
 Section: Included Files
*/
#include "lcd_7seg.h"
#include "lcd_16seg.h"
#include "lcd_segments.h"

#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif
     
/**
 Section: Data Type Definitions
*/

/** LCD Operating Mode Definition
 
 @Summary 
   Defines the LCD operating mode.
 
 @Description
   This routine defines the LCD operating mode.
 
 Remarks:
   None
 */
enum LCD_MODE
{
    LCD_MODE_NORMAL,
    LCD_BLINK_PRIMARY_MEMORY,
    LCD_BLINK_SECONDARY_MEMORY_2,
    LCD_MODE_ALTERNATE,
    LCD_COLON_BLINK,
};

/** LCD Power Mode Definition
 
 @Summary 
   Defines the LCD power mode for reference ladder.
 
 @Description
   This routine defines the LCD power mode for reference ladder.
 
 Remarks:
   None
 */
enum LCD_POWER_MODE
{
    LCD_POWER_MODE_OFF = 0,
    LCD_POWER_MODE_LOW = 1,
    LCD_POWER_MODE_MEDIUM = 2,
    LCD_POWER_MODE_HIGH = 3
};

/**
 Section: Interface Routines
*/

/**
  @Summary
    Initializes the LCD module

  @Description
    This routine initializes the LCD module. This routine should only be called 
    once during system initialization.    

  @Preconditions
    None.

  @Param
    None.

  @Returns
    None.

  @Example
    <code>
    LCD_Initialize();
    </code>     
*/
void LCD_Initialize(void);

/**
  @Summary
    Sets LCD module power mode.
 
  @Description
    This routine sets the LCD module reference ladder
    power control.
 
  @Preconditions
    None.
 
  @Param
    powerMode   -   Power mode value for reference ladder.
 
  @Returns
    None.
 
  @Example
    <code>
    LCD_SetPowerMode (powerMode);
    </code>    
*/
void LCD_SetPowerMode (enum LCD_POWER_MODE powerMode);

/**
  @Summary
    Sets the operating mode for LCD module.

  @Description
    This routine sets the operating mode for LCD module.

  @Preconditions
    None.

  @Param
    mode -   Operating mode to be set for the LCD module.

  @Returns
    None.

  @Example
    <code>
    LCD_ModeSet(enum LCD_MODE mode);
    </code>     
*/
void LCD_ModeSet(enum LCD_MODE mode);
enum BATTERY_STATUS
{
    BATTERY_STATUS_FULL,
    BATTERY_STATUS_MEDIUM,
    BATTERY_STATUS_LOW,
    BATTERY_STATUS_CRITICAL,
    BATTERY_STATUS_UNKNOWN
};

/**
  @Summary
    This method prints the potentiometer value on the LCD screen

  @Description
    This method prints the updated potentiometer value on the LCD screen, this 
    method takes the potentiometer value as an input param.

  @Preconditions
    SEG and COM for LCD segment characters has to be pre assigned to display the
    pot values on the LCD screen, This method calls LCD driver method to display
    values on the LCD Screen.
  
  @Returns
    None

  @Param
    Potentiometer value to be printed on the screen
*/
void LCD_DEMO_PrintPot(uint16_t value);
/**
  @Summary
    This method prints the Time value on the LCD screen

  @Description
    This method prints the updated Time value on the LCD screen, this 
    method takes the Time value as hour and minutes as an input

  @Preconditions
    SEG and COM for LCD segment characters has to be pre assigned to display the
    Time value on the LCD screen, This method calls LCD driver method to display
    values on the LCD Screen.
  
 
  @Returns
    None

  @Param
    hour : Hour value to be printed on LCD
    min  : Minute value to be printed on LCD.
*/
void LCD_DEMO_PrintTime(uint8_t hour, uint8_t min);
/**
   @Summary
    This method prints the Temperature value on the LCD screen

  @Description
    This method prints the updated Temperature value on the LCD screen, this 
    method takes the Temperature value in Celsius as an input parameter. This 
    Method prints the temperature value both in Celsius and Fahrenheit in 
    an alternate mode

  @Preconditions
   SEG and COM for LCD segment characters has to be pre assigned to display the
   Temperature values on the LCD screen, This method calls LCD driver method to display
   values on the LCD Screen.
  
  @Returns
    None

  @Param
    Temperature in Celsius value to be printed on the screen
*/
void LCD_DEMO_PrintTemperature(double temp);
/**
  @Summary
    This method sets the Battery icon status on the LCD screen

  @Description
    This method takes the BATTERY_STATUS enum values as an input parameter and
    sets the battery status according to the status on the LCD screen

  @Preconditions
    SEG and COM for LCD segment characters has to be pre assigned to display the
    Battery status the LCD screen, This method calls LCD driver method to display
    values on the LCD Screen.
  
  @Returns
    None

  @Param
    BATTERY_STATUS enum value
*/
void LCD_DEMO_SetBatteryStatus(enum BATTERY_STATUS status);

/**
  @Summary
    This method prints the Voltage value on the LCD screen

  @Description
    This method prints the updated Voltage value on the LCD screen, this 
    method takes the Voltage value in V as an input parameter.

  @Preconditions
   SEG and COM for LCD segment characters has to be pre assigned to display the
   Voltage values on the LCD screen, This method calls LCD driver method to display
   values on the LCD Screen.
  
  @Returns
    None

  @Param
    Voltage in Volts value to be printed on the screen
*/
void LCD_DEMO_PrintVoltage(double voltage);
/*
  @Summary
    This method prints PIC24 and LCD alternately the LCD screen

  @Description
    This method prints PIC24 and LCD alternately the LCD screen

  @Preconditions
   SEG and COM for LCD segment characters has to be pre assigned to display the
   PIC24 and LCD values on the LCD screen, This method calls LCD driver method 
   to display values on the LCD Screen.
  
  @Returns
    None

  @Param
    None
*/
void LCD_DEMO_PrintPIC24(void);

/**
  @Summary
 Clears the LCD screen

  @Description
    This routine clear the LCD Screen

  @Preconditions
    None.

  @Param
   None
 
  @Returns
    None.

  @Example
   None 
*/

void LCD_CLEAR(void);
#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif

#endif //LCD_H

