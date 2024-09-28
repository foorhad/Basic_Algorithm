#include <bits/stdc++.h>
#define ll long long int
#define nl '\n'
#define fast() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
const long long int INF = 1e18+5;
using namespace std;
// void convert(int n, int m, int matrix[][]){

// }
int main()
{
 fast();
     int n;cin>>n;
    int matrix[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>matrix[i][j];
        }
    }

    vector<pair<int,int> >v[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(matrix[i][j]>0 && i!=j){
                v[i].push_back(make_pair(j,matrix[i][j]));
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<i<<" -> ";
        for(pair<int,int> g : v[i]){
            cout<<"{"<<g.first<<", "<<g.second<<"} ";
        }
        cout<<endl;
    }


    return 0;
}