#include "SnakeHead.h"
#include "../Game.h"

SnakeHead::SnakeHead(const sf::Vector2f& pos) {
	m_SnakePart->setFillColor(sf::Color::Yellow);
	m_SnakePart->setPosition(pos);
}

void SnakeHead::Update(const float& dt) {
	int32 maxSnakePosX = Game::Instance()->GetWindow().getSize().x + m_SnakePart->getRadius();
	int32 minSnakePosX = -m_SnakePart->getRadius();
	int32 maxSnakePosY = Game::Instance()->GetWindow().getSize().y + m_SnakePart->getRadius();
	int32 minSnakePosY = -m_SnakePart->getRadius();

	// Wrap the snake around the x position
	if (m_SnakePart->getPosition().x > maxSnakePosX) {
		m_SnakePart->setPosition(minSnakePosX, m_SnakePart->getPosition().y);
	} else if (m_SnakePart->getPosition().x < minSnakePosX) {
		m_SnakePart->setPosition(maxSnakePosX, m_SnakePart->getPosition().y);
	}

	// Wrap the snake around the y position
	if (m_SnakePart->getPosition().y > maxSnakePosY) {
		m_SnakePart->setPosition(m_SnakePart->getPosition().x, minSnakePosY);
	} else if (m_SnakePart->getPosition().y < minSnakePosY) {
		m_SnakePart->setPosition(m_SnakePart->getPosition().x, maxSnakePosY);
	}

	// Acceleration / deceleration
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		m_MoveSpeed += m_Acceleration * dt;

		if (m_MoveSpeed > MAX_MOVE_SPEED) {
			m_MoveSpeed = MAX_MOVE_SPEED;
		}
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		m_MoveSpeed -= m_Acceleration * dt;

		if (m_MoveSpeed < -MAX_MOVE_SPEED) {
			m_MoveSpeed = -MAX_MOVE_SPEED;
		}
	}

	// Rotate to turn
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		m_SnakePart->setRotation(m_SnakePart->getRotation() - ROTATE_SPEED * dt);
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		m_SnakePart->setRotation(m_SnakePart->getRotation() + ROTATE_SPEED * dt);
	}

	m_SnakePart->move(MoveForward(dt));
}