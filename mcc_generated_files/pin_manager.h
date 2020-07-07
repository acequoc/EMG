/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.0
        Device            :  PIC16LF18426
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.10 and above
        MPLAB 	          :  MPLAB X 5.35	
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set LED aliases
#define LED_TRIS                 TRISAbits.TRISA2
#define LED_LAT                  LATAbits.LATA2
#define LED_PORT                 PORTAbits.RA2
#define LED_WPU                  WPUAbits.WPUA2
#define LED_OD                   ODCONAbits.ODCA2
#define LED_ANS                  ANSELAbits.ANSA2
#define LED_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define LED_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define LED_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define LED_GetValue()           PORTAbits.RA2
#define LED_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define LED_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define LED_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define LED_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define LED_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define LED_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define LED_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define LED_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set VOUT1 aliases
#define VOUT1_TRIS                 TRISAbits.TRISA4
#define VOUT1_LAT                  LATAbits.LATA4
#define VOUT1_PORT                 PORTAbits.RA4
#define VOUT1_WPU                  WPUAbits.WPUA4
#define VOUT1_OD                   ODCONAbits.ODCA4
#define VOUT1_ANS                  ANSELAbits.ANSA4
#define VOUT1_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define VOUT1_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define VOUT1_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define VOUT1_GetValue()           PORTAbits.RA4
#define VOUT1_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define VOUT1_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define VOUT1_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define VOUT1_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define VOUT1_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define VOUT1_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define VOUT1_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define VOUT1_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set VOUT2 aliases
#define VOUT2_TRIS                 TRISAbits.TRISA5
#define VOUT2_LAT                  LATAbits.LATA5
#define VOUT2_PORT                 PORTAbits.RA5
#define VOUT2_WPU                  WPUAbits.WPUA5
#define VOUT2_OD                   ODCONAbits.ODCA5
#define VOUT2_ANS                  ANSELAbits.ANSA5
#define VOUT2_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define VOUT2_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define VOUT2_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define VOUT2_GetValue()           PORTAbits.RA5
#define VOUT2_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define VOUT2_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define VOUT2_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define VOUT2_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define VOUT2_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define VOUT2_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define VOUT2_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define VOUT2_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set VOUT3 aliases
#define VOUT3_TRIS                 TRISCbits.TRISC0
#define VOUT3_LAT                  LATCbits.LATC0
#define VOUT3_PORT                 PORTCbits.RC0
#define VOUT3_WPU                  WPUCbits.WPUC0
#define VOUT3_OD                   ODCONCbits.ODCC0
#define VOUT3_ANS                  ANSELCbits.ANSC0
#define VOUT3_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define VOUT3_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define VOUT3_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define VOUT3_GetValue()           PORTCbits.RC0
#define VOUT3_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define VOUT3_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define VOUT3_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define VOUT3_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define VOUT3_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define VOUT3_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define VOUT3_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define VOUT3_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set VOUT4 aliases
#define VOUT4_TRIS                 TRISCbits.TRISC1
#define VOUT4_LAT                  LATCbits.LATC1
#define VOUT4_PORT                 PORTCbits.RC1
#define VOUT4_WPU                  WPUCbits.WPUC1
#define VOUT4_OD                   ODCONCbits.ODCC1
#define VOUT4_ANS                  ANSELCbits.ANSC1
#define VOUT4_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define VOUT4_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define VOUT4_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define VOUT4_GetValue()           PORTCbits.RC1
#define VOUT4_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define VOUT4_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define VOUT4_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define VOUT4_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define VOUT4_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define VOUT4_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define VOUT4_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define VOUT4_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set VOUT5 aliases
#define VOUT5_TRIS                 TRISCbits.TRISC2
#define VOUT5_LAT                  LATCbits.LATC2
#define VOUT5_PORT                 PORTCbits.RC2
#define VOUT5_WPU                  WPUCbits.WPUC2
#define VOUT5_OD                   ODCONCbits.ODCC2
#define VOUT5_ANS                  ANSELCbits.ANSC2
#define VOUT5_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define VOUT5_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define VOUT5_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define VOUT5_GetValue()           PORTCbits.RC2
#define VOUT5_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define VOUT5_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define VOUT5_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define VOUT5_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define VOUT5_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define VOUT5_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define VOUT5_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define VOUT5_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set VOUT6 aliases
#define VOUT6_TRIS                 TRISCbits.TRISC3
#define VOUT6_LAT                  LATCbits.LATC3
#define VOUT6_PORT                 PORTCbits.RC3
#define VOUT6_WPU                  WPUCbits.WPUC3
#define VOUT6_OD                   ODCONCbits.ODCC3
#define VOUT6_ANS                  ANSELCbits.ANSC3
#define VOUT6_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define VOUT6_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define VOUT6_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define VOUT6_GetValue()           PORTCbits.RC3
#define VOUT6_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define VOUT6_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define VOUT6_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define VOUT6_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define VOUT6_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define VOUT6_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define VOUT6_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define VOUT6_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set RC4 procedures
#define RC4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define RC4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define RC4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define RC4_GetValue()              PORTCbits.RC4
#define RC4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define RC4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define RC4_SetPullup()             do { WPUCbits.WPUC4 = 1; } while(0)
#define RC4_ResetPullup()           do { WPUCbits.WPUC4 = 0; } while(0)
#define RC4_SetAnalogMode()         do { ANSELCbits.ANSC4 = 1; } while(0)
#define RC4_SetDigitalMode()        do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set RC5 procedures
#define RC5_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define RC5_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define RC5_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define RC5_GetValue()              PORTCbits.RC5
#define RC5_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define RC5_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define RC5_SetPullup()             do { WPUCbits.WPUC5 = 1; } while(0)
#define RC5_ResetPullup()           do { WPUCbits.WPUC5 = 0; } while(0)
#define RC5_SetAnalogMode()         do { ANSELCbits.ANSC5 = 1; } while(0)
#define RC5_SetDigitalMode()        do { ANSELCbits.ANSC5 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/