#include <bits/stdc++.h>
using namespace std;

double maximumValue(vector<pair<int, int>> &a, int n, int w, vector<double> &considered)
{
    vector<pair<long double, long double>> frac;

    for (int i = 0; i < n; i++)
    {
        frac.push_back(make_pair((a[i].second / (double)a[i].first), i));
    }

    long double ans = 0;

    sort(frac.begin(), frac.end());
    reverse(frac.begin(), frac.end());
    for (int i = 0; i < n; i++)
    {
        int currItemWeight = a[frac[i].second].first;
        if (currItemWeight <= w)
        {
            considered[frac[i].second] = 1;
            ans += frac[i].first * currItemWeight;
            w -= currItemWeight;
        }
        // fraction
        else
        {
            considered[frac[i].second] = (w / (double)currItemWeight);
            ans += frac[i].first * w;
            w = 0;
        }
    }
    return ans;
}

int main()
{
    cout << "Enter value of number of elements and Capacity of knapsack" << endl;
    int n, capacity;
    cin >> n >> capacity;
    vector<pair<int, int>> a;
    vector<double> considered(n, 0);
    cout << "Enter N lines where ith line denote value of Wi and Vi" << endl;
    for (int i = 0; i < n; i++)
    {
        int ele1, ele2;
        cin >> ele1 >> ele2;
        a.push_back(make_pair(ele1, ele2));
    }
    considered.clear();
    cout << "Maximum value = " << maximumValue(a, n, capacity, considered) << endl;
    cout << "Fraction of considered : ";

    for (int i = 0; i < n; i++)
    {
        cout << considered[i] << " ";
    }
    cout << endl;
    return 0;
}

/*
* Output

Enter value of number of elements and Capacity of knapsack
5 10
Enter N lines where ith line denote value of Wi and Vi
1 1
2 2
3 3
4 4
5 5
Maximum value = 10
Fraction of considered : 0 0 0.333333 1 1

*/