/* 
 * File:   lcd_16seg.h
 * Author: brub9
 *
 * Created on 8 décembre 2024, 21:36
 */

#ifndef LCD_16SEG_H
#define LCD_16SEG_H

#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif

/**
 Section: Interface Routines
*/

/**
  @Summary
    Sets the 16 segment digit CHAR5 with the value.
  
  @Description
    This routine sets the 16 segment digit CHAR5 with the value.
  
  @Returns
    None
  
  @Param
    cData - The character data to be printed.
    
  @Example
    <code>
     LCD_CHAR5_Print(char cData);
    </code>
*/
void LCD_CHAR5_Print(char cData);

/**
  @Summary
    Sets the 16 segment digit CHAR5 with the value in the alternate mode.
  
  @Description
    Sets routine sets the 16 segment digit CHAR5 with the value. This is 
    used in blinking and alternate screen modes.  This sets which segments will 
    be active in this alternate functionality.
  
  @Returns
    None
  
  @Param
    cData - The character data to be printed.
    
  @Example
    <code>
     LCD_CHAR5_AltPrint(char cData);
    </code>
*/
void LCD_CHAR5_AltPrint(char cData);


#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif

#endif //LCD_16SEG_H
