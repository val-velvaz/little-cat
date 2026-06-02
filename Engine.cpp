#include "Engine.hpp"

Engine::Engine()
	: m_BackgroundTexture("background.png"),
	  m_BackgroundSprite(m_BackgroundTexture)

{
	m_Window.create(VideoMode::getDesktopMode(),
		"Simple Game Engine",
		State::Fullscreen);

}

void Engine::start() {
	Clock clock;

	while (m_Window.isOpen()) {
		Time dt = clock.restart();
		float dtAsSeconds = dt.asSeconds();

		input();
		update(dtAsSeconds);
		draw();
	}
}