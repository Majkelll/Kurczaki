#pragma once

#include <SFML/Graphics.hpp>

class player
{
private:
	sf::Vector2f position_;
	sf::Texture texture_;
	sf::Sprite sprite_;
	sf::Texture shield_texture_;
	sf::Sprite shield_sprite_;
	sf::RenderWindow& m_window_;

	int hp_;
	int points_;
	float speed_;
	float shoot_speed_;
	int size_;
	int weapon_lvl_;
	int speed_lvl_;
	int shoot_lvl_;
	int shoot_timer_;

	int god_mode_timer_;
	bool god_mode_;

	sf::Texture hp_texture_;

	std::vector<sf::Sprite> hp_sprites_;

	void init_variables();
	void init_shape();
	void move_collider();
	void move();
	void hp_render() const;
	void hp_update();

public:
	explicit player(sf::RenderWindow& window);

	sf::Vector2f get_position() const;
	int get_size() const;
	int get_points() const;
	int get_hp() const;
	bool get_god_mode() const;
	float get_shoot_speed() const;
	float get_speed() const;

	void on_god_mode();
	void set_points(int new_points);
	void set_hp(int new_hp);
	void set_shoot_speed(float new_speed);
	void set_speed(float new_speed);

	bool shoot();
	void update();
	void render() const;
};
