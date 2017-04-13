#pragma once

#include "SnakePart.h"

class SnakeHead : public SnakePart {
public:
	SnakeHead();
	~SnakeHead();

	virtual void Update(const float& dt);
};