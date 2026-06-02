#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Cat {
private:
	Vector2f m_Position;
	Texture m_Texture;
	Sprite m_Sprite;

	bool m_LeftPressed = false;
	bool m_RightPressed = false;
	float m_Speed = 400.f;

public:
	Cat();

	Sprite getSprite();

	void moveLeft();
	void moveRight();
	void stopLeft();
	void stopRight();

	void update(float elapsedTime);
};