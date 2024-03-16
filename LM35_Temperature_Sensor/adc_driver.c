#include<LPC21xx.h>
#include"header.h"
void adc_init (void)
{
PINSEL1 |=0x15400000; //Po.27->Ain0
	                    //Po.28->Ain1
	                    //Po.29->Ain2
	                    //Po.30->Ain3
ADCR=0x00200400;      //diselect channels
	                    //ADC clock 3MHZ
	                    //10 bits resolution
}
u16 adc_read (u8 ch_num)
{
u16 result=0;
ADCR |=(1<<ch_num);  // select ch_num
ADCR |=(1<<24);
while(((ADDR>>31)&1)==0); 
ADCR ^=(1<<24);   //stop ADC
result=((ADDR>>6)&0x3FF);  //extract result
ADCR ^=(1<<ch_num);
return result;
}