# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
int n;
int arr[200010];
int brr[200010];
vector<int> v[100010];
int ch[100010],ch2[100010];
int num[100010];
void sol()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(ch[i]==0)
        {
            cnt++;
            int cur=i;
            while(ch[cur]==0)
            {
                ch[cur]=1;
                num[cur]=cnt;
                v[cnt].push_back(cur);
                cur=arr[cur];
            }
        }
    }    
    int res=0;
    for(int i=1;i<=n;i++)
    {
        cin>>brr[i];
        if(ch2[num[brr[i]]]==0)
        {
            ch2[num[brr[i]]]=1;
            res+=v[num[brr[i]]].size();
        }
        cout<<res<<' ';
    }
    cout<<'\n';
    for(int i=1;i<=n;i++)
    {
        ch[i]=ch2[i]=num[i]=0;
        v[i].clear();
    }
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        sol();
    }
}