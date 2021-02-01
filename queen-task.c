
// queen-task.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <string.h>

char boards[8][8][8];

struct field_struct
{
    char x;
    char y;
};

typedef struct field_struct  Field;

void showFieldState(char field)
{
    switch (field) {
    case 0:
        printf(" .");
        break;
    case 1:
        printf(" Q");
        break;
    case 2:
        printf(" x");
        break;
    default:
        printf("  ");
    }
}

void showBoard(char board[8][8])
{
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++) {
            showFieldState(board[i][j]);
        }
        printf("\n");
    }
}

Field getNearestNextEmpty(char board[8][8], char x, char y)
{
    Field result;
    result.x = -1;
    result.y = -1;

    for (int i = x; i < 8; i++) {
        if (!board[i][y]) {
            result.x = i;
            result.y = y;
            return result;
        }
    }
    for (int j = y + 1; j < 8; j++)
        for (int i = 0; i < 8; i++)
        {
            if (!board[i][j]) {
            result.x = i;
            result.y = j;
            return result;
            }
        }
    return result;
}

inline void markSetQueen(char board[8][8], char x, char y)
{
    board[x][y] = 1;
}

inline void markWrongField(char board[8][8], char x, char y)
{
    board[x][y] = 3;
}

void markThreatened(char board[8][8], char x, char y)
{
    for (int i = x - 1; i >= 0; i--)
        if (!board[i][y]) board[i][y] = 2;
    for (int i = x + 1; i < 8; i++)
        if (!board[i][y]) board[i][y] = 2;
    for (int j = y - 1; j >= 0; j--)
        if (!board[x][j]) board[x][j] = 2;
    for (int j = y + 1; j < 8; j++)
        if (!board[x][j]) board[x][j] = 2;
    int i = x - 1;
    int j = y - 1;
    while (i >= 0 && j >= 0) {
        if (!board[i][j]) board[i][j] = 2;
        i--;
        j--;
    }
    i = x - 1;
    j = y + 1;
    while (i >= 0 && j < 8) {
        if (!board[i][j]) board[i][j] = 2;
        i--;
        j++;
    }
    i = x + 1;
    j = y + 1;
    while (i < 8 && j < 8) {
        if (!board[i][j]) board[i][j] = 2;
        i++;
        j++;
    }
    i = x + 1;
    j = y - 1;
    while (i < 8 && j >= 0) {
        if (!board[i][j]) board[i][j] = 2;
        i++;
        j--;
    }
}

int step(char board[8][8], char x, char y, char level)
{
    Field q = getNearestNextEmpty(board, x, y);
    if (q.x >= 0) {
        if (level == 7) {
            markSetQueen(board, q.x, q.y);
            return 1;
        }

        int result = 0;
        while (q.x >= 0) {
            memcpy(boards[level + 1], board, sizeof(char) * 8 * 8);
            markSetQueen(boards[level + 1], q.x, q.y);
            markThreatened(boards[level + 1], q.x, q.y);
            result = step(boards[level + 1], q.x, q.y, level + 1);
            if (result) break;
            markWrongField(board, q.x, q.y);
            q = getNearestNextEmpty(board, x, y);
        }
        return result;
    }
    else {
        return 0;
    }

}

int main()
{
    printf("Start\n");
    showBoard(boards[0]);
    Field q = getNearestNextEmpty(boards[0], 0, 0);
    markSetQueen(boards[0], q.x, q.y);
    markThreatened(boards[0], q.x, q.y);
    printf("\n");
    showBoard(boards[0]);

    /*
    q = getNearestNextEmpty(boards[0], q.x, q.y);
    markSetQueen(boards[0], q.x, q.y);
    markThreatened(boards[0], q.x, q.y);
    printf("\n");
    showBoard(boards[0]);
    */

    int res = step(boards[0], 0, 0, 0);
    printf(" --- \n");
    printf("Res = %d\n", res);
    printf(" --- \n");

    printf("\n");
    showBoard(boards[0]);
    printf("\n");
    showBoard(boards[1]);
    printf("\n");
    showBoard(boards[2]);
    printf("\n");
    showBoard(boards[3]);
    printf("\n");
    showBoard(boards[4]);
    printf("\n");
    showBoard(boards[5]);
    printf("\n");
    showBoard(boards[6]);
    printf("\n");
    showBoard(boards[7]);

}







// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
