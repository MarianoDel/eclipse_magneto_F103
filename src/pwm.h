#ifndef PWM_H_
#define PWM_H_

enum channels_pwm
{
	PWM_CHANNEL_1 = 0x01,
	PWM_CHANNEL_2 = 0x02,
	PWM_CHANNEL_3 = 0x04,
	PWM_CHANNEL_4 = 0x08
};

void PWM_TIM1_CONFIG (unsigned short prescaler, unsigned short periodo, unsigned short duty1, unsigned short duty2, unsigned short duty3, unsigned short duty4, unsigned char channel_en);
void PWM_TIM1_DUTY (unsigned short duty, unsigned short channel);
void PWM_TIM2_CONFIG (unsigned short prescaler, unsigned short periodo, unsigned short duty1, unsigned short duty2, unsigned short duty3, unsigned short duty4, unsigned char channel_en);
void PWM_TIM2_DUTY (unsigned short duty, unsigned short channel);
void PWM_TIM3_CONFIG (unsigned short prescaler, unsigned short periodo, unsigned short duty1, unsigned short duty2, unsigned short duty3, unsigned short duty4, unsigned char channel_en);
void PWM_TIM3_DUTY (unsigned short duty, unsigned short channel);
void PWM_TIM4_CONFIG (unsigned short prescaler, unsigned short periodo, unsigned short duty1, unsigned short duty2, unsigned short duty3, unsigned short duty4, unsigned char channel_en);
void PWM_TIM4_DUTY (unsigned short duty, unsigned short channel);

#endif
