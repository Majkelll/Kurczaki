#pragma once
#include "MoveBody.h"

class egg final : public move_body
{
private:
	int damage_;
public:
	int get_damage() const;
	void init_variables(sf::Vector2f new_pos);
	using move_body::move_body;
};
