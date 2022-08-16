#pragma once

#include "daytime.h"

class led_channel {
private:
	const uint8_t pin;			/// Gpio PWM pin
	uint8_t current_power;		/// Current LED power
	uint8_t max_day_power;		/// Max LED power at day
	uint8_t max_night_power;	/// Max LED power at night

	time_t sunrise;				/// Sunrise time
	time_t sunset;				/// Susnset time

	const char name;			/// Led channel name
	void set_power(const daytime_t daytime);

public:
	led_channel(const uint8_t pin, const char name, const uint8_t max_day_power, const uint8_t max_night_power, const time_t sunrise, const time_t sunset);
	~led_channel();

	void init(void);
	void set_max_power(const uint8_t max_power, daytime_t daytime);
	void set_current_power_on_value(const uint8_t power);
	void set_sunset(const time_t sunset);
	void set_sunrise(const time_t sunrise);

	uint8_t current_power_get(void);
	uint8_t max_day_power_get(void);
	uint8_t max_night_power_get(void);

	char name_get(void);
	time_t sunrise_time_get(void);
	time_t sunset_time_get(void);

	void handle(const time_t current_time);

};