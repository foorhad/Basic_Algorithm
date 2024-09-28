#include <bits/stdc++.h>
#define fast() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
int main()
{
 fast();
    vector<int> ar[2];
    ar[0].push_back(1);
    ar[0].push_back(2);
    ar[0].push_back(6);
    ar[1].push_back(3);
    ar[1].push_back(4);
    ar[1].push_back(5);

    // cout<<ar[0].size();
    for (int i = 0; i < 2; i++)
    {
        for(int j : ar[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return 0;
}