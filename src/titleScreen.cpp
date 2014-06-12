/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * titleScreen.cpp
 *
 */

#include "titleScreen.h"

TitleScreen::TitleScreen()
{
	Window::SetTitle("Click to start");

	Window::Clear();
	Window::Present();
}

TitleScreen::~TitleScreen()
{
	CleanUp();
}

void
TitleScreen::EventHandler(SDL_Event* event)
{
	switch (event->type) {
		case SDL_QUIT:
			timesYouTryToExit++;
			switch (timesYouTryToExit) {
				case 1:
					Window::SetTitle("NO! You haven't play it");
					break;
				case 2:
					Window::SetTitle("I say no");
					break;
				case 3:
					Window::SetTitle("I SAY NO!!");
					break;
				case 4:
					Window::SetTitle("NOOOOOO");
					break;
				case 5:
					Window::SetTitle("Fine... you won");
					break;
				case 6:
					gameIsRunning = false;
					gameState = GAME_QUIT;
					break;
			}
			break;
		case SDL_MOUSEBUTTONDOWN:
			gameIsRunning = false;
			gameState = GAME_STAGE_1;
			break;
	}
}

void
TitleScreen::Update()
{
}

void
TitleScreen::Render()
{
}

void
TitleScreen::CleanUp()
{
}
