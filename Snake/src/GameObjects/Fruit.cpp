#include "Fruit.h"

Fruit::Fruit(): m_Radius(8) {
	m_Fruit.setRadius(m_Radius);
}

Fruit::~Fruit() {
}

void Fruit::Draw(sf::RenderWindow& window) const {
	window.draw(m_Fruit);
}

void Fruit::SetPosition(sf::Vector2f pos) {
	m_Fruit.setPosition(pos);
}


const sf::FloatRect& Fruit::GetGlobalBounds() const {
	return m_Fruit.getGlobalBounds();
}
