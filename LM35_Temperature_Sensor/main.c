#include<lpc21xx.h>
#include"header.h"
#include<LPC21XX.H>
main()
{
	u16 temp;
	
	float vout,temperature;
	adc_init();
	uart0_init(9600);
	lcd_init();
	IODIR0=1<<17;
	IOSET0=1<<17;
	uart0_tx_string("ADC\r\n");
	while(1)
	{
		temp=adc_read(1);
		vout=(temp*3.3)/1023;
		temperature=(vout-0.5)/0.01;
		uart0_tx_string("\r\nTEMP=");
		uart0_tx_float(temperature);


		lcd_cmd(0x80);
		lcd_cmd(0x01);
		lcd_string("T = ");
		lcd_float(temperature);
		delay_ms(1000);

		 if(temperature<30)
		 {
			IOCLR0=1<<17;
			delay_ms(250);
			IOSET0=1<<17;
			delay_ms(240);


		 }
		 else if(temperature>30)
		{
		IOCLR0=1<<17;
		delay_ms(500);
		IOSET0=1<<17;
		delay_ms(500);

		}

	}
}