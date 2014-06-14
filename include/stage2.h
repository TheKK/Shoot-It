/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * stage2.h
 *
 */

#ifndef STAGE_2_H
#define STAGE_2_H

#include <iostream>
#include <sstream>
#include <cmath>
#include <SDL.h>

#include "global.h"
#include "window.h"

#include "gameState.h"

using namespace std;

extern int screenW;
extern int screenH;

extern int windowW;
extern int windowH;

extern bool gameIsRunning;
extern enum GameStateFlag gameState;
extern int clickCount;

class Stage2: public GameState
{
	public:
		Stage2();
		~Stage2();

		void EventHandler(SDL_Event* event);
		void Update();
		void Render();
	private:
		int vanishTime = 50;
		int currentTime = 0;

		void CleanUp();
};

#endif
