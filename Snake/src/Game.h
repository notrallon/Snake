#pragma once

#include "Common.h"
#include "GameObjects/Snake.h"
#include "GameObjects/Fruit.h"

class Game {
public:
								~Game();

	static Game* Instance() {
		if (m_Instance == nullptr) {
			m_Instance = new Game();
		}
		return m_Instance;
	}

	void						Init();
	void						Restart();

	void						HandleEvents();
	void						Update();
	void						LateUpdate();
	void						Draw();
	void						Quit();

	const bool&					IsRunning() const;
	const sf::RenderWindow&		GetWindow() const;

private:
								Game();
	static Game*				m_Instance;

	sf::RenderWindow			m_Window;
	sf::Clock					m_Clock;
	sf::Time					m_ElapsedTime;

	bool						m_Running;
	bool						m_Restart;

	Snake*						m_Snake;
	Fruit						m_Fruit;

	void						RestartClock();
};
