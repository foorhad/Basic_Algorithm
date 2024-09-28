#include <bits/stdc++.h>
#define fast() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
int main()
{
 fast();
    vector<vector<int>>v;
    v.push_back(vector<int>({1,2,3,4}));
    v.push_back(vector<int>({5,6,7}));
    v.push_back(vector<int>({8,9,10}));
    v[0].push_back(5);
    
    // cout<<v.size()<<endl;
    // cout<<v[0].size()<<endl;

    // for (int i = 0; i < v.size(); i++)
    // {
    //     for (int j = 0; j < v[i].size(); j++)
    //     {
    //        cout<<v[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<v.size();


    

    return 0;
}