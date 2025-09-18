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
vector<int> v[100010];
int arr[100010];
vector<int> ans1,ans2;
int main()
{
    fastio;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        for(int j=1;j<=a;j++)
        {
            int b;
            cin>>b;
            v[i].push_back(b);
        }
    }
    fill(arr+1,arr+n+1,1);
    while(1)
    {
        int flag=0;
        for(int i=1;i<=n;i++)
        {
            int cnt=0;
            for(auto j:v[i])
            {
                if(arr[i]==arr[j]) cnt++;
            }
            if(cnt>=2)
            {
                arr[i]^=3;
                flag=1;
            }
        }
        if(flag==0) break;
    }
    for(int i=1;i<=n;i++){
        if(arr[i]==1)
            ans1.push_back(i);
        else ans2.push_back(i);
    }
    if(ans1.size()==0 || ans2.size()==0)
    {
        cout<<"1 1\n"<<n-1<<" ";
        for(int i=2;i<=n;i++) cout<<i<<" ";
        return 0;
    }
    cout<<ans1.size()<<" ";
    for(auto i:ans1)
        cout<<i<<" ";
    cout<<'\n';
    cout<<ans2.size()<<" ";
    for(auto i:ans2)
        cout<<i<<" ";
    cout<<'\n';
}