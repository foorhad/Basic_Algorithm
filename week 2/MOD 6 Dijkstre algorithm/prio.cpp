#include <bits/stdc++.h>
#define fast() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
// class cmp
// {
// public:
//     bool operator()(pair<int, int> x, pair<int, int> y)
//     {
//         return x.second > y.second;
//     }
// };
int main()
{
    fast();
    // priority_queue< pair<int,int>,vector<pair<int,int>> >pq;
    priority_queue<int,vector<int>,greater<int>>pq;
    // pq.push({2,3});
    // pq.push({1,30});
    // pq.push({6,6});

    pq.push(5);
    pq.push(9);
    pq.push(40);
    pq.push(-4);
    pq.push(1);

    // while (!pq.empty())
    // {
    //     cout<<pq.top().first<<" "<<pq.top().second<<endl;
    //     pq.pop();
    // }

    while (!pq.empty())
    {
       cout<<pq.top()<<endl;
       pq.pop();
    }
    


    return 0;
}