#include<LPC21xx.h>
#include"header.h"
void adc_init (void)
{
PINSEL1 |=0x15400000;
ADCR=0x00200400;
}
u16 adc_read (u8 ch_num)
{
u16 result=0;
ADCR |=(1<<ch_num);
ADCR |=(1<<24);
while(((ADDR>>31)&1)==0);
ADCR ^=(1<<24);
result=((ADDR>>6)&0x3FF);
ADCR ^=(1<<ch_num);
return result;
}