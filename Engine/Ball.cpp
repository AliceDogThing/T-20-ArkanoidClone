#include "Ball.h"

Ball::Ball(Vec2 pos_in, Vec2 vel_in)
	:
	pos(pos_in),
	//Vec2(pos.x - (dimension/2),pos.y - (dimension/2))
	vel(vel_in)
{
}

void Ball::Update()
{
	pos += vel;
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
		if (pos.y + dimension < paddle.GetRect().bottom && pos.y > paddle.GetRect().top)
		{
			if (pos.x < paddle.GetRect().right)
				pos.x = paddle.GetRect().left - dimension;
			if (pos.x > paddle.GetRect().left)
				pos.x = paddle.GetRect().right + dimension;
			ReboundX();
		}
		else if (pos.y < paddle.GetRect().top)
		{
			//pos.y -= 1;
			ReboundY();
		}
	}
}





void Ball::DoBrickCollision(Brick & brick)
{
	if (GetRect().CheckCollision(brick.rect))
	{
		brick.destroyed = true;
		if (pos.y + dimension < brick.rect.bottom && pos.y > brick.rect.top)
		{
			ReboundX();
		}
		else
		{
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