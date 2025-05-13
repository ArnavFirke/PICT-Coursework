#include <bits/stdc++.h>
using namespace std;
class Nqueens
{
    vector<int> board;
    vector<vector<int>> result;

public:
    Nqueens(int n) : board(n, -1) {}
    bool isSafe(int row, int col)
    {
        for (int i = 0; i < row; i++)
        {
            if (board[i] == col or abs(board[i] - col) == abs(i - row))
                return false;
        }
        return true;
    }
    void recsolve(int row, int n)
    {
        if (row == n)
        {
            result.push_back(board);
            return;
        }
        for (int col = 0; col < n; col++)
        {
            if (isSafe(row, col))
            {
                board[row] = col;
                recsolve(row + 1, n);
            }
        }
    }

    int print()
    {
        for (auto rows : result)
        {
            for (auto sol : rows)
            {
                for (int i = 0; i < rows.size(); i++)
                {
                    if (sol == i)
                    {
                        cout << "Q ";
                    }
                    else
                    {

                        cout << ". ";
                    }
                }
                cout << "\n";
            }
            cout << "\n";
        }
        return result.size();
    }
};
int main()
{
    int n;
    char ch = 'y';
    while (ch == 'y')
    {
        cout << "Enter the number of queens (n): ";
        cin >> n;
        Nqueens nq(n);
        nq.recsolve(0, n);
        int sol = nq.print();
        cout << "Number of solutions: " << sol << endl;
        cout << "Want to continue (y/n): ";
        cin >> ch;
    }
    return 0;
}