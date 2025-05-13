#include <iostream>
#include <vector>
using namespace std;

const int N = 4;
int board[N][N] = {0};
pair<int, int> placed = {0, 0};

void printBoard(int board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << (board[i][j] ? "Q " : ". ");
        cout << endl;
    }
}

bool isSafe(int board[N][N], int x, int y)
{
    for (int i = 0; i < N; i++)
        if (board[i][y] == 1 || board[x][i] == 1)
            return false;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] == 1 && (abs(i - x) == abs(j - y)))
                return false;
        }
    }

    return true;
}

bool NQueens(int board[N][N], int col)
{
    if (col >= N)
        return true;

    if (col == placed.second)
        return NQueens(board, col + 1);

    for (int i = 0; i < N; i++)
    {
        if (i == placed.first)
            continue;

        if (isSafe(board, i, col))
        {
            board[i][col] = 1;

            if (NQueens(board, col + 1))
                return true;

            board[i][col] = 0;
        }
    }
    return false;
}

int main()
{

    cout << "Enter the position where you want initial placement: ";
    cin >> placed.first >> placed.second;

    board[placed.first][placed.second] = 1;

    cout << "Initial Board\n";
    printBoard(board);
    cout << "\n\n";

    if (NQueens(board, 0))
    {
        cout << "Solution\n";
        printBoard(board);
    }
    else
    {
        cout << "No Solution\n";
    }

    return 0;
}
