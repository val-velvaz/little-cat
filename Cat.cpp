#include "Cat.hpp"

Cat::Cat() : m_Texture("cat.png"), m_Sprite(m_Texture) {
	m_Position.x = 500.f;
	m_Position.y = 800.f;

	int frameWidth = 32;
	int frameHeight = 32;

	sf::IntRect rectangle({ 0, 128 }, { frameWidth, frameHeight });
	m_Sprite.setTextureRect(rectangle);

	m_Texture.setSmooth(false);

	m_Sprite.setScale({ 16.0f, 16.0f });
}

Sprite Cat::getSprite() {
	return m_Sprite;
}

void Cat::moveLeft() {
	m_LeftPressed = true;
}
void Cat::moveRight() {
	m_RightPressed = true;
}

void Cat::stopLeft() {
	m_LeftPressed = false;
}

void Cat::stopRight() {
	m_RightPressed = false;
}

void Cat::moveUp() {
	m_UpPressed = true;
}

void Cat::stopUp() {
	m_UpPressed = false;
}

void Cat::jump() {
	if (!m_UpPressed) {
		m_VerticalVelocity = m_JumpForce;
		m_isJumping = true;
	}
}

void Cat::update(float elapsedTime) {
	// cat travels 400 pxs per second
	// regardless of fps

	if (m_RightPressed) m_Position.x += m_Speed * elapsedTime;
	if (m_LeftPressed) m_Position.x -= m_Speed * elapsedTime;

	if (m_isJumping) {
		m_VerticalVelocity += m_Gravity * elapsedTime;
	}

	m_Position.y += m_VerticalVelocity * elapsedTime;

	if (m_Position.y >= m_FloorLevel) {

		m_Position.y = m_FloorLevel;
		m_VerticalVelocity = 0.f;
		m_isJumping = false;
	}

	if (m_Position.y <= m_SkyLevel) {
		m_Position.y = m_SkyLevel ;
	}

	if (m_Position.x <= m_LeftLevel) {
		m_Position.x = m_LeftLevel;
	}

	if (m_Position.x >= m_RightLevel) {
		m_Position.x = m_RightLevel;
	}


	m_Sprite.setPosition(m_Position);
}