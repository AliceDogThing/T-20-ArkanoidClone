#include "Ball.h"

Ball::Ball(Vec2 pos_in, Vec2 vel_in)
	:
	pos(pos_in),
	vel(vel_in)
{
}

void Ball::Update(float dt)
{
	pos += vel * speed * dt;
}

void Ball::Draw(Graphics & gfx) const
{
	SpriteCodex::DrawBall(pos , gfx);
	//+ Vec2(dimension, dimension)
}

RectF Ball::GetRect() const
{
	return RectF(pos.x - dimension, pos.x+ dimension, pos.y - dimension, pos.y + dimension);
}

void Ball::DoPaddleCollision(Paddle & paddle)
{
	if (GetRect().CheckCollision(paddle.GetRect()))
	{
		if (pos.y < paddle.GetRect().top)
		{
			pos.y = paddle.topLeft.y - (2 * dimension);
			ReboundY();
		}
		else if (pos.y + dimension < paddle.GetRect().bottom && pos.y > paddle.GetRect().top)
		{
			if (pos.x + dimension < paddle.GetRect().right)
				pos.x = paddle.GetRect().left - (2*dimension);
			if (pos.x + dimension > paddle.GetRect().left)
				pos.x = paddle.GetRect().right + (2 * dimension);
			ReboundX();
		}
		
	}
}





void Ball::DoBrickCollision(Brick & brick)
{
	if (GetRect().CheckCollision(brick.GetRect()))
	{
		brick.destroyed = true;
		if (pos.y + dimension < brick.GetRect().bottom && pos.y > brick.GetRect().top)
		{
			ReboundX();
		}
		else
		{
			if (pos.y > brick.GetRect().top) 
				pos.y += dimension;
			else if (pos.y + 2*dimension < brick.GetRect().bottom)
				pos.y -= dimension;

			ReboundY();
		}
	}
}

void Ball::DoWallCollision(Graphics & gfx)
{
	if (pos.x - dimension< 0)
	{
		pos.x = dimension;
		vel.x = -vel.x;
	}
	else if ((pos.x + dimension)  > gfx.ScreenWidth)
	{
		pos.x = gfx.ScreenWidth - (dimension);
		vel.x = -vel.x;
	}

	if ((pos.y - dimension) < 0)
	{
		pos.y = dimension;
		vel.y = -vel.y;
	}

}

void Ball::ReboundX()
{
	vel.x = -vel.x;
}

void Ball::ReboundY()
{
	vel.y = -vel.y;
}