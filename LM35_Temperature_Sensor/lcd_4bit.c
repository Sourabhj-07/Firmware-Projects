#include<LPC21xx.h>
#include "header.h"
#define RS (1<<17)  //P1.17
#define RW (1<<18)   //P1.18
#define EN (1<<19)  //P1.19
void lcd_data(unsigned char data)
{
	unsigned int temp=0;
	IOCLR1=0x00FE0000;  //clear P1.17 - P1.23
	temp=(data & 0xF0)<<16;  //higher nibble
	IOSET1=temp;
	IOSET1=RS;
	IOCLR1=RW;
	IOSET1=EN;
	delay_ms(2);   //lcd processing time
	IOCLR1=EN;
	
	IOCLR1=0x00FE0000;
	temp=(data & 0x0F)<<20; //lower nibble
	IOSET1=temp;
	IOSET1=RS;
	IOCLR1=RW;
	IOSET1=EN;
	delay_ms(2);
	IOCLR1=EN;
}

void lcd_cmd(unsigned char cmd)
{
	unsigned int temp=0;
	IOCLR1=0x00FE0000;
	temp=(cmd & 0xF0)<<16;
	IOSET1=temp;
	IOCLR1=RS;
	IOCLR1=RW;
	IOSET1=EN;
	delay_ms(2);
	IOCLR1=EN;
	
	
	IOCLR1=0x00FE0000;
	temp=(cmd & 0x0F)<<20;
	IOSET1=temp;
	IOCLR1=RS;
	IOCLR1=RW;
	IOSET1=EN;
	delay_ms(2);
	IOCLR1=EN;
}

void lcd_init(void)
{
	IODIR1 |=0x00FE0000;
	PINSEL2=0;
	lcd_cmd(0x03);  //enable first line
	lcd_cmd(0x02);  //init lcd in 4bits mode
	lcd_cmd(0x28);  //enable 2 rows
	lcd_cmd(0x0E);  //cursor on
	lcd_cmd(0x01);  //clr screen
}

void lcd_string(unsigned char *ptr)
{
	while(*ptr)
	{
		lcd_data(*ptr);
		ptr++;
	}
}
void lcd_float(float f)
{
	int n=f;
	lcd_integer(n);
	n=(f-n)*1000000;
	lcd_data('.');
	lcd_integer(n);
}
void lcd_integer (int num)
{
	int a[10],i;
	if(num==0)
	{
		lcd_data('0') ;
	}
	if(num<0)
	{
		lcd_data('-');
		num=-num;
		
	}
	i=0;
	while(num>0)
	{
		a[i]=num%10;
		num=num/10;
		i++;
	}
	for(i=i-1;i>=0;i--)
	{
		lcd_data(a[i]+48);
	}
}



