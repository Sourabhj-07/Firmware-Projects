#include<lpc21xx.h>
#include"header.h"
main()
{
	u16 temp;   
	
	float vout,temperature;
	adc_init();      //adc initialzation
	lcd_init();      //lcd initialization
	IODIR0=1<<17;    //setting P0.17 as o/p direction
	IOSET0=1<<17;
	while(1)
	{
		temp=adc_read(1); //read Ain1
		vout=(temp*3.3)/1023;
		temperature=(vout-0.5)/0.01;
	
		lcd_cmd(0x80);  //setting cursor on 1st row 1st column
		lcd_cmd(0x01);
		lcd_string("T = ");
		lcd_float(temperature);
		delay_ms(1000);   //1sec delay

		 if(temperature<30)   //temperature below 30°C
		 {
			IOCLR0=1<<17;   
			delay_ms(250); //250 milisec delay
			IOSET0=1<<17;
			delay_ms(250);


		 }
		 else if(temperature>30) //temperature above 30°C
		{
		IOCLR0=1<<17;
		delay_ms(500);  //500 milisec delay
		IOSET0=1<<17;
		delay_ms(500);

		}

	}
}
