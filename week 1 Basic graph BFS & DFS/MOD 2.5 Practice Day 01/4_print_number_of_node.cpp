#include <bits/stdc++.h>
#define fast() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
    fast();
    int N, e;
    cin >> N >> e;
    vector<int> ar[N];
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        ar[a].push_back(b);
        ar[b].push_back(a);
    }
    int n;cin>>n;
    cout<<ar[n].size()<<endl;
    return 0;
}