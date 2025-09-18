#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    cout<<1<<" ";
    srand(time(NULL));
    for(int i=2;i<=n;i++)
    {
        int flag=rand()%300;
        int num=rand()%1000+1;
        if(flag==0) num=1;
        cout<<num<<" ";
    }
}