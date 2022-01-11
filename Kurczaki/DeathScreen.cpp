#include "DeathScreen.h"

void death_screen::init_variables()
{
	this->button_size_ = sf::Vector2f(500, 100);
	this->button_position_ = sf::Vector2f(1280 / 2 - this->button_size_.x / 2, 300);

	this->lose_texture_.loadFromFile("./assets/lose.png");
	this->lose_texture_.setSmooth(true);

	this->lose_sprite_.setTexture(this->lose_texture_);
	this->lose_sprite_.setTextureRect(sf::IntRect(0, 0, 1280, 720));
	this->lose_sprite_.setPosition(0, 0);

	this->buttons_.emplace_back(sf::Vector2f(this->button_position_.x, this->button_position_.y + 240), 2,
	                            this->button_size_, "Exit", this->m_window_);
}

void death_screen::render_score()
{
	this->text_score_.setString("Score: " + std::to_string(this->m_window_handler_.get_score()));
	m_window_.draw(this->text_score_);
}

void death_screen::render_background() const
{
	this->m_window_.draw(this->lose_sprite_);
}

void death_screen::init_text()
{
	this->font_.loadFromFile("./assets/font.ttf");
	this->text_score_.setFont(this->font_);
	this->text_score_.setString("Score: 0");
	this->text_score_.setCharacterSize(80);
	this->text_score_.setOrigin(-500, -300);
}

void death_screen::update_state()
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
		button::update();
	}
}

bool death_screen::button_hit_box(const sf::Vector2f button_pos, const sf::Vector2i mouse_pos) const
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

death_screen::death_screen(sf::RenderWindow& window, window_handler& new_window_handler)
	: m_window_(window), m_window_handler_(new_window_handler)
{
	this->init_variables();
	this->init_text();
}

void death_screen::update()
{
	this->mouse_pos_ = sf::Mouse::getPosition(this->m_window_);
	this->update_state();
}

void death_screen::render()
{
	m_window_.clear();

	this->render_background();
	this->render_score();

	m_window_.display();
}
