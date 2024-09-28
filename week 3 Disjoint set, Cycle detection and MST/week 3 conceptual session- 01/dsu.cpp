#include <bits/stdc++.h>
#define ll long long int
#define nl '\n'
#define fast() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
const long long int INF = 1e18 + 5;
using namespace std;
const int N = 1e5 + 5;
int par[N];
int level[N];
void initialize(int n)
{
    for (int i = 1; i < n; i++)
        par[i] = -1, level[i] = 0;
}
int find(int n)
{
    cout << "calling node " << n << endl;
    if (par[n] == -1)
        return n;
    else
    {
        int leader = find(par[n]);
        par[n] = leader;
        return leader;
    }
}
void Union(int n1, int n2)
{
    int leaderA = find(n1);
    int leaderB = find(n2);
    par[leaderB] = leaderA;
}
void Union_by_rank(int n1, int n2)
{
    int leaderA = find(n1);
    int leaderB = find(n2);
    if(level[leaderA] > level[leaderB]){
        par[leaderB] = leaderA;
    }
    else if(level[leaderB] > level[leaderA]){
        par[leaderA] = leaderB;
    }
    else{
        par[leaderB] = leaderA;
        level[leaderA]++;
    }
    
}
int main()
{
    fast();
    initialize(8);
    Union_by_rank(6, 7);
    Union_by_rank(5, 6);
    Union_by_rank(4, 5);
    Union_by_rank(3, 4);
    Union_by_rank(2, 3);
    Union_by_rank(1, 2);
    // Union(6, 7);
    // Union(5, 6);
    // Union(4, 5);
    // Union(3, 4);
    // Union(2, 3);
    // Union(1, 2);

    cout << "*************************" << nl;
    cout << find(7) << nl;
    cout << "#####################" << nl;
    cout << find(6) << nl;
    cout << "#####################" << nl;
    cout << find(5) << nl;
    cout << "#####################" << nl;
    cout << find(4) << nl;
    cout << "#####################" << nl;
    cout << find(3) << nl;
    cout << "#####################" << nl;
    cout << find(2) << nl;
    cout << "#####################" << nl;
    cout << find(1) << nl;
  

    return 0;
}