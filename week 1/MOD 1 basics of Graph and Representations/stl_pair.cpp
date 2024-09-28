#include <bits/stdc++.h>
using namespace std;
int main()
{
    //1st way
    pair<int,int>p(12,20);
    cout<<p.first<<" "<<p.second<<endl;

    //2nd way
    pair<string,int>p1;
    p1 = make_pair("Algorithm",20);
    cout<<p1.first<<" "<<p1.second<<endl;
    //3rd way
    pair<string,int>p2;
    p2={"Algo",20};
    cout<<p2.first<<" "<<p2.second<<endl;
    

    return 0;
}