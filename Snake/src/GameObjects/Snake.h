#pragma once

#include "../Common.h"
#include "SnakePart.h"

class Snake {
public:
									Snake(const sf::Vector2f& pos = sf::Vector2f(0, 0));
									~Snake();

	void							Update(const float& dt);
	void							Draw(sf::RenderWindow& window);
	bool							CheckCollision(sf::FloatRect other) const;

	void							Grow();
	void							Cut(const uint32& pieces);

private:
	std::vector<SnakePart*>			m_SnakeBody;
};