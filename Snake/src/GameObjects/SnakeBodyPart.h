#pragma once

#include "SnakePart.h"

class SnakeBodyPart : public SnakePart {
public:
	SnakeBodyPart(SnakePart* target);

	void Update(const float& dt) override;

private:
	SnakePart* m_TargetPart;
};