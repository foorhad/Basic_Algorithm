#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,e;cin>>n>>e;
    vector<int>ar[n];
    while(e--){
        int a,b;cin>>a>>b;
        ar[a].push_back(b);
    }
    for(int x : ar[0])cout<<x<<" ";
    return 0;
}