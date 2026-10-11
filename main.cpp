#include <iostream>
#include <vector>
#include <string>

// Function to check if a player has won
bool hasWon(const std::vector<std::string>& board, char player) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }
    
    // Check columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return true;
        }
    }
    
    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }
    
    return false;
}

// Function to count the number of pieces for each player
void countPieces(const std::vector<std::string>& board, int& countX, int& countO) {
    countX = 0;
    countO = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 'x') {
                countX++;
            } else if (board[i][j] == 'o') {
                countO++;
            }
        }
    }
}

int main() {
    std::vector<std::string> board(3);
    
    // Read the board
    for (int i = 0; i < 3; i++) {
        std::cin >> board[i];
    }
    
    // Check if x has won
    bool xWins = hasWon(board, 'x');
    // Check if o has won
    bool oWins = hasWon(board, 'o');
    
    // Count the number of x and o pieces
    int countX, countO;
    countPieces(board, countX, countO);
    
    // Check for invalid game states
    // Case 1: Both players have won
    if (xWins && oWins) {
        std::cout << "invalid" << std::endl;
        return 0;
    }
    
    // Case 2: x wins but o has made the same number of moves as x
    // Since x goes first, x should have one more move than o when x wins
    if (xWins && countX == countO) {
        std::cout << "invalid" << std::endl;
        return 0;
    }
    
    // Case 3: o wins but x has fewer moves than o
    // Since x goes first, x should have the same number of moves as o when o wins
    if (oWins && countX < countO) {
        std::cout << "invalid" << std::endl;
        return 0;
    }
    
    // Case 4: o wins but x has more than one extra move
    // Since x goes first, x should have exactly the same number of moves as o when o wins
    if (oWins && countX > countO) {
        std::cout << "invalid" << std::endl;
        return 0;
    }
    
    // Case 5: The difference in moves is more than 1
    // Since players alternate turns with x going first, the difference should be at most 1
    if (countX > countO + 1 || countO > countX) {
        std::cout << "invalid" << std::endl;
        return 0;
    }
    
    // If x has won
    if (xWins) {
        std::cout << "win" << std::endl;
        return 0;
    }
    
    // If o has won
    if (oWins) {
        std::cout << "lose" << std::endl;
        return 0;
    }
    
    // If the board is full (9 pieces)
    if (countX + countO == 9) {
        std::cout << "tie" << std::endl;
        return 0;
    }
    
    // Otherwise, the game is still ongoing
    std::cout << "ongoing" << std::endl;
    return 0;
}