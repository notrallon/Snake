#pragma once

#define _USE_MATH_DEFINES

#include <stdint.h>
#include <iostream>
#include <stdio.h>
#include <math.h>

#include <SFML/Graphics.hpp>

#define RADIANS M_PI / 180.0f

typedef uint8_t		uint8;
typedef uint16_t	uint16;
typedef uint32_t	uint32;
typedef uint64_t	uint64;

typedef int8_t		int8;
typedef int16_t		int16;
typedef int32_t		int32;
typedef int64_t		int64;

enum collisionLayer_t { NONE, SNAKE, FRUIT, OTHER };