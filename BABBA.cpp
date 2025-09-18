#include <bits/stdc++.h>
using namespace std;
int dpA[100],dpB[100];
int main()
{
    int n;
    dpB[1]=1;
    for(int i=2;i<=50;i++)
    {
        dpA[i]=dpB[i-1];
        dpB[i]=dpA[i-1]+dpB[i-1];
    }
    cin>>n;
    cout<<dpA[n]<<" "<<dpB[n];
}