#include <cmath>
#include <cstdio>
// #include <vector>
#include <iostream>
#include <cstring>
// #include <algorithm>
using namespace std;

void greetAndInstruct(){
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

void displayBoard(char board[])
{
  int n = strlen(board);

  for (int j = 0; j < 3; j++)
  {
    int t = 3 * j;
    cout << board[t] << " | " << board[t + 1] << " | " << board[t + 2] << "          " << board[t + 9] << " | " << board[t + 10] << " | " << board[t + 11] << "          " << board[t + 18] << " | " << board[t + 19] << " | " << board[t + 20] << endl;
    if (j < 2)
    {
      cout << "---------"
          << "          "
          << "---------"
          << "          "
          << "---------" << endl;
    }
  }
}

bool checkIfLegal(int cellNbre, char board[])
{
  int n = cellNbre - 1;
  if (cellNbre > 27 || cellNbre < 1)
  {
    return false;
  }
  else if (board[n] == 'O' || board[n] == 'X')
  {
    return false;
  }
  return true;
}

bool checkWinner(char board[]){

}

void computerMove(char board[]){

}

