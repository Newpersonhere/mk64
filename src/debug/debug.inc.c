#include <ultra64.h>
#include <debug.h>
#include "all_variables.h"

#if DVDL

extern s32 gGlobalTimer;

/** 
 * Edit this to edit what displays on the screen while the DVDL is active.
 * The Size of the structure array is calculated at compile time.
 */
variableWatchAttributes gMainVariableWatchList[] = {
	{
		"Global Timer: ",
		&gGlobalTimer,
		sizeof(gGlobalTimer), 
		DISPLAY_DECIMAL_NUMBER | DISPLAY_SIGNED_NUMBER,
		0, 0
	},
	{
		"Actors: ",
		&gNumActors,
		sizeof(gNumActors), 
		DISPLAY_DECIMAL_NUMBER,
		0, 0
	},
	{
		"Player Type: ",
		&gPlayers[0].unk_000,
		sizeof(gPlayerOne->unk_000), 
		DISPLAY_HEXIDECIMAL_NUMBER,
		0, 0
	},
	{
		"X ",
		&gPlayers[0].pos[0],
		sizeof(gPlayerOne->pos[0]), 
		DISPLAY_FLOAT_NUMBER,
		0, 0
	},
	{
		"Y ",
		&gPlayers[0].pos[1],
		sizeof(gPlayerOne->pos[1]), 
		DISPLAY_FLOAT_NUMBER,
		0, 0
	},
	{
		"Z ",
		&gPlayers[0].pos[2],
		sizeof(gPlayerOne->pos[2]), 
		DISPLAY_FLOAT_NUMBER,
		0, 0
	},
};

#endif
