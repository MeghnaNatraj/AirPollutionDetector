//-----------------------------------------------------------------------------------------------------//
// PROJECT NAME  -  ADC WITH I2C PROTOCOL
// AUTHOR MAIL     - bhau2727@gmail.com
// DATE OF ALTERED - 27/7/2011
// HARDWARE        - PCF 8591 WITH P89V51RD2 BASED 
// SOFTWARE        - INPUTS   HIGH LEVEL - 1 // LOW LEVEL - 0 //READ ADC RESULT from channel 0,1,2,3
//-----------------------------------------------------------------------------------------------------//

//----------------------------------HEADER Declarations--------------------------------------//
#include <reg51.h>

#include "adc8591.h"

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

//----------------------------------ADC value--------------------------------------//
unsigned char ADC0,ADC1,ADC2,ADC3;

//----------------------------------MAIN program--------------------------------------//
main()
{
	unsigned char d[4];

	initlcd();									//lcd initialization
	printlcd("ADC...",0,0);
    while(1)
    {
	    cmd_lcd(0x0c);							//cursor off
    	
	    i2c_read(0x9E,0x41,&d[0]);				//read ADC RESULT from channel 0 PUT 0X44
		printnum_lcd(d[0], 1, 4*0);				//display on lcd
		ADC0 = d[0];

	    i2c_read(0x9E,0x42,&d[1]);				//read ADC RESULT from channel 1 PUT 0X45
		printnum_lcd(d[1], 1, 4*1);				//display on lcd
		ADC1 = d[1];

	    i2c_read(0x9E,0x43,&d[2]);				//read ADC RESULT from channel 2 PUT 0X46
		printnum_lcd(d[2], 1, 4*2);				//display on lcd
		ADC2 = d[2];

	    i2c_read(0x9E,0x44,&d[3]);				//read ADC RESULT from channel 3 PUT 0X47
		printnum_lcd(d[3], 1, 4*3);				//display on lcd
	    ADC3 = d[3];

	}
}

//----------------------------------Ascii to decimal--------------------------------------//

void printnum_lcd(unsigned char num, unsigned char row, unsigned char col)
{
	unsigned char x1, x2, dig3, dig4, dig5;
	unsigned int x3;
	cmd_lcd(0x80+(0x40*row)+ col);

	x3=num/100;
	x2=num%100;
	x1=x3%100;
	dig3=x1%10;
	dig4=x2/10;
	dig5=x2%10;	

	data_lcd(dig3+0x30);
	data_lcd(dig4+0x30);
	data_lcd(dig5+0x30);
}

//----------------------------------initialise lcd--------------------------------------//

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
