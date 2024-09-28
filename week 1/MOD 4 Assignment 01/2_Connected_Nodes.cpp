#include <bits/stdc++.h>
#define fast() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

int main()
{
 fast();
    int n,e;
    cin>>n>>e;
    vector<int>ar[n];
    while (e--)
    {
        int a,b;cin>>a>>b;
        ar[a].push_back(b);
        ar[b].push_back(a);
    }
    
    int q;cin>>q;
    while (q--)
    {
        int x;cin>>x;
        vector<int>v;
        for(int child : ar[x])v.push_back(child);
        sort(v.begin(),v.end(),greater<int>());

        if(v.empty())cout<<"-1";
        else
            for(int val : v)cout<<val<<" ";
        v.clear();
        cout<<endl;
    }
    return 0;
}