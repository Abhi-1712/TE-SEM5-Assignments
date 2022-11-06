#include <bits/stdc++.h>
using namespace std;

class KnapSack
{
private:
    vector<pair<int, float>> items;
    int currentIndex;
    float profit = 0.0;
    int no_of_items = 0;
    int sackCapacity = 0;

    // Driver function to sort the vector elements
    // by second element of pairs in according order
    static bool sortByValues(const pair<int, float> &a, const pair<int, float> &b)
    {
        return (a.second < b.second);
    }

    float recursiveKnapsack(int currentIndex, int currentCapacity)
    {
        // Base case
        if (currentIndex < 0)
            return 0;

        float recursiveProfit1 = 0.0; // profit calculated based on first item as starting point

        // Allow only those items whose weights are less than or equal to sackCapacity
        if (items[currentIndex].first <= currentCapacity)
        {
            recursiveProfit1 += items[currentIndex].second + recursiveKnapsack(currentIndex - 1, currentCapacity - items[currentIndex].first);
            // cout << recursiveProfit1 << " " << items[currentIndex].first << " " << items[currentIndex].second << endl;
        }

        float recursiveProfit2 = recursiveKnapsack(currentIndex - 1, currentCapacity); // profit calculated based on first item as starting point
        return max(recursiveProfit1, recursiveProfit2);
    }

public:
    void takeInput()
    {
        cout << "Enter no. of items : ";
        cin >> no_of_items;
        cout << "Enter weights(quantity) and values(cost) : ";
        for (int i = 0; i < no_of_items; i++)
        {
            int first;
            float second;
            cin >> first;
            cin >> second;
            items.push_back(make_pair(first, second));
        }
        cout << "Enter knapsack capacity : ";
        cin >> sackCapacity;
    }

    float maximumProfit()
    {
        // Ensure values are sorted according to their values
        sort(items.begin(), items.end(), sortByValues);
        return recursiveKnapsack(no_of_items - 1, sackCapacity);
    }
};

int main()
{
    KnapSack k = KnapSack();
    k.takeInput();
    cout << "Maximum profit : " << k.maximumProfit() << endl;
    return 0;
}

/*
* Output

Enter no. of items : 4
Enter weights(quantity) and values(cost) : 2 3
3 4
4 5
5 6
Enter knapsack capacity : 5
Maximum profit : 7

*/