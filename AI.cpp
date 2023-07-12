#include "AI.h"

//select 'x' or 'o' value for player and ai
void AI::init(int aiPlayer) {
	_aiPlayer = aiPlayer;

	if (aiPlayer == XVAL) {
		_humanPlayer = OVAL;
	}
	else {
		_humanPlayer = XVAL;
	}
}

//perform the best possible move
void AI::performMove(Board& board) {
	AiMove bestMove = getBestMove(board, _aiPlayer);
	board.setVal(bestMove.x, bestMove.y, _aiPlayer);
}

//perform recursive minimax algorithm
AiMove AI::getBestMove(Board& board, int player) {

	int winner = board.checkVictory();
	if (winner == _aiPlayer) {
		return AiMove(10);
	}
	else if (winner == _humanPlayer) {
		return AiMove(-10);
	}
	else if (winner == TIE_VAL) {
		return AiMove(0);
	}

	std::vector<AiMove> moves;

	for (size_t y = 0; y < board.getSize(); y++) {
		for (size_t x = 0; x < board.getSize(); x++) {
			if (board.getVal(x, y) == NO_VAL) {
				AiMove move;
				move.x = x;
				move.y = y;
				board.setVal(x, y, player);

				//check whose turn it is
				if (player == _aiPlayer) {
					move.score = getBestMove(board, _humanPlayer).score;
				}
				else {
					move.score = getBestMove(board, _aiPlayer).score;
				}
				moves.push_back(move);

				board.setVal(x, y, NO_VAL);
			}
		}
	}
	int bestMove = 0;

	//maximize score if the current player is an ai player
	if (player == _aiPlayer) {
		int bestScore = -1000000;
		for (int i = 0; i < moves.size(); i++) {
			if (moves[i].score > bestScore) {
				bestMove = i;
				bestScore = moves[i].score;
			}
		}
	}

	//minimize score if current player is human opponent
	else {
		if (player == _humanPlayer) {
			int bestScore = 1000000;
			for (int i = 0; i < moves.size(); i++) {
				if (moves[i].score < bestScore) {
					bestMove = i;
					bestScore = moves[i].score;
				}
			}
		}
	}
	return moves[bestMove];
}
