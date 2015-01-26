/*
 * Copyright 2014:
 * Company: Tachcard Limited
 * Website: http://www.tachcard.com/
 * Email: controllerdreamlive@gmail.com
 * Authors: Bogdanov Maksim
 * Date: 30-12-2014
 */


#ifndef __STRIPE_H
#define __STRIPE_H

#include <stm32f4xx.h>


#define STRIPE_2_PIN_P GPIO_Pin_13
#define STRIPE_2_PIN_N GPIO_Pin_14
#define STRIPE_2_PORT GPIOB
#define STRIPE_2_RCC_PERIPH RCC_AHB1Periph_GPIOB


extern void message_to_buff_2(char * );
extern void stripe_init(void);
extern void buff_2_to_magnetic(void);

void stripe_2_toggle(void);
void vait_stripe_2_half_period(void);
void vait_stripe_2_period(void);


#endif
