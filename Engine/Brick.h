#pragma once

#include "Vec2.h"
#include "RectF.h"
#include "Colors.h"
#include "Graphics.h"

class Brick
{
public:
	Brick(RectF rect_in, Color color_in);
	Brick() = default;
	void Draw(Graphics& gfx) const;
public:
	RectF rect;
	Color color;
	bool destroyed;

private:

};