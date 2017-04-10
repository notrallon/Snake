#pragma once
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Fruit {
public:
	Fruit();
	~Fruit();

	void					Draw(sf::RenderWindow& window) const;

	void					SetPosition(sf::Vector2f pos);

	const sf::FloatRect&	GetGlobalBounds() const;

private:
	sf::CircleShape			m_Fruit;

	float					m_Radius;
};
