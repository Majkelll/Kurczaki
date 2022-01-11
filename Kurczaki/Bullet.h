#pragma once
#include "MoveBody.h"

class bullet final : public move_body
{
public:
	void init_variables(sf::Vector2f new_position);
	using move_body::move_body;
};
