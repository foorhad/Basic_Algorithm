#include <bits/stdc++.h>
#define ll long long int
#define nl '\n'
#define fast() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
const long long int INF = 1e18+5;
using namespace std;
void convert(int n, vector<pair<int,int>>adj_list[]){
    int matrix[n][n];
      for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            matrix[i][j]=-1;
            if(i==j)matrix[i][j]=1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for(pair<int,int> node : adj_list[i]){
            matrix[i][node.first]=node.second;
        }
    }
    for(int i=0;i<n;i++){
        for (int j = 0; j < n; j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<nl;
    }
}
int main()
{
 fast();
    int nodes,edges;cin>>nodes>>edges;
    vector<pair<int,int>>adj_list[nodes];
    while (edges--)
    {
       int u,v,w;cin>>u>>v>>w;
       adj_list[u].push_back({v,w});
       adj_list[v].push_back({u,w});
    }
    convert(nodes,adj_list);
   
    return 0;
}