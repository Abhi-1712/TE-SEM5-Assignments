
#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int> w, vector<int> v, int n, int maxw)
{

    vector<vector<int>> dp(n + 1, vector<int>(maxw + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= maxw; j++)
        {
            if (j - w[i - 1] >= 0)
            {
                int consider = v[i - 1] + dp[i - 1][j - w[i - 1]];
                int dontConsider = dp[i - 1][j];
                dp[i][j] = max(consider, dontConsider);
            }
            else
            {
                int dontConsider = dp[i - 1][j];
                dp[i][j] = dontConsider;
            }
        }
    }
    return dp[n][maxw];
}

int main()
{

    cout << "Enter Number of Elements" << endl;
    int n;
    cin >> n;

    cout << "Enter Weight array" << endl;
    vector<int> w(n);
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }

    cout << "Enter Value array" << endl;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    cout << "Enter maximum weight of knapsack" << endl;
    int maxw;
    cin >> maxw;

    cout << "Value of maximum value knapsack can hold " << endl;
    cout << knapsack(w, v, n, maxw) << endl;

    return 0;
}

/*
* Output

Enter Number of Elements
4
Enter Weight array
2
3
4
5
Enter Value array
3 4 5 6
Enter maximum weight of knapsack
5
Value of maximum value knapsack can hold
7

*/