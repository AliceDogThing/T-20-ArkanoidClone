#pragma once
#include "Vec2.h"

class RectF
{

public:
	RectF(float left_in, float right_in, float top_in, float bottom_in);
	RectF() = default;
	RectF(const Vec2& topLeft, const Vec2& bottomRight);
	RectF(const Vec2& topLeft, float width, float height);
	bool CheckCollision(const RectF& other) const;
	

public:
	float left;
	float right;
	float top;
	float bottom;


};