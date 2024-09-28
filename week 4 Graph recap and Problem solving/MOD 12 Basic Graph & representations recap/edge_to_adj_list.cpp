#include <bits/stdc++.h>
#define ll long long int
#define nl '\n'
#define fast() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
const long long int INF = 1e18+5;
using namespace std;
int main()
{
 fast();
    int n,e;cin>>n>>e;
    vector<pair<int,int> >vec[n];
    while (e--)
    {
        int u,v,w;cin>>u>>v>>w;
        vec[u].push_back(make_pair(v,w));
        // vec[v].push_back(make_pair(u,w));
    }

    for(int i=0;i<n;i++){
        cout<<i<<" -> ";
        for(pair<int,int> g : vec[i]){
            cout<<"{"<<g.first<<", "<<g.second<<"} ";
        }
        cout<<endl;
    }
    
    return 0;
}