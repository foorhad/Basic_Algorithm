#include <bits/stdc++.h>
#define fast() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
int r,c;
char mat[1005][1005];
bool vis[1005][1005]={false};
vector<pair<int, int>> xy = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; // movement
bool valid(int i, int j){
    if(i>=0 && i<r && j>=0 && j<c)return true;
    return false;
}
int cnt=0;
void bfs(int si, int sj){
    if(mat[si][sj]=='.'){
        cnt++;
        queue<pair<int,int>>q;
        q.push({si,sj});
        vis[si][sj]=true;

        while (!q.empty()){
            pair<int,int>n=q.front();q.pop();
            int rn = n.first;
            int cn= n.second;

            for(auto p : xy){
                int i = rn+p.first;
                int j = cn+p.second;
                if(valid(i,j) && !vis[i][j] && mat[i][j]=='.'){
                    q.push({i,j});
                    vis[i][j]=true;
                }
            }
        }
    }
}
int main()
{
 fast();
    cin>>r>>c;
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cin>>mat[i][j];
        }
    }
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            if(!vis[i][j]){
                bfs(i,j);
            }
        }
    }
   cout<<cnt<<endl;
    return 0;
}
