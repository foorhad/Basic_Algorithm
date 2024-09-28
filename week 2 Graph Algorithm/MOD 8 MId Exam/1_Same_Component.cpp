#include <bits/stdc++.h>
#define ll long long int
#define fast() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
const long long int INF = 1e18+5;
using namespace std;

int r, c;
char mat[1005][1005];
vector<pair<int,int>>v={{0,1},{0,-1},{-1,0},{1,0}};

bool vis[1005][1005]={false};

bool valid(int si, int sj){
    if(si >=0 && si<r && sj>=0 && sj<c)return true;
    else return false;
}
void dfs(int i, int j)
{
    vis[i][j]=true;
    for(auto p : v){ 
        int f=i+p.first; int s =j+p.second;
        if(valid(f,s)==true && vis[f][s]==false && mat[f][s]=='.')
            dfs(f,s);
    }
}
int main()
{
    fast();
    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> mat[i][j];
        }
    }
    int si, sj;
    cin >> si >> sj;
    int di,dj;cin>>di>>dj;
    dfs(si, sj);
    if(vis[di][dj])cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;
}