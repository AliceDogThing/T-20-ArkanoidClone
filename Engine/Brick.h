#pragma once

#include "RectF.h"
#include "Colors.h"
#include "Graphics.h"

class Brick
{
public:
	Brick(Vec2 pos_in, Color color_in);
	Brick() = default;
	void Draw(Graphics& gfx) const;
	RectF GetRect() const;
	void Initialize(const Vec2& pos_inn, Color c_in);
public:
	Vec2 pos;
	Color color;
	bool destroyed = false;
	float width = 80.0f;
	float height = 25.0f;
	float buffer = 2.0f;
private:

};