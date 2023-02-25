#include <iostream>
#include <vector>
#include <string>
// contact emai-praytoprashant@gmail.com
using namespace std;

// Function to print the game board
void printBoard(const vector<string>& board) {
    cout << "\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i * 3 + j] << " | ";
        }
        cout << "\n";
    }
}

// Function to check if the game has ended
bool isGameOver(const vector<string>& board, string& winner) {
    // Check rows
    for (int i = 0; i < 9; i += 3) {
        if (board[i] != "-" && board[i] == board[i+1] && board[i+1] == board[i+2]) {
            winner = board[i];
            return true;
        }
    }

    // Check columns
    for (int i = 0; i < 3; ++i) {
        if (board[i] != "-" && board[i] == board[i+3] && board[i+3] == board[i+6]) {
            winner = board[i];
            return true;
        }
    }

    // Check diagonals
    if (board[0] != "-" && board[0] == board[4] && board[4] == board[8]) {
        winner = board[0];
        return true;
    }
    if (board[2] != "-" && board[2] == board[4] && board[4] == board[6]) {
        winner = board[2];
        return true;
    }

    // Check if board is full (tie game)
    bool boardFull = true;
    for (int i = 0; i < 9; ++i) {
        if (board[i] == "-") {
            boardFull = false;
            break;
        }
    }
    if (boardFull) {
        winner = "Tie";
        return true;
    }

    // Game is not over yet
    return false;
}

int main() {
    vector<string> board(9, "-");  // Initialize game board
    string player1 = "X";  // Player 1 uses "X"
    string player2 = "O";  // Player 2 uses "O"
    string currentPlayer = player1;
    string winner = "";

    cout << "Tic Tac Toe\n";
    printBoard(board);

    // Game loop
    while (!isGameOver(board, winner)) {
        cout << "Player " << currentPlayer << ", enter a position (1-9): ";
        int pos;
        cin >> pos;
        while (pos < 1 || pos > 9 || board[pos-1] != "-") {
            cout << "Invalid position. Please enter a position (1-9): ";
            cin >> pos;
        }
        board[pos-1] = currentPlayer;
        printBoard(board);
        currentPlayer = (currentPlayer == player1) ? player2 : player1;  // Switch players
    }

    cout << "Game over. ";
    if (winner == "Tie") {
        cout << "It's a tie!\n";
    } else {
        cout << "Player " << winner << " wins!\n";
    }

    return 0;
}
