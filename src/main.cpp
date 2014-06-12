/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * main.cpp
 *
 */

#include <iostream>

#include "global.h"
#include "window.h"

#include "gameState.h"
#include "titleScreen.h"
#include "stage1.h"
#include "stage2.h"
#include "timer.h"

int screenW;
int screenH;

int windowW;
int windowH;

bool gameIsRunning = true;

enum GameStateFlag gameState;

GameState* game = NULL;

int clickCount = 0;

int
Init()
{
	//Initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0){
		fprintf(stderr, "Error while init SDL subsystem: %s\n", SDL_GetError());
		exit(1);
	}

	//TODO: Maybe I should make another class to handle these thing
	if (IMG_Init(IMG_INIT_PNG) < 0) {
		fprintf(stderr, "Error while init SDL_image: %s\n", IMG_GetError());
		exit(1);
	}

	//Get current displayer size and data
	SDL_DisplayMode mode;
	SDL_GetCurrentDisplayMode(0, &mode);

	screenW = mode.w;
	screenH = mode.h;

	windowW = screenW / 10;
	windowH = screenH / 10;

	Window::Init(GAME_TITLE, windowW, windowH);

	gameState = GAME_TITLE_SCREEN;

	return 0;
}

void
CleanUp()
{
	Window::Quit();
	SDL_Quit();
	IMG_Quit();
}

void
EventHandler(SDL_Event* event)
{
}

int
main(int argc, char* argv[])
{
	if (Init() < 0)
		return 1;

	SDL_Event event;
	Timer timer;

	//Here we go!
	while (1) {
		//Swtich game status
		switch (gameState) {
			case GAME_TITLE_SCREEN:
				game = new TitleScreen();
				gameIsRunning = true;
				break;

			case GAME_STAGE_1:
				game = new Stage1();
				gameIsRunning = true;
				break;

			case GAME_STAGE_2:
				game = new Stage2();
				gameIsRunning = true;
				break;

			case GAME_QUIT:
				return 0;
				break;
		}
		//Main game loop
		while (gameIsRunning) {
			timer.Start();

			while (SDL_PollEvent(&event))
					game->EventHandler(&event);

			game->Update();
			game->Render();	

			if (timer.GetTicks() < (1000 / GAME_FPS))
				SDL_Delay((1000 / GAME_FPS) - timer.GetTicks());
		}

		delete game;
	}

	CleanUp();

	return 0;
}
