/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * stage1.h
 *
 */

#ifndef STAGE_1_H
#define STAGE_1_H

#include <iostream>
#include <sstream>
#include <SDL.h>

#include "global.h"
#include "window.h"

#include "gameState.h"

using namespace std;

extern bool gameIsRunning;
extern enum GameStateFlag gameState;
extern int clickCount;

class Stage1: public GameState
{
	public:
		Stage1();
		~Stage1();

		void EventHandler(SDL_Event* event);
		void Update();
		void Render();
	private:
		void CleanUp();
};

#endif
