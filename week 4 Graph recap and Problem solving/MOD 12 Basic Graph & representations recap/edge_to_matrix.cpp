#include <bits/stdc++.h>
#define ll long long int
#define nl '\n'
#define fast() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
const long long int INF = 1e18+5;
using namespace std;
int main()
{
 fast();
    int nodes,edges;cin>>nodes>>edges;
    int matrix[nodes][nodes];
    for(int i=0;i<nodes;i++){
        for(int j=0;j<nodes;j++){
            matrix[i][j]=0;
            if(i==j)matrix[i][j]=1;
        }
    }
    while (edges--)
    {
       int u,v,w;cin>>u>>v>>w;
       matrix[u][v]=w;
       matrix[v][u]=w;
    }

    for(int i=0;i<nodes;i++){
        for(int j=0;j<nodes;j++){
           cout<<matrix[i][j]<<" ";
        }
        cout<<nl;
    }
    
    return 0;
}