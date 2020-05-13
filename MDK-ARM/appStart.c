#include "usb_device.h"
#include "main.h"

void changeColor(int8_t *color);
int translator(int8_t *buff);

enum colors{RED,
						YELLOW,
						GREEN,
						PINK,
						ENDOFLIST};

extern TIM_HandleTypeDef htim1;
extern int8_t color[];
int8_t tmpColor[128]={0};

void appStart(int8_t *buff){
		int8_t tmpColorBuf[128]="YELLOW";


		changeColor(buff);
	
		
}

void changeColor(int8_t *color){
	int tmpColor[20][3]={{10,20,30},{40,100,50},{100,35,15},{15,80,70},{100,100,50}};
	int pwm_pins[3]={TIM_CHANNEL_1,TIM_CHANNEL_2,TIM_CHANNEL_3};
		
	int tColor=translator(color);
	
	for(int i=0;i<3&&tColor<5;i++)
		{
			__HAL_TIM_SET_COMPARE(&htim1, pwm_pins[i], tmpColor[i][tColor]);
		}
}
	
int translator(int8_t *buff){
	
	int8_t colorDefine[5][128]={
								"1",
								"2",
								"3",
								"4"};
	int i=0;								
	for(;i<5;i++){
		if(strcmp((char*)colorDefine[i],(char*) buff)==0){
		break;
		}
	}
	
	return i;
}