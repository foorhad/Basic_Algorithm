#include <bits/stdc++.h>
#define ll long long int
#define fast() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
bool vis[10][10];
int dis[10][10];
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
        n = 8, m = 8;

        string s,d;
        cin>>s>>d;
        int si, sj, di, dj;
        si = s[0]-'a';
        sj = s[1]-'1';
        di = d[0]-'a';
        dj = d[1]-'1';
        memset(dis,-1,sizeof(dis));
        memset(vis,false,sizeof(vis));
        bfs(si,sj);
        cout<<dis[di][dj]<<endl;
    }
    
    return 0;
}