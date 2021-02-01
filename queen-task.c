
// queen-task.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <string.h>

char boards[7][8][8] = { 0 };

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
    printf("    a b c d e f g h\n");
    for (int i = 0; i < 8; i++){
        printf("%d :", i + 1);
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
            memcpy(boards[level], board, sizeof(char) * 8 * 8);
            markSetQueen(boards[level], q.x, q.y);
            markThreatened(boards[level], q.x, q.y);
            result = step(boards[level], q.x, q.y, level + 1);
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
