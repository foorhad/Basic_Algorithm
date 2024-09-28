#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,e;
    cin>>n>>e;
    int matrix[n][n];
    memset(matrix,0,sizeof(matrix));
    while (e--){
        int a,b;cin>>a>>b;
        matrix[a][b]=1;
        matrix[b][a]=1; //undirected graph
    }
    // for (int i = 0; i < n; i++){
    //    for (int j = 0; j < n; j++){
    //     cout<<matrix[i][j]<<" ";
    //    }
    //    cout<<endl;
    // }

    //connection check
    if(matrix[3][4]==1)cout<<"connected";
    else cout<<"Not connected";
    
    return 0;
}