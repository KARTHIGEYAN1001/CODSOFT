#include <iostream>
using namespace std;

void initBoard(char board[3][3]) {
    char c = '1';
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = c++;
        }
    }
}

void displayBoard(char board[3][3]) {
    cout << "\n";
    for (int i = 0; i < 3; ++i) {
        cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << "\n";
        if (i != 2) cout << "---+---+---\n";
    }
    cout << "\n";
}

bool checkWin(char board[3][3], char p) {
    // rows and columns
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == p && board[i][1] == p && board[i][2] == p) return true;
        if (board[0][i] == p && board[1][i] == p && board[2][i] == p) return true;
    }
    // diagonals
    if (board[0][0] == p && board[1][1] == p && board[2][2] == p) return true;
    if (board[0][2] == p && board[1][1] == p && board[2][0] == p) return true;
    return false;
}

bool checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

void switchPlayer(char &player) {
    player = (player == 'X') ? 'O' : 'X';
}

bool makeMove(char board[3][3], int cell, char player) {
    if (cell < 1 || cell > 9) return false;
    int r = (cell - 1) / 3;
    int c = (cell - 1) % 3;
    if (board[r][c] == 'X' || board[r][c] == 'O') return false;
    board[r][c] = player;
    return true;
}

int main() {
    char board[3][3];
    char currentPlayer;
    char playAgain;

    do {
        initBoard(board);
        currentPlayer = 'X';
        bool gameOver = false;

        while (!gameOver) {
            displayBoard(board);

            int move;
            cout << "Player " << currentPlayer
                 << ", enter your move (1-9): ";
            cin >> move;

            if (!makeMove(board, move, currentPlayer)) {
                cout << "Invalid move, try again.\n";
                continue;
            }

            if (checkWin(board, currentPlayer)) {
                displayBoard(board);
                cout << "Player " << currentPlayer << " wins!\n";
                gameOver = true;
            } else if (checkDraw(board)) {
                displayBoard(board);
                cout << "The game is a draw.\n";
                gameOver = true;
            } else {
                switchPlayer(currentPlayer);
            }
        }

        cout << "Play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}
