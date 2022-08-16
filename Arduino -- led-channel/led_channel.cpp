#include "led_channel.h"

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


led_channel::led_channel(uint8_t pin, char chn, uint8_t max_day_power, uint8_t max_night_power, time_t sunrise, time_t sunset):pin(pin)
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
}

void led_channel::set_current_power_on_value(const uint8_t power)
{
}

void led_channel::set_sunset(const time_t sunset)
{
}

void led_channel::set_sunrise(const time_t sunrise)
{
}

uint8_t led_channel::current_power_get(void)
{
	return uint8_t();
}

uint8_t led_channel::max_day_power_get(void)
{
	return uint8_t();
}

uint8_t led_channel::max_night_power_get(void)
{
	return uint8_t();
}

char led_channel::name_get(void)
{
	return 0;
}

time_t led_channel::sunrise_time_get(void)
{
	return time_t();
}

time_t led_channel::sunset_time_get(void)
{
	return time_t();
}

void led_channel::handle(const time_t curret_time)
{
}
