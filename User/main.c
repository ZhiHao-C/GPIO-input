#include "stm32f10x.h"                  // Device header
#include "bps_led.h"
#include "key.h"

uint8_t keynum;
uint8_t key;

void delay_ms(int n)//ÑÓÊ±º¯Êý
{
	int i;
	while (n--)
	{
		for(i=0;i<1;i++);
	}
}



int main()
{
	LED_R_GPIO_Config();
	LED_G_GPIO_Config();
	
	while (1)
	{
		KEY1_GPIO_Config();
		if(key_scan(KEY1_GPIO_PORT,KEY1_GPIO_PIN)==key_on)
		{
			LED_G_TOGGLE;
		}
		
		KEY2_GPIO_Config();
		
		key=key_scan(GPIOC,KEY2_GPIO_PIN);
//		if(key_scan(KEY2_GPIO_PORT,KEY2_GPIO_PIN)==key_on)
//		{
//			LED_R_TOGGLE;
//		}
//		
		
		if(key==key_on)
		{
			keynum=1-keynum;
			if(keynum==1)
			{
				LED_G_GPIO_PORT->ODR &=~0x20;
			}
			else if (keynum==0)
			{
				LED_G_GPIO_PORT->ODR|=0x20;
			}
		}
	}
}

