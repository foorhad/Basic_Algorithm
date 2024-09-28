#include <bits/stdc++.h>
#define ll long long int
#define nl '\n'
#define fast() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
const long long int INF = 1e18+5;
using namespace std;
void convert(int n, vector<int>adj_list[]){
    int matrix[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            matrix[i][j]=0;
            if(i==j)matrix[i][j]=1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for(int n : adj_list[i]){
            matrix[i][n]=1;
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
    vector<int>adj_lst[nodes];
    while (edges--)
    {
       int u,v;cin>>u>>v;
       adj_lst[u].push_back(v);
       adj_lst[v].push_back(u);
    }
    convert(nodes,adj_lst);
   
    return 0;
}