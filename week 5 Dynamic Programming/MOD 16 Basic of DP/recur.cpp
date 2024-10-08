#include <bits/stdc++.h>
#define ll long long int
#define pi pair<ll, ll>
#define nl '\n'
#define fast() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
const long long int INF = 1e18+5;
const int N = 1e6 + 5;
using namespace std;

int n;
int sum = 0;
void recur(int i){
    if(i==n)return;
    sum += i;
    recur(i+1);
}
int main()
{
 fast();
    cin>>n;
    recur(1);
    cout<<sum<<nl;
    return 0;
}