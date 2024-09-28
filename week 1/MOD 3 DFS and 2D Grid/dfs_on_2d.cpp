#include <bits/stdc++.h>
#define ll long long int
#define fast() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
const long long int INF = 1e18+5;
using namespace std;

int r, c;
char mat[20][20];
vector<pair<int,int>>v={{0,1},{0,-1},{-1,0},{1,0}};
bool vis[20][20]={false};

bool valid(int i, int j){
    if(i>=0 && i<r && j>=0 && j<c)return true;
    return false;
}

void dfs(int i, int j)
{
    cout<<i<<" "<<j<<endl;
    vis[i][j]=true;
    for(auto p : v) //o(v)
    { 
        int child_i=i+p.first, child_j =j+p.second;
        if(valid(child_i,child_j) && !vis[child_i][child_j] && mat[child_i][child_j]=='.')
            dfs(child_i,child_j);
    }
}
int main()
{
    fast();
    cin >> r >> c;
    for (int i = 0; i < r; i++) //o(n*n)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> mat[i][j];
        }
    }
    int si, sj;
    cin >> si >> sj;
    dfs(si, sj);
    return 0;
}