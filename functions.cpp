#include <cmath>
#include <cstdio>
// #include <vector>
#include <iostream>
// #include <algorithm>
using namespace std;

​void greetAndInstruct(){

}

void displayBoard(char board[]){
  cout << "Hello and welcome to the Tic - Tac - Toe challenge : Player against Computer.\n
  The board is numbered from 1 to 27 as per the following : \n\n
  1 | 2 | 3              10 | 11 | 12               19 | 20 | 21\n
  ---------              ------------               ------------
  4 | 5 | 6              13 | 14 | 15               22 | 23 | 24\n
  ---------              ------------               ------------
  7 | 8 | 9              16 | 17 | 18               25 | 26 | 27\n\n
  Player starts first. Simply input the number of the cell you want to occupy. Player’smove is marked with X. Computer’s move is marked with O.\n\n
  Start ? (y / n) :" << endl;
}

bool checkIfLegal​(int cellNbre, char board[]){

}

bool checkWinner(char board[]){

}

void computerMove(char board[]);

