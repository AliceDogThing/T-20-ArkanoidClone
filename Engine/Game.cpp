/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	
	aBrick(Vec2(0.0f,0.0f), Colors::Red),
	bBrick(Vec2(3.0f,5.0f), Colors::Blue),
	paddle(Vec2(330.0f,500.0f)),
	ball(Vec2( 200.0f, 270.0f), Vec2(2.0f, -2.0f))
	//
{
	int brickCount = 0;
	for (int xCount = 1; xCount < bricksX; xCount++)
	{
		for (int yCount = 1; yCount < bricksY; yCount++)
		{
			
			bricks[brickCount].Initialize(Vec2((float)xCount,(float) yCount), Colors::Magenta);
			++brickCount;
		}
	}
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	float dt = ft.Mark();
	paddle.Update(wnd.kbd, dt, gfx);
	ball.Update();
	ball.DoWallCollision(gfx);
	int brickCount = 0;
	for (int xCount = 1; xCount < bricksX; xCount++)
	{
		for (int yCount = 1; yCount < bricksY; yCount++)
		{
			if (!bricks[brickCount].destroyed) 
			{
				ball.DoBrickCollision(bricks[brickCount]);
			}
			++brickCount;
		}
	}

	ball.DoPaddleCollision(paddle);
}

void Game::ComposeFrame()
{
	paddle.Draw(gfx);
	ball.Draw(gfx);
	int brickCount = 0;
	for (int xCount = 1; xCount < bricksX; xCount++)
	{
		for (int yCount = 1; yCount < bricksY; yCount++)
		{
			if (!bricks[brickCount].destroyed)
			{
				bricks[brickCount].Draw(gfx);
			}
			++brickCount;
		}
	}
}
