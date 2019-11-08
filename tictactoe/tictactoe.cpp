/**
 * A simple 2-player Tic-Tac-Toe implementation in C++.
 *
 * @file tictactoe.cpp
 * @author Brenda Yau
 */

#include <iostream>

using namespace std;

bool isWon(char, char[][3]);
bool isDraw(char[][3]);
void displayBoard(char[][3]);
void makeAMove(char[][3], char);

int main()
{
   char board[3][3] = { { ' ', ' ', ' ' },{ ' ', ' ', ' ' },{ ' ', ' ', ' ' } };
   displayBoard(board);

   while (true) {
      // The first player makes a move
      makeAMove(board, 'X');
      displayBoard(board);
      if (isWon('X', board)) {
         cout << "X player won" << endl;
         exit(0);
      }
      else if (isDraw(board)) {
         cout << "No winner" << endl;
         exit(0);
      }

      // The second player makes a move
      makeAMove(board, 'O');
      displayBoard(board);

      if (isWon('O', board)) {
         cout << "O player won" << endl;
         exit(0);
      }
      else if (isDraw(board)) {
         cout << "No winner" << endl;
         exit(0);
      }
   }

   return 0;
}

/**
 * Returns whether player has won the game.
 *
 * @param player either 'X' or 'O' to choose which player's data to display.
 * @param board 3x3 board values.
 * @return true if player won,  false otherwise.
 */
bool isWon(char player, char board[][3])
{
   // check case
   // show all row, column, diag cases where a win is true:
   // 3 row, 3 col, 2 diagonal
   // all in one long statement of ors
   if ((board[0][0] == player && board[0][1] == player && board[0][2] == player)
       || (board[1][0] == player && board[1][1] == player && board[1][2] == player)
       || (board[2][0] == player && board[2][1] == player && board[2][2] == player)
       || (board[0][0] == player && board[1][1] == player && board[2][2] == player)
       || (board[0][0] == player && board[1][0] == player && board[2][0] == player)
       || (board[1][0] == player && board[1][1] == player && board[1][2] == player)
       || (board[2][0] == player && board[2][1] == player && board[2][2] == player))
      return true;
   return false;
}

/**
 * Returns whether player has tied with another player.
 *
 * @param board 3x3 board values.
 * @return true if player tied with opponent, false otherwise.
 */
bool isDraw(char board[][3])
{
   // isWon for either character is false, then return true
   // implicit otherwise return false;

   for (int r = 0; r < 3; r++)
      for (int c = 0; c < 3; c++)
      {
         if (board[r][c] == ' ')
            return false;
      }
   return true;
}

/**
 * Displays tic-tac-toe board to the console.
 *
 * @param board 3x3 board values.
 */
void displayBoard(char board[][3])
{
   // keep output alignment consistent
   // print to console according to sample output
   // display using given parameter values
   cout << endl;
   for (int r = 0; r < 3; r++)
   {
      cout << "-------------\n";
      for (int c = 0; c < 3; c++)
      {
         cout << "| " << board[r][c] << " ";
      }
      cout << "|\n";
   }
   cout << "-------------\n";
}

/**
 * Handles player input.
 * Updates board with new move according to player input.
 *
 * @param board 3x3 board values.
 * @param player either 'X' or 'O' to choose which player's data to display.
 */
void makeAMove(char board[][3], char player)
{
   // handle user input: error when not a 0,1,2
   // update row, column values according to input:
   // change value in board by reference (global change)
   bool validInput = false;
   int r, c;
   while(!validInput)
   {
      cout << "Enter a row (0, 1, 2) for player " << player << "   : ";
      cin >> r;
      cout << "Enter a column (0, 1, 2) for player " << player << ": ";
      cin >> c;

      if (board[r][c] == ' ' && r >= 0 && r <= 2 && c >= 0 && c <= 2)
      {
         board[r][c] = player;
         validInput = true;
      }
      else if (r < 0 || c < 0 || r > 2 || c > 2)
      {
         cout << "Invalid input.\n";
      }
      else
         cout << "This cell is already occupied. Try a different cell\n";
   }

}
