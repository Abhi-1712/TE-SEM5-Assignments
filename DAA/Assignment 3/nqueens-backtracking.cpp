#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<string> &a, int row, int col)
{
    // check if the column had a queen before.
    int n = a[0].size();
    for (int i = 0; i != row; ++i)
        if (a[i][col] == 'Q')
            return false;
    // check if the 45° diagonal had a queen before.
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
        if (a[i][j] == 'Q')
            return false;
    // check if the 135° diagonal had a queen before.
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j)
        if (a[i][j] == 'Q')
            return false;
    return true;
}

bool solve(vector<string> &a, int r)
{
    int n = a[0].size();

    if (r == n)
        return true;

    for (int c = 0; c < n; c++)
    {
        // Checking if we can place queen at current position
        if (isValid(a, r, c))
        {
            a[r][c] = 'Q';

            // checking weather we get right combinatin on placing queen at [r][c]
            if (solve(a, r + 1))
                return true;

            a[r][c] = 'o';
        }
    }
    return false;
}

int main()
{
    int n;
    cout << "Enter Value of number of queens: ";
    cin >> n;
    vector<string> a;
    vector<vector<string>> ans;

    string s;
    for (int i = 0; i < n; i++)
    {
        s += 'o';
    }

    for (int i = 0; i < n; i++)
    {
        a.push_back(s);
    }

    solve(a, 0);

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << endl;
    }
    cout << endl;

    return 0;
}

/*
* Output



*/