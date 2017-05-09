#pragma once

#include "SnakePart.h"

class SnakeHead : public SnakePart {
public:
			SnakeHead(const sf::Vector2f& pos);

	void	Update(const float& dt) override;
};