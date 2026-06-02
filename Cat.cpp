#include "Cat.hpp"

Cat::Cat() : m_Texture("cat.png"), m_Sprite(m_Texture) {
	m_Position.x = 500.f;
	m_Position.y = 800.f;
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

void Cat::update(float elapsedTime) {
	// cat travels 400 pxs per second
	// regardless of fps

	if (m_RightPressed) m_Position.x += m_Speed * elapsedTime;
	if (m_LeftPressed) m_Position.x += m_Speed * elapsedTime;

	m_Sprite.setPosition(m_Position);
}