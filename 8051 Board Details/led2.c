//-----------------------------------------------------------------------------------------------------//
// PROJECT NAME    - LED TOGGLE
// AUTHOR MAIL     - bhau2727@gmail.com
// DATE OF ALTERED - 27/7/2011
// HARDWARE        - PCF 8591 WITH P89V51RD2 BASED 
// SOFTWARE        - INPUTS   HIGH LEVEL - 1 // LOW LEVEL - 0 //SWITCH2 AND SWITCH3 CONNECTED TO PORT 0's P0.6 AND P0.7
//                   LED1 AND LED2 CONNECTED TO PORT 1's P1.0 AND P1.1
//-----------------------------------------------------------------------------------------------------//

//----------------------------------HEADER Declarations--------------------------------------//
#include <REG51.H>

void delay_ms(unsigned int ms); //delay declarations

sbit SW1 = P1^0;  //switch 2
sbit SW2 = P1^1;  //switch 3

sbit LED1 = P0^7;  //led1
sbit LED2 = P0^6;  //led2

//----------------------------------main funtion--------------------------------------//
void main(void)
{
   LED1 = 0;  //initiate led zero
   LED2 = 0;  //initiate led zero
   while(1)
   {
      if(SW1 == 0)  //if switch 2 press led1 toggle
      {
         LED1 = ~LED1;
         delay_ms(500);
      }
      if(SW2 == 0)  //if switch 3 press led2 toggle
      {
         LED2 = ~LED2;
         delay_ms(500);
      }
   }
}

//----------------------------------delay defination----------------------------------//

void delay_ms(unsigned int ms)
{
   unsigned char t1;
   unsigned int t2;

   for(t1=0; t1<ms; t1++){
      for(t2=0; t2<711; t2++);
   }
}   
