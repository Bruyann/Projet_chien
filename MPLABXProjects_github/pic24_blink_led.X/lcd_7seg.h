/* 
 * File:   lcd_7seg.h
 * Author: brub9
 *
 * Created on 8 décembre 2024, 21:35
 */

#ifndef LCD_7SEG_H
#define LCD_7SEG_H

#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif

/**
 Section: Interface Routines
*/

/**
  @Summary
    Sets the 7 segment digit CHAR4 with the value.
  
  @Description
    This routine sets the 7 segment digit CHAR4 with the value.
  
  @Returns
    None
  
  @Param
    cData - The character data to be printed.
    
  @Example
    <code>
     LCD_CHAR4_Print(char cData);
    </code>
*/
void LCD_CHAR4_Print(char cData);

/**
  @Summary
    Sets the 7 segment digit CHAR4 with the value in the alternate mode.
  
  @Description
    Sets routine sets the 7 segment digit CHAR4 with the value. This is 
    used in blinking and alternate screen modes.  This sets which segments will 
    be active in this alternate functionality.
  
  @Returns
    None
  
  @Param
    cData - The character data to be printed.
    
  @Example
    <code>
     LCD_CHAR4_AltPrint(char cData);
    </code>
*/
void LCD_CHAR4_AltPrint(char cData);

/**
  @Summary
    Sets the 7 segment digit CHAR1 with the value.
  
  @Description
    This routine sets the 7 segment digit CHAR1 with the value.
  
  @Returns
    None
  
  @Param
    cData - The character data to be printed.
    
  @Example
    <code>
     LCD_CHAR1_Print(char cData);
    </code>
*/
void LCD_CHAR1_Print(char cData);

/**
  @Summary
    Sets the 7 segment digit CHAR1 with the value in the alternate mode.
  
  @Description
    Sets routine sets the 7 segment digit CHAR1 with the value. This is 
    used in blinking and alternate screen modes.  This sets which segments will 
    be active in this alternate functionality.
  
  @Returns
    None
  
  @Param
    cData - The character data to be printed.
    
  @Example
    <code>
     LCD_CHAR1_AltPrint(char cData);
    </code>
*/
void LCD_CHAR1_AltPrint(char cData);

/**
  @Summary
    Sets the 7 segment digit CHAR3 with the value.
  
  @Description
    This routine sets the 7 segment digit CHAR3 with the value.
  
  @Returns
    None
  
  @Param
    cData - The character data to be printed.
    
  @Example
    <code>
     LCD_CHAR3_Print(char cData);
    </code>
*/
void LCD_CHAR3_Print(char cData);

/**
  @Summary
    Sets the 7 segment digit CHAR3 with the value in the alternate mode.
  
  @Description
    Sets routine sets the 7 segment digit CHAR3 with the value. This is 
    used in blinking and alternate screen modes.  This sets which segments will 
    be active in this alternate functionality.
  
  @Returns
    None
  
  @Param
    cData - The character data to be printed.
    
  @Example
    <code>
     LCD_CHAR3_AltPrint(char cData);
    </code>
*/
void LCD_CHAR3_AltPrint(char cData);

/**
  @Summary
    Sets the 7 segment digit CHAR2 with the value.
  
  @Description
    This routine sets the 7 segment digit CHAR2 with the value.
  
  @Returns
    None
  
  @Param
    cData - The character data to be printed.
    
  @Example
    <code>
     LCD_CHAR2_Print(char cData);
    </code>
*/
void LCD_CHAR2_Print(char cData);

/**
  @Summary
    Sets the 7 segment digit CHAR2 with the value in the alternate mode.
  
  @Description
    Sets routine sets the 7 segment digit CHAR2 with the value. This is 
    used in blinking and alternate screen modes.  This sets which segments will 
    be active in this alternate functionality.
  
  @Returns
    None
  
  @Param
    cData - The character data to be printed.
    
  @Example
    <code>
     LCD_CHAR2_AltPrint(char cData);
    </code>
*/
void LCD_CHAR2_AltPrint(char cData);


#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif

#endif //LCD_7SEG_H
