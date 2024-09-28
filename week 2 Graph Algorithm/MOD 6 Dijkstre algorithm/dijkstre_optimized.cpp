#include <bits/stdc++.h>
#define fast() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

// class cmp{
//     public:
//         bool operator()(pair<int,int>x, pair<int,int>y){
//             return x.second > y.second;
//         }
// };

vector<pair<int,int>>adj_list[1005]; //adjacancy_list
int dis[100];
void dijkstre(int src){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,src});
    dis[src] = 0;

    while (!pq.empty()){
        pair<int,int> p = pq.top(); pq.pop();
        int parentNode = p.second;
        int parentCost = p.first;

        for(auto p : adj_list[parentNode]){
            int childNode = p.first;
            int childCost = p.second;

            if(parentCost+childCost < dis[childNode]){
                dis[childNode] =  parentCost+childCost;
                pq.push({dis[childNode],childNode});
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
        int a,b,c;cin>>a>>b>>c;
        adj_list[a].push_back({b,c});
        adj_list[b].push_back({a,c});
    }
    for(int i=0; i<n; i++)dis[i]=INT_MAX;
    dijkstre(0);
    for(int i=0; i<n; i++)cout<<dis[i]<<" ";
    
    return 0;
}