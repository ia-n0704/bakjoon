# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int n,m;
int arr[1000010];
int ch[1000010];
int main()
{
    fastio;
    cin>>n>>m;
    for(int i=0;i<n;i++) 
    {
        cin>>arr[i];
        ch[arr[i]]=1;
    }
    int a=0;
    int b=0;
    int i;
    int temp=0;
    int temp2=0;
    for(i=0;i<=arr[n-1];i++)
    {
        if(arr[temp]==i)
        {
            if(b<1)
                break;
            else
                b--;
            temp++;
        }
        else if(arr[temp2]-m<=i && a>0)
        {
            b++;
            a--;
            temp2++;
        }
        else
            a++;
        //cout<<i<<" : " <<a<<" "<<b<<'\n';
    }
    if(i!=arr[n-1]+1)
        cout<<"fail";
    else 
        cout<<"success";
}