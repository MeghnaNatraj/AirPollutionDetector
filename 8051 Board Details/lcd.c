//-----------------------------------------------------------------------------------------------------//
// PROJECT NAME    - LCD TEST
// AUTHOR MAIL     - bhau2727@gmail.com
// DATE OF ALTERED - 27/7/2011
// HARDWARE        - PCF 8591 WITH P89V51RD2 BASED 
// SOFTWARE        - INPUTS   HIGH LEVEL - 1 // LOW LEVEL - 0 //ENABLE AND REGSEL PIN PORT 3's P3.4 AND P3.5
//                   R/W PIN CONNECTED TO GROUND
//-----------------------------------------------------------------------------------------------------//

//----------------------------------HEADER Declarations--------------------------------------//
#include <reg51.h>
#include <string.h>
//----------------------------------LCD Declarations--------------------------------------//
void initlcd(void);
void cmd_lcd(unsigned char command);
void data_lcd(unsigned char data2lcd);
void lcd_shortdelay(void);
void delay_ms(unsigned int milliseconds);

#define CLR_LCD cmd_lcd(0x01); delay_ms(5)
#define RETURN_HOME_LCD cmd_lcd(0x02); delay_ms(5)  
#define LCD_PORT P1

sbit enable=P3^4;
sbit regsel=P3^5;

void data_mode(void);

void printlcd(unsigned char *message, unsigned char row, unsigned char col);


//----------------------------------MAIN PROGRAM--------------------------------------//

void main(void)
{
    initlcd(); //init lcd
   
    while(1)
    {
   
     	printlcd(" LCD TEST.. ", 0, 0); //print on lcd frist line
     	cmd_lcd(0x0C);       //currsor off
     	delay_ms(1000);
	 	CLR_LCD;
	 	delay_ms(1000);
     	RETURN_HOME_LCD;
 	}
}

//----------------------------------LCD funtions--------------------------------------//

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

void printlcd(unsigned char *message, unsigned char row, unsigned char col)
{
   cmd_lcd(0x80 + (0x40*row) + col);
   
   for(; *message; message++)
      data_lcd(*message);
   
}

void lcd_shortdelay(void)
{
   unsigned char t=23;
   while(t--);
}
   
void delay_ms(unsigned int ms)
{
   unsigned char t1;
   unsigned int t2;

   for(t1=0; t1<ms; t1++){
      for(t2=0; t2<711; t2++);
   }
}