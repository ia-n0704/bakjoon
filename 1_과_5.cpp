# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define all(x) (x).begin,(x).end()
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
int t;
string n;
int main()
{
    fastio;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int five=0,one=0,f_idx=0,o_idx=0;
        for(int i=0;i<n.length();i++)
        {
            if(n[i]=='5')
            {
                five++;
                f_idx=i+1;
            }
            else
            {
                one++;
                o_idx=i+1;
            }
        }
        if(one==0)
            cout<<"0 5"<<'\n';
        else if(five==0)
        {
            if(one%3==0)
                cout<<"0 3\n";
            else if(one%3==1)
                cout<<"1 3\n";
            else
            {
                if((one/3)%2==0)
                    cout<<"0 11\n";
                else cout<<"1 11\n";
            }
        }
        else if(one==five)
            cout<<"0 3\n";
        else if(one<five)
        {
            five-=one;
            if(five%3==0)
                cout<<"0 3\n";
            else if(five%3==1)
                cout<<f_idx<<" 3\n";
            else cout<<o_idx<<" 3\n";
        }
        else
        {
            one-=five;
            if(one%3==0)
                cout<<"0 3\n";
            else if(one%3==1)
                cout<<o_idx<<" 3\n";
            else cout<<f_idx<<" 3\n";
        }
    }
}
