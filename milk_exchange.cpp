#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
string s;
ll arr[200010];
int ch[200010];
ll res;
ll sum;
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m;
    cin>>s;
    for(int i=0;i<n;i++) 
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    //for(int i=0;i<n;i++) cout<<brr[i]<<" ";
    for(int i=0;i<n;i++)
    {
        if(ch[i]) continue;
        if(s[i]=='L')
        {
            ch[i]=1;
            ll num=0;
            int idx=i-1;
            while(1)
            {
                
                idx--;
                if(idx==n) idx=0;
                else if(idx==-1) idx=n-1;
                if(s[idx]=='R')
                    num+=arr[idx];
                else break;                
                if(ch[idx]){
                    num=0;
                    break;
                }
                ch[idx]=1;
            }
            //cout<<num<<" ";
            res+=min(m,num);
            num=0;
            idx=i;
            while(1)
            {
                
                idx++;
                if(idx==n) idx=0;
                else if(idx==-1) idx=n-1;
                if(s[idx]=='L')
                    num+=arr[i];
                else break;                
                if(ch[idx])
                {
                    num=0;
                    break;
                }
                ch[idx]=1;
            }
            //cout<<num<<'\n';
            res+=min(m,num);
        }
    }
    cout<<sum-res;
}