#include "Snake.h"
#include "SnakeHead.h"
#include "SnakeBodyPart.h"

Snake::Snake(const sf::Vector2f& pos) {
	sf::Vector2f size(16, 16);
	SnakeHead* head = new SnakeHead(pos);
	m_SnakeBody.push_back(head);

	for (int i = 0; i < 2; i++) {
		SnakePart* bodyPart = new SnakeBodyPart(m_SnakeBody.back());
		m_SnakeBody.push_back(bodyPart);
	}
}

Snake::~Snake() {
	for (SnakePart* bodyPart : m_SnakeBody) {
		delete bodyPart;
	}
	m_SnakeBody.clear();
}

void Snake::Update(const float& dt) {
	// Update the position of all snake parts
	for (int32 i = m_SnakeBody.size() - 1; i >= 0; i--) {
		m_SnakeBody[i]->Update(dt);
	}

	// We check for collisions after we've all snakeparts positions
	for (uint32 i = 2; i < m_SnakeBody.size(); i++) {
		SnakePart* prevPart = m_SnakeBody[i - 1];
		SnakePart* currentPart = m_SnakeBody[i];

		// If the head collides with another part of the snake and 
		// not colliding with the part before that, we cut the snake.
		// We have to check the collision with both parts since this way
		// we can reverse the snake and go backwards without it cutting off itself
		if (CheckCollision(currentPart->GetGlobalBounds()) &&
			!CheckCollision(prevPart->GetGlobalBounds())) {
			Cut(m_SnakeBody.size() - i);

			// If there is an collision we break out of the loop
			break;
		}
	}

}

void Snake::Draw(sf::RenderWindow& window) {
	// We itterate through all the snakes backwards when drawing
	// the snake, because we always want the head to be on top.
	for (int32 i = m_SnakeBody.size() - 1; i >= 0; i--) {
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

void Snake::Cut(const uint32& pieces) {
	for (uint32 i = 0; i < pieces; i++) {
		delete m_SnakeBody.back();
		m_SnakeBody.pop_back();
	}
}