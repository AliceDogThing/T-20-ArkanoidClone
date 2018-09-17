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
	
	aRect( Vec2(40.0f, 30.0f), Vec2(110.0f, 150.0f)),
	bRect(Vec2(220.0f, 200.0f), Vec2(300.0f, 300.0f)),
	aBrick(aRect, Colors::Red),
	bBrick(bRect, Colors::Blue),
	paddle(Vec2(330.0f,500.0f)),
	ball(Vec2( 200.0f, 270.0f), Vec2(2.0f,-2.0f))
{
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
	ball.DoBrickCollision(aBrick);
	ball.DoBrickCollision(bBrick);
	ball.DoPaddleCollision(paddle);
}

void Game::ComposeFrame()
{
	aBrick.Draw(gfx);
	bBrick.Draw(gfx);
	paddle.Draw(gfx);
	ball.Draw(gfx);
}
