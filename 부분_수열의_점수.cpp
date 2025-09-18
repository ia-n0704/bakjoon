#include <bits/stdc++.h>
#define N 200020
#define inf 1e16
using namespace std;
typedef long long ll;
struct line
{
    ll a,b;
    double x;
    ll f(ll x) {return a*x+b;}
};
vector <line> L;
ll A[N],B[N],S[N];
int n;
double cross(line p,line q)
{
    return (double)(q.b-p.b)/(p.a-q.a);
}
void _insert(ll a,ll b)
{
    if(L.size()==0)
    {
        L.push_back({a,b,-inf});
        return;
    }
    line k={a,b};
    while(L.size())
    {
        line top=L.back();
        if(top.x>cross(top,k))
            L.pop_back();
        else break;
    }
    k.x=cross(L.back(),k);
    //cout<<a<<" "<<b<<" "<<L.size()<<" "<<k.x<<'\n';
    L.push_back(k);
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>S[i];
        S[i]*=-1;
        A[i]=A[i-1]+S[i];
        B[i]=B[i-1]+A[i];
    }
    ll res=min((ll)0,S[1]);
    _insert(-1,0);
    for(int i=2;i<=n;i++)
    {
        ll temp=S[i];
        int l=0,r=L.size()-1;
        while(l<r)
        {
            int mid=(l+r)/2;
            if(A[i]<=L[mid+1].x) 
                r=mid;
            else l=mid+1;
        }
        temp=min(temp,L[r].f(A[i])+A[i]*(i+1)-B[i-1]);
        res=min(res,temp);
        //printf("%d | %d %lld %lld %lld %lld\n",i,l,L[l].a,L[l].b,temp,res);
        _insert(-i,B[i-2]);
    }
    cout<<-res;
}