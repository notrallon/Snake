#include "SnakeBodyPart.h"

SnakeBodyPart::SnakeBodyPart(SnakePart* target) : SnakePart(), m_TargetPart(target) {
	//m_SnakePart = new sf::CircleShape();
	//m_SnakePart->setRadius(8);
	m_SnakePart->setFillColor(sf::Color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1));
	m_SnakePart->setPosition(target->GetPosition());
}

SnakeBodyPart::~SnakeBodyPart() {

}

void SnakeBodyPart::Update(const float& dt) {
	sf::Vector2f	currentPosition = m_SnakePart->getPosition();
	sf::Vector2f	targetPosition = m_TargetPart->GetPosition();
	sf::Vector2f	distance = targetPosition - currentPosition;
	float			mag = sqrt(distance.x * distance.x + distance.y * distance.y);


	if (mag > 720 / 2) {
		m_SnakePart->move(sin(M_PI * m_SnakePart->getRotation() / 180.0f) * m_MoveSpeed * dt,
			-1 * cos(M_PI * m_SnakePart->getRotation() / 180.0f) * m_MoveSpeed * dt);

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

	} else {
		float difSpeed = m_TargetPart->GetSpeed() - m_MoveSpeed;

		m_MoveSpeed += difSpeed * 50 * dt;

		m_SnakePart->move(distance * mag * dt);

		float rotDif = m_TargetPart->GetRotation() - m_SnakePart->getRotation();

		m_SnakePart->setRotation(m_SnakePart->getRotation() + rotDif * dt);
	}
}