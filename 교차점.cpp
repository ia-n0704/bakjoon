# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
struct line
{
    int x1,y1;
    int x2,y2;
};
int ccw(int x1,int y1,int x2,int y2,int x3,int y3)
{
    int ans=(x1*y2+x2*y3+x3*y1)-(x2*y1+x3*y2+x1*y3);
    if(ans>0) return 1;
    else if(ans==0) return 0;
    else return -1;
}
int compare(line a,line b)
{
    int A=ccw(a.x1,a.y1,a.x2,a.y2,b.x1,b.y1);
    int B=ccw(a.x1,a.y1,a.x2,a.y2,b.x2,b.y2);
    int C=ccw(b.x1,b.y1,b.x2,b.y2,a.x1,a.y1);
    int D=ccw(b.x1,b.y1,b.x2,b.y2,a.x2,a.y2);
    if(A==0 && B==0)
    {
        pair<int,int> p1={a.x1,a.y1};
        pair<int,int> p2={a.x2,a.y2};
        pair<int,int> p3={b.x1,b.y1};
        pair<int,int> p4={b.x2,b.y2};
        if(p1>p2) swap(p1,p2);
        if(p3>p4) swap(p3,p4);
        if(C==0 && D==0)
        {
            if(p2<p3 || p4<p1) return 0;
            if(p2==p3 || p4==p1) return 1;
        }
        return 4;
    }
    return A*B<=0 && C*D<=0;
}
int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--)
    {
        int res=0,flag=0;
        int stx,sty,enx,eny;
        line a;
        cin>>stx>>sty>>enx>>eny;
        cin>>a.x1>>a.y1>>a.x2>>a.y2;
        vector<line> v;
        v.push_back({stx,sty,stx,eny});
        v.push_back({stx,sty,enx,sty});
        v.push_back({stx,eny,enx,eny});
        v.push_back({enx,sty,enx,eny});
        for(auto i:v)
        {
            int num;
            num=compare(a,i);
            if(num==4)
            {
                //cout<<i.x1<<" "<<i.y1<<" "<<i.x2<<" "<<i.y2<<" | "<<a.x1<<" "<<a.y1<<" "<<a.x2<<" "<<a.y2<<'\n';
                flag=1;
            }
            else res+=num;
        }
        vector<pair<int,int>> v2;
        v2.push_back({stx,sty});
        v2.push_back({stx,eny});
        v2.push_back({enx,sty});
        v2.push_back({enx,eny});
        for(auto i:v2)
        {
            if(ccw(a.x1,a.y1,i.first,i.second,a.x2,a.y2)==0)
            {
                if(min(a.x1,a.x2)<=i.first && max(a.x1,a.x2)>=i.first && min(a.y1,a.y2)<=i.second && max(a.y1,a.y2)>=i.second)
                    res--;
            }
        }
        if(flag) cout<<"4\n";
        else cout<<res<<'\n';
    }
}