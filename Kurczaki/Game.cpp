#include "Game.h"

void game::init_variables()
{
	this->background_texture_.loadFromFile("./assets/background.jpg");
	this->background_texture_.setSmooth(true);

	this->background_sprite_.setTexture(this->background_texture_);
	this->background_sprite_.setTextureRect(sf::IntRect(0, 0, 1280, 720));

	this->current_lvl_ = 1;
	init_text_score();
}

void game::init_text_score()
{
	this->font_.loadFromFile("./assets/font.ttf");
	this->text_score_.setFont(this->font_);
	this->text_score_.setString("Score: 0");
	this->text_score_.setCharacterSize(40);
	this->text_score_.setOrigin(-20, -10);
}

void game::update_lvl()
{
	if (this->enemies_.empty())
	{
		this->current_lvl_++;
		this->generate_lvl(this->current_lvl_);
	}
}

game::game(sf::RenderWindow& window, window_handler& new_window_handler)
	: m_window_(window), m_window_handler_(new_window_handler), player_(window)
{
	this->init_variables();
	this->generate_lvl(this->current_lvl_);
}

void game::generate_lvl(const int level)
{
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			enemies_.emplace_back(std::make_unique<enemy>(sf::Vector2f(40 + 100.f * i, 60 + 100.f * j), m_window_));
		}
	}

	for (auto& e : enemies_)
	{
		e->set_hp(e->get_hp() * level);
	}
}

void game::update_eggs()
{
	for (auto egg = eggs_.begin(); egg != eggs_.end(); ++egg)
	{
		egg->update();
		if (egg->get_to_destruction())
		{
			this->eggs_.erase(egg);
		}
		if ((this->collider(this->player_.get_position(), egg->get_position(), this->player_.get_size(),
		                    egg->get_size()))
			&& !this->player_.get_god_mode())
		{
			this->player_.set_hp(this->player_.get_hp() - 1);
			this->eggs_.erase(egg);
		}
	}
}

void game::update_bullets()
{
	for (int i = 0; i < this->bullets_.size(); i++)
	{
		bullets_[i]->update();
		if (bullets_[i]->get_to_destruction())
		{
			this->bullets_.erase(this->bullets_.begin() + i);
		}
	}
}

void game::update_hit_box_bullets_enemies()
{
	for (int j = 0; j < this->bullets_.size(); j++)
	{
		for (const auto& enemy : this->enemies_)
		{
			if (this->collider(bullets_[j]->get_position(), enemy->get_position(), bullets_[j]->get_size(),
			                   enemy->get_size()))
			{
				enemy->set_hp(enemy->get_hp() - bullets_[j]->get_damage());
				this->bullets_.erase(this->bullets_.begin() + j);
			}
		}
	}
}

void game::update_shoot()
{
	if (player_.shoot())
	{
		bullets_.emplace_back(std::make_unique<bullet>(m_window_));
		bullets_[bullets_.size() - 1]->init_variables(sf::Vector2f(
			this->player_.get_position().x + this->player_.get_size() / 2,
			this->player_.get_position().y));
	}
}

void game::update_enemies()
{
	for (int i = 0; i < this->enemies_.size(); i++)
	{
		enemies_[i]->update();
		if (rand() % (3000 / this->current_lvl_) == 500)
		{
			this->eggs_.emplace_back(m_window_);
			eggs_.back().init_variables(this->enemies_[i]->get_position());
		}
		if (rand() % 5000 == 100)
		{
			this->generate_power_ups(this->enemies_[i]->get_position());
		}
		if (this->enemies_[i]->get_hp() <= 0)
		{
			this->enemies_.erase(this->enemies_.begin() + i);
			this->player_.set_points(this->player_.get_points() + 5 * this->current_lvl_);
		}
	}
}

void game::update()
{
	this->m_window_handler_.set_score(this->player_.get_points());
	this->state_handler();
	this->update_shoot();
	this->player_.update();
	this->update_text();
	this->update_enemies();
	this->update_lvl();
	this->update_power_ups();
	this->update_eggs();
	this->update_bullets();
	this->update_hit_box_bullets_enemies();
}

void game::render()
{
	m_window_.clear();

	this->render_background();
	this->render_enemies();
	this->player_.render();
	this->render_score();
	this->render_power_ups();
	this->render_eggs();
	this->render_bullets();

	m_window_.display();
}

bool game::collider(sf::Vector2f pos1, sf::Vector2f pos2, int size1, int size2)
{
	if (pos1.x < pos2.x + size2 &&
		pos1.x + size1 > pos2.x &&
		pos1.y < pos2.y + size2 &&
		size1 + pos1.y > pos2.y
	)
	{
		return true;
	}
	return false;
}

void game::generate_power_ups(sf::Vector2f pos)
{
	this->power_ups_.emplace_back(m_window_);
	power_ups_.back().init_variables(pos);
}

void game::state_handler()
{
	if (player_.get_hp() <= 0)
	{
		this->m_window_handler_.set_render_state(3);
	}
}

void game::render_power_ups()
{
	for (auto& p : this->power_ups_)
	{
		p.render();
	}
}

void game::render_enemies() const
{
	for (int i = 0; i < this->enemies_.size(); i++)
	{
		enemies_[i]->render();
	}
}

void game::render_background() const
{
	m_window_.draw(this->background_sprite_);
}

void game::render_score() const
{
	m_window_.draw(this->text_score_);
}

void game::render_eggs()
{
	for (auto& e : this->eggs_)
	{
		e.render();
	}
}

void game::render_bullets() const
{
	for (int i = 0; i < this->bullets_.size(); i++)
	{
		bullets_[i]->render();
	}
}

void game::update_power_ups()
{
	for (auto buff = power_ups_.begin(); buff != power_ups_.end(); ++buff)
	{
		buff->update();
		if (buff->get_to_destruction())
		{
			this->power_ups_.erase(buff);
		}
		if (this->collider(this->player_.get_position(), buff->get_position(), this->player_.get_size(),
		                   buff->get_size()))
		{
			switch (buff->get_buff())
			{
			case 0:
				this->player_.set_hp(this->player_.get_hp() + 1);
				break;
			case 1:
				this->player_.on_god_mode();
				break;
			case 2:
				this->player_.set_shoot_speed(this->player_.get_shoot_speed() - 10);
				break;
			case 3:
				for (auto& a : this->eggs_)
				{
					a.set_speed(a.get_speed() + 4);
				}
				break;
			case 4:
				this->player_.set_speed(this->player_.get_speed() + 1);
				break;
			}
			this->power_ups_.erase(buff);
		}
	}
}

void game::update_text()
{
	this->text_score_.setString("Score: " + std::to_string(this->player_.get_points()));
}
