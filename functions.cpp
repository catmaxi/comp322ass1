#include <cmath>
#include <cstdio>
// #include <vector>
#include <iostream>
// #include <algorithm>
using namespace std;

​void greetAndInstruct(){
  cout << "Hello and welcome to the Tic-Tac-Toe challenge: Player against Computer.\n" << endl;
  cout << "The board is numbered from 1 to 27 as per the following:\n\n" << endl;
  cout << "1 | 2 | 3" << "          " << "10 | 11 | 12" << "          " << "19 | 20 | 21" << endl;
  cout << "---------" << "          " << "------------" << "          " << "------------" << endl;
  cout << "4 | 5 | 6" << "          " << "13 | 14 | 15" << "          " << "22 | 23 | 24" << endl;
  cout << "---------" << "          " << "------------" << "          " << "------------" << endl;
  cout << "7 | 8 | 9" << "          " << "16 | 17 | 18" << "          " << "25 | 26 | 27\n" << endl;
  cout << "Player starts first. Simply input the number of the cell you want to occupy. Player's move is marked with X. Computer's move is marked with O.\n" << endl;
  cout << "Start? (y/n):" << endl;
}

void displayBoard(char board[]){

  cout << "1 | 2 | 3" << "          " << "10 | 11 | 12" << "          " << "19 | 20 | 21" << endl;
  cout << "---------" << "          " << "------------" << "          " << "------------" << endl;
  cout << "4 | 5 | 6" << "          " << "13 | 14 | 15" << "          " << "22 | 23 | 24" << endl;
  cout << "---------" << "          " << "------------" << "          " << "------------" << endl;
  cout << "7 | 8 | 9" << "          " << "16 | 17 | 18" << "          " << "25 | 26 | 27\n" << endl;

  
}

bool checkIfLegal​(int cellNbre, char board[]){

}

bool checkWinner(char board[]){

}

void computerMove(char board[]);

