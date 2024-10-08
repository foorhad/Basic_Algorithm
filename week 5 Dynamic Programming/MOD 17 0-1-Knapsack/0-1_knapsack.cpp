#include <bits/stdc++.h>
#define ll long long int
#define pi pair<ll, ll>
#define nl '\n'
#define fast() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
const long long int INF = 1e18 + 5;
const int N = 1e6 + 5;
using namespace std;

int knapsack(int n, int weight[], int value[], int W)
{

    if (n == 0 || W == 0)
        return 0;
    if (weight[n - 1] <= W)
    {
        int opt1 = knapsack(n - 1, weight, value, W - weight[n-1]) + value[n-1];
        int opt2 = knapsack(n - 1, weight, value, W);
        return max(opt1, opt2);
    }
    else
    {
        int opt2 = knapsack(n - 1, weight, value, W);
        return opt2;
    }
}
int main()
{
    fast();
    int n;
    cin >> n;
    int weight[n], value[n];
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> value[i];
    }

    int W;
    cin >> W;
    cout << knapsack(n, weight, value, W);
    return 0;
}