#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,e;cin>>n>>e;
    vector<pair<int,int>>v;
    while (e--)
    {
       int a,b;cin>>a>>b;
       v.push_back({a,b});
    }

    //1st way to print
    // for(int i=0; i<v.size(); i++){
    //     cout<<v[i].first<<" "<<v[i].second<<endl;
    // }

    //2nd way to print
    // for(pair<int,int> p : v){
    //     cout<<p.first<<" "<<p.second<<endl;
    // }

    //3rd way to print
    for(auto p : v){
        cout<<p.first<<" "<<p.second<<endl;
    }
    
    return 0;
}