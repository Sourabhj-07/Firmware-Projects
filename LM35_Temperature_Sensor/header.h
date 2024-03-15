extern void delay_ms(unsigned int ms);
extern void delay_sec(unsigned int sec);

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned short int u16;


extern void lcd_cgram(void);
extern void lcd_init(void);
extern void lcd_data(unsigned char data);
extern void lcd_cmd(unsigned char cmd);
extern void lcd_string(unsigned char *);
extern void lcd_hex(u8 temp);
extern void lcd_float(float f);

extern void uart0_init(unsigned int baud);
extern void uart0_rx_string(unsigned char *ptr,int max_bytes);
extern void uart0_tx_string(unsigned char *ptr);
extern void uart0_tx(unsigned char data);
extern unsigned char uart0_rx(void);
extern void uart0_hex(u8 temp);
extern void uart0_tx_integer(short int num);
extern void uart0_tx_float(float num);

extern u16 adc_read(u8 ch_num);
extern void adc_init (void);