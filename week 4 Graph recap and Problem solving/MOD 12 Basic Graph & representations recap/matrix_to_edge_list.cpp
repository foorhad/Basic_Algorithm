#include <bits/stdc++.h>
#define ll long long int
#define nl '\n'
#define fast() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
const long long int INF = 1e18+5;
using namespace std;
int main()
{
 fast();
    int n;cin>>n;
    int matrix[n][n];
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        cin>>matrix[i][j];
      }
    }
    vector<pair<int,int>>edgelist;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if(matrix[i][j]>0 && i!=j)edgelist.push_back({i,j});
      }
    }
    for(pair<int,int> child : edgelist){
        cout<<child.first<<" "<<child.second<<nl;
    }

    
    
    return 0;
}