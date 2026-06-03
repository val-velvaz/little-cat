#include "Engine.hpp"

Engine::Engine()
	: m_BackgroundTexture("background.png"),
	  m_BackgroundSprite(m_BackgroundTexture)

{
	m_Window.create(VideoMode::getDesktopMode(),
		"Simple Game Engine",
		State::Fullscreen);

	sf::Vector2u windowSize = m_Window.getSize();
	sf::Vector2u textureSize = m_BackgroundTexture.getSize();

	m_BackgroundTexture.setSmooth(false);

	float scaleX = (float)windowSize.x / textureSize.x;
	float scaleY = (float)windowSize.y / textureSize.y;

	m_BackgroundSprite.setScale({ scaleX, scaleY });
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