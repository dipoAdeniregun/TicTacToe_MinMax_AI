#pragma once
#include "Board.h"
#include <vector>

struct AiMove {
	AiMove() {};
	AiMove(int _score) : score(_score) {};
	int x;
	int y;
	int score;
};

class AI
{
private:
	int _aiPlayer;
	int _humanPlayer;

	AiMove getBestMove(Board& board, int player);

public:
	//initializes ai player
	void init(int aiPlayer);

	//performs the ai move
	void performMove(Board& board);
};

