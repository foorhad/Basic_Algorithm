#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,e;cin>>n>>e;
    vector<int>ar[n];
    while (e--)
    {
        int a,b;cin>>a>>b;
        ar[a].push_back(b);
        ar[b].push_back(a);
    }
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<ar[i].size();j++){
    //         cout<<ar[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // for(int i=0; i<ar[0].size(); i++){
    //     cout<<ar[0][i]<<" ";
    // }
    
    
    return 0;
}