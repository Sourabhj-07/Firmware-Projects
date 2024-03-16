extern void delay_ms(unsigned int ms);

typedef unsigned short int u16;
typedef unsigned char u8;


extern void lcd_init(void);
extern void lcd_data(unsigned char );
extern void lcd_cmd(unsigned char cmd);
extern void lcd_string(unsigned char *);
extern void lcd_float(float f);
extern void lcd_integer (int );

extern void uart0_init(unsigned int baud);
extern void uart0_tx_string(unsigned char *ptr);
extern void uart0_tx_float(float num);

extern u16 adc_read(u8 ch_num);
extern void adc_init (void);
