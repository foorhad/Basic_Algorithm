#include <bits/stdc++.h>
#define fast() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
vector<int>ar[1005];
bool vis[1005];
int parent[1005];
void path_printing(int src){
    queue<int> q;
    q.push(src);
    vis[src]=true;

    while(!q.empty()){
        int par = q.front();
        q.pop();

        for(int child : ar[par]){
            if(vis[child]==false){
                q.push(child);
                vis[child]=true;
                parent[child]=par;
            }
        }
    }
}
int main()
{
 fast();
    int n,e;cin>>n>>e;
    while (e--)
    {
        int a,b;cin>>a>>b;
        ar[a].push_back(b);
        ar[b].push_back(a);
    }
    int q;cin>>q;
    while(q--){
        int src,des;cin>>src>>des;
        memset(parent,-1,sizeof(parent));
        memset(vis,false,sizeof(vis));
        path_printing(src);
        
        if(parent[des]==-1)cout<<-1<<endl;
        else{
            int x = des;
            int count = -1;
            while (x!=-1)
            {
                count++;
                x = parent[x];
            }
            cout<<count<<endl;
        }
    }
   
    return 0;
}