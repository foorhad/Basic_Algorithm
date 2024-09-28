#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> ar[n]; //array of vector
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        ar[a].push_back(b);
        ar[b].push_back(a); //undirected graph
    }
    
    // for (int x : ar[1])
    // {
    //     cout << x << " ";
    // }
    for (int i = 0; i < ar[4].size(); i++)
    {
        cout << ar[4][i] << " ";
    }

    return 0;
}