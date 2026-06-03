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
	if (Keyboard::isKeyPressed(Keyboard::Key::A) || Keyboard::isKeyPressed(Keyboard::Key::Left))
		m_Cat.moveLeft();
	else m_Cat.stopLeft();

	if (Keyboard::isKeyPressed(Keyboard::Key::D) || Keyboard::isKeyPressed(Keyboard::Key::Right))
		m_Cat.moveRight();
	else m_Cat.stopRight();

	if (Keyboard::isKeyPressed(Keyboard::Key::W) || Keyboard::isKeyPressed(Keyboard::Key::Up))
		m_Cat.jump();
}