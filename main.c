/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC12F1572
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"
#include "user.h"
#include "system.h"


#define DELAY_MS 150

const uint16_t trans[]={ 
        0b1111111111111111,
        0b0000000000001101,  //  A  
        0b0000000001010111,  //  B
        0b0000000001110111,  //  C  
        0b0000000000010111,  //  D  
        0b0000000000000001,  //  E  
        0b0000000001110101,  //  F  
        0b0000000000011111,  //  G  
        0b0000000001010101,  //  H  
        0b0000000000000101,  //  I  
        0b0000000011111101,  //  J  
        0b0000000000110111,  //  K  
        0b0000000001011101,  //  L  
        0b0000000000001111,  //  M  
        0b0000000000000111,  //  N  
        0b0000000000111111,  //  O  
        0b0000000001111101,  //  P  
        0b0000000011011111,  //  Q  
        0b0000000000011101,  //  R  
        0b0000000000010101,  //  S  
        0b0000000000000011,  //  T  
        0b0000000000110101,  //  U  
        0b0000000011010101,  //  V  
        0b0000000000111101,  //  W  
        0b0000000011010111,  //  X  
        0b0000000011110111,  //  Y  
        0b0000000001011111,  //  Z  
        0b0000000000000000   //  0  
        };

int morse(char *message) {
    for (uint8_t index = 0; message[index]; index++) {
        uint16_t morse_code = 0;
        uint8_t morse_char = message[index];
       
        if (morse_char == 0x20) {           // SPACE 
            __delay_ms (DELAY_MS * 7);
            continue;
        }
        
        morse_code = trans[morse_char & 0x1f];
        
        for (; morse_code; morse_code >>=2) {
            uint_fast8_t morse_bleep = morse_code & 0x03; 
            
            IO_LED_SetHigh ();
            while (morse_bleep--) {
                __delay_ms (DELAY_MS);
            }
            IO_LED_SetLow ();
            __delay_ms (DELAY_MS);

        }
        
        __delay_ms (3 * DELAY_MS);

    }
    
    return -1;
}

/*
                         Main application
 */
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

    // CGK code
    InitApp();
    ConfigureOscillator();
    
    while (1)
    {
        morse ("  s o s   sos sos sos");
        morse ("hello world");
        morse ("   ");
        morse ("Happy Birthday");
        IO_LED_Toggle ();
        __delay_ms (500);
        
    }
}
/**
 End of File
*/