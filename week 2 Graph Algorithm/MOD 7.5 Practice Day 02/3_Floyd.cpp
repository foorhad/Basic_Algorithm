#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int matrix[105][105];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> matrix[i][j];
            if (matrix[i][j] == -1)
                matrix[i][j] = INT_MAX;
        }
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (matrix[i][k] != INT_MAX && matrix[k][j] != INT_MAX && matrix[i][k] + matrix[k][j] < matrix[i][j])
                {
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                }
            }
        }
    }

    int mx = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (matrix[i][j] > mx)
            {
                if (matrix[i][j] != INT_MAX)
                {
                    mx = matrix[i][j];
                }
            }
        }
    }
    cout << mx;
}
