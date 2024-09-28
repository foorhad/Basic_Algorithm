#include <bits/stdc++.h>
#define ll long long int
#define fast() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
const long long int INF = 1e18+5;
using namespace std;

int main()
{
    fast();
    ll nodes, edge;
    cin >> nodes >> edge;

    ll matrix[nodes+1][nodes+1];
    for (int i = 1; i <= nodes; i++){
        for (int j = 1; j <= nodes; j++){
            matrix[i][j]=INF;
            if(i==j)matrix[i][j]=0;
        }
    }
    
    while (edge--)
    {
        ll a,b, c;
        cin >> a >> b >> c;
        matrix[a][b]=min(matrix[a][b],c);
    }

    for (int k = 1; k <=nodes ; k++){ 
        for (int i = 1; i <=nodes ; i++){
            for (int j = 1; j <=nodes ; j++){
                if(matrix[i][k]+matrix[k][j] < matrix[i][j]){
                    matrix[i][j] = matrix[i][k]+matrix[k][j];
                }
            }
        }
    }
    int q;cin>>q;
    while (q--)
    {
        ll u, v;
        cin >> u >> v;
        if(matrix[u][v]==INF)cout<<-1<<endl;
        else cout<<matrix[u][v]<<endl;
    }

    return 0;
}