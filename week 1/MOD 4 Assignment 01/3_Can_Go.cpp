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
void dfs(int si, int sj){
    vis[si][sj]=true;
    for(auto p : xy){
        int rn = si+p.first;
        int cn = sj+p.second;

        if(valid(rn,cn) && !vis[rn][cn] && mat[rn][cn]!='#'){
            dfs(rn,cn);
        }
    }
}
int main()
{
 fast();
    cin>>r>>c;
    int si_A,sj_A;
    int di_B,dj_B;
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cin>>mat[i][j];
            if(mat[i][j]=='A')si_A=i, sj_A=j;
            if(mat[i][j]=='B')di_B=i, dj_B=j;
            
        } 
    }
    
   dfs(si_A,sj_A);
   if(vis[di_B][dj_B])cout<<"YES"<<endl;
   else cout<<"NO"<<endl;
    return 0;
}