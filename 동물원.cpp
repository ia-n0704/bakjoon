#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ch[50];
int main()
{
    int n;
    ll arr[50];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        ch[arr[i]]++;
    }
    ll flag=0;
    ll res=1;
    ll anum=-1,bnum=-1,acnt=0,bcnt=0;
    for(int i=0;i<=40;i++)
    {
        if(flag && ch[i])
        {
            cout<<0;
            return 0;
        }
        if(ch[i]==0) flag=1;
        else if(ch[i]==1)
        {
            if(anum==i-1 && bnum==i-1)
            {
                anum=i;
                res*=2;
            }
            else if(anum==i-1)
            {
                anum=i;
            }
            else if(bnum==i-1)
            {
                bnum=i;
            }
        }
        else if(ch[i]==2)
        {
            if(anum==i-1 && bnum==i-1)
            {
                bcnt++;
                anum=bnum=i;                
            }
            else 
            {
                cout<<0;
                return 0;
            }
        }
        else 
        {
            cout<<0;
            return 0;
        }
    }
    cout<<res*(ll)pow(2,bcnt);
}