#include <bits/stdc++.h>
#define ll long long int
#define pi pair<ll, ll>
#define nl '\n'
#define fast() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
const long long int INF = 1e18+5;
const int N = 1e5 + 5;
using namespace std;


int main()
{
 fast();

    int tc;cin>>tc;
    while(tc--){
        int n;cin>>n;
        int h[N];
        vector<int>v;
        for(ll i=0;i<n;i++){
            cin>>h[i];
            v.push_back(h[i]);
        }

        sort(v.begin(),v.end(),greater<>());

        int a=v[0];
        int b=v[1];

        vector<int>v1;
        for(int i=0;i<n;i++){
            if(h[i]==a)v1.push_back(i);
            if(h[i]==b)v1.push_back(i);
        }   
    
        sort(v.begin(),v.end());
        cout<<v1[0]<<" "<<v1[1]<<nl;
        
    }

    return 0;
}