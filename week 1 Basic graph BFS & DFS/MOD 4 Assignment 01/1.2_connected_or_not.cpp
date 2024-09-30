#include <bits/stdc++.h>
using namespace std;
vector<int>adj_list[1005]; //adjacency list
int main()
{
    int n,e;cin>>n>>e;
    while (e--)
    {
        int a,b;cin>>a>>b;
        adj_list[a].push_back(b);
    }
    int q;cin>>q;
    while (q--)
    {
       int u,v;cin>>u>>v;
       bool flag = false;
       if(u==v)flag=true;
       else{
            for(int val : adj_list[u]){
                if(v==val){
                    flag=true;;
                    break;
                }
            }
       }
       
       if(flag){
        cout<<"YES"<<endl;
        flag = false;
       }
       else cout<<"NO"<<endl;
    }
    
    
    return 0;
}
