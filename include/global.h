/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * glocal.h
 *
 */

#ifndef GLOBAL_H
#define GLOBAL_H

#define GAME_TITLE		"Rainbow-dot"
#define GAME_FPS		60

//Recored current game status
enum GameStateFlag
{
	GAME_TITLE_SCREEN = 0x00,
	GAME_STAGE_1,
	GAME_STAGE_2,
	GAME_QUIT
};

#endif
