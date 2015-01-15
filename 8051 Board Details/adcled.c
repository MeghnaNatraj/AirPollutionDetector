//-----------------------------------------------------------------------------------------------------//
// PROJECT NAME    - LED ON OFF FROM ADC WITH I2C PROTOCOL
// AUTHOR MAIL     - bhau2727@gmail.com
// DATE OF ALTERED - 27/7/2011
// HARDWARE        - PCF 8591 WITH P89V51RD2 BASED 
// SOFTWARE        - INPUTS   HIGH LEVEL - 1 // LOW LEVEL - 0 //READ ADC RESULT from channel 0. AND connect
//                   led2 to P0.0. , If Pot is varied - ON Delay timing will be varied 
//-----------------------------------------------------------------------------------------------------//

//----------------------------------HEADER Declarations--------------------------------------//
#include <reg51.h>

#include "adc8591.h"
void delay_us(unsigned int us);

sbit led2 = P0^0;
void main(void)
{
	
	led2 = 0;
	while(1)
    {
		unsigned char i,d;
		i2c_read(0x9E,0x40,&d);				//read ADC RESULT from channel 0 PUT 0X44
		while(d == 0)
		{
		//	i2c_read(0x9E,0x40,&d);				//read ADC RESULT from channel 0 PUT 0X44
			led2 = 0;
			delay_us(25);
			//if(d > 0)
			//break;		
		}
		d++;
		led2 = 1;
        for(i=0;i<d;i++)            // Delay
	  	{ 
			delay_us(1000);
		}
	//	i2c_read(0x9E,0x44,&d);
	    led2 = 0;
        for(i=0;i<d;i++)            // Delay
	  	{
	 		delay_us(950);
		}	
		d=0;
	}
}

void delay_us(unsigned int us)   // Delay Declarations...
{  
	unsigned int z;
	us = us;
	for(z=0;z<us;z++);           	
}
