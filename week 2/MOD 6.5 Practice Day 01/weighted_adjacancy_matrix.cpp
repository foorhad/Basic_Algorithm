#include <bits/stdc++.h>
#define fast() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
int main()
{
 fast();
    int n,e;cin>>n>>e;
    int matrix[n][n];
    memset(matrix,-1,sizeof(matrix));

// input
    while (e--)
    {
        int a,b,c;cin>>a>>b>>c;
        matrix[a][b]=c;
        matrix[b][a]=c;
    }


    //output
    for(int i=0; i<n; i++){
        for (int j = 0; j < n; j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    
    
    return 0;
}