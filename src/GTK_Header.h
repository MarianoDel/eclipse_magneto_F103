#ifndef GTK_HEADER_H_
#define GTK_HEADER_H_

#include <stm32f10x.h>
#include <stm32f10x_gpio.h>
#include <stm32f10x_rcc.h>
#include <stm32f10x_tim.h>
#include <stm32f10x_adc.h>
#include <stm32f10x_flash.h>
#include <stm32f10x_usart.h>
//#include <stm32f10x_exti.h>
#include <misc.h>
#include <math.h>

#include "string.h"
#include "stdio.h"
#include "GTK_Hard.h"
#include "timer.h"
#include "uart.h"
//#include "lcd.h"
#include "float.h"
//#include "flash_program.h"
#include "pwm.h"
#include "adc.h"
#include "GTK_Estructura.h"
#include "GTK_Signal.h"
#include "flash_program.h"
#include "GTK_Errors.h"

//--- PARA FUNCIONAR SIN ANTENA CONECTADA ---//
//#define FUNC_SIN_ANTENA_CH1
//#define WITH_TEMP_CH1

//--- PARA FRECUENCIA XTAL VER GTK_Hard.h ---//

enum resultados
{
	NO_INIT = 0,
	TRABAJANDO,
	FIN_OK,
	FIN_ERROR,
	FIN_TIMEOUT
};

enum bool
{
	FALSE = 0,
	TRUE = !FALSE
};

//Funciones de PWM.
#define PWM1_Init() PWM_TIM1_CONFIG (10, 1000, 0, 0, 0, 0, (PWM_CHANNEL_1 | PWM_CHANNEL_2))
#define PWM2_Init() PWM_TIM2_CONFIG (10, 1000, 0, 0, 0, 0, (PWM_CHANNEL_1 | PWM_CHANNEL_2))
#define PWM3_Init() PWM_TIM3_CONFIG (10, 1000, 0, 0, 0, 0, (PWM_CHANNEL_1 | PWM_CHANNEL_2 | PWM_CHANNEL_3 | PWM_CHANNEL_4))
#define PWM4_Init() PWM_TIM4_CONFIG (10, 1000, 0, 0, 0, 0, (PWM_CHANNEL_1 | PWM_CHANNEL_2 | PWM_CHANNEL_3 | PWM_CHANNEL_4))

#define PWM_CH1_TiempoSubida(d) 			PWM_TIM2_DUTY (d, PWM_CHANNEL_1)
#define PWM_CH1_TiempoMantenimiento(d) 		PWM_TIM2_DUTY (d, PWM_CHANNEL_2)
#define PWM_CH1_TiempoBajada(d) 			PWM_TIM1_DUTY (d, PWM_CHANNEL_1)

#define PWM_CH2_TiempoSubida(d) 			PWM_TIM1_DUTY (d, PWM_CHANNEL_2)
#define PWM_CH2_TiempoMantenimiento(d) 		PWM_TIM3_DUTY (d, PWM_CHANNEL_1)
#define PWM_CH2_TiempoBajada(d) 			PWM_TIM3_DUTY (d, PWM_CHANNEL_2)

#define PWM_CH3_TiempoSubida(d) 			PWM_TIM3_DUTY (d, PWM_CHANNEL_3)
#define PWM_CH3_TiempoMantenimiento(d) 		PWM_TIM3_DUTY (d, PWM_CHANNEL_4)
#define PWM_CH3_TiempoBajada(d) 			PWM_TIM4_DUTY (d, PWM_CHANNEL_1)

#define PWM_CH4_TiempoSubida(d) 			PWM_TIM4_DUTY (d, PWM_CHANNEL_2)
#define PWM_CH4_TiempoMantenimiento(d) 		PWM_TIM4_DUTY (d, PWM_CHANNEL_3)
#define PWM_CH4_TiempoBajada(d) 			PWM_TIM4_DUTY (d, PWM_CHANNEL_4)

//Funciones UART.
/*
#define UART_PC_Send(x) 	UART3Send(x)
#define UART_PC_Init() 		UART3_Config()
#define UART_PC_Receive()	UART3_Receive()

#define UART_CH1_Init()		UART1_Config()
#define UART_CH1_Send(data)	UART1Send(data)
#define UART_CH1_Receive()	UART1_Receive()

#define UART_CH2_Init()		UART2_Config()
#define UART_CH2_Send(data)	UART2Send(data)
#define UART_CH2_Receive()	UART2_Receive ()

#define UART_CH3_Init()		UART4_Config()
#define UART_CH3_Send(data)	UART4Send(data)
#define UART_CH3_Receive()	UART4_Receive ()

#define UART_CH4_Init()		UART5_Config()
#define UART_CH4_Send(data)	UART5Send(data)
#define UART_CH4_Receive()	UART5_Receive ()
*/
//CAMBIO MAGNETO V2.0 28-02-15
#define UART_PC_Init() 		UART1_Config()
#define UART_PC_Send(x) 	UART1Send(x)
#define UART_PC_Receive()	UART1_Receive()

#define UART_CH1_Init()		UART2_Config()
#define UART_CH1_Send(x)	UART2Send(x)
#define UART_CH1_Receive()	UART2_Receive()

#define UART_CH2_Init()		UART3_Config()
#define UART_CH2_Send(x)	UART3Send(x)
#define UART_CH2_Receive()	UART3_Receive ()

#define UART_CH3_Init()		UART4_Config()
#define UART_CH3_Send(x)	UART4Send(x)
#define UART_CH3_Receive()	UART4_Receive ()

#define UART_CH4_Init()		UART5_Config()
#define UART_CH4_Send(x)	UART5Send(x)
#define UART_CH4_Receive()	UART5_Receive ()
//FIN CAMBIO 28-02-15
#define GTK_HALF_FULL_MASK	0x01
#define GTK_SIN_TIME_MASK	0x02
#define GTK_BEEPER_MASK 	0x04
#define GTK_TICKER_MASK 	0x08

#endif