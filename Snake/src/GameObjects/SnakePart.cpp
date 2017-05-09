#include "SnakePart.h"
#include "../Game.h"

SnakePart::SnakePart() : m_SnakePart(nullptr)
                       , m_MoveSpeed(0)
                       , m_Acceleration(250) {
	m_SnakePart = new sf::CircleShape();
	m_SnakePart->setRadius(8);
	m_SnakePart->setFillColor(sf::Color::Magenta);
	m_SnakePart->setOrigin(8, 8);
}

SnakePart::~SnakePart() {
	delete m_SnakePart;
}

void SnakePart::Draw(sf::RenderWindow& window) const {
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

const sf::Vector2f& SnakePart::MoveForward(float dt) const {
	return sf::Vector2f(sin(M_PI * m_SnakePart->getRotation() / 180.0f) * m_MoveSpeed * dt, 
						-1 * cos(M_PI * m_SnakePart->getRotation() / 180.0f) * m_MoveSpeed * dt);
}
