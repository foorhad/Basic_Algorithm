#include <bits/stdc++.h>
#define ll long long int
#define nl '\n'
#define fast() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
const long long int INF = 1e18+5;
using namespace std;

class Edge{
public: 
    int u,v,w;
    Edge(int u, int v, int w){
        this->u=u;
        this->v=v;
        this->w=w;
    }
};
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

    vector<Edge>edgelist;

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if(matrix[i][j]>0 && i!=j){
            edgelist.push_back(Edge(i,j,matrix[i][j]));
        }
      }
    }
    for(Edge child : edgelist){
        cout<<child.u<<" "<<child.v<<" "<<child.w<<nl;
    }

    
    
    return 0;
}