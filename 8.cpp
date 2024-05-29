// job sequensing Problem

#include <bits/stdc++.h>

using namespace std;

int findMaxDeadline(vector<int> &deadlines)
{
    int n = deadlines.size();
    int maxdeadline = 0;

    for (int i = 0; i < n; i++)
    {
        maxdeadline = max(maxdeadline, deadlines[i]);
    }

    return maxdeadline;
}

int jobsequencing(vector<int> &deadlines, vector<int> &profits)
{
    int n = deadlines.size();

    vector<pair<int, int>> jobs(n);

    for (int i = 0; i < n; i++)
    {
        jobs[i] = {profits[i], deadlines[i]};
    }

    sort(jobs.rbegin(), jobs.rend());

    int maxDeadline = findMaxDeadline(deadlines);

    vector<int> slots(maxDeadline, -1);

    int maxProfit = 0;

    for (int i = 0; i < n; i++)
    {
        int profit = jobs[i].first;
        int deadline = jobs[i].second;

        for (int j = deadline - 1; j >= 0; j--)
        {
            if (slots[j] == -1)
            {
                slots[j] = i;
                maxProfit += profit;
                break;
            }
        }
    }

    return maxProfit;
}

int main()
{
    vector<int> deadlines = {2, 1, 2, 1, 1};
    vector<int> profits = {100, 19, 27, 25, 15};

    cout << "Max. Profit  : " << jobsequencing(deadlines, profits);
}