# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
int n;
pll a[100010],b[100010];
ll dp[100010];
int ptr;
struct Line {
    ll m, b;
    double x;
    Line(ll _m, ll _b, double _x) : m(_m), b(_b), x(_x) {};
    ll f(ll x) {
        return m * x + b;
    }
};
vector<Line> lines;

double intersect(Line& a, Line& b) {
    return (double)(b.b - a.b) / (a.m - b.m);
}

void addLine(ll m, ll b) {
    Line a(m, b, -1e10);
    if (lines.empty()) {
        lines.push_back(a);
        return;
    }
    while (!lines.empty()) {
        Line top = lines.back();
        double x = intersect(top, a);
        //cout<<'\n'<<x<<" "<<top.x<<'\n';
        if (x <= top.x) lines.pop_back();
        else break;
    }
    //cout<<lines.back().m<<" "<<lines.back().b<<'\n';
    a.x = intersect(lines.back(), a);
    //cout<<" | "<<a.x<<'\n';
    lines.push_back(a);
    if (ptr >= lines.size()) ptr = lines.size() - 1;
    return;
}

ll query(ll x) {
    while (ptr < lines.size() - 1 && lines[ptr + 1].x < x) ++ptr;
    return lines[ptr].f(x);
}
int main()
{
    fastio;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i].fi>>a[i].se;
    sort(a+1,a+n+1);
    int idx=0;
    for(int i=0;i<n;i++)
    {
        while(idx && b[idx-1].se<=a[i+1].se)
            idx--;
        b[idx++]=a[i+1];
    }
    n=idx;
    addLine(b[0].second,0);
    for(int i=0;i<n-1;i++)
    {
        dp[i]=query(b[i].fi);
        addLine(b[i+1].se,dp[i]);
    }
    cout<<query(b[n-1].fi);
}
