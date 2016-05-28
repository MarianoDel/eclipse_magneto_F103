#ifndef _USARTFV_H_
#define _USARTFV_H_

void UART1_Config(void);
void UART1Send(const char * ptrSend);
void UART2_Config(void);
void UART2Send(char * ptrSend);
void UART3_Config(void);
void UART3Send(char * ptrSend);
void UART4_Config(void);
void UART4Send(char * ptrSend);
void UART5_Config(void);
void UART5Send(char * ptrSend);
void UART1_Receive (void);
void UART2_Receive (void);
void UART3_Receive (void);
void UART4_Receive (void);
void UART5_Receive (void);
void UART_Tim6 (void);

#endif
