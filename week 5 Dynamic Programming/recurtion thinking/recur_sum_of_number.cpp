#include <bits/stdc++.h>
#define ll long long int
#define pi pair<ll, ll>
#define nl '\n'
#define fast() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
const long long int INF = 1e18+5;
const int N = 1e6 + 5;
using namespace std;

int sum_of_number(int n){
    if(n==0)return 0;
    int last_digit = n%10;
    int remaining = n/10;
    cout<<remaining<<" "<<last_digit<<nl;
    return sum_of_number(remaining)+last_digit;
}

int main()
{
 fast();
    int number;cin>>number;
    cout<<sum_of_number(number);
    return 0;
}