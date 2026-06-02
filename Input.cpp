#include "Engine.hpp"

void Engine::input() {
	// os event queue
	while (const auto event = m_Window.pollEvent()) {
		if (event->is<Event::Closed>())
			m_Window.close();
	}

	if (Keyboard::isKeyPressed(Keyboard::Key::Escape))
		m_Window.close();

	// movement
	if (Keyboard::isKeyPressed(Keyboard::Key::A))
		m_Cat.moveLeft();

	else m_Cat.stopLeft();

	if (Keyboard::isKeyPressed(Keyboard::Key::D))
		m_Cat.moveRight();
	else m_Cat.stopRight();
}