#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,e;cin>>n>>e;
    int matrix[n][n];
    memset(matrix,0,sizeof(matrix));
    while (e--)
    {
        int a,b,c;cin>>a>>b>>c;
        matrix[a][b]=c;
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