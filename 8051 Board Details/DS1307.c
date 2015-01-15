//-----------------------------------------------------------------------------------------------------//
// PROJECT NAME    - RTC
// AUTHOR MAIL     - bhau2727@gmail.com
// DATE OF ALTERED - 27/7/2011
// HARDWARE        - PCF 8591 WITH P89V51RD2 BASED 
// SOFTWARE        - INPUTS   HIGH LEVEL - 1 // LOW LEVEL - 0 //FOR SET TIME CONNECTE TO PORT 0's P0.7
//                   TO LOW LEVEL
//-----------------------------------------------------------------------------------------------------//

//----------------------------------HEADER Declarations--------------------------------------//
#include <reg51.h>
#include "_DLY_R8C.c"
#include "_LCD_R8C.c"
#include "_I2C_R8C.c"
#include "_RTC_R8C.c"

sbit SET = P0^7;
//----------------------------------MAIN program--------------------------------------//
void main(void)
{

	lcd_init();    //intiate lcd 
	lcd_clear();

	ds1307_init();  //intiate ds1307

	lcd_printxy(1,1,"RTC...");  //display RTC on LCD first line
	delay_ms(1000);
	SET = 1;
	
	if(SET == 0)  // set time at first time only
	{
		ds1307_set_time(2,8,11,2,11,27,00);
	}
	
//aaa:	
	while(1)
	{
		
		ds1307_get_time();   //get the time from ds1307
		//lcd_clear();
		lcd_printxy(1,1,"DATE - ");//print date on lcd first line
		lcd_print_b(day);
		lcd_putchar('/');
		lcd_print_b(mth);
		lcd_putchar('/');
		lcd_print_b(year);
		lcd_printxy(2,1,"TIME - ");//print date on lcd second line
		lcd_print_b(hrs);
		lcd_putchar(':');
		lcd_print_b(min);
		lcd_putchar(':');
		lcd_print_b(sec);
		delay_ms(1000);
		//goto aaa;
    }
	
}


