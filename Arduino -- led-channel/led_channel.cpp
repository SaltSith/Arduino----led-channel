#include "led_channel.h"

#include <Arduino.h>

void led_channel::set_power(const daytime_t daytime)
{
	bool update = true;

	if (daytime == DAY) {
		if (this->current_power < this->max_day_power) {
			this->current_power++;
		}
		else if (this->current_power > this->max_day_power) {
			this->current_power--;
		}
		else {
			update = false;
		}
	}
	else if (daytime == NIGHT) {
		if (this->current_power < this->max_night_power) {
			this->current_power++;
		}
		else if (this->current_power > this->max_night_power) {
			this->current_power--;
		}
		else {
			update = false;
		}
	}
	else {
		update = false;
	}

	if (update) {
		analogWrite(this->pin, this->current_power);
	}
}


led_channel::led_channel(const uint8_t pin, const char name, const uint8_t max_day_power, const uint8_t max_night_power, const time_t sunrise, const time_t sunset):pin(pin), name(name)
{
	this->current_power = 0;
	this->max_day_power = max_day_power;
	this->max_night_power = max_night_power;
	
	this->sunrise = sunrise;
	this->sunset = sunset;
}

led_channel::~led_channel()
{
}

void led_channel::init(void)
{
	pinMode(this->pin, OUTPUT);
	analogWrite(this->pin, LOW);
}

void led_channel::set_max_power(const uint8_t max_power, daytime_t daytime)
{
	if (daytime == DAY) {
		this->max_day_power = max_power;
	}
	else if (daytime == NIGHT) {
		this->max_night_power = max_power;
	}
}

void led_channel::set_current_power_on_value(const uint8_t power)
{
	if ((power < min_power) || (power > max_power)) {
		return;
	}

	this->current_power = power;
	analogWrite(this->pin, this->current_power);
}

void led_channel::set_sunset(const time_t sunset)
{
	this->sunset = sunset;
}

void led_channel::set_sunrise(const time_t sunrise)
{
	this->sunrise = sunrise;
}

uint8_t led_channel::current_power_get(void)
{

	return this->current_power;
}

uint8_t led_channel::max_day_power_get(void)
{

	return this->max_day_power;
}

uint8_t led_channel::max_night_power_get(void)
{

	return this->max_night_power;
}

char led_channel::name_get(void)
{

	return this->name;
}

time_t led_channel::sunrise_time_get(void)
{

	return this->sunrise;
}

time_t led_channel::sunset_time_get(void)
{

	return this->sunset;
}

void led_channel::handle(const time_t current_time)
{
	if (((current_time.hour * 60 + current_time.minute) >= (this->sunset.hour * 60 + this->sunset.minute)) &&
		((current_time.hour * 60 + current_time.minute) < (this->sunrise.hour * 60 + this->sunrise.minute))) {
		this->set_power(DAY);
	}
	else {
		this->set_power(NIGHT);
	}
}
