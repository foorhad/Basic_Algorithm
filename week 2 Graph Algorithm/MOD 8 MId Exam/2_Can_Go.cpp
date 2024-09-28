#include <bits/stdc++.h>
#define ll long long int
#define fast() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
const long long int INF = 1e19 + 5;
using namespace std;
ll n, e;
vector<pair<ll, ll>> v[1000006];
ll dis[1000006];
void dijkstre(ll src)
{
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, src});
    dis[src] = 0;

    while (!pq.empty())
    {
        pair<ll, ll> p = pq.top();
        pq.pop();
        int parentNode = p.second;
        ll parentcost = p.first;

        for (auto child : v[parentNode])
        {
            int childNode = child.second;
            ll childcost = child.first;

            if (parentcost + childcost < dis[childNode])
            {
                dis[childNode] = parentcost + childcost;
                pq.push({dis[childNode], childNode});
            }
        }
    }
}
int main()
{
    fast();
    cin >> n >> e;
    while (e--)
    {
        ll a, b, w;
        cin >> a >> b >> w;
        v[a].push_back({w, b});
    }
    for (ll i= 0; i <= 1000006; i++)
        dis[i] = INF;

    ll src;
    cin >> src;
    dijkstre(src);

    ll tc;
    cin >> tc;
    while (tc--)
    {
        ll d, dw;
        cin >> d >> dw;
        if (dis[d] <= dw)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}