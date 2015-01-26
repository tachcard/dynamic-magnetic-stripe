/*
 * Copyright 2014:
 * Company: Tachcard Limited
 * Website: http://www.tachcard.com/
 * Email: controllerdreamlive@gmail.com
 * Authors: Bogdanov Maksim
 * Date: 30-12-2014
 */

#include "stripe.h"

#define bin(a,b,c,d,e,f,g,h) \
(a<<7)|(b<<6)|(c<<5)|(d<<4)| \
(e<<3)|(f<<2)|(g<<1)|(h<<0)

unsigned char stripe_2_buff[67]; // (76 * 7 bit per char) / 8 bit per byte
unsigned char buff_2_index;
unsigned char buff_2_bit_index;

// waiting half the withdrawal period, a bit of information on the magnetic strip
void vait_stripe_2_half_period(void) {
	int timer = 350;
	while (timer) {
		timer--;
	}
}

// waiting period output bits of information on the magnetic strip
void vait_stripe_2_period(void) {
	int timer = 700;
	while (timer) {
		timer--;
	}
}

// character conversion in a sequence of 5 bits, 4 of them information and 5th CRC
char make_char_for_stripe_2(char c) {
	switch (c) {
	case '0':
		return bin(0,0,0,1,0,0,0,0);
	case '1':
		return bin(0,0,0,0,0,0,0,1);
	case '2':
		return bin(0,0,0,0,0,0,1,0);
	case '3':
		return bin(0,0,0,1,0,0,1,1);
	case '4':
		return bin(0,0,0,0,0,1,0,0);
	case '5':
		return bin(0,0,0,1,0,1,0,1);
	case '6':
		return bin(0,0,0,1,0,1,1,0);
	case '7':
		return bin(0,0,0,0,0,1,1,1);
	case '8':
		return bin(0,0,0,0,1,0,0,0);
	case '9':
		return bin(0,0,0,1,1,0,0,1);
	case ':':
		return bin(0,0,0,1,1,0,1,0);
	case ';':
		return bin(0,0,0,0,1,0,1,1);
	case '<':
		return bin(0,0,0,1,1,1,0,0);
	case '=':
		return bin(0,0,0,0,1,1,0,1);
	case '>':
		return bin(0,0,0,0,1,1,1,0);
	case '?':
		return bin(0,0,0,1,1,1,1,1);
	}
	return -1;
}

// buffered data by 5 bits per symbol
void char_to_buff_2(char cc) {
	unsigned char i;
	for (i = 0; i < 5; i++) {
		if (cc & (1 << i)) {
			stripe_2_buff[buff_2_index] |= (1 << buff_2_bit_index);
		} else {
			stripe_2_buff[buff_2_index] &= ~(1 << buff_2_bit_index);
		}
		buff_2_bit_index++;
		if (buff_2_bit_index >= 8) {
			buff_2_bit_index = 0;
			buff_2_index++;
			stripe_2_buff[buff_2_index] = 0;
		}
	}
}

// serial transmission of characters from the buffer in a magnetic strip
void buff_2_to_magnetic(void) {
	unsigned char i, ii;
	for (i = 0; i <= buff_2_index; i++) {
		for (ii = 0; ii < 8; ii++) {
			if (stripe_2_buff[i] & (1 << ii)) {
				stripe_2_toggle();
				vait_stripe_2_half_period();
				stripe_2_toggle();
				vait_stripe_2_half_period();
			} else {
				stripe_2_toggle();
				vait_stripe_2_period();
			}
		}
	}
}

// recording line to the clipboard
char str_to_buff_2(char * c) {
	char cc, lrc = 0;
	while (*c != '\0') {
		cc = make_char_for_stripe_2(*c);
		char_to_buff_2(cc);
		lrc ^= cc;
		c++;
	}
	// additional character to test all posts
	char_to_buff_2(lrc);
	return 0;
}

// recording in a buffer
void message_to_buff_2(char * str) {
	int i;
	buff_2_index = 0;
	buff_2_bit_index = 0;

	for (i = 0; i < 5; i++) {
		char_to_buff_2(0);
	}
	str_to_buff_2(str);
	for (i = 0; i < 9; i++) {
		char_to_buff_2(0);
	}

}

// invert the magnetic field on the magnetic strip
void stripe_2_toggle(void) {
	GPIO_ToggleBits(STRIPE_2_PORT, STRIPE_2_PIN_P | STRIPE_2_PIN_N);
}

// configuration GPIO
void stripe_init(void) {
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_AHB1PeriphClockCmd(STRIPE_2_RCC_PERIPH, ENABLE);
	GPIO_SetBits(STRIPE_2_PORT, STRIPE_2_PIN_P);
	GPIO_ResetBits(STRIPE_2_PORT, STRIPE_2_PIN_N);

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Pin = STRIPE_2_PIN_P | STRIPE_2_PIN_N;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(STRIPE_2_PORT, &GPIO_InitStructure);
}

