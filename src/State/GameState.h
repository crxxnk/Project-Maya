#pragma once

enum GameState {
	EDITOR,
	GAME,
	PAUSED
};
extern GameState currentState;