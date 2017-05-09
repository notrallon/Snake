#pragma once

#include "../Common.h"

class SnakePart {
public:
							SnakePart();
	virtual					~SnakePart();

	virtual void			Update(const float& dt) = 0;
	void					Draw(sf::RenderWindow& window) const;

	const sf::Vector2f&		GetPosition() const;
	const float&			GetRotation() const;
	sf::FloatRect			GetGlobalBounds() const;
	const float&			GetSpeed() const;

protected:
	sf::CircleShape*		m_SnakePart;
	float					m_MoveSpeed;
	float					m_Acceleration;

	const sf::Vector2f&		MoveForward(float dt) const;
};