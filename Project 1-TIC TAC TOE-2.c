#include <stdio.h>

int main() {
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    int player = 1;
    int moves = 0;
    char mark;
    int win = 0;
    int row, col;

    // Main game loop
    while (1) {
        // Print current board
        printf("\n");
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                printf(" %c ", *(*(board + i) + j)); // Pointer notation
                if (j < 2) printf("|");
            }
            if (i < 2) printf("\n---+---+---\n");
        }
        printf("\n");

        // Set player's mark
        if (player == 1) mark = 'X';
        else mark = 'O';

        // Player input: Get row and column
        printf("Player %d (%c), enter row and column (1-3 each): ", player, mark);
        scanf("%d %d", &row, &col);

        // Adjust indices: C arrays start from 0
        row--; col--;

        // Input validation
        if ((row < 0 || row > 2) || (col < 0 || col > 2)) {
            printf("Invalid input, try again.\n");
            continue; // Jump statement
        }
        if (*(*(board + row) + col) != ' ') {
            printf("Cell taken, try again.\n");
            continue; // Jump statement
        }

        // Place mark and count move
        *(*(board + row) + col) = mark;
        moves++;

        // Check for win (rows, columns, diagonals)
        for (int i = 0; i < 3; i++) {
            // Row
            if (*(*(board + i) + 0) == mark &&
                *(*(board + i) + 1) == mark &&
                *(*(board + i) + 2) == mark) {
                win = 1;
                break; // Jump statement
            }
            // Column
            if (*(*(board + 0) + i) == mark &&
                *(*(board + 1) + i) == mark &&
                *(*(board + 2) + i) == mark) {
                win = 1;
                break; // Jump statement
            }
        }
        // Diagonals
        if (*(*(board + 0) + 0) == mark &&
            *(*(board + 1) + 1) == mark &&
            *(*(board + 2) + 2) == mark) {
            win = 1;
        }
        else if (*(*(board + 0) + 2) == mark &&
                 *(*(board + 1) + 1) == mark &&
                 *(*(board + 2) + 0) == mark) {
            win = 1;
        }

        // If win is detected:
        if (win == 1) {
            printf("\nPlayer %d (%c) wins!\n", player, mark);
            // Show final board
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    printf(" %c ", *(*(board + i) + j));
                    if (j < 2) printf("|");
                }
                if (i < 2) printf("\n---+---+---\n");
            }
            printf("\n");
            break; // Ends game
        }

        // Check for tie (board full, no win)
        if (moves == 9 && win == 0) {
            printf("\nIt's a tie! Both players are equal on their inputs.\n");
            // Print final board
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    printf(" %c ", *(*(board + i) + j));
                    if (j < 2) printf("|");
                }
                if (i < 2) printf("\n---+---+---\n");
            }
            printf("\n");
            break; // Ends game
        }

        // Switch player
        if (player == 1) player = 2;
        else player = 1;
    }
    return 0;
}
