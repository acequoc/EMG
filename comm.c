#include "comm.h"
#include "mcc_generated_files/mcc.h"


void _puts(char *pt)
{
    unsigned char index;
    index = 0;
    while(pt[index]) 
    {
        while(!EUSART1_is_tx_ready());
        EUSART1_Write(pt[index++]);        
    }
}

void write(unsigned char *pt, unsigned char length)
{
    unsigned char i;
    
    //while(EUSART1_is_tx_ready())
    //{
    for (i=0; i<length; i++) {
        while(!EUSART1_is_tx_ready());
        EUSART1_Write(pt[i]);
        //printf(pt[i]);
    }
    //while(!EUSART1_is_tx_done());
    //break;
    //}

    /*while(*_pt)
    {
        //while(!EUSART1_is_tx_ready());
        EUSART1_Write(*_pt++);
    }*/
}

void _sprintf(unsigned char *mess, unsigned short val)
{
    
  unsigned short aux;  
  //char *test="12345\n"; 
 
  //_mess = 1+'0';
  //value range 0.000 - 9.999
  
  aux = val%10;
  val /= 10;  
    
  mess[5] = 0x00;
  //mess[5] = '\n';
    
  mess[4] = (unsigned char)aux+'0';
    
  aux = val%10;
  val /= 10;
    
  mess[3] = (unsigned char)aux+'0';
    
  aux = val%10;
  val /= 10;
    
  mess[2] = (unsigned char)aux+'0';
  mess[1] = '.';
  mess[0] = (unsigned char)val+'0';  
 
  
 /* _mess[6] = '\0';
  
  aux = val%10;
  val /= 10;  
    
  //mess[5] = 0x00;
  _mess[5] = (unsigned char)aux+'0';
    
  aux = val%10;
  val /= 10;
    
  _mess[4] = (unsigned char)aux+'0';
    
  aux = val%10;
  val /= 10;
  _mess[3] = (unsigned char)aux+'0';
    
  _mess[2] = '.';
  _mess[1] = (unsigned char)val+'0';
  _mess[0] = ' ';  */
}

unsigned char _gets(unsigned char *pt, unsigned char length)
{
    unsigned char index;
    //read a line
    index = 0;
    while (index < length) {
        pt[index] = EUSART1_Read();
        if (pt[index] == 0x0a) {
            index --; //uncommented only if CR+LN
            return index; 
        } 
        index++;
    } 
    
    //error, buffer Overflow
    return 0;    
}
