#pragma once
#include "MoveBody.h"

class power_up : public move_body
{
private:
	int buff_;
	int buff_value_;
public:
	int get_buff() const;
	int get_buff_value() const;
	void init_variables(sf::Vector2f new_pos);
	using move_body::move_body;
};
