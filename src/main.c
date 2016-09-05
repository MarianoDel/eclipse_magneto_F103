#include "GTK_Header.h"

char buffSendErr[64];

#define TIME_RUN_DEF 250
unsigned short timeRun = TIME_RUN_DEF;

volatile unsigned char flagMuestreo = 0;
unsigned short adc0[4] = {0,0,0,0};

volatile unsigned int session_warning_up_channel_1_stage_time = 0;
//--- Señal 1Hz (Half) ---//
/*
#define FIELD_PERCENT 			100
#define RISING_TIME				100//ms
#define MAINTENANCE_TIME		300	//ms
#define FALLING_TIME			100//ms
#define LOW_TIME				500//ms
*/

//--- Señal 1Hz (Full) ---//
#define FIELD_PERCENT 			70
#define RISING_TIME				100//ms
#define MAINTENANCE_TIME		300	//ms
#define FALLING_TIME			100//ms
#define LOW_TIME				100//ms
#define ANTENNA_RESISTANCE		12 //Ohm
#define ANTENNA_INDUCTANCE		88 //mHy

//--- Señal canal 4 ---//
unsigned char GTK_SIGNAL_CH4_field_percent = 70;
unsigned short GTK_SIGNAL_CH4_rising_time = 100;//ms
unsigned short GTK_SIGNAL_CH4_maintenance_time = 300;//ms
unsigned short GTK_SIGNAL_CH4_falling_time = 100;//ms
unsigned short GTK_SIGNAL_CH4_low_time = 100;//ms
unsigned char GTK_SIGNAL_CH4_antenna_resistance = 12; //Ohm
unsigned char GTK_SIGNAL_CH4_antenna_inductance = 88; //mHy
unsigned char GTK_SIGNAL_CH4_current_max_integer = 1;
unsigned char GTK_SIGNAL_CH4_current_max_decimal = 88;

#define CURRENT_MAX_INTEGER	1
#define CURRENT_MAX_DECIMAL	88


//Estructuras.
session_typedef session_slot_aux;

session_typedef session_ch_1;
session_typedef session_ch_2;
session_typedef session_ch_3;
session_typedef session_ch_4;

unsigned char temp_actual_channel_1_int = 0;
unsigned char temp_actual_channel_1_dec = 0;
unsigned char temp_actual_channel_2_int = 0;
unsigned char temp_actual_channel_2_dec = 0;
unsigned char temp_actual_channel_3_int = 0;
unsigned char temp_actual_channel_3_dec = 0;
unsigned char temp_actual_channel_4_int = 0;
unsigned char temp_actual_channel_4_dec = 0;

//session_typedef session_slot_1;
//session_typedef session_slot_2;
//session_typedef session_slot_3;
//session_typedef session_slot_4;
//session_typedef session_slot_5;

unsigned char channel_1_pause = 0;
unsigned char channel_2_pause = 0;
unsigned char channel_3_pause = 0;
unsigned char channel_4_pause = 0;


void SystemInit (void);		//dumb function en otro momento inicializaba clock aca

int main (void)
{
	unsigned char i = 0;
	unsigned char counter_keep_alive = 0;
	//Configuracion de clock.
	RCC_Config ();

	//Configuracion led. & Enabled Channels
	Led_Config();

	//Timer 1ms.
	TIM7_Init();

	//Timer 100ms.
	TIM6_Init();

	//Signal timer.
	TIM5_Init();

	//ADC1.
	ADC1_Init();

	//UART_Debug Config.
	UART_PC_Init();
	UART_CH1_Init();
	UART_CH2_Init();
	UART_CH3_Init();
	UART_CH4_Init();

	//Configuracion PWM.
	PWM1_Init();
	PWM2_Init();
	PWM3_Init();
	PWM4_Init();

	//Initialize channels.
	Channel_1_Init();
	Channel_2_Init();
	Channel_3_Init();
	Channel_4_Init();

	//pruebo TIM5 100us step
	for (i = 0; i < 250; i++)
	{
		if (LED1)
			LED1_OFF;
		else
			LED1_ON;

//		while (!session_warning_up_channel_1_stage_time);
//
//		session_warning_up_channel_1_stage_time = 100;	//10ms
		Wait_ms(100);
	}


	UART_PC_Send("Ready! \r\n");

	//mando ENABLE los canales
	ENA_CH1_ON;
	ENA_CH2_ON;
	ENA_CH3_ON;
	ENA_CH4_ON;
	Wait_ms(10);
	ENA_CH1_OFF;
	ENA_CH2_OFF;
	ENA_CH3_OFF;
	ENA_CH4_OFF;

	while (TRUE)
	{
		if (timeRun == 0)	//decrece cada 1ms
		{

			if (counter_keep_alive > 10)
			{
				counter_keep_alive = 0;

				//sprintf(&buffSendErr[0], (const char *) "keepalive,%d,%d,%d,%d\r\n", session_ch_1.status, session_ch_2.status, session_ch_3.status, session_ch_4.status);
				//UART_PC_Send(&buffSendErr[0]);

				//UART_PC_Send("ant0,010.60,078.20,002.00,065.00,4\r\n");

				if (session_ch_1.status == 0)
					UART_CH1_Send("keepalive\r\n");
				if (session_ch_2.status == 0)
					UART_CH2_Send("keepalive\r\n");
				if (session_ch_3.status == 0)
					UART_CH3_Send("keepalive\r\n");
				if (session_ch_4.status == 0)
					UART_CH4_Send("keepalive\r\n");
			}
			else
				counter_keep_alive++;

			//Led3Toggle();

			timeRun = TIME_RUN_DEF;
		}

		//ADC control.
		//Session_Current_Limit_control();

		//Channel 1.
		Session_Channel_1 ();
		UART_CH1_Receive();

		//Channel 2.
		Session_Channel_2 ();
		UART_CH2_Receive();

		//Channel 3.
		Session_Channel_3 ();
		UART_CH3_Receive();

		//Channel 4.
		Session_Channel_4 ();	//si comento esto se cuelga saltando simepre TIM1_1MS pero parece solo con el debugger puesto PROBR QUITNDO TODOS LOS BREAKS
		UART_CH4_Receive();

		//Rececion de la configuracion por PC.
		UART_PC_Receive();


	}
/*
	while (TRUE)
	{

		//--- Channel 4 ---//
		GTK_Signal_Channel_4(GTK_SIGNAL_CH4_field_percent, GTK_SIGNAL_CH4_rising_time, GTK_SIGNAL_CH4_maintenance_time, GTK_SIGNAL_CH4_falling_time, GTK_SIGNAL_CH4_low_time, GTK_SIGNAL_CH4_current_max_integer, GTK_SIGNAL_CH4_current_max_decimal, GTK_SIGNAL_CH4_antenna_resistance, GTK_SIGNAL_CH4_antenna_inductance, ENABLE);

		//Rececion de la configuracion por PC.
		UART_PC_Receive();
	}
*/
/*
	while (TRUE)
	{

		signal();


		//PWM_CH4_TiempoBajada(1000);

		if (flagMuestreo == 1)
		{
			i = ADC1_Scan ((ADC_CHANNEL1 | ADC_CHANNEL2 | ADC_CHANNEL3 | ADC_CHANNEL4), &adc0[0]);

			if (i == FIN_OK)
			{
				flagMuestreo = 0;
			}

			if (i == FIN_ERROR)
			{
				flagMuestreo = 0;
			}

			if (i == FIN_TIMEOUT)
			{
				flagMuestreo = 0;
			}
		}

		//Recepcion desde antena 1.
		UART_CH1_Receive();

		//Recepcion desde antena 2.
		UART_CH2_Receive();

		//Recepcion desde antena 3.
		UART_CH3_Receive();

		//Recepcion desde antena 4.
		UART_CH4_Receive();

		//Recepcion desde la PC.
		UART_PC_Receive();
	}
	*/
}

void SystemInit (void)
{

}

