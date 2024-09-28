#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi pair<int, int>
#define nl '\n'
#define fast() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
const long long int INF = 1e18+5;
const int N = 1e6 + 5;
int n;
char grid[50][50];
bool vis[50][50];
int dis[50][50];
vector<pi >d;
bool valid(int i,int j){
    if(i>=0 && i<n && j>=0 && j<n)return true;
    else return false;
}

void bfs(int si, int sj){
    vis[si][sj]=true;
    dis[si][sj]=0;

    queue<pi >q;
    q.push({si,sj});

    while (!q.empty())
    {
        pair<int,int> parent = q.front();q.pop();
        int parent_i = parent.first;
        int parent_j = parent.second;

        for(int i=0;i<4;i++){
            int child_i = parent_i+d[i].first;
            int child_j = parent_j+d[i].second;

            if(valid(child_i,child_j) && !vis[child_i][child_j] && grid[child_i][child_j]!='T'){
                q.push({child_i,child_j});
                vis[child_i][child_j]=true;
                dis[child_i][child_j] = dis[parent_i][parent_j]+1;
            }
        }
    }
    
}
int main()
{
    
    d.push_back({0,1});
    d.push_back({0,-1});
    d.push_back({-1,0});
    d.push_back({1,0});

    int si,sj,di,dj;

    while(cin>>n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin>>grid[i][j];
                if(grid[i][j]=='S'){
                    si=i,sj=j;
                }
                if(grid[i][j]=='E'){
                    di = i,dj=j;
                }
            }  
        }
    
    }
    memset(dis,-1, sizeof(dis));
    memset(vis,false, sizeof(vis));
    bfs(si,sj);
    cout<<dis[di][dj]<<nl;


    return 0;
}