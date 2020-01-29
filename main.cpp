#include <cmath>
#include <cstdio>
#include <array>
// #include <vector>
#include <iostream>
#include <cstring>
#include <string>
//#include <iomanip>

// #include <algorithm>
// #include "functions.cpp"
using namespace std;

void displayBoard(char boardreal[])
{
  int n = strlen(boardreal);
  //    size_t n = sizeof(board)/sizeof(board[0]);
  //    printf("%d = %d/%d\n", n, sizeof(board), sizeof(board[0]));
  //    for(int i = 0; i < n; i++){
  //        printf("%c", (board[i]));
  //        cout << board[i];
  //    }

  string board[27];
  for (int i = 0; i < n; i++)
  {
    if (boardreal[i] == 'X')
    {
      board[i] = "X";
    }
    else if (boardreal[i] == 'O')
    {
      board[i] = "O";
    }
    else
    {
      //        string s;
      if ((i + 1) < 10)
      {
        //            board[i].insert(0, " ");
        board[i] = to_string(i + 1);
        cout << "heya|" << board[i] << "|" << endl;
      }
      board[i] = to_string(i + 1);
      //        cout << i+1 << endl;
    }
  }

  //    for (int k = 0; k < n; ++k) {
  //        cout << board[k] << endl;
  //    }
  for (int j = 0; j < 3; j++)
  {
    int t = 3 * j;
    //      cout << "heya|" << board[j] << "|" <<  endl;
    cout << board[t] << " | " << board[t + 1] << " | " << board[t + 2] << "          " << board[t + 9] << " | " << board[t + 10] << " | " << board[t + 11] << "          " << board[t + 18] << " | " << board[t + 19] << " | " << board[t + 20] << endl;
    if (j < 2)
    {
      cout << "---------"
           << "          "
           << "------------"
           << "          "
           << "------------" << endl;
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
//    bool win = false;
//
//}

//void computerMove(char board[]){
//
//}

int main(void)
{
  char board[] = {'X', 'O', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '\0'};
  printf("the length of board is %d\n", strlen(board));
  displayBoard(board);
  char b = (checkIfLegal(27, board)) ? 't' : 'f';
  cout << "is this legal? " << b << endl;

  //    cout << setfill('0') << setw(5) << 25;

  //  char boardreally[27];
  //  boardreally[0] = 'a';
  //    for (int i = 0; i < 27; i++) {
  //        if(boardreally[i] != '\0'){
  //            printf("this is null |%u| vs |%u|", boardreally[i], '\u0000');
  //        }
  //    }
}