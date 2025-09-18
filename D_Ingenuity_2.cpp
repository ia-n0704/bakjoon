# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
void sol()
{
    int m;
    string t;
    cin>>m>>t;
    if(m%2) 
    {
        cout<<"NO"<<'\n';
        return;
    }
    int n=0,s=0,e=0,w=0;
    for(int i=0;i<t.length();i++)
    {
        if(t[i]=='N') n++;
        if(t[i]=='S') s++;
        if(t[i]=='E') e++;
        if(t[i]=='W') w++;
    }  
    int ns_n=min(n,s),ns_s=min(n,s);
    int ew_e=min(e,w),ew_w=min(e,w);
    n-=ns_n;
    s-=ns_s;
    e-=ew_e;
    w-=ew_w;
    if(n%2 || s%2 || e%2 || w%2 || (ns_n+ew_e+n+s+e+w<2)) 
    {
        cout<<"NO\n";
        return;
    }
    else
    {
        int flagone=0,flagtwo=0;
        int tempn=0,temps=0,tempe=1,tempw=1;
        for(int i=0;i<t.length();i++)
        {
            if(t[i]=='N')
            {
                if(ns_n)
                {
                    ns_n--;
                    if(tempn)
                    {
                        tempn=0;
                        cout<<"R";
                    }
                    else 
                    {
                        tempn=1;
                        cout<<"H";
                    }
                }
                else
                {
                    if(flagone)
                    {
                        flagone=0;
                        cout<<"R";
                    }
                    else 
                    {
                        flagone=1;
                        cout<<"H";
                    }
                }
            }
            else if(t[i]=='S')
            {
                if(ns_s)
                {
                    ns_s--;
                    if(temps)
                    {
                        temps=0;
                        cout<<"R";
                    }
                    else 
                    {
                        temps=1;
                        cout<<"H";
                    }
                }
                else
                {
                    if(flagone)
                    {
                        flagone=0;
                        cout<<"R";
                    }
                    else 
                    {
                        flagone=1;
                        cout<<"H";
                    }
                }
            }
            else if(t[i]=='E')
            {
                if(ew_e)
                {
                    ew_e--;
                    if(tempe)
                    {
                        tempe=0;
                        cout<<"R";
                    }
                    else 
                    {
                        tempe=1;
                        cout<<"H";
                    }
                }
                else
                {
                    if(flagtwo)
                    {
                        flagtwo=0;
                        cout<<"R";
                    }
                    else 
                    {
                        flagtwo=1;
                        cout<<"H";
                    }
                }
            }
            else if(t[i]=='W')
            {
                if(ew_w)
                {
                    ew_w--;
                    if(tempw)
                    {
                        tempw=0;
                        cout<<"R";
                    }
                    else 
                    {
                        tempw=1;
                        cout<<"H";
                    }
                }
                else
                {
                    if(flagtwo)
                    {
                        flagtwo=0;
                        cout<<"R";
                    }
                    else 
                    {
                        flagtwo=1;
                        cout<<"H";
                    }
                }
            }
        }
    }
    cout<<'\n';
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