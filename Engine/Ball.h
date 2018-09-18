#pragma once

#include "RectF.h"
#include "Paddle.h"
#include "Brick.h"
#include "SpriteCodex.h"


class Ball
{

public:
	Ball() = default;
	Ball(Vec2 pos_in, Vec2 vel_in);

	void Update(float dt);
	void Draw(Graphics& gfx) const;
	RectF GetRect() const; 
	void DoPaddleCollision(Paddle& paddle);
	void DoBrickCollision(Brick& brick);
	void DoWallCollision(Graphics& gfx);
	bool CheckLifeLost(Graphics& gfx);
	void ReboundX();
	void ReboundY();
public:
	Vec2 pos;
	Vec2 vel;
	const float dimension = 7.0f;
	float speed = 2.0f * 60.0f;
};