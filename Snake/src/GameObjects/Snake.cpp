#include "Snake.h"
#include "SnakeHead.h"
#include "SnakeBodyPart.h"

Snake::Snake() {
	sf::Vector2f size(16, 16);
	SnakePart* head = new SnakeHead();
	m_SnakeBody.push_back(head);

	for (int i = 0; i < 10; i++) {
		SnakePart* bodyPart = new SnakeBodyPart(m_SnakeBody.back());
		m_SnakeBody.push_back(bodyPart);
	}

	m_RotateSpeed = 360;
}

Snake::~Snake() {
	for (SnakePart* bodyPart : m_SnakeBody) {
		delete bodyPart;
	}
	m_SnakeBody.clear();
}

void Snake::Update(const float& dt) {
	for (int i = m_SnakeBody.size() - 1; i >= 0; i--) {
		m_SnakeBody[i]->Update(dt);
	}
}

void Snake::Draw(sf::RenderWindow& window) {
	for (int i = m_SnakeBody.size() - 1; i >= 0; i--) {
		m_SnakeBody[i]->Draw(window);
	}
}

bool Snake::CheckCollision(sf::FloatRect other) const {
	return m_SnakeBody[0]->GetGlobalBounds().intersects(other);
}

void Snake::Grow() {
	SnakePart* bodyPart = new SnakeBodyPart(m_SnakeBody.back());
	m_SnakeBody.push_back(bodyPart);
}

