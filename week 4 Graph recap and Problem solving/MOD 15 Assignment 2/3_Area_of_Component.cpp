#include <bits/stdc++.h>
#define ll long long int
#define pi pair<ll, ll>
#define nl '\n'
#define fast() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
const long long int INF = 1e18+5;
const int N = 1e6 + 5;
using namespace std;
int n,m;

bool vis[1005][1005];

char grid[1005][1005];
int cnt_area=0;
bool valid(int i,int j){
    if(i>=0 && i<n && j>=0 && j<m)return true;
    return false;
}

vector<pi>movement={{0,1},{0,-1},{-1,0},{1,0}};

void bfs(int i, int j){
    cnt_area++;
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

            if(valid(child_i,child_j) && !vis[child_i][child_j] && grid[child_i][child_j]=='.'){
                q.push({child_i,child_j});
                cnt_area++;
                vis[child_i][child_j]=true;
            }
        }
    }
    
}

int main()
{
 fast();
    memset(vis,false,sizeof(vis));
    int ans = INT_MAX;
    cin>>n>>m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>grid[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(!vis[i][j] && grid[i][j]=='.'){
                bfs(i,j);
                if(cnt_area < ans){
                    ans=cnt_area;
                }
                cnt_area=0;
            }
        }
    }
    if(ans==INT_MAX)cout<<-1<<nl;
    else cout<<ans<<nl;
    
    return 0;
}