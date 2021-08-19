#include <iostream>
using namespace std;

#define N 9

bool findEmptyLocation(int grid[N][N], int &row, int &col) {
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (grid[row][col] == 0)
                return true;
        }
    }
    return false;
}

bool presentInRow(int grid[N][N], int row, int option) {
    for (int col = 0; col < N; col++) {
        if (grid[row][col] == option)
            return true;
    }
    return false;
}

bool presentInCol(int grid[N][N], int col, int option) {
    for (int row = 0; row < N; row++) {
        if (grid[row][col] == option)
            return true;
    }
    return false;
}

bool presentInSmallBox(int grid[N][N], int row_start, int col_start, int option) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++)
        {
            if (grid[row_start + row][col_start + col] == option)
                return true;
        }
    }
    return false;
}

bool isvalid(int grid[N][N], int row, int col, int option) {
    if (!presentInRow(grid, row, option) &&
        !presentInCol(grid, col, option) &&
        !presentInSmallBox(grid, row - row % 3, col - col % 3, option) &&
        grid[row][col] == 0) {
        return true;
    }
    else
        return false;
}

bool solver(int grid[N][N])
{
    int row, col;
    if (!findEmptyLocation(grid, row, col)) {
        return true;
    }

    for (int option = 1; option <= 9; option++) {
        if (isvalid(grid, row, col, option)) {
            grid[row][col] = option;

            if(solver(grid)) return true;

            grid[row][col] = 0;
        }
    }
    return false;
}

void printgrid(int grid[N][N]) {
    cout << "\nThe solution is : \n\n";
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            cout << grid[row][col] << " ";
        }
        cout << endl;
    }
}

void inputgrid(int (*grid)[N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            cin >> grid[row][col];
        }
        cout << endl;
    }
}

int main()
{
    int grid[N][N];

    cout << "Enter the 9x9 Sudoku Puzzle\n";
    cout << "(0 for empty locations)\n";

    inputgrid(grid);

    if (solver(grid))
    {
        printgrid(grid);
    }
    else
        cout << "No solution exists\n";
    return 0;
}

/*
3 0 6 5 0 8 4 0 0
5 2 0 0 0 0 0 0 0
0 8 7 0 0 0 0 3 1
0 0 3 0 1 0 0 8 0
9 0 0 8 6 3 0 0 5
0 5 0 0 9 0 6 0 0
1 3 0 0 0 0 2 5 0
0 0 0 0 0 0 0 7 4
0 0 5 2 0 6 3 0 0


// int grid[N][N] = {
//     {3, 0, 6, 5, 0, 8, 4, 0, 0},
//     {5, 2, 0, 0, 0, 0, 0, 0, 0},
//     {0, 8, 7, 0, 0, 0, 0, 3, 1},
//     {0, 0, 3, 0, 1, 0, 0, 8, 0},
//     {9, 0, 0, 8, 6, 3, 0, 0, 5},
//     {0, 5, 0, 0, 9, 0, 6, 0, 0},
//     {1, 3, 0, 0, 0, 0, 2, 5, 0},
//     {0, 0, 0, 0, 0, 0, 0, 7, 4},
//     {0, 0, 5, 2, 0, 6, 3, 0, 0}};
*/