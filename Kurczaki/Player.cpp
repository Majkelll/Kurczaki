#include "Player.h"

void player::init_variables()
{
	this->position_.x = 1280 / 2 - 50;
	this->position_.y = 720 - 150;
	this->hp_ = 1;
	this->points_ = 0;
	this->speed_ = 5.f;
	this->size_ = 100;
	this->shoot_speed_ = 25;
	this->weapon_lvl_ = 1;
	this->speed_lvl_ = 1;
	this->shoot_lvl_ = 1;

	this->texture_.loadFromFile("./assets/ship.png");
	this->texture_.setSmooth(true);

	this->hp_texture_.loadFromFile("./assets/heart.png");
	this->hp_texture_.setSmooth(true);

	this->shield_texture_.loadFromFile("./assets/shield.png");
	this->shield_texture_.setSmooth(true);
}

void player::init_shape()
{
	this->sprite_.setTexture(this->texture_);
	this->sprite_.setTextureRect(sf::IntRect(0, 0, 100, 100));

	this->shield_sprite_.setTexture(this->shield_texture_);
	this->shield_sprite_.setTextureRect(sf::IntRect(0, 0, 100, 100));
}

void player::move_collider()
{
	if (this->position_.x + this->size_ > m_window_.getSize().x)
	{
		this->position_.x = m_window_.getSize().x - this->size_;
		this->position_.y = this->position_.y;
	}
	if (this->position_.x < 0)
	{
		this->position_.x = 0;
		this->position_.y = this->position_.y;
	}
	if (this->position_.y < 0)
	{
		this->position_.x = this->position_.x;
		this->position_.y = 0;
	}
	if (this->position_.y > 720 - this->size_)
	{
		this->position_.x = this->position_.x;
		this->position_.y = m_window_.getSize().y - this->size_;
	}
}

void player::move()
{
	sf::Vector2f velocity(0.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		velocity.x -= this->speed_;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		velocity.x += this->speed_;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		velocity.y += this->speed_;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		velocity.y -= this->speed_;
	}
	this->position_.x += velocity.x;
	this->position_.y += velocity.y;

	this->move_collider();
}

void player::hp_render() const
{
	for (const auto& hp_sprite : this->hp_sprites_)
	{
		m_window_.draw(hp_sprite);
	}
}

void player::hp_update()
{
	if (this->hp_ != this->hp_sprites_.size())
	{
		hp_sprites_.clear();
		for (int i = 0; i < this->hp_; i++)
		{
			sf::Sprite temp;
			temp.setTexture(this->hp_texture_);
			temp.setTextureRect(sf::IntRect(0, 0, 40, 40));
			temp.setPosition(sf::Vector2f(m_window_.getSize().x - 60 - (i * 40), 20.f));
			hp_sprites_.push_back(temp);
		}
	}
}

sf::Vector2f player::get_position() const
{
	return this->position_;
}

int player::get_size() const
{
	return this->size_;
}

int player::get_points() const
{
	return this->points_;
}

void player::on_god_mode()
{
	this->god_mode_ = true;
	this->god_mode_timer_ = 300;
}

void player::set_points(const int new_points)
{
	this->points_ = new_points;
}

void player::set_hp(const int new_hp)
{
	this->hp_ = new_hp;
}

void player::set_shoot_speed(const float new_speed)
{
	this->shoot_speed_ = new_speed;
	if (new_speed < 0)
	{
		this->shoot_speed_ = 0;
	}
}

void player::set_speed(const float new_speed)
{
	this->speed_ = new_speed;
}

int player::get_hp() const
{
	return this->hp_;
}

bool player::get_god_mode() const
{
	return this->god_mode_;
}

float player::get_shoot_speed() const
{
	return this->shoot_speed_;
}

float player::get_speed() const
{
	return this->speed_;
}

bool player::shoot()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->shoot_timer_ < 0)
	{
		this->shoot_timer_ = this->shoot_speed_;
		return true;
	}
	this->shoot_timer_ -= 1;
	return false;
}

player::player(sf::RenderWindow& window)
	: m_window_(window)
{
	this->init_variables();
	this->init_shape();
}

void player::update()
{
	if (this->god_mode_timer_ > 0 && this->god_mode_ == true)
	{
		this->god_mode_timer_--;
	}
	else
	{
		this->god_mode_ = false;
	}
	this->move();
	this->shoot();
	this->hp_update();
	this->shield_sprite_.setPosition(this->position_);
	this->sprite_.setPosition(this->position_);
}

void player::render() const
{
	m_window_.draw(this->sprite_);
	if (this->god_mode_)
	{
		m_window_.draw(this->shield_sprite_);
	}
	this->hp_render();
}
