# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
vector<int> v1,v2;
int ah,am,bh,bm;
int pah,pam,pbh,pbm;
set<int> s1,s2;
#define mod 1440
string s[10]={"Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday"};
int main()
{
    fastio;
    scanf("%d:%d",&ah,&am);
    scanf("%d:%d",&bh,&bm);
    scanf("%d:%d",&pah,&pam);
    scanf("%d:%d",&pbh,&pbm);
    int anum=ah*60+am;
    int bnum=bh*60+bm;
    int ap=pah*60+pam;
    int bp=pbh*60+pbm;
    int temp=anum+ap;
    while(1)
    {
        if(s1.count(temp%mod))
            break;
        else
        {
            v1.push_back(temp);
            s1.insert(temp%mod);
        }
        temp+=ap;
    }
    temp=bnum+bp;
    while(1)
    {
        if(s2.count(temp%mod))
            break;
        else
        {
            v2.push_back(temp);
            s2.insert(temp%mod);
        }
        temp+=bp;
    }
    int res=1000000000;
    for(auto i:v1)
    {
        for(auto j:v2)
        {
            //cout<<j<<'\n';
            if(i==j)
            {
                res=min(j,res);
            }
        }
    }
    if(res==100000000)
        cout<<"Never";
    else
    {
        int y=res/60;
        y%=7;
        cout<<s[y]<<'\n';
        if(((res/60)%24)/10==0) cout<<0;
        cout<<(res/60)%24<<":";
        if((res%60)/10==0) cout<<0;
        cout<<res%60;
    }
}   