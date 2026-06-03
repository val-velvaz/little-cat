#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Cat {
private:
	Vector2f m_Position;
	Texture m_Texture;
	Sprite m_Sprite;
	const float FRAME_ANCHOR = 32.f;
	const float SCALE = 16.f;
	const float CAT_SIZE = (FRAME_ANCHOR * SCALE) / 2;

	bool m_LeftPressed = false;
	bool m_RightPressed = false;
	bool m_UpPressed = false;

	bool m_isJumping = false;

	float m_Speed = 400.f;
	float m_VerticalVelocity = 0.f;

	const float m_Gravity = 2000.f;
	const float m_JumpForce = -800.f;

	//boundaries
	const float m_FloorLevel = 800.f + CAT_SIZE;
	const float m_SkyLevel = 0.0f - CAT_SIZE;
	const float m_RightLevel = 2000.f + CAT_SIZE;
	const float m_LeftLevel = 0.f - CAT_SIZE;

public:
	Cat();

	Sprite getSprite();

	void moveLeft();
	void moveRight();

	void stopLeft();
	void stopRight();

	void moveUp();
	void stopUp();

	void jump();

	void update(float elapsedTime);
};