# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int n,f;
string s;
int ch[20010];
vector<string> v;
int main()
{
    fastio;
    cin>>n>>f;
    cin>>s;
    for(int i='a';i<='z';i++)
    {
        for(int j='a';j<='z';j++)
        {
            int cnt=0;
            if(i==j) continue;
            fill(ch,ch+n+1,0);
            for(int k=0;k<n-2;k++)
            {
                if(s[k]==char(i) && s[k+1]==char(j) && s[k+2]==char(j))
                {
                    ch[k]=ch[k+1]=ch[k+2]=1;
                    cnt++;
                }
            }
            int flag=0;
            for(int k=0;k<n-2;k++)
            {
                int temp=0,idx;
                if(s[k]==char(i)) temp++;
                if(s[k+1]==char(j)) temp++;
                if(s[k+2]==char(j)) temp++;
                if(temp==2)
                {
                    if(s[k]!=char(i)) idx=k;
                    else if(s[k+1]!=char(j)) idx=k+1;
                    else idx=k+2;
                    if(ch[idx]==0)
                    {
                        flag=1;
                        break;
                    }
                }
            }
            if(cnt+flag>=f)
            {
                string res;
                res+=char(i);
                res+=char(j);
                res+=char(j);
                v.push_back(res);
                //cout<<res<<" "<<flag<<'\n';
            }
        }
    }    
    cout<<v.size()<<'\n';
    for(auto i:v) cout<<i<<'\n';
}