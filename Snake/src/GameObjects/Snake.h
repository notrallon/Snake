#pragma once

#include "SnakePart.h"

class Snake {
public:
									Snake();
									~Snake();

	void							Update(const float& dt);
	void							Draw(sf::RenderWindow& window);
	bool							CheckCollision(sf::FloatRect other) const;

	void							Grow();

private:
	float							m_RotateSpeed;
	float							m_MoveSpeed;

	//std::vector<sf::CircleShape*>	m_SnakeBody;
	std::vector<SnakePart*>			m_SnakeBody;
};