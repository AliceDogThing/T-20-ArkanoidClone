#include "RectF.h"

RectF::RectF(float left_in, float right_in, float top_in, float bottom_in)
	:
	left (left_in),
	right(right_in),
	top(top_in),
	bottom(bottom_in)
{
}

RectF::RectF(const Vec2 & topLeft, const Vec2 & bottomRight)
	:
	RectF(topLeft.x, bottomRight.x,topLeft.y,bottomRight.y)
	/*
	left(topLeft.x),
	right(bottomRight.x),
	top(topLeft.y),
	bottom(bottomRight.y)
	*/
{
}

RectF::RectF(const Vec2 & topLeft, float width, float height)
	:
	RectF(topLeft.x, topLeft.x+width, topLeft.y,topLeft.y + height)

	//left(topLeft.x),
	//right(topLeft.x + width),
	//top(topLeft.y),
	//bottom(topLeft.y+height)

{
}

bool RectF::CheckCollision(const RectF & other) const
{
	return
		(left < other.right && right > other.left &&
		top < other.bottom && bottom > other.top);

}
