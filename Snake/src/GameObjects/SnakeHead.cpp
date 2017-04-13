#include "SnakeHead.h"

SnakeHead::SnakeHead() : SnakePart() {
	//m_SnakePart = new sf::CircleShape();
	//m_SnakePart->setRadius(8);
	m_SnakePart->setFillColor(sf::Color::Yellow);
	m_SnakePart->setPosition(420, 420);
}

SnakeHead::~SnakeHead() {

}

void SnakeHead::Update(const float& dt) {
	if (m_SnakePart->getPosition().x > 1280 + m_SnakePart->getRadius()) {
		m_SnakePart->setPosition(-m_SnakePart->getRadius(), m_SnakePart->getPosition().y);
	}
	else if (m_SnakePart->getPosition().x < -m_SnakePart->getRadius()) {
		m_SnakePart->setPosition(1280 + m_SnakePart->getRadius(), m_SnakePart->getPosition().y);
	}

	if (m_SnakePart->getPosition().y > 720 + m_SnakePart->getRadius()) {
		m_SnakePart->setPosition(m_SnakePart->getPosition().x, -m_SnakePart->getRadius());
	}
	else if (m_SnakePart->getPosition().y < -m_SnakePart->getRadius()) {
		m_SnakePart->setPosition(m_SnakePart->getPosition().x, 720 + m_SnakePart->getRadius());
	}

	// Get input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		m_MoveSpeed += 250 * dt;

		if (m_MoveSpeed > MAX_MOVE_SPEED) {
			m_MoveSpeed = MAX_MOVE_SPEED;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		m_MoveSpeed -= 250 * dt;

		if (m_MoveSpeed < MIN_MOVE_SPEED) {
			m_MoveSpeed = MIN_MOVE_SPEED;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		m_SnakePart->setRotation(m_SnakePart->getRotation() - ROTATE_SPEED * dt);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		m_SnakePart->setRotation(m_SnakePart->getRotation() + ROTATE_SPEED * dt);
	}

	m_SnakePart->move(sin(M_PI * m_SnakePart->getRotation() / 180.0f) * m_MoveSpeed * dt, -1 * cos(M_PI * m_SnakePart->getRotation() / 180.0f) * m_MoveSpeed * dt);
}