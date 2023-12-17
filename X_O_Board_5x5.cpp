//
// Created by Mohamed Fathy on 12/16/2023.
//
//
// Created by Mohamed Fathy on 12/13/2023.
//
#include<bits/stdc++.h>
#include"BoardGame_Classes.hpp"
X_O_Board_5x5::X_O_Board_5x5() {
    n_rows = n_cols = 5;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}

bool X_O_Board_5x5::update_board (int x, int y, char mark){
    if (!(x < 0 || x > 4 || y < 0 || y > 4) && (board[x][y] == 0)) {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else
        return false;
}
void X_O_Board_5x5::display_board() {
    for (int i: {0,1,2,3,4}) {
        cout << "\n| ";
        for (int j: {0,1,2,3,4}) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board [i][j] << " |";
        }
        cout << "\n-----------------------------";
    }
    cout << endl;
}
int X_O_Board_5x5::is_winner5x5() {
    if(n_moves==25) {
        if (board[0][2] == 'X') {
            if (board[0][0] == board[0][2] && board[0][1] == board[0][2]) {
                ptsX++;
            }
            if (board[0][3] == board[0][2] && board[0][1] == board[0][2]) {
                ptsX++;
            }
            if (board[0][4] == board[0][2] && board[0][3] == board[0][2]) {
                ptsX++;
            }
        } else if (board[0][2] == 'O') {
            if (board[0][0] == board[0][2] && board[0][1] == board[0][2]) {
                ptsO++;
            }
            if (board[0][1] == board[0][2] && board[0][3] == board[0][2]) {
                ptsO++;
            }
            if (board[0][4] == board[0][2] && board[0][3] == board[0][2]) {
                ptsO++;
            }
        }
        if(board[2][0]=='X'){
            if (board[0][0] == board[2][0] && board[1][0] == board[2][0]) {
                ptsX++;
            }
            if (board[3][0] == board[2][0] && board[1][0] == board[2][0]) {
                ptsX++;
            }
            if (board[4][0] == board[2][0] && board[3][0] == board[2][0]) {
                ptsX++;
            }
        }else if(board[2][0]=='O'){
            if (board[0][0] == board[2][0] && board[1][0] == board[2][0]) {
                ptsO++;
            }
            if (board[1][0] == board[2][0] && board[3][0] == board[2][0]) {
                ptsO++;
            }
            if (board[4][0] == board[2][0] && board[3][0] == board[2][0]) {
                ptsO++;
            }
        }
        if(board[1][2]=='X'){
            if (board[1][0] == board[1][2] && board[1][1] == board[1][2]) {
                ptsX++;
            }
            if (board[1][3] == board[1][2] && board[1][1] == board[1][2]) {
                ptsX++;
            }
            if (board[1][4] == board[1][2] && board[1][3] == board[1][2]) {
                ptsX++;
            }
        }else if(board[1][2]=='O'){
            if (board[1][0] == board[1][2] && board[1][1] == board[1][2]) {
                ptsO++;
            }
            if (board[1][1] == board[1][2] && board[1][3] == board[1][2]) {
                ptsO++;
            }
            if (board[1][4] == board[1][2] && board[1][3] == board[1][2]) {
                ptsO++;
            }
        }
        if(board[2][1]=='X'){
            if (board[0][1] == board[2][1] && board[1][1] == board[2][1]) {
                ptsX++;
            }
            if (board[3][1] == board[2][1] && board[1][1] == board[2][1]) {
                ptsX++;
            }
            if (board[4][1] == board[2][1] && board[3][1] == board[2][1]) {
                ptsX++;
            }
        }else if(board[2][1]=='O'){
            if (board[0][1] == board[2][1] && board[1][1] == board[2][1]) {
                ptsO++;
            }
            if (board[1][1] == board[2][1] && board[3][1] == board[2][1]) {
                ptsO++;
            }
            if (board[4][1] == board[2][1] && board[3][1] == board[2][0]) {
                ptsO++;
            }
        }if(board[2][2]=='X'){
            if (board[1][0] == board[2][2] && board[2][1] == board[2][2]) {
                ptsX++;
            }
            if (board[2][3] == board[2][2] && board[2][1] == board[2][2]) {
                ptsX++;
            }
            if (board[2][4] == board[2][2] && board[2][3] == board[2][2]) {
                ptsX++;
            }
        }else if(board[2][2]=='O'){
            if (board[2][0] == board[2][2] && board[2][1] == board[2][2]) {
                ptsO++;
            }
            if (board[2][1] == board[2][2] && board[2][3] == board[2][2]) {
                ptsO++;
            }
            if (board[2][4] == board[2][2] && board[2][3] == board[2][2]) {
                ptsO++;
            }
        }
        if(board[2][2]=='X'){
            if (board[0][2] == board[2][2] && board[1][2] == board[2][2]) {
                ptsX++;
            }
            if (board[3][2] == board[2][2] && board[1][2] == board[2][2]) {
                ptsX++;
            }
            if (board[4][2] == board[2][2] && board[3][2] == board[2][2]) {
                ptsX++;
            }
        }else if(board[2][2]=='O'){
            if (board[0][2] == board[2][2] && board[1][2] == board[2][2]) {
                ptsO++;
            }
            if (board[1][2] == board[2][2] && board[3][2] == board[2][2]) {
                ptsO++;
            }
            if (board[4][2] == board[2][2] && board[3][2] == board[2][2]) {
                ptsO++;
            }
        }
        if(board[3][2]=='X'){
            if (board[3][0] == board[3][2] && board[3][1] == board[3][2]) {
                ptsX++;
            }
            if (board[3][3] == board[3][2] && board[3][1] == board[3][2]) {
                ptsX++;
            }
            if (board[3][4] == board[3][2] && board[3][3] == board[3][2]) {
                ptsX++;
            }
        }else if(board[3][2]=='O'){
            if (board[3][0] == board[3][2] && board[3][1] == board[3][2]) {
                ptsO++;
            }
            if (board[3][1] == board[3][2] && board[3][3] == board[3][2]) {
                ptsO++;
            }
            if (board[3][4] == board[3][2] && board[3][3] == board[3][2]) {
                ptsO++;
            }
        }
        if(board[2][3]=='X'){
            if (board[0][3] == board[2][3] && board[1][3] == board[2][3]) {
                ptsX++;
            }
            if (board[3][3] == board[2][3] && board[1][3] == board[2][3]) {
                ptsX++;
            }
            if (board[4][3] == board[2][3] && board[3][3] == board[2][3]) {
                ptsX++;
            }
        }else if(board[2][3]=='O'){
            if (board[0][3] == board[2][3] && board[1][3] == board[2][3]) {
                ptsO++;
            }
            if (board[1][3] == board[2][3] && board[3][3] == board[2][3]) {
                ptsO++;
            }
            if (board[4][3] == board[2][3] && board[3][3] == board[2][3]) {
                ptsO++;
            }
        }
        if(board[4][2]=='X'){
            if (board[4][0] == board[4][2] && board[4][1] == board[4][2]) {
                ptsX++;
            }
            if (board[4][3] == board[4][2] && board[4][1] == board[4][2]) {
                ptsX++;
            }
            if (board[4][4] == board[4][2] && board[4][3] == board[4][2]) {
                ptsX++;
            }
        }else if(board[4][2]=='O'){
            if (board[4][0] == board[4][2] && board[4][1] == board[4][2]) {
                ptsO++;
            }
            if (board[4][1] == board[4][2] && board[4][3] == board[4][2]) {
                ptsO++;
            }
            if (board[4][4] == board[4][2] && board[4][3] == board[4][2]) {
                ptsO++;
            }
        }
        if(board[2][4]=='X'){
            if (board[0][4] == board[2][4] && board[1][4] == board[2][4]) {
                ptsX++;
            }
            if (board[3][4] == board[2][4] && board[1][4] == board[2][4]) {
                ptsX++;
            }
            if (board[4][4] == board[2][4] && board[3][4] == board[2][4]) {
                ptsX++;
            }
        }else if(board[2][4]=='O'){
            if (board[0][4] == board[2][4] && board[1][4] == board[2][4]) {
                ptsO++;
            }
            if (board[1][4] == board[2][4] && board[3][4] == board[2][4]) {
                ptsO++;
            }
            if (board[4][4] == board[2][4] && board[3][4] == board[2][4]) {
                ptsO++;
            }
        }
        if(board[2][2]=='X'){
            if(board[0][0]==board[2][2]&&board[1][1]==board[2][2]){
                ptsX++;
            }
            if(board[1][1]==board[2][2]&&board[3][3]==board[2][2]){
                ptsX++;
            }
            if(board[3][3]==board[2][2]&&board[4][4]==board[2][2]){
                ptsX++;
            }
        }else if(board[2][2]=='O') {
            if (board[0][0] == board[2][2] && board[1][1] == board[2][2]) {
                ptsO++;
            }
            if (board[1][1] == board[2][2] && board[3][3] == board[2][2]) {
                ptsO++;
            }
            if (board[3][3] == board[2][2] && board[4][4] == board[2][2]) {
                ptsO++;
            }
        }
        if(board[2][2]=='X'){
            if(board[0][4]==board[2][2]&&board[1][3]==board[2][2]){
                ptsX++;
            }
            if(board[1][3]==board[2][2]&&board[3][1]==board[2][2]){
                ptsX++;
            }
            if(board[3][1]==board[2][2]&&board[4][0]==board[2][2]){
                ptsX++;
            }
        }else if(board[2][2]=='O') {
            if (board[0][4] == board[2][2] && board[1][3] == board[2][2]) {
                ptsO++;
            }
            if (board[1][3] == board[2][2] && board[3][1] == board[2][2]) {
                ptsO++;
            }
            if (board[3][1] == board[2][2] && board[4][0] == board[2][2]) {
                ptsO++;
            }
        }
        if(board[1][1]=='X'){
            if(board[0][2]==board[1][1]&&board[2][0]==board[1][1]){
                ptsX++;
            }
        }else  if(board[1][1]=='O') {
            if (board[0][2] == board[1][1] && board[2][0] == board[1][1]) {
                ptsO++;
            }
        }
        if(board[3][3]=='X'){
            if(board[2][4]==board[3][3]&&board[4][2]==board[3][3]){
                ptsX++;
            }
        }else  if(board[3][3]=='O') {
            if (board[2][4] == board[3][3] && board[4][2] == board[3][3]) {
                ptsO++;
            }
        }
        if(board[1][3]=='X'){
            if(board[0][2]==board[1][3]&&board[2][4]==board[1][1]){
                ptsX++;
            }
        }else  if(board[1][3]=='O') {
            if (board[0][2] == board[1][3] && board[2][4] == board[1][3]) {
                ptsO++;
            }
        }
        if(board[3][1]=='X'){
            if(board[4][2]==board[1][1]&&board[2][0]==board[3][1]){
                ptsX++;
            }
        }else  if(board[3][1]=='O') {
            if (board[4][2] == board[1][1] && board[2][0] == board[3][1]) {
                ptsO++;
            }
        }
        if(board[1][2]=='X'){
            if(board[0][3]==board[1][2]&&board[2][1]==board[1][2]){
                ptsX++;
            }
            if(board[3][0]==board[1][2]&&board[2][1]==board[1][2]){
                ptsX++;
            }
        }else if(board[1][2]=='O'){
            if(board[0][3]==board[1][2]&&board[2][1]==board[1][2]){
                ptsO++;
            }
            if(board[3][0]==board[1][2]&&board[2][1]==board[1][2]){
                ptsO++;
            }
        }
        if(board[2][3]=='X'){
            if(board[1][4]==board[2][3]&&board[3][2]==board[2][3]){
                ptsX++;
            }
            if(board[4][1]==board[2][3]&&board[3][2]==board[2][3]){
                ptsX++;
            }
        }else if(board[2][3]=='O'){
            if(board[1][4]==board[2][3]&&board[3][2]==board[2][3]){
                ptsO++;
            }
            if(board[1][4]==board[2][3]&&board[3][2]==board[2][3]){
                ptsO++;
            }
        }
        if(board[2][1]=='X'){
            if(board[1][0]==board[2][1]&&board[3][2]==board[2][1]){
                ptsX++;
            }
            if(board[4][3]==board[2][1]&&board[3][2]==board[2][1]){
                ptsX++;
            }
        }else if(board[2][1]=='O'){
            if(board[1][0]==board[2][1]&&board[3][2]==board[2][1]){
                ptsO++;
            }
            if(board[4][3]==board[2][1]&&board[3][2]==board[2][1]){
                ptsO++;
            }
        }
        if(board[1][2]=='X'){
            if(board[0][1]==board[1][2]&&board[2][3]==board[1][2]){
                ptsX++;
            }
            if(board[3][4]==board[1][2]&&board[2][3]==board[1][2]){
                ptsX++;
            }
        }else if(board[1][2]=='O'){
            if(board[0][1]==board[1][2]&&board[2][3]==board[1][2]){
                ptsO++;
            }
            if(board[3][4]==board[1][2]&&board[2][3]==board[1][2]){
                ptsO++;
            }
        }
    }
    if (ptsX > ptsO && n_moves==25) {
        return 1;
    } else if (ptsO > ptsX && n_moves==25) {
        return 2;

    } else return 0;

}

bool X_O_Board_5x5::is_draw() {
    return (n_moves == 25 && is_winner()==0);
}
bool X_O_Board_5x5::game_is_over() {
    return n_moves >= 25;
}
bool X_O_Board_5x5::is_winner() {

}