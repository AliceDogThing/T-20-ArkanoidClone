#pragma once

#include "RectF.h"
#include "Keyboard.h"
#include "Graphics.h"
#include "Vec2.h"

class Paddle
{
public:
	Paddle(const Vec2& pos_in);
	Paddle() = default;
	void Update(const Keyboard& kbd, float dt, Graphics& gfx);
	void Draw(Graphics& gfx);

public:
	Vec2 topLeft;
	const float width = 70.0f;
	const float height = 20.0f;
	RectF rect;
	Color c = Colors::White;
	Color wingColor;
	float speed = 300.0f;

};