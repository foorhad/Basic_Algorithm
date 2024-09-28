#include <bits/stdc++.h>
#define ll long long int
#define fast() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main()
{
    fast();
    
    ll nodes, edge;
    cin >> nodes >> edge;
    ll adj_matrix[nodes][nodes];
    for (int i = 0; i < nodes; i++)
    {
        for (int j = 0; j < nodes; j++)
        {
            if (i == j)
                adj_matrix[i][j] = 0;
            else
                adj_matrix[i][j] = INT_MAX;
        }
    }
    
    //input
    while (edge--)
    {
        int u, v, c;
        cin >> u >> v >> c;
        adj_matrix[u][v] = c;
    }

    for (int k = 0; k < nodes; k++)
    {
        for (int i = 0; i < nodes; i++)
        {
            for (int j = 0; j < nodes; j++)
            {
                if (adj_matrix[i][k] + adj_matrix[k][j] < adj_matrix[i][j])
                {
                    adj_matrix[i][j] = adj_matrix[i][k] + adj_matrix[k][j];
                }
            }
        }
    }


    for (int i = 0; i < nodes; i++)
    {
        for (int j = 0; j < nodes; j++)
        {
            if (adj_matrix[i][j] == INT_MAX)
                cout << "INF" << " ";
            else
                cout << adj_matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}