#include "SnakePart.h"

SnakePart::SnakePart() : m_SnakePart(nullptr) {
	m_SnakePart = new sf::CircleShape();
	m_SnakePart->setRadius(8);
	m_SnakePart->setFillColor(sf::Color::Magenta);
	m_SnakePart->setOrigin(8, 8);
}

SnakePart::~SnakePart() {
	delete m_SnakePart;
}

void SnakePart::Draw(sf::RenderWindow& window) {
	window.draw(*m_SnakePart);
}

const sf::Vector2f& SnakePart::GetPosition() const {
	return m_SnakePart->getPosition();
}

const float& SnakePart::GetRotation() const {
	return m_SnakePart->getRotation();
}

sf::FloatRect SnakePart::GetGlobalBounds() const {
	return m_SnakePart->getGlobalBounds();
}

const float& SnakePart::GetSpeed() const {
	return m_MoveSpeed;
}