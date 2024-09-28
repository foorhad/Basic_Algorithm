#include <bits/stdc++.h>
#define ll long long int
#define fast() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

bool vis[105][105];
int dis[105][105];

vector<pair<int,int>> v={{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};
int n,m;
bool valid(int i, int j){
        if(i>=0 && i<n && j>=0 && j<m) return true;
        return false;
    }
void bfs(int si, int sj){
    queue<pair<int,int>>q;
    q.push({si,sj});
    vis[si][sj]=true;
    dis[si][sj]=0;
    while (!q.empty())
    {
        pair<int,int> p = q.front();q.pop();
        int i = p.first;
        int j = p.second;

        for(auto child : v){
            int childNodei = child.first+i;
            int childNodej = child.second+j;
            if(valid(childNodei,childNodej) && !vis[childNodei][childNodej]){
                q.push({childNodei,childNodej});
                vis[childNodei][childNodej]=true;
                dis[childNodei][childNodej]=dis[i][j]+1;
            } 
        }
    }
}
int main()
{
 fast();
    int tc;cin>>tc;
    while (tc--)
    {
        cin>>n>>m;
        int ki,qi,kj,qj;
        cin>>ki>>qi>>kj>>qj;

        memset(vis,false,sizeof(vis));
        memset(dis,-1,sizeof(dis));

        bfs(ki,qi);
        cout<<dis[kj][qj]<<endl;
    }
    
    return 0;
}