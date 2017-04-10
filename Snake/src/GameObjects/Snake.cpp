#include "Snake.h"

Snake::Snake() {
	sf::Vector2f size(16, 16);
	sf::CircleShape* head = new sf::CircleShape();
	//head->setSize(size);
	head->setRadius(8);
	head->setOrigin(size.x / 2, size.y / 2);
	head->setFillColor(sf::Color::Yellow);
	head->setPosition(320, 320);
	m_SnakeBody.push_back(head);

	for (int i = 0; i < 10; i++) {
		sf::CircleShape* bodyPart = new sf::CircleShape();
		bodyPart->setRadius(8);
		bodyPart->setOrigin(size.x / 2, size.y / 2);
		bodyPart->setFillColor(sf::Color::Green);
		bodyPart->setPosition(head->getPosition());
		m_SnakeBody.push_back(bodyPart);
	}

	m_RotateSpeed = 360;
}

Snake::~Snake() {
	for (sf::CircleShape* bodyPart : m_SnakeBody) {
		delete bodyPart;
	}
	m_SnakeBody.clear();
}

void Snake::Update(float dt) {
	sf::CircleShape* head = m_SnakeBody[0];

	if (head->getPosition().x > 1280 + head->getRadius()) {
		head->setPosition(-head->getRadius(), head->getPosition().y);
	}
	else if (head->getPosition().x < -head->getRadius()) {
		head->setPosition(1280 + head->getRadius(), head->getPosition().y);
	}

	// Get input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		m_MoveSpeed += 250 * dt;

		if (m_MoveSpeed > MAX_MOVE_SPEED) {
			m_MoveSpeed = MAX_MOVE_SPEED;
		}
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		m_MoveSpeed -= 250 * dt;

		if (m_MoveSpeed < MIN_MOVE_SPEED) {
			m_MoveSpeed = MIN_MOVE_SPEED;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		head->setRotation(head->getRotation() - m_RotateSpeed * dt);
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		head->setRotation(head->getRotation() + m_RotateSpeed * dt);
	}

	for (int i = m_SnakeBody.size() - 1; i > 0; i--) {
		sf::Vector2f	currentPosition		= m_SnakeBody[i]->getPosition();
		sf::Vector2f	targetPosition		= m_SnakeBody[i - 1]->getPosition();
		sf::Vector2f	distance			= targetPosition - currentPosition;
		float			mag					= sqrt(distance.x * distance.x + distance.y * distance.y);

		if (mag > 720 / 2) {
			m_SnakeBody[i]->move(sin(M_PI * m_SnakeBody[i]->getRotation() / 180.0f) * m_MoveSpeed * dt,
								 -1 * cos(M_PI * m_SnakeBody[i]->getRotation() / 180.0f) * m_MoveSpeed * dt);

			if (m_SnakeBody[i]->getPosition().x > 1280 + head->getRadius()) {
				m_SnakeBody[i]->setPosition(0, m_SnakeBody[i]->getPosition().y);
			} else if (m_SnakeBody[i]->getPosition().x < 0) {
				m_SnakeBody[i]->setPosition(1280, m_SnakeBody[i - 1]->getPosition().y);
			}
		} else {
			m_SnakeBody[i]->move(distance * mag * dt);
			m_SnakeBody[i]->setRotation(m_SnakeBody[i - 1]->getRotation());
		}


	}

	head->move(sin(M_PI * head->getRotation() / 180.0f) * m_MoveSpeed * dt, -1 * cos(M_PI * head->getRotation() / 180.0f) * m_MoveSpeed * dt);
}

void Snake::Draw(sf::RenderWindow& window) {
	for (int i = m_SnakeBody.size() - 1; i >= 0; i--) {
		window.draw(*m_SnakeBody[i]);
	}
}

bool Snake::CheckCollision(sf::FloatRect other) const {
	return m_SnakeBody[0]->getGlobalBounds().intersects(other);
}

void Snake::Grow() {
	sf::CircleShape* bodyPart = new sf::CircleShape();
	bodyPart->setRadius(8);
	bodyPart->setOrigin(8, 8);
	bodyPart->setFillColor(sf::Color::Green);
	bodyPart->setPosition(m_SnakeBody.back()->getPosition());
	m_SnakeBody.push_back(bodyPart);
}

