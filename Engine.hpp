#pragma once
#include <SFML/Graphics.hpp>
#include "Cat.hpp"

using namespace sf;

class Engine {
private:
	RenderWindow m_Window;
	Texture m_BackgroundTexture;
	Sprite m_BackgroundSprite;

	Cat m_Cat;

	void input();
	void update(float dtAsSeconds);
	void draw();

public:
	Engine();
	void start();
};