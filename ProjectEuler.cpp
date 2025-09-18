#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> v;
int ch[20];
void go(int x,ll num)
{
    if(x>9)
    {
        v.push_back(num);
        return;
    }
    for(int i=0;i<10;i++)
    {
        if(ch[i]==0)
        {
            ch[i]=1;
            go(x+1,num*10+i);
            ch[i]=0;
        }
    }
}
int main()
{
    for(int i=0;i<10;i++)
    {
        ch[i]=1;
        go(1,i);
        for(int j=0;j<10;j++) ch[i]=0;
    }
    sort(v.begin(),v.end());
    cout<<v[999999];
}