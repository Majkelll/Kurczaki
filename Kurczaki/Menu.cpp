#include "Menu.h"

void menu::init_variables()
{
	this->button_size_ = sf::Vector2f(500, 100);
	this->button_position_ = sf::Vector2f(1280 / 2 - this->button_size_.x / 2, 300);

	this->background_texture_.loadFromFile("./assets/menu.png");
	this->background_texture_.setSmooth(true);

	this->background_sprite_.setTexture(this->background_texture_);
	this->background_sprite_.setTextureRect(sf::IntRect(0, 0, 1280, 720));
	this->background_sprite_.setPosition(0, 0);

	this->buttons_.emplace_back(this->button_position_, 1, this->button_size_, "Play", this->m_window_);
	this->buttons_.emplace_back(sf::Vector2f(this->button_position_.x, this->button_position_.y + 120), 2,
	                            this->button_size_, "Exit", this->m_window_);
}

bool menu::button_hit_box(sf::Vector2f button_pos, const sf::Vector2i mouse_pos) const
{
	int size2 = 1;
	if (button_pos.x < mouse_pos.x + 1 &&
		button_pos.x + this->button_size_.x > mouse_pos.x &&
		button_pos.y < mouse_pos.y + 1 &&
		this->button_size_.y + button_pos.y > mouse_pos.y)
	{
		return true;
	}
	return false;
}

void menu::render_background() const
{
	this->m_window_.draw(this->background_sprite_);
}

void menu::update_state()
{
	for (auto& b : this->buttons_)
	{
		if (this->button_hit_box(b.get_position(), this->mouse_pos_)
			&& sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (b.get_name() == "Play")
			{
				this->m_window_handler_.set_render_state(2);
			}
			if (b.get_name() == "Exit")
			{
				m_window_.close();
			}
		}
	}
}

menu::menu(sf::RenderWindow& window, window_handler& new_window_handler)
	: m_window_(window), m_window_handler_(new_window_handler)
{
	this->init_variables();
}

void menu::update()
{
	this->mouse_pos_ = sf::Mouse::getPosition(this->m_window_);
	this->update_state();
}

void menu::render() const
{
	m_window_.clear();

	this->render_background();

	m_window_.display();
}
