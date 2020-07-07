#include "logger.h"
#include "mcc_generated_files/mcc.h"
#include "comm.h"
#include <stdlib.h>
#include <string.h>


volatile unsigned char message_format;

volatile unsigned short ADC_value;
volatile unsigned char ADC_state;
volatile unsigned char ADC_count;

volatile unsigned char TMR1_state;

volatile unsigned char WIFI_tx_buf[WIFI_TX_BUFFER_SIZE];
volatile unsigned char WIFI_tx_buf_ind;

adcc_channel_t channel = VOUT1;
/*typedef enum{
    bit10,
    bit12 
}ADCmode;
//ADCmode mode = bit10; 
ADCmode mode =bit12;*/

void logger_initialize(void)
{
    message_format = MESSAGE_BINARY; //ADC transmitted values default to binary
         
    ADC_state = ADC_IDLE;
    ADC_value = 0;
    ADC_count = 0;
    
    //ADCC_EnableContinuousConversion(); 
    
    TMR1_StopTimer();
    TMR1_state = TMR1_STOP;
    TMR1_SetInterruptHandler(_TMR1_Ready); //Redirect TMR1_ISR_handler to custom function
    
    
}

void bt_message_handler(void)
{
    unsigned char message;
    message = EUSART1_Read();
    process_message(message);
}

void process_message(unsigned char message)
{
       
    //Message handler
    switch (message) {
        case 't': //Test communications
            _puts("Ok\n");            
            break;
        
        case 'T': //toggle between binary data or text mode           
            toggle_format();
            break;
            
        case 's': //start continuous analog monitoring
            if (TMR1_state == TMR1_RUNNING)
                return;                     
            TMR1_StartTimer();
            TMR1_state = TMR1_RUNNING;
            //printf("timer start");
            break;
            
        case 'S': //stop continuous analog sampling              
            TMR1_StopTimer();
            TMR1_state = TMR1_STOP;
            ADCC_StopConversion();
            break;    
                           
       /* case 'm': // 10 bit mode
            mode = bit10; 
              _puts("10 bit mode\n"); 
            break;
            
        case 'M': // 12bit mode
            mode = bit12; 
             _puts("12 bit mode\n"); 
            break;
        
        case 'a':
            ADCC_StartConversion(channel);
            break;*/
            
        case '1':
            channel = VOUT1;
             //ADCC_StopConversion();   
            //ADCC_StartConversion(channel);
            //while(!ADCC_IsConversionDone());
            //ADC_state = ADC_READY;
            _puts("channel 1\n");
            //ADC_state = ADC_READY;
            //ADCC_StartConversion(channel);
            //ADCC_StopConversion();
            break;
            
        case '2':
            channel = VOUT2;
            //ADCC_StopConversion(); 
            //ADCC_StartConversion(VOUT2);   
            _puts("channel 2\n");
             break;
             
        case '3':
            channel = VOUT3;
            //ADCC_StopConversion(); 
            //ADCC_StartConversion(VOUT3);    
            _puts("channel 3\n");
            break;
            
        case '4':
            channel = VOUT4;
            //ADCC_StopConversion(); 
            //ADCC_StartConversion(VOUT4);    
            _puts("channel 4\n");
            break;
            
        case '5':
            channel = VOUT5;
            //ADCC_StopConversion(); 
            //ADCC_StartConversion(VOUT5);    
            _puts("channel 5\n");
            break;
            
        case '6':
            channel = VOUT6;
            //ADCC_StopConversion(); 
            //ADCC_StartConversion(VOUT6); 
            _puts("channel 6\n");
            break;
            
        default:
            break;            
    }
}

void read_analog()
{
    unsigned short adc_val;
    //unsigned char aux[2];
    unsigned long  aux1;
    //unsigned char *mess;
    //unsigned char test[]="12345\n";
    //unsigned char i;
    unsigned char mess[5];
   
    //adc_val = ADC_value;
    adc_val = ADC_value>>2;
    ADC_state = ADC_IDLE; //Reset flag!
   
    if (message_format == MESSAGE_BINARY) {    
       WIFI_tx_buf[WIFI_tx_buf_ind++] = (unsigned char)(adc_val & 0xff);
       WIFI_tx_buf[WIFI_tx_buf_ind++] = (unsigned char)((adc_val >> 8) & 0xff);
            
       if (WIFI_tx_buf_ind == WIFI_TX_BUFFER_SIZE) {
            write(WIFI_tx_buf,WIFI_TX_BUFFER_SIZE);                
            WIFI_tx_buf_ind = 0;
       }
    }
    
    //if(mode == bit12)
    else
    {
        //val_mv = ((unsigned long)adc_val*3300UL/1024UL); 
        aux1 = (unsigned long)(adc_val )*3300UL;
        adc_val = (unsigned short)(aux1 >> 10); //divides by 4096. Result is in mV
        _sprintf(mess,adc_val); // Takes a value in mV and returns a string in V with 3 decimals
        mess[5] = '\n';   
        write(mess,6);
        //write(test,6);
        
        /*while(EUSART1_is_tx_ready())
        {
            for(i=0; i< (unsigned char)sizeof(test);i++)
            {
                EUSART1_Write(test[i]);
            }
            break;
        }*/
            
        //write(mess,6);
        //__delay_ms(500);
    }
    /*else
    {//10bit adc
        aux1 = (unsigned long)(adc_val>>2)*3300UL;
        adc_val = (unsigned short)(aux1 >> 10); //divides by 1024. Result is in mV
        _sprintf(mess,adc_val); // Takes a value in mV and returns a string in V with 3 decimals
        mess[5] = '\n';
        //mess = &test;
        write(mess,6);
        //EUSART1_Write('Q');
    }*/
    //ADC_state = ADC_IDLE; //Reset flag!
    //ADCC_StartConversion(channel);
        
}

void toggle_format() 
{
    if (message_format == MESSAGE_BINARY) {
        message_format = MESSAGE_TEXT;
            _puts("tmode\n");
    } else {
        message_format = MESSAGE_BINARY;
            _puts("bmode\n");
    }
}
void _TMR1_Ready()
{   
    if (TMR1_state == TMR1_RUNNING) {  
        ADCON0bits.ADON = 0; //turn off the ADC
        ADCON0bits.ADON = 1; //turn on the ADC 
        //ADCC_StopConversion(); 
        ADCC_StartConversion(channel);
    }    
}







