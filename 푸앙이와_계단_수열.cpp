#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int n,k;
int arr[100010];
int ch[100010],ch2[100010];
int dfs(int x)
{
    if(x+1>n || abs(arr[x+1]-arr[x])!=1) return ch[x]=x;
    return ch[x]=dfs(x+1);
}
int main()
{
    fastio;
    cin>>n>>k;
    if(k<=3)
    {
        cout<<n/3+(bool)(n%3);
        return 0;
    }
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=1;i<=n;i++)
        if(ch[i]==0) dfs(i);
    vector<int> v;
    for(int i=1;i<=n;i++)
    {
        if(ch[i]-i+1>=k)
            ch2[i]=1;
    }
    int l=1;
    int res=0;
    while(l<=n)
    {
        if(ch2[l])
        {
            l+=k;
            res++;
            continue;
        }
        while(l<=n)
        {
            int flag=0;
            for(int i=3;i>=1;i--)
            {
                if(ch2[l+i])
                {
                    l+=i;
                    res++;
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                l+=3;
                res++;
            }
            else break;     
        }
    }
    cout<<res;
}