#include <cmath>
#include <cstdio>
#include <array>
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

bool checkIfTaken(int cellNumber, char board[])
{
  return !(board[cellNumber] == 'O' || board[cellNumber] == 'X');
}

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
  cout
      << "Player starts first. Simply input the number of the cell you want to occupy. Player's move is marked with X. Computer's move is marked with O.\n"
      << endl;
  cout << "Start? (y/n):" << endl;

  bool isValid = false;
  string answer;
  cin >> answer;

  //    if (answer == "y")
  //    {
  //        isValid = true;
  ////        break;
  //    }
  //    if (answer == "n")
  //    {
  //        isValid = true;
  //        cout << "See you next time!" << endl;
  //        exit(0);
  //    }

  while (isValid == false)
  {
    //        cin >> answer;
    if (answer == "y")
    {
      isValid = true;
      break;
    }
    if (answer == "n")
    {
      isValid = true;
      cout << "See you next time!" << endl;
      exit(0);
    }
    cout << "your answer is " << answer << endl;
    cout << "The answer you have submitted is not valid. Please try again." << endl;
    cout
        << "Player starts first. Simply input the number of the cell you want to occupy. Player's move is marked with X. Computer's move is marked with O.\n"
        << endl;
    cout << "Start? (y/n):" << endl;
    cin >> answer;
  }
}

void displayBoard(char board[])
{
  string board2[27];
  for (int i = 0; i < 27; i++)
  {
    if (board[i] == 'X')
    {
      board2[i] = "X";
    }
    else if (board[i] == 'O')
    {
      board2[i] = "O";
    }
    else
    {
      if ((i + 1) < 10)
      {
        board2[i] = to_string(i + 1);
      }
      board2[i] = to_string(i + 1);
    }
  }

  //        for (int k = 0; k < 27; ++k) {
  //            cout << board[k] << endl;
  //        }
  for (int j = 0; j < 3; j++)
  {
    int t = 3 * j;
    //      cout << "heya|" << board[j] << "|" <<  endl;
    cout << board2[t] << " | " << board2[t + 1] << " | " << board2[t + 2] << "          " << board2[t + 9] << " | "
         << board2[t + 10] << " | " << board2[t + 11] << "          " << board2[t + 18] << " | " << board2[t + 19]
         << " | " << board2[t + 20] << endl;
    if (j < 2)
    {
      cout << "---------"
           << "          "
           << "------------"
           << "          "
           << "------------" << endl;
    }
  }

  //    printf("hey");
}

bool checkIfLegal(int cellNbre, char board[])
{
  int n = cellNbre - 1;
  if (cellNbre > 27 || cellNbre < 1)
  {
    cout << "This move is not valid. Please input a different number." << endl;
    return false;
  }
  else if (board[n] == 'O' || board[n] == 'X')
  {
    cout << "This move is not valid. Please input a different number." << endl;
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
  exit(0);
}

void computerMove(char board[])
{
  for (int i = 0; i < 27; ++i)
  {
    if (checkIfTaken(i, board))
    {
      char testBoard[27];
      copy(board, board + 27, testBoard);
      //            for (int j = 0; j < 27; ++j) {
      //                cout << testBoard[j]<< "|";
      //            }
      testBoard[i] = 'O';
      if (checkWinner(testBoard))
      {
        board[i] = 'O';
        return;
      }
    }
  }

  for (int i = 0; i < 27; ++i)
  {
    if (checkIfTaken(i, board))
    {
      char testBoard[27];
      copy(board, board + 27, testBoard);
      testBoard[i] = 'X';
      if (checkWinner(testBoard))
      {
        board[i] = 'O';
        return;
      }
    }
  }
  //    for (int j = 0; j < 27; ++j) {
  //        cout << board[j]<< "|";
  //    }

  int listMoves[] = {14, 17, 13, 11, 15, 5, 23, 1, 7, 27, 25, 19, 3, 9, 21, 10, 18, 12, 16, 2, 4, 20, 24, 8, 26, 22,
                     6};

  for (int j = 0; j < 27; ++j)
  {
    if (checkIfTaken(listMoves[j] - 1, board))
    {
      board[listMoves[j] - 1] = 'O';
      break;
    }
  }
}

int main(void)
{
  // char board[] = {'X', 'O', 'c', 'd', 'X', 'f', 'g', 'h', 'X', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
  //                 'u', 'v', 'w', 'x', 'y', 'z', '0', '\0'};
  // char board2[] = {'X', 'O', 'c', 'd', 'd', 'f', 'g', 'h', 'X', 'j', 'k', 'l', 'm', 'X', 'o', 'p', 'q', 'r', 's', 't',
  //                  'u', 'v', 'w', 'x', 'y', 'z', 'X', '\0'};
  // char board3[] = {'X', 'O', 'c', 'd', 'X', 'f', 'g', 'h', 'X', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
  //                  'O', 'v', 'w', 'O', 'y', 'z', 'O', '\0'};
  // char board4[] = {'X', 'O', 'c', 'O', 'X', 'f', 'g', 'h', 'X', 'j', 'k', 'l', 'm', 'O', 'o', 'p', 'q', 'r', 's', 't',
  //                  'O', 'v', 'w', 'O', 'y', 'z', 'O', '\0'};
  // //  printf("the length of board is %d\n", strlen(board));
  // displayBoard(board);
  // char b = (checkIfLegal(27, board)) ? 't' : 'f';
  // cout << "is this legal? " << b << endl;

  // cout << "board1|" << checkWinner(board) << endl;
  // cout << "board2|" << checkWinner(board2) << endl;
  // cout << "board3|" << checkWinner(board3) << endl;
  // cout << "board4|" << checkWinner(board4) << endl;

  //    cout << setfill('0') << setw(5) << 25;

  greetAndInstruct();
  char board[27];
  for (int i = 0; i < 27; ++i)
  {
    board[i] = '1';
  }
  displayBoard(board);
  cout << "Your turn. Input a number:" << endl;
  string s;
  int move;
  cin >> move;
  //    cout << move << endl;

  //    cout << checkIfLegal(move, board)<< endl;
  while (true)
  {

    while (!checkIfLegal(move, board))
    {
      //            cout << "this is not legal";
      cin >> move;
    }
    board[move - 1] = 'X';

    if (checkWinner(board))
    {
      exit(0);
    }
    computerMove(board);
    if (checkWinner(board))
    {
      exit(0);
    }
    displayBoard(board);
    cout << "Your turn. Input another number:" << endl;
    cin >> move;
  }
}