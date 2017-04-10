#pragma once

#include "../Common.h"

#define MAX_MOVE_SPEED 255
#define MIN_MOVE_SPEED 0

class Snake {
public:
									Snake();
									~Snake();

	void							Update(float dt);
	void							Draw(sf::RenderWindow& window);
	bool							CheckCollision(sf::FloatRect other) const;

	void							Grow();

private:
	float							m_RotateSpeed;
	float							m_MoveSpeed;

	std::vector<sf::CircleShape*>	m_SnakeBody;
};