#include <iostream>
using namespace std;

char board[3][3] =
{
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};

char currentPlayer = 'X';

void drawBoard()
{
    cout << "\n";
    for(int i = 0; i < 3; i++) 
    {
        for(int j = 0; j < 3; j++)
          {
            cout << " " << board[i][j] << " ";
            if(j < 2) cout << "|";
        }
      
        if(i < 2) cout << "\n---+---+---\n";
    }
    cout << "\n\n";
}

bool placeMark(int pos)
{
    int row = (pos - 1) / 3;
    int col = (pos - 1) % 3;

    if(board[row][col] != 'X' && board[row][col] != 'O') 
    {
        board[row][col] = currentPlayer;
        return true;
    }
    return false;
}

bool checkWin()
{
    for(int i = 0; i < 3; i++)
      {
        if(board[i][0] == currentPlayer &&
           board[i][1] == currentPlayer &&
           board[i][2] == currentPlayer)
            return true;

        if(board[0][i] == currentPlayer &&
           board[1][i] == currentPlayer &&
           board[2][i] == currentPlayer)
            return true;
    }

    if(board[0][0] == currentPlayer &&
       board[1][1] == currentPlayer &&
       board[2][2] == currentPlayer)
        return true;

    if(board[0][2] == currentPlayer &&
       board[1][1] == currentPlayer &&
       board[2][0] == currentPlayer)
        return true;

    return false;
}

bool isDraw() 
{
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

void switchPlayer()
{
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

int main()
{
    int position;
    cout << "TIC TAC TOE (C++)\n";

    while(true)
      {
        drawBoard();
        cout << "Player " << currentPlayer << ", enter position (1-9): ";
        cin >> position;

        if(position < 1 || position > 9 || !placeMark(position))
        {
            cout << "Invalid move! Try again.\n";
            continue;
        }

        if(checkWin())
        {
            drawBoard();
            cout << "Player " << currentPlayer << " wins! 🎉\n";
            break;
        }

        if(isDraw()) 
        {
            drawBoard();
            cout << "Game Draw! 🤝\n";
            break;
        }

        switchPlayer();
    }

    return 0;
}
