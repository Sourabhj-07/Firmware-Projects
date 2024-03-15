#include<LPC21xx.h>
#include "header.h"
#define RS (1<<17)
#define RW (1<<18)
#define EN (1<<19)
void lcd_data(unsigned char data)
{
	unsigned int temp=0;
	IOCLR1=0x00FE0000;
	temp=(data & 0xF0)<<16;
	IOSET1=temp;
	IOSET1=RS;
	IOCLR1=RW;
	IOSET1=EN;
	delay_ms(2);
	IOCLR1=EN;
	
	IOCLR1=0x00FE0000;
	temp=(data & 0x0F)<<20;
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
	lcd_cmd(0x03);
	lcd_cmd(0x02);
	lcd_cmd(0x28);
	lcd_cmd(0x0E);
	lcd_cmd(0x01);
}

void lcd_string(unsigned char *ptr)
{
	while(*ptr)
	{
		lcd_data(*ptr);
		ptr++;
	}
}

