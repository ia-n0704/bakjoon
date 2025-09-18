# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int n;
int arr[1010];
int ch[1010];
vector<int> v;
int main()
{
    fastio;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    sort(arr+1,arr+n+1);
    int st=1;
    int temp=-100;
    for(int i=1;i<=n;i++)
    {
        while(ch[st]) st++;
        int flag=0;
        if(temp+1==arr[st])
        {
            for(int j=st+1;j<=n;j++)
            {
                if(ch[j]==0 && temp+2<=arr[j])
                {
                    cout<<arr[j]<<" ";
                    ch[j]=1;
                    temp=arr[j];
                    break;
                }
            }
            continue;
        }
        for(int j=st+1;j<=n;j++)
        {
            if(ch[j]==0 && arr[st]+2<=arr[j])
            {
                cout<<arr[st]<<" ";
                ch[st]=1;
                temp=arr[st];
                st++;
                flag=1;
                break;
            }
        }
        if(!flag)
        {
            int flag2=0;
            for(int j=st+1;j<=n;j++)
            {
                if(ch[j]==0 && arr[st]<arr[j])
                {
                    cout<<arr[j]<<" ";
                    ch[j]=1;
                    temp=arr[j];
                    flag2=1;
                    break;
                }
            }
            if(flag2==0)
            {
                cout<<arr[st]<<" ";
                ch[st]=1;
                st++;
                temp=arr[st];                
            }
        }
    }
}