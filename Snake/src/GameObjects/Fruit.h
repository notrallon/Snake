#pragma once
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Fruit {
public:
							Fruit();
							~Fruit();

	void					Draw(sf::RenderWindow& window) const;

	void					SetPosition(const sf::Vector2f& pos);
	void					SetRandomPosition(const sf::Vector2u& frame);

	const sf::FloatRect&	GetGlobalBounds() const;
	const float&			GetRadius() const;

private:
	sf::CircleShape			m_Fruit;
};
