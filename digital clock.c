#include<avr/io.h>
#include<util/delay.h>
void lcdcmd(char x)
{
	
	PORTD=x;
	PORTC=0b00000100;
	_delay_ms(100);
	PORTC=0b00000000;
	_delay_ms(100);
}

void lcddata(char x)
{
	PORTD=x;
	PORTC=0b00000101;
	_delay_ms(100);
	PORTC=0b00000001;
	_delay_ms(100);
	
}
void display(char y[])
{
	int i;
	for(i=0;y[i]!='\0';i++)
	
	{
		lcddata(y[i]);
	}
}

void main()
{ int a,b,c;char d[10],e[10],f[10];
	DDRC=0b11111111;
	DDRD=0b11111111;
	while(1)
	{
		lcdcmd(0x38);
		lcdcmd(0x0E);
		lcdcmd(0x01);
		for(a=1;a<=12;a++)
		{
			for(b=0;b<=59;b++)
			{
				for(c=0;c<=59;c++)
			{
				
			itoa(a,d,10);
			itoa(b,e,10);
			itoa(c,f,10);
			display(d:e:f);
			_delay_ms(2000);
			lcdcmd(0x01);
		}
			}		
}

		}
	}		