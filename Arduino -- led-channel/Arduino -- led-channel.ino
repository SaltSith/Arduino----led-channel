/*
 Name:		Arduino____led_channel.ino
 Created:	8/15/2022 10:18:32 PM
 Author:	marcin
*/

#include "led_channel.h"

led_channel channel_A(7, 'A', 240, 15, (time_t) { 10, 12 }, (time_t) { 20, 25 });


time_t compute_time(void)
{
	static uint8_t h = 8, m = 0, s = 0;

	s++;
	if (s > 60) {
		m++;
		s = 0;
	}

	if (m > 60) {
		h++;
		m = 0;
	}

	if (h > 23) {
		h = 0;
	}

	Serial.println(String(h) + ":" + String(m) + ":" + String(s));

	return time_t{ h, m };
}


// the setup function runs once when you press reset or power the board
void setup() {
	channel_A.init();
	Serial.begin(115200);
}

// the loop function runs over and over again until power down or reset
void loop() {
	channel_A.handle(compute_time());
}
