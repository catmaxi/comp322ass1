#include <cmath>
#include <cstdio>
#include <array>
// #include <vector>
#include <iostream>
#include <cstring>

// #include <algorithm>
// #include "functions.cpp"
using namespace std;

void displayBoard(char board[])
{
  int n = strlen(board);
  //    size_t n = sizeof(board)/sizeof(board[0]);
  //    printf("%d = %d/%d\n", n, sizeof(board), sizeof(board[0]));
  //    for(int i = 0; i < n; i++){
  //        printf("%c", (board[i]));
  //        cout << board[i];
  //    }

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

//bool checkWinner(char board[]){
//
//}
//
//void computerMove(char board[]){
//
//}

int main(void)
{
  char board[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '\0'};
  printf("the length of board is %d\n", strlen(board));
  displayBoard(board);
  char b = (checkIfLegal(27, board)) ? 't' : 'f';
  cout << "is this legal? " << b;
}