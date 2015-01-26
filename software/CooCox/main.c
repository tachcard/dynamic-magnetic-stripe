/*
 * Copyright 2014:
 * Company: Tachcard Limited
 * Website: http://www.tachcard.com/
 * Email: controllerdreamlive@gmail.com
 * Authors: Bogdanov Maksim
 * Date: 30-12-2014
 */

#include <stm32f4xx.h>
#include "stripe.h"
long int timer;

int main(void) {

	// example string, max 76
	char example_str[] = ";1234567?";

	// GPIO initialization
	stripe_init();

	while (1) {
		// converting a string into a sequence of bits
		message_to_buff_2(example_str);
		// serial output buffer contents to a magnetic stripe
		buff_2_to_magnetic();
		// sleep
		timer = 1000000;
		while (timer) {
			timer--;
		}
	}
}
