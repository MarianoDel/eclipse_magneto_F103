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

#define GTK_HALF_FULL_MASK	0x01
#define GTK_SIN_TIME_MASK	0x02
#define GTK_BEEPER_MASK 	0x04
#define GTK_TICKER_MASK 	0x08

#endif
