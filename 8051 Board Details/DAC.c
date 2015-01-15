//-----------------------------------------------------------------------------------------------------//
// PROJECT NAME  -   DAC WITH I2C PROTOCOL
// AUTHOR MAIL     - bhau2727@gmail.com
// DATE OF ALTERED - 27/7/2011
// HARDWARE        - PCF 8591 WITH P89V51RD2 BASED 
// SOFTWARE        - INPUTS   HIGH LEVEL - 1 // LOW LEVEL - 0 //READ THE RESULT AT DAC PIN ON BOARD
//-----------------------------------------------------------------------------------------------------//
//----------------------------------HEADER Declarations--------------------------------------//
#include <reg51.h>

#include "dac8591.h"

//----------------------------------LCD Declarations--------------------------------------//
void initlcd(void);
void cmd_lcd(unsigned char command);
void data_lcd(unsigned char data2lcd);
void lcd_shortdelay(void);
void delay_ms(unsigned char milliseconds);
void printnum_lcd(unsigned char message, unsigned char row, unsigned char col);  //ascii to decimal
void printlcd(unsigned char *message, unsigned char row, unsigned char col);

sbit enable=P3^4;
sbit regsel=P3^5;
#define LCD_PORT P1

#define CLR_LCD cmd_lcd(0x01); delay_ms(5)
#define RETURN_HOME_LCD cmd_lcd(0x02); delay_ms(5)  

void delay_ms(unsigned char milliseconds);
//----------------------------------MAIN program--------------------------------------//

main()
{
	

	initlcd();									//lcd initialization
	printlcd("DAC TEST...",0,0);
    while(1)
    {
		int d = 0x50;
	    cmd_lcd(0x0c);		   				//cursor off
		for(;d<0xa0;d++)
		{
			if(d >=0x10)
	    		i2c_write(0x9E,0x40,d);				//write DAC RESULT to chip
			delay_ms(15);
		}
		//d++;
		for(d=0xa0;d>0x50;d--)
		{

			i2c_write(0x9E,0x40,d);				//write DAC RESULT to chip
			delay_ms(15);
		}
	
	}
}


//----------------------------------Init lcd--------------------------------------//
void initlcd()
{
	enable=0;
	delay_ms(20);
	cmd_lcd(0x30);
	delay_ms(5);
	cmd_lcd(0x30);
	cmd_lcd(0x30);
	cmd_lcd(0x38);
	cmd_lcd(0x08);
	CLR_LCD;
	cmd_lcd(0x06);
	cmd_lcd(0x0e);
}

void cmd_lcd(unsigned char command)
{
	LCD_PORT=command;
	regsel=0;
	enable=1;
	enable=0;
	lcd_shortdelay();
}
void data_lcd(unsigned char databyte)
{	
	LCD_PORT=databyte;
	regsel=1;
	enable=1;
	enable=0;
	lcd_shortdelay();
}
void lcd_shortdelay(void)
{
	unsigned char t=23;
	while(t--);
}
	
void delay_ms(unsigned char ms)
{
	unsigned char t1;
	unsigned int t2;

	for(t1=0; t1<ms; t1++){
		for(t2=0; t2<711; t2++);
	}
}
void printlcd(unsigned char *message, unsigned char row, unsigned char col)
{
   cmd_lcd(0x80 + (0x40*row) + col);
   
   for(; *message; message++)
      data_lcd(*message);
   
}
