#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Cat {
private:
	Vector2f m_Position;
	Sprite m_Sprite;
	Texture m_Texture;

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