#include "Game.h"

Game* Game::m_Instance = nullptr;

Game::Game(): m_Running(true)
            , m_Restart(false) {
	m_Window.create({ 1280, 720, 32 }, "Snake - Richard Norqvist", sf::Style::Close);

	Init();
}

Game::~Game() {
}

void Game::Init() {
	srand(time(nullptr));
	m_Restart = false;
	m_Snake = new Snake();

	m_Fruit.SetPosition(sf::Vector2f(std::rand() % m_Window.getSize().x, std::rand() % m_Window.getSize().y));
}

void Game::Restart() {
	m_Restart = true;
}

void Game::HandleEvents() {
	sf::Event evnt;

	while (m_Window.pollEvent(evnt)) { 
		switch (evnt.type) {
		
		case sf::Event::Closed: {
			m_Running = false;
		} break;

		default: {
		} break;

		}
	}
}


void Game::Update() {
	float dt = m_ElapsedTime.asSeconds();
	m_Snake->Update(dt);

	if (m_Snake->CheckCollision(m_Fruit.GetGlobalBounds())) {
		m_Snake->Grow();
		m_Fruit.SetPosition(sf::Vector2f(std::rand() % m_Window.getSize().x, std::rand() % m_Window.getSize().y));
	}
}

void Game::LateUpdate() {
	if (m_Restart) {
		delete m_Snake;
		Init();
	}

	RestartClock();
}

void Game::Draw() {
	m_Window.clear();
	m_Fruit.Draw(m_Window);
	m_Snake->Draw(m_Window);
	m_Window.display();
}

void Game::Quit() {
	m_Running = false;
}

const bool& Game::IsRunning() const {
	return m_Running;
}

const sf::RenderWindow& Game::GetWindow() const {
	return m_Window;
}

void Game::RestartClock() {
	m_ElapsedTime = m_Clock.restart();
}
