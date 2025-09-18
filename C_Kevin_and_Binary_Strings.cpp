# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
void sol()
{
    cin>>s;
    int n=(int)s.length();
    cout<<1<<" "<<n<<" ";
    int cnt=0;
    int idx=n;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='0')
        {
            idx=i;
            break;
        }
        cnt++;
    }
    if(idx==n) 
    {
        cout<<"1 1"<<'\n';
        return;
    }
    int cnt2=0;
    for(int i=idx+1;i<n;i++)
    {
        if(s[i]=='1')
        {
            int temp=max(0,idx-cnt2-1);
            cout<<temp+1<<" "<<temp+n-idx<<'\n';
            return;
        }
        cnt2++;
    }
    cout<<"1 "<<n-idx<<'\n';
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