#include "MoveBody.h"

move_body::move_body(sf::RenderWindow& window)
	: m_window_(window), to_destruction_(false)
{
}

sf::Vector2f move_body::get_position() const
{
	return this->position_;
}

int move_body::get_speed() const
{
	return this->speed_;
}

int move_body::get_damage() const
{
	return this->damage_;
}

int move_body::get_size() const
{
	return this->size_;
}

bool move_body::get_to_destruction() const
{
	return this->to_destruction_;
}

void move_body::set_speed(const int new_speed)
{
	this->speed_ = new_speed;
}

void move_body::set_damage(const int new_damage)
{
	this->damage_ = new_damage;
}

void move_body::set_size(const int new_size)
{
	this->size_ = new_size;
}

void move_body::set_texture(const sf::Texture new_texture)
{
	this->texture_ = new_texture;
}

void move_body::init_sprite(const sf::IntRect texture_pos)
{
	this->sprite_.setTexture(this->texture_);
	this->sprite_.setTextureRect(texture_pos);
}

void move_body::set_to_destruction()
{
	this->to_destruction_ = true;
}

void move_body::set_position(const sf::Vector2f new_pos)
{
	this->position_ = new_pos;
}

void move_body::update()
{
	this->position_.y -= this->speed_;
	if (this->position_.y > m_window_.getSize().y
		|| this->position_.y < 0)
	{
		this->set_to_destruction();
	}
}

void move_body::render()
{
	this->sprite_.setPosition(this->position_);
	m_window_.draw(this->sprite_);
}
