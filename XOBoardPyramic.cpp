//
// Created by Mahmoud Nael on 12/13/2023.
//
#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "BoardGame_Classes.hpp"

XOBoardPyramic::XOBoardPyramic() {
	n_rows = 3;
	n_cols = 5;
	board = new char*[n_rows];
	int numOfCol = 1;
	for (int i = 0; i < n_rows; i++) {
		board [i] = new char[numOfCol];
		for (int j = 0; j < n_cols; j++)
			board[i][j] = 0;
		numOfCol += 2;
	}
}


// Return true  if move is valid and put it on board
// within board boundaries in empty cell
// Return false otherwise
bool XOBoardPyramic::update_board (int x, int y, char mark){
	// Only update if move is valid
	if (!(x < 0 || x > 2 || y < 0 || y > 4) && (board[x][y] == 0)) {
		if (x == 0 && y != 2){
			return false;
		} else if(x == 1 && (y < 1 || y > 3)){
			return false;
		}
		board[x][y] = toupper(mark);
		n_moves++;
		return true;
	}
	else
		return false;
}

// Display the board and the pieces on it
void XOBoardPyramic::display_board() {
	cout << '\n';
	for (int i: {0,1,2}) {
		int* cols;
		int colsSize;
		if (i == 0) {
			colsSize = 1;
			cols = new int(1);
			cols[0] = 2;
		}
		else if (i == 1){
			colsSize = 3;
			cols = new int(3);
			cols[0] = 1;
			cols[1] = 2;
			cols[2] = 3;
		} else {
			colsSize = 5;
			cols = new int(5);
			cols[0] = 0;
			cols[1] = 1;
			cols[2] = 2;
			cols[3] = 3;
			cols[4] = 4;
		}
		for (int j = 0; j < colsSize; j++) {
			if(j == 0){
				cout << setw(((5 - colsSize) / 2) * 12);
			}
			if (colsSize == 3 && j == 0){
				cout << setw(((5 - colsSize) / 2) * 12 + 1);
			}
			cout << "| ";
			cout << "(" << i << "," << cols[j] << ")";
			cout << setw(2) << board [i][cols[j]] << " |";
		}
		cout << "\n-------------------------------------------------------\n";
	}
	cout << endl;
}


// Returns true if there is any winner
// either X or O
// Written in a complex way. DO NOT DO LIKE THIS.
bool XOBoardPyramic::is_winner() {
	char row_win[4], col_win[1], diag_win[2];

	col_win[0] = board[0][2] & board[1][2] & board[2][2];

	row_win[0] = board[1][1] & board[1][2] & board[1][3];
	row_win[1] = board[2][0] & board[2][1] & board[2][2];
	row_win[2] = board[2][1] & board[2][2] & board[2][3];
	row_win[3] = board[2][2] & board[2][3] & board[2][4];

	diag_win[0] = board[0][2] & board[1][1] & board[2][0];
	diag_win[1] = board[0][2] & board[1][3] & board[2][4];

	if(row_win[0] && (row_win[0] == board[1][1])){
		return true;
	}
	
	for (int i:{1,2,3}) {
		if ( (row_win[i] && (row_win[i] == board[2][i - 1])))
		{return true;}
	}
	if((col_win[0] && (col_win[0] == board[0][2]))){
		return true;
	}
	if ((diag_win[0] && diag_win[0] == board[0][2]) ||
	    (diag_win[1] && diag_win[1] == board[0][2]))
	{return true;}
	return false;
}

// Return true if 9 moves are done and no winner
bool XOBoardPyramic::is_draw() {
	return (n_moves == 9 && !is_winner());
}

bool XOBoardPyramic::game_is_over () {
	return n_moves >= 9;
}