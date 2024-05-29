// Fractional Knapsack

#include <bits/stdc++.h>
using namespace std;

double fractionalKnapsack(int capacity, vector<int> &profits, vector<int> &weights)
{
    int n = profits.size();

    vector<int> indices(n);

    for (int i = 0; i < n; i++)
    {
        indices[i] = i;
    }

    auto cmp = [&](int a, int b)
    {
        double ratio1 = (double)profits[a] / weights[a];
        double ratio2 = (double)profits[b] / weights[b];

        return ratio1 > ratio2;
    };

    sort(indices.begin(), indices.end(), cmp);

    double finalvalue = 0.0;

    for (int i = 0; i < n; i++)
    {
        int idx = indices[i];

        if (weights[idx] <= capacity)
        {
            finalvalue += profits[idx];
            capacity -= weights[idx];
        }
        else
        {
            finalvalue += profits[idx] * ((double)capacity / (double)weights[idx]);
            break;
        }
    }

    return finalvalue;
}

int main()
{
    int capacity = 20;

    vector<int> profits = {25, 24, 15};
    vector<int> weights = {18, 15, 10};

    double maxProfit = fractionalKnapsack(capacity, profits, weights);

    cout << "Max Profit in knapsack : " << maxProfit << endl;
}