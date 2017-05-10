#include "SnakeBodyPart.h"
#include "../Game.h"

SnakeBodyPart::SnakeBodyPart(SnakePart* target) : m_TargetPart(target) {
	m_SnakePart->setFillColor(sf::Color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1));
	m_SnakePart->setPosition(target->GetPosition());
}

void SnakeBodyPart::Update(const float& dt) {
	float maxSnakePosX = Game::Instance()->GetWindow().getSize().x + m_SnakePart->getRadius();
	float minSnakePosX = -m_SnakePart->getRadius();
	float maxSnakePosY = Game::Instance()->GetWindow().getSize().y + m_SnakePart->getRadius();
	float minSnakePosY = -m_SnakePart->getRadius();

	sf::Vector2f	currentPosition = m_SnakePart->getPosition();
	sf::Vector2f	targetPosition = m_TargetPart->GetPosition();
	sf::Vector2f	distance = targetPosition - currentPosition;
	float			mag = sqrt(distance.x * distance.x + distance.y * distance.y);


	if (mag > maxSnakePosY / 2) {
		m_SnakePart->move(MoveForward(dt));

		if (m_SnakePart->getPosition().x > maxSnakePosX) {
			m_SnakePart->setPosition(minSnakePosX, m_SnakePart->getPosition().y);
		} else if (m_SnakePart->getPosition().x < minSnakePosX) {
			m_SnakePart->setPosition(maxSnakePosX, m_SnakePart->getPosition().y);
		}

		if (m_SnakePart->getPosition().y > maxSnakePosY) {
			m_SnakePart->setPosition(m_SnakePart->getPosition().x, minSnakePosY);
		} else if (m_SnakePart->getPosition().y < minSnakePosY) {
			m_SnakePart->setPosition(m_SnakePart->getPosition().x, maxSnakePosY);
		}

	} else {
		float difSpeed = m_TargetPart->GetSpeed() - m_MoveSpeed;

		m_MoveSpeed += difSpeed * m_Acceleration * dt;

		//m_SnakePart->move(distance * ((abs(m_MoveSpeed) / m_Acceleration) * mag) * dt);
		m_SnakePart->move(distance * mag * dt);

		float rotDif = m_TargetPart->GetRotation() - m_SnakePart->getRotation();

		m_SnakePart->setRotation(m_SnakePart->getRotation() + rotDif * 360 * dt);
	}
}