#include "MenuButton.h"

void MenuButton::clickHitBox()
{
}

MenuButton::MenuButton(sf::RenderWindow& window, WindowHendler& windowHandler)
	:m_window(window), m_windowHandler(m_windowHandler)

{
}

int MenuButton::get_width()
{
	return this->width;
}

int MenuButton::get_height()
{
	return this->height;
}

void MenuButton::update()
{
	clickHitBox();
}

void MenuButton::render()
{
}
