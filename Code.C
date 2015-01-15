#include <reg51.h>
#include<string.h>
sfr ldata=0x90;
unsigned char t;
sbit rs=P3^5;
sbit en=P3^4;
sbit sno2=P2^0;
sbit co=P2^1;
unsigned char i;
void lcdcmd(unsigned char value);
void lcddata(unsigned char value[]);
void MSDelay(unsigned int itime);
void lcd_init();
void main ()
{
       P2=0XFF;
       P1=0X00;
       P0=0X00;
       lcdcmd(0x38);
	   MSDelay (50);
	   lcdcmd(0x0E);
	   MSDelay (50);
	   lcdcmd(0x01);
	   MSDelay (50);
	   lcdcmd(0x06);
	   MSDelay (50);
	   lcdcmd(0x80);
	   MSDelay (50);

   while(1)
   {
      while(sno2==0&&co==0) 
	   {
	    lcd_init();
        lcddata("INDUSTRIAL ");
        lcd_init();
        lcddata("POLLUTION");
        lcd_init();
        lcddata("DETECTION SYSTEM");
        MSDelay (100);
        lcdcmd(0xC0);
        lcddata("LOW POLLUTION");
        MSDelay (100);
       }
   while(sno2==1&&co==0) 
      {
	   lcd_init();
       lcddata("SNO2 LEVEL-HIGH");
       MSDelay (100);
       lcdcmd(0xC0);
       lcddata("MEDIUM POLLUTION");
       MSDelay (100);
     }
   while(sno2==0&&co==1) 
      {
	   lcd_init();
       lcdcmd(0X80);
       MSDelay (50);
       lcddata("CO LEVEL-HIGH");
       MSDelay (100);
       lcdcmd(0xC0);
       lcddata("MEDIUM POLLUTION");
       MSDelay (100);
      }
   while(sno2==1&&co==1) 
      {
	   lcd_init();
       lcdcmd(0X80);
       MSDelay (50);
       lcddata("SN02+CO-100%");
       MSDelay (100);
       lcdcmd(0xC0);
       lcddata("HIGH POLLUTION");
       MSDelay (100);
     }
   }
}


void lcdcmd(unsigned char value)
{
     ldata=value;
	 rs=0;
	 en=1;
	 MSDelay(1);
	 en=0;
	 return;
}

 void lcddata(unsigned char value[])
{

    for(i=0;i<strlen(value);i++)
    {
     ldata=value[i];
	 rs=1;
	 en=1;
	 MSDelay(1);
	 en=0;
	 MSDelay(15);
    }

	 return;
 }
 void MSDelay(unsigned int itime)
 {
      unsigned int i,j;
	  for(i=0;i<itime;i++)
	      for(j=0;j<1275;j++);
}
void lcd_init(void) 
{
  lcdcmd(0x38); //setting 8-bit interface, 2 lines, 5*7 Pixels
  MSDelay(1);
  lcdcmd(0x0e); //turning on underline visible cursor
  MSDelay(1);     
  lcdcmd(0x01); //clearing screen
  lcdcmd(0x80); //m
}

