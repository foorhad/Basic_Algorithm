#include <bits/stdc++.h>
#define ll long long int
#define pi pair<int,int>
#define nl '\n'
#define fast() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
const long long int INF = 1e18+5;
const int N = 1e6 + 5;
using namespace std;
int n,m;

bool vis[1005][1005];
char grid[1005][1005];
map<pi,pi>par;
bool valid(int i,int j){
    if(i>=0 && i<n && j>=0 && j<m)return true;
    return false;
}

vector<pi>movement={{0,1},{0,-1},{-1,0},{1,0}};

void bfs(int i, int j){
    vis[i][j]=true;
    queue<pi>q;
    q.push({i,j});

    while (!q.empty())
    {
        pi parent = q.front();q.pop();
        int parent_i = parent.first;
        int parent_j = parent.second;

        for(pi child : movement){
            int child_i = parent_i+child.first;
            int child_j = parent_j+child.second;

            if(valid(child_i,child_j) && !vis[child_i][child_j] && grid[child_i][child_j]!='#'){
                par[{child_i,child_j}]={parent_i,parent_j};
                q.push({child_i,child_j});
                vis[child_i][child_j]=true;
            }
        }
    }
    
}

int main()
{
 fast();
    memset(vis,false,sizeof(vis));
    cin>>n>>m;
    int si,sj,di,dj;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>grid[i][j];
            if (grid[i][j]=='R')
            {
               si=i,sj=j;
            }
            if (grid[i][j]=='D')
            {
               di=i,dj=j;
            }
        }
    }
    bfs(si,sj);
    if(vis[di][dj]){
        int pathi = par[{di,dj}].first, pathj = par[{di,dj}].second;
        while (grid[pathi][pathj]!=grid[si][sj])
        {
            grid[pathi][pathj]='X';
            
            int nsti= par[{pathi,pathj}].first;
            pathj =  par[{pathi,pathj}].second;

            pathi = nsti;
        }
    
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout<<grid[i][j];
        }
        cout<<nl;
    }
    
    
    return 0;
}