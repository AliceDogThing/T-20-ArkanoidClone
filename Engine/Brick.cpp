#include "Brick.h"

Brick::Brick(Vec2 pos_in, Color color_in)
	:
	pos(pos_in),
	color(color_in)
{

}

void Brick::Draw(Graphics& gfx) const
{
	Vec2 drawnSpot = Vec2(pos.x * width + buffer, pos.y * height + buffer);
	gfx.DrawRect(RectF(drawnSpot, width - buffer, height - buffer), color);
}

RectF Brick::GetRect() const
{
	Vec2 drawnSpot = Vec2(pos.x * width, pos.y * height);
	return RectF(drawnSpot, width, height);
}

void Brick::Initialize(const Vec2 & pos_inn, Color c_in)
{
	pos = pos_inn;
	color = c_in;
}
