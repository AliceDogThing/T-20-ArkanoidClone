#include "Paddle.h"

Paddle::Paddle(const Vec2 & pos_in)
	:
	topLeft(pos_in)
{
}

void Paddle::Update(const Keyboard& kbd, float dt, Graphics& gfx)
{

	if (kbd.KeyIsPressed(VK_LEFT))
	{
		topLeft.x -= speed * dt;
	}
	else if (kbd.KeyIsPressed(VK_RIGHT))
	{
		topLeft.x += speed * dt;
	}
	if (topLeft.x + width > gfx.ScreenWidth)
	{
		topLeft.x -= (topLeft.x + width) - gfx.ScreenWidth;
	}
	if (topLeft.x < 0)
	{
		topLeft.x -= topLeft.x;
	}
}

void Paddle::Draw(Graphics& gfx)
{
	gfx.DrawRect(RectF(topLeft, width, height), c);
}
