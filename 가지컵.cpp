# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int T;
int n;
string s,t;
int main()
{
    fastio;
    cin>>T;
    while(T--)
    {
        cin>>n;
        cin>>s>>t;
        int temp=0;
        int a=0,b=0;
        char lose='A',win='A';
        int g=0,o=0,d=0;
        int w=0,l=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='G') g++;
            else if(s[i]=='O') o++;
            else if(s[i]=='D') d++;

            if(t[i]=='D')
                a=1;
            else
            {
                b=1;
                if(t[i]=='L') l++;
                else w++;
                if(s[i]=='?')
                    continue;
                if(t[i]=='L')
                {
                    if(lose=='A')
                        lose=s[i];
                }  
                else
                {
                    if(win=='A')
                        win=s[i];
                }
            }
        }
        if((a && b) || temp || (!w+!l==1))
        {
            cout<<"NO\n";
            continue;
        }
        if(a==1)
        {
            if(!g && !o && !d)
            {
                cout<<"YES\n";
                for(int i=0;i<n;i++)
                    cout<<"G";
                cout<<'\n';
                continue;
            }
            if(g && !o && !d)
            {
                cout<<"YES\n";
                for(int i=0;i<n;i++)
                    cout<<"G";
                cout<<'\n';
                continue;
            }
            if(!g && o && !d)
            {
                cout<<"YES\n";
                for(int i=0;i<n;i++)
                    cout<<"O";
                cout<<'\n';
                continue;
            }
            if(!g && !o && d)
            {
                cout<<"YES\n";
                for(int i=0;i<n;i++)
                    cout<<"D";
                cout<<'\n';
                continue;
            }
            if(!g+!o+!d>n-g-o-d)
            {
                cout<<"NO\n";
                continue;
            }
            cout<<"YES\n";
            for(int i=0;i<n;i++)
            {
                if(s[i]!='?')
                    cout<<s[i];
                else
                {
                    if(g==0)
                    {
                        g++;
                        cout<<"G";
                    }
                    else if(o==0)
                    {
                        o++;
                        cout<<"O";
                    }
                    else 
                    {
                        cout<<"D";
                        d++;
                    }
                }
            }
            cout<<'\n';
        }
        else
        {
            if(!g && !o && !d)
            {
                cout<<"YES\n";
                for(int i=0;i<n;i++)
                {
                    if(t[i]=='W')
                        cout<<"O";
                    else cout<<"D";
                }
                cout<<'\n';
                continue;
            }
            if(g && o && d)
            {
                cout<<"NO\n";
                continue;
            }
            if(win!='A' && lose!='A')
            {
                if((win=='G' && lose=='D') || (win=='O' && lose=='G') || (win=='D' && lose=='O'))
                {
                    cout<<"NO\n";
                    continue;
                }
            }
            cout<<"YES\n";
            for(int i=0;i<n;i++)
            {
                if(t[i]=='W')
                {
                    if(win=='A')
                    {
                        if(lose=='O')
                            cout<<"G";
                        else if(lose=='D')
                            cout<<"O";
                        else cout<<"D";
                    }
                    else
                        cout<<win;                    
                }
                else 
                {
                    if(lose=='A')
                    {
                        if(win=='D')
                            cout<<"G";
                        else if(win=='G')
                            cout<<"O";
                        else cout<<"D";
                    }
                    else
                        cout<<lose;
                }
            }
            cout<<'\n';
        }
    }
}