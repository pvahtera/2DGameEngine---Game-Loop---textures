#pragma once

#include "ECS.h"
#include "PositionComponent.h"
#include "SpriteComponent.h"







/*

class PositionComponent : public Component
{
private:
	int xpos;
	int ypos;

public:
	// expose and set y and x pos
	int x() { return xpos;  }
	int y() { return ypos; }

	void init() override
	{
		xpos = 0;
		ypos = 0;
	}

	void update() override
	{
		xpos++;
		ypos++;
	}

	void setPos(int x, int y)
	{
		xpos = x;
		ypos = y;
	}
};

*/
