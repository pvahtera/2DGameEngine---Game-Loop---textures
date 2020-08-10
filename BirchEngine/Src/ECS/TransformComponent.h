#pragma once

#include "Components.h"


class TransformComponent : public Component
{
private:
	int xpos;
	int ypos;

public:

	//set up a default value
	TransformComponent()
	{
		xpos = 0;
		ypos = 0;
	}

	TransformComponent(int x, int y)
	{
		xpos = x;
		ypos = y;

	}

	void update() override
	{
		xpos++;
		ypos++;
	}

	/*
	// expose and set y and x pos
	int x() { return xpos; }
	int y() { return ypos; }
	*/


	int x() { return xpos; }
	void x(int x) { xpos = x; }
	int y() { return ypos; }
	void y(int y) { ypos = y; }
	void setPos(int x, int y) { xpos = x; ypos = y; }

};
