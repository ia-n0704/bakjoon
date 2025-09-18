# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[100010];
ll num[100010];
ll sum;
ll res;
int main()
{       
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    for(int i=0;i<n;i++) 
    {
        cin>>arr[i];
        if(i==0) num[i]=arr[i];
        else num[i]=num[i-1]+arr[i];
        sum+=arr[i];
    }
    if(n==2)
    {
        for(int i=0;i<n;i++)
        {
            if(arr[i]<0)
                res+=1;
        }
        cout<<res;
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        ll temp=num[n-1];
        if(i!=0) temp-=num[i-1];
        for(int j=0;j<i;j++)
        {
            temp+=arr[j];
            //cout<<res<<" "<<sum<<'\n';
            if(temp<0) 
            {
                res+=(-temp)/sum;
                if((-temp)%sum)
                    res++;
            }
        }
        temp=0;
        for(int j=i;j>=0;j--)
        {
            temp+=arr[j];
            //cout<<res<<" "<<sum<<'\n';
            if(temp<0) 
            {
                res+=(-temp)/sum;
                if((-temp)%sum)
                    res++;
            }
        }
    }
    cout<<res;
}
