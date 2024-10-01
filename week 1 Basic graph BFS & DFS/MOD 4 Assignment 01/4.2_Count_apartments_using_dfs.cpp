#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;
    int matrix[1005][1005];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < e; j++)
        {
            matrix[i][j] = -1;
            if (i == j)
                matrix[i][j] = 1;
        }
    }

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        matrix[a][b] = 1;
    }

    int q;
    cin >> q;
    while (q--)
    {
        int u, v;
        cin >> u >> v;

        if (matrix[u][v] == 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
