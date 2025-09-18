# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int t;
int n;
string s;
int main()
{
    fastio;
    cin>>t;
    while(t--)
    {
        int num=0;
        cin>>n;
        cin>>s;
        for(int i=0;i<s.length();i++)
            if(s[i]=='0') num=1;
        string p,q;
        int flag=0;
        for(int i=0;i<n;i++)
        {
            if(flag==1 || s[i]=='1')
            {
                flag=1;
                p+=s[i];
            }
        }
        flag=0;
        int flag2=0;
        int temp1=0,temp2=0;
        int a=0,b=0;
        for(int i=0;i<p.length();i++)
        {
            if(flag && p[i]=='0')
                temp1=1;
            if(flag2 && p[i]=='1')
                temp2=1;
            if(temp1==0 && p[i]=='1')
            {
                a++;
                flag=1;
            }
            if(temp2==0 && p[i]=='0')
            {
                b++;
                flag2=1;
            }
        }
        if(a==0)
        {
            cout<<0<<'\n';
            continue;
        }
        if(b==0)
        {
            if(num) q+='0';
            else q+='1';
        }
        else if(a<=b)
            q=p.substr(0,p.length()-a);
        else
            q=p.substr(a-b,p.length()-a);
        for(int i=0;i<p.length();i++)
        {
            if(i>=p.length()-q.length())
            {
                if((p[i]=='1' && q[i-(p.length()-q.length())]=='0') || (p[i]=='0' && q[i-(p.length()-q.length())]=='1'))
                    cout<<1;
                else cout<<0;
            }
            else cout<<p[i];
        }
        cout<<'\n';
    }
}