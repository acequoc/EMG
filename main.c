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
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC18LF14K22
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
#include "mcc_generated_files/adcc.h"
#include "comm.h"
#include "logger.h"
#include "mcc_generated_files/eusart1.h"
//#include "mcc_generated_files/adcc.h"
/*
                         Main application
 */
void main(void)
{   
    // Initialize the device
    SYSTEM_Initialize();

    //custom initialization
    //logger_initialize();
    ADCC_Initialize();
    EUSART1_Initialize();
    logger_initialize();
    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts
    // Use the following macros to:
    //char adc_array[6];
    //int data = 0;
    //int adc_data = 0;
    //int calc_data = 0;
    //int test_data = 4500;
    //char a[] = "AT\r\n";

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    
   //the MCU is ON 
    

    while (1)
    {
        // Add your application code
        if (EUSART1_is_rx_ready()) 
        {
            bt_message_handler();   
            /*if(EUSART1_is_tx_ready())
            {
                //ADCC_StartConversion(VOUT1);
                //while(!ADCC_IsConversionDone()){
                //printf("reading analog...\r\n");
                read_analog();
                //ADCC_StopConversion();}
            }*/
        }
        /*if(EUSART1_is_tx_ready()) 
        {
            //printf("reading analog...\r\n");
            read_analog();        
        }   */
        if(ADC_state == ADC_READY)
        {
            //printf("reading analog...");
            //ADCC_StopConversion();
            read_analog();
        }
    }
}
/**
 End of File
*/