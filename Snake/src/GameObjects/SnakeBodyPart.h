#pragma once

#include "SnakePart.h"

class SnakeBodyPart : public SnakePart {
public:
	SnakeBodyPart(SnakePart* target);
	~SnakeBodyPart();

	virtual void Update(const float& dt);

private:
	SnakePart* m_TargetPart;
};