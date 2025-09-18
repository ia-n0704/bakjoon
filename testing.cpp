#include <bits/stdc++.h>
using namespace std;
int cnt[200010];
int num[200010];
int res[20010];
int s[200010];
int k;
void go(int x,int n)
{
    if(x>2*n)
    {
        for(int i=1;i<=2*n;i++)
            printf("%d ",res[i]);
        printf("\n");
        return;
    }
    for(int i=n;i>=1;i--)
    {
        s[x]=s[x-1]+i;
        if(cnt[i]==2) continue;
        if(cnt[i]==1)
        {
            if((i>k) && (s[x-1]-s[num[i]])%i!=k) continue;
            cnt[i]=2;
            res[x]=i;
            go(x+1,n);
            res[x]=0;
            cnt[i]=1;
        }
        else
        {
            cnt[i]=1;
            num[i]=x;
            res[x]=i;
            go(x+1,n);
            res[x]=0;
            cnt[i]=0;
            num[i]=0;
        }
    }
}
using namespace std;
int main()
{
    int n;
    cin>>n>>k;   
    go(1,n);
}