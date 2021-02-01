
// queen-task.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "stdio.h"

char fields[8][8];

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

int main()
{
    printf("Start\n");
    showBoard(fields);
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
