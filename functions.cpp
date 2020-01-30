#include <cmath>
#include <cstdio>
// #include <vector>
#include <iostream>
#include <cstring>
#include <string>
// #include <algorithm>
using namespace std;

void greetAndInstruct()
{
  cout << "Hello and welcome to the Tic-Tac-Toe challenge: Player against Computer.\n"
       << endl;
  cout << "The board is numbered from 1 to 27 as per the following:\n\n"
       << endl;
  cout << "1 | 2 | 3"
       << "          "
       << "10 | 11 | 12"
       << "          "
       << "19 | 20 | 21" << endl;
  cout << "---------"
       << "          "
       << "------------"
       << "          "
       << "------------" << endl;
  cout << "4 | 5 | 6"
       << "          "
       << "13 | 14 | 15"
       << "          "
       << "22 | 23 | 24" << endl;
  cout << "---------"
       << "          "
       << "------------"
       << "          "
       << "------------" << endl;
  cout << "7 | 8 | 9"
       << "          "
       << "16 | 17 | 18"
       << "          "
       << "25 | 26 | 27\n"
       << endl;
  cout << "Player starts first. Simply input the number of the cell you want to occupy. Player's move is marked with X. Computer's move is marked with O.\n"
       << endl;
  cout << "Start? (y/n):" << endl;
}

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

bool checkWinner(char board[])
{
  //    bool win = false;
  //    int board3d[3][3][3];
  //    int ind = 0;
  //    for (int i = 0; i < 3; i++) {
  //        int ind = 9 * i;
  //        for (int j = 0; j < 3; j++) {
  //            for (int k = 0; k < 3; k++) {
  //                if (board[ind + k] == 'X') {
  //                    board3d[i][j][k] = 1;
  //                } else if (board[ind + k] == 'O') {
  //                    board3d[i][j][k] = -1;
  //                } else {
  //                    board3d[i][j][k] = 0;
  //                }
  //            }
  //            ind += 3;
  //        }
  //    }

  int boardint[27];
  int sum2 = 0;

  for (int i = 0; i < 27; i++)
  {
    if (board[i] == 'X')
    {
      boardint[i] = 1;
    }
    else if (board[i] == 'O')
    {
      boardint[i] = -1;
    }
    else
    {
      boardint[i] = 0;
    }
  }
  //    for (int m = 0; m < 27; ++m) {
  //        cout << boardint[m] << endl;
  //    }
  // checks for horizontal lines
  for (int l = 0; l < 3; ++l)
  {
    for (int i = 0; i < 3; i++)
    {
      int sum = 0;
      for (int j = 0; j < 3; j++)
      {
        //                printf(" this is index%d\n", 9 * l + 3 * i + j);
        sum += boardint[9 * l + 3 * i + j];
      }
      //            cout << "this is one group" << endl;
      if (sum >= 3)
      {
        cout << "Player won!" << endl;
        return true;
      }
      else if (sum <= -3)
      {
        cout << "Computer won!" << endl;
        return true;
      }
    }
  }

  // checks for vertical lines
  for (int l = 0; l < 3; ++l)
  {
    for (int i = 0; i < 3; i++)
    {
      int sum = 0;
      for (int j = 0; j < 3; j++)
      {
        //                printf(" this is index%d\n", 9 * l + 3 * j + i);
        sum += boardint[9 * l + 3 * j + i];
      }
      //            cout << "this is one group" << endl;
      if (sum >= 3)
      {
        cout << "Player won!" << endl;
        return true;
      }
      else if (sum <= -3)
      {
        cout << "Computer won!" << endl;
        return true;
      }
    }
  }

  //Check for lines going into the plane
  for (int i = 0; i < 9; i++)
  {
    int sum = 0;
    for (int j = 0; j < 3; j++)
    {
      //            printf(" this is index%d\n", 9 * j + i);
      sum += boardint[9 * j + i];
    }
    //        cout << "this is one group" << endl;
    if (sum >= 3)
    {
      cout << "Player won!" << endl;
      return true;
    }
    else if (sum <= -3)
    {
      cout << "Computer won!" << endl;
      return true;
    }
  }

  // Checks for diagonals facing you
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      int sum = 0;
      for (int k = 0; k < 3; ++k)
      {
        if (j == 0)
        {
          //                    printf(" this is index%d\n", (9 * i) + (2 * j) + (k * 4));
          sum += boardint[(9 * i) + (2 * j) + (k * 4)];
        }
        else
        {
          //                    printf(" this is index%d\n", (9 * i) + (2 * j) + (k * 2));
          sum += boardint[(9 * i) + (2 * j) + (k * 2)];
        }
      }
      //            cout << "this is one group" << endl;
      if (sum >= 3)
      {
        cout << "Player won!" << endl;
        return true;
      }
      else if (sum <= -3)
      {
        cout << "Computer won!" << endl;
        return true;
      }
    }
  }

  //Checks for diagonals facing up/down
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      int sum = 0;
      for (int k = 0; k < 3; ++k)
      {
        if (j == 0)
        {
          //                    printf(" this is index%d\n", (3 * i) + (k * 10));
          sum += boardint[(3 * i) + (k * 10)];
        }
        else
        {
          //                    printf(" this is index%d\n", (3 * i) + (2 * j) + (k * 8));
          sum += boardint[(3 * i) + (2 * j) + (k * 8)];
        }
      }
      //            cout << "this is one group" << endl;
      if (sum >= 3)
      {
        cout << "Player won!" << endl;
        return true;
      }
      else if (sum <= -3)
      {
        cout << "Computer won!" << endl;
        return true;
      }
    }
  }

  //Checks for diagonals facing sideways.
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      int sum = 0;
      for (int k = 0; k < 3; ++k)
      {
        if (j == 0)
        {
          //                    printf(" this is index%d\n", (i) + (k * 12));
          sum += boardint[(i) + (k * 12)];
        }
        else
        {
          //                    printf(" this is index%d\n", 6 + (i) + (k * 6));
          sum += boardint[6 + (i) + (k * 6)];
        }
      }
      //            cout << "this is one group" << endl;
      if (sum >= 3)
      {
        cout << "Player won!" << endl;
        return true;
      }
      else if (sum <= -3)
      {
        cout << "Computer won!" << endl;
        return true;
      }
    }
  }

  // Checks for diagonals that spans the 4 corners of the whole 3D cube
  // 1. 0 - 13 - 26
  sum2 = 0;
  //    printf(" this is index%d\n", 0);
  //    printf(" this is index%d\n", 13);
  //    printf(" this is index%d\n", 26);
  sum2 += (boardint[0] + boardint[13] + boardint[26]);
  //    cout << "this is one group" << endl;
  if (sum2 >= 3)
  {
    cout << "Player won!" << endl;
    return true;
  }
  else if (sum2 <= -3)
  {
    cout << "Computer won!" << endl;
    return true;
  }
  // 2. 2 - 13 - 24
  sum2 = 0;
  //    printf(" this is index%d\n", 2);
  //    printf(" this is index%d\n", 13);
  //    printf(" this is index%d\n", 24);
  sum2 += (boardint[2] + boardint[13] + boardint[24]);
  //    cout << "this is one group" << endl;
  if (sum2 >= 3)
  {
    cout << "Player won!" << endl;
    return true;
  }
  else if (sum2 <= -3)
  {
    cout << "Computer won!" << endl;
    return true;
  }
  // 3. 6 - 13 - 20
  sum2 = 0;
  //    printf(" this is index%d\n", 6);
  //    printf(" this is index%d\n", 13);
  //    printf(" this is index%d\n", 20);
  //    cout << "this is one group" << endl;
  sum2 += (boardint[6] + boardint[13] + boardint[20]);
  if (sum2 >= 3)
  {
    cout << "Player won!" << endl;
    return true;
  }
  else if (sum2 <= -3)
  {
    cout << "Computer won!" << endl;
    return true;
  }
  // 4. 8 - 13 - 18
  sum2 = 0;
  //    printf(" this is index%d\n", 8);
  //    printf(" this is index%d\n", 13);
  //    printf(" this is index%d\n", 18);
  //    cout << "this is one group" << endl;
  sum2 += (boardint[8] + boardint[13] + boardint[18]);
  if (sum2 >= 3)
  {
    cout << "Player won!" << endl;
    return true;
  }
  else if (sum2 <= -3)
  {
    cout << "Computer won!" << endl;
    return true;
  }

  for (int i = 0; i < 27; i++)
  {
    if (board[i] != 'X' || board[i] != 'O')
    {
      return false;
    }
  }
  cout << "It's a tie!" << endl;
  return true;
}

// void computerMove(char board[]){

// }