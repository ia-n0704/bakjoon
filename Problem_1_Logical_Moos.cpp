# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pair<int,int>> vpii;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int n,q;
string s[200010];
int arr[200010];
int num[200010];
vi f[200010];
vi t[200010];
vpii last[200010];
int main()
{
    fastio;
    cin>>n>>q;
    int temp=0,cnt=0,res=0;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        if(i==n)
        {
            if(s[i]=="false")
                temp=1;
            if(temp==0)
            {
                num[cnt]=1;
                res=1;
            }
            else num[cnt]=0;
        }
        else if(i%2)
        {
            if(s[i]=="false")
                temp=1;
        }
        else
        {
            if(s[i]=="or")
            {
                if(temp==0)
                {
                    num[cnt]=1;
                    res=1;
                }
                else num[cnt]=0;  
                temp=0;
                cnt++;
            }
        }
        if(i%2)
        {
            arr[i]=cnt;
            if(s[i]=="false")
                f[cnt].push_back(i);
            else t[cnt].push_back(i);
        }
    }
    int startl=-1,startr=-1,endl=-1,endr=-1;
    if(res==1)
    {
        for(int i=0;i<=cnt;i++)
        {
            if(num[cnt]==1 && startl==-1)
            {
                startl=t[cnt][0];
                startr=t[cnt].back();
            }
            else if(num[cnt]==1)
            {
                endl=t[cnt][0];
                endr=t[cnt].back();
            }
        }
        if(endl==-1)
        {
            endl=startl;
            endr=startr;
        }
    }
    while(q--)
    {
        int a,b;
        string t;
        cin>>a>>b>>t;
        int c=1;
        if(t=="false") c=0;
        if(c==res) cout<<"Y";
        else
        {
            if(c==1)
            {
                
            }
            else
            {
                if(a<=startr && b>=endl)
                    cout<<"Y";
                else cout<<"N";
            }
        }
    }
}