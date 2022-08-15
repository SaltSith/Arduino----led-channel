#pragma once

#include <stdint.h>

typedef struct {
	uint8_t hour;
	uint8_t minute;
} time_t;

typedef enum {
	DAY = 0,
	NIGHT,
} daytime_t;
