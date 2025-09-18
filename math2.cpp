#include <bits/stdc++.h>
using namespace std;
int num[15];
typedef long long ll;
int main()
{
    ll res=0;
    for(ll i=10000;i<=99999;i++)
    {
        ll temp=i;
        while(temp)
        {
            num[temp%10]++;
            temp/=10;
        }
        //cout<<i<<'\n';
        //for(int j=0;j<=9;j++) cout<<num[j]<<" ";
        //cout<<'\n';
        int cnt=0;
        for(int j=1;j<=9;j++)
            if(num[j]) cnt++;
        if(num[0]==0 && cnt==2)
        {
            //cout<<i<<'\n';
            res+=i;
        }
        fill(num,num+14,0);
    }
    cout<<res;
}