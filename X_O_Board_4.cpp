//
// Created by Mohamed Fathy on 12/16/2023.
//
//
// Created by Mohamed Fathy on 12/16/2023.
//
#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "BoardGame_Classes.hpp"
using namespace std;
X_O_Board_4::X_O_Board_4() {
    n_rows =7 ;
    n_cols = 6;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}

void X_O_Board_4::display_board() {
    for (int i: {0,1,2,3,4,5,6}) {
        cout << "\n| ";
        for (int j: {0,1,2,3,4,5}) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board [i][j] << " |";
        }
        cout << "\n-----------------------------";
    }
    cout << endl;
}
bool X_O_Board_4::is_draw() {
    return (n_moves == 42 && !is_winner());
}

bool X_O_Board_4::game_is_over () {
    return n_moves >= 42;
}
bool X_O_Board_4::update_board (int x, int y, char mark){
    // Only update if move is valid
    if (!(x < 0 || x > 7 || y < 0 || y > 6) && (board[x][y] == 0)) {
        for(int i=6;i>=0;i--) {
            if(board[i][y]==0) {
                board[i][y] = toupper(mark);
                n_moves++;
                break;
            }
        }
        return true;
    }
    else
        return false;
}
bool X_O_Board_4::is_winner() {
    char row_win[7], col_win[6], diag_win[2];

    for(int i=0;i<3;i++){
        for(int j=6;j>=0;j--) {
            if (i + 3 < 6) {
                if (board[j][i] == board[j][i + 1] && board[j][i + 1] == board[j][i + 2]) {
                if (board[j][i + 2] == board[j][i + 3]) {
                    if(board[j][3]=='X'||board[j][3]=='O') {
                        return true;
                    }
                    }else return false;
                }
            }
        }
    }
    for(int i=6;i>=0;i--){
        for(int j=0;j<6;j++) {
            if (i-3>=0) {
                if (board[i][j] == board[i-1][j] && board[i-1][j] == board[i-2][j]) {
                    if (board[i-2][j] == board[i-3][j]) {
                        if(board[3][j]=='X'||board[3][j]=='O') {
                            return true;
                        }
                    }else return false;
                }
            }
        }
    }
    for(int i=0;7>i;++i){
        for(int j=0;6>j;++j){
            if(i>3 || j>2){continue;}
            if((board[i][j]&board[i+1][j+1]&board[i+2][j+2]&board[i+3][j+3])=='O' || (board[i][j]&board[i+1][j+1]&board[i+2][j+2]&board[i+3][j+3])=='X'){
                return true;
            }
        }
    }

    for(int i=0;7>i;++i){
        for(int j=6;0<j;--j){
            if(i>3 || j<2){continue;}
            if((board[i][j]&board[i+1][j-1]&board[i+2][j-2]&board[i+3][j-3])=='O' || (board[i][j]&board[i+1][j-1]&board[i+2][j-2]&board[i+3][j-3])=='X'){
                return true;
            }
        }
    }

    return false;
}
