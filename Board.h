#pragma once
#include <string>
#include <vector>

const int TIE_VAL = -1;
// Indexes for board values
const int NO_VAL = 0;
const int XVAL = 1;
const int OVAL = 2;

class Board
{
public:
	//initialize the board
	void init(int size);

	//clear the board
	void clear();

	//print the board
	void print() const;

	//check if there's a winner on the current board
	int checkVictory() const;

	// Sets value at x,y spot
	void setVal(int x, int y, int val) {
		_board[y * _size + x] = val;
	}

	// Gets value at x,y spot
	int getVal(int x, int y) const {
		return _board[y * _size + x];
	}

	// Getters
	int getSize() const { return _size; }


private:
	//add horizontal line while printing
	void addHorizontalLine(std::string& s) const;

	//add vertical lguide lines while printing
	void addGuide(std::string& s) const;

	int _size;
	std::vector<int> _board;
};

