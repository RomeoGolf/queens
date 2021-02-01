
#include <stdio.h>
#include <string.h>

/* the boards buffer for recursion levels */
char boards[7][8][8] = { 0 };

/* a position on a board */
struct field_struct
{
    char x;
    char y;
};
typedef struct field_struct  Field;

/* the result queens positions */
Field queens[8];

/* Show a state of a board field */
void showFieldState(char field)
{
    switch (field) {
    case 0:     /* empty */
        printf(" .");
        break;
    case 1:     /* queen position */
        printf(" Q");
        break;
    case 2:     /* threatened field*/
        printf(" x");
        break;
    default:    /* other (e. g. wrong) */
        printf(" x");
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

/* Find a nearest empty safe field on the board started from [x, y] inclusive */
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

/* Mark the fields the queen threats from [x, y] */
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

/* Step the recursive search */
int step(char board[8][8], char x, char y, char level)
{
    Field q = getNearestNextEmpty(board, x, y);
    if (q.x >= 0) {
        if (level == 7) {
            markSetQueen(board, q.x, q.y);
            queens[7].x = q.x;
            queens[7].y = q.y;
            return 1;
        }

        int result = 0;
        while (q.x >= 0) {
            memcpy(boards[level], board, sizeof(char) * 8 * 8);
            markSetQueen(boards[level], q.x, q.y);
            queens[level].x = q.x;
            queens[level].y = q.y;
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
    for (int i = 0; i < 8; i++) {
        memset(boards, 0, 7 * 8 * 8 * sizeof(char));    /* clear the boards buffer before new search*/
        int res = step(boards[0], i, 0, 0);             /* set the first queen position */
        printf(" --- \n");
        if (res) {
            printf("First queen at [%c%c]:\n", 0 + 'a', i + '1');
            showBoard(boards[6]);
            for (int i = 0; i < 8; i++) {
                printf("[%c%c] ", queens[i].y + 'a', queens[i].x + '1');
            }
            printf("\n");
        }
    }
}
