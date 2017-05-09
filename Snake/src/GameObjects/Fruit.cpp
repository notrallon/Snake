#include "../Common.h"
#include "Fruit.h"

Fruit::Fruit() {
	m_Fruit.setRadius(7);
	m_Fruit.setFillColor(sf::Color::Red);
}

Fruit::~Fruit() {
}

void Fruit::Draw(sf::RenderWindow& window) const {
	window.draw(m_Fruit);
}

void Fruit::SetPosition(const sf::Vector2f& pos) {
	m_Fruit.setPosition(pos);
}

void Fruit::SetRandomPosition(const sf::Vector2u& frame) {
	sf::Vector2f newPos(rand() % int32(frame.x - m_Fruit.getRadius() * 2),
						rand() % int32(frame.y - m_Fruit.getRadius() * 2));

	SetPosition(newPos);
}


const sf::FloatRect& Fruit::GetGlobalBounds() const {
	return m_Fruit.getGlobalBounds();
}

const float& Fruit::GetRadius() const {
	return m_Fruit.getRadius();
}

