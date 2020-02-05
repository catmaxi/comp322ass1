#include <cmath>
#include <cstdio>
#include <array>
// #include <vector>
#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
#include "functions.h"

// #include <algorithm>
// #include "functions.cpp"
using namespace std;

int main(void)
{

  greetAndInstruct();

  char board[27];
  for (int i = 0; i < 27; ++i)
  {
    board[i] = '1';
  }
  displayBoard(board);
  cout << "Your turn. Input a number:" << endl;

  int move;
  cin >> move;

  while (!cin.good())
  {
    cin.clear();
    cin.ignore(INT8_MAX, '\n');
    cout << "You did not input a number. Please try again." << endl;
    cin >> move;
  }

  while (true)
  {

    while (!checkIfLegal(move, board))
    {

      cin >> move;
    }
    board[move - 1] = 'X';

    checkWinner(board);

    // if (checkWinner(board))
    // {
    //   cout << "Player won!" << endl;
    //   exit(0);
    // }
    computerMove(board);
    checkWinner(board);

    // if (checkWinner(board))
    // {
    //   cout << "Computer won!" << endl;
    //   exit(0);
    // }
    displayBoard(board);
    cout << "Your turn. Input another number:" << endl;
    cin >> move;
    while (!cin.good())
    {
      cin.clear();
      cin.ignore(INT8_MAX, '\n');
      cout << "You did not input a number. Please try again." << endl;
      cin >> move;
    }
  }
}