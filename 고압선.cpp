# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll idx[2010];
ll idx2[2010];
struct Line
{
    int idx1,idx2;
    ll dx,dy;
    pll px,py;
    int flag;
};
vector<Line> line;
bool cmp(Line x,Line y)
{
    return x.dx*y.dy==x.dy*y.dx;
}
bool compare(Line x,Line y)
{
    if(cmp(x,y)) 
    {
        if(x.flag!=y.flag) return x.flag<y.flag;
        if(x.idx1==y.idx1)
            return x.idx2<y.idx2;
        return x.idx1<y.idx1;
    }
    return x.dx*y.dy>x.dy*y.dx;
}
double dist(pll x,pll y)
{
    return sqrt((x.first-y.first)*(x.first-y.first)+(x.second-y.second)*(x.second-y.second));
}
double cal(pll p,pll x,pll y)
{
    ll a=y.second-x.second;
    ll b=-(y.first-x.first);
    ll c=(y.first-x.first)*x.second-(y.second-x.second)*x.first;
    return abs(a*p.first+b*p.second+c)/(double)sqrt(a*a+b*b);
}
int main()
{
    fastio;
    cin>>n; 
    for(ll i=1;i<=n;i++)
        cin>>arr[i].first>>arr[i].second;
    sort(arr+1,arr+n+1);
    iota(idx+1,idx+n+1,1);
    iota(idx2+1,idx2+n+1,1);
    for(ll i=1;i<=n;i++)
    {  
        for(ll j=i+1;j<=n;j++)
        {
            pll a=arr[i],b=arr[j];
            if(a.first==b.first && a.second<b.second) swap(a,b);
            else if(a.first<b.first) swap(a,b);
            line.push_back({i,j,a.first-b.first,a.second-b.second,arr[i],arr[j],0});
            if(a.second-b.second>=0)
                line.push_back({i,j,(a.second-b.second),-(a.first-b.first),arr[i],arr[j],1});
            else
                line.push_back({i,j,-(a.second-b.second),(a.first-b.first),arr[i],arr[j],1});
        }
    }
    sort(line.begin(),line.end(),compare);

    double res=0;
    ll j=0;
    for(ll i=0;i<line.size();i=j)
    {
        while(j<line.size() && cmp(line[i],line[j])) j++;
        for(ll k=i;k<j;k++)
        {
            ll l=line[k].idx1;
            ll r=line[k].idx2; 
           // cout<<l<<" "<<r<<'\n';           
            if(line[k].flag)
            {
                if(abs(idx[l]-idx[r])==1)
                {
                    //cout<<line[k].px.first<<" "<<line[k].px.second<<" | "<<line[k].py.first<<" "<<line[k].py.second<<'\n';
                    res=max(res,dist(line[k].px,line[k].py));
                }
            }
            else
            {
                swap(idx[l],idx[r]);
                swap(idx2[idx[l]],idx2[idx[r]]);
                if(idx[l]>idx[r]) swap(l,r);
                if(idx[l]>1)
                    res=max(res,cal(arr[idx2[idx[l]-1]],arr[l],arr[r]));
                if(idx[r]<n)
                    res=max(res,cal(arr[idx2[idx[r]+1]],arr[l],arr[r]));
            }
        }
    }
    printf("%.10lf",res/2);
}



/*#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define IDX(v, x) (lower_bound(all(v), x) - v.begin())
using namespace std;

using uint = unsigned;
using ll = long long;
using ull = unsigned long long;
using Point = pair<ll, ll>;

istream& operator >> (istream &in, Point &t){ in >> t.x >> t.y; return in; }
Point operator + (Point p1, Point p2){ return {p1.x+p2.x, p1.y+p2.y}; }
Point operator - (Point p1, Point p2){ return {p1.x-p2.x, p1.y-p2.y}; }
ll    operator * (Point p1, Point p2){ return p1.x*p2.x + p1.y*p2.y; } /// dot product
ll    operator / (Point p1, Point p2){ return p1.x*p2.y - p2.x*p1.y; } /// cross product

ll _CCW(const Point &p1, const Point &p2, const Point &p3){ return (p2-p1)/(p3-p2); }
int CCW(Point p1, Point p2, Point p3){
    ll res = _CCW(p1, p2, p3);
    return (res > 0) - (res < 0);
}
ll D(const Point &p1, const Point &p2){
    ll dx = p1.x - p2.x, dy = p1.y - p2.y;
    return dx*dx + dy*dy;
}
inline double hypot(const Point p){ return hypot(p.x, p.y); }
inline Point Rot(const Point p){ return p.y >= 0 ? Point(p.y, -p.x) : Point(-p.y, p.x); }

int N, Idx[2020], Ord[2020];
Point A[2020];

struct Line{
    int i, j, flag; // -1: rot90
    Point s, e, dir;
    Line(int i, int j, int flag) : i(i), j(j), flag(flag), s(A[i]), e(A[j]) {
        if(s > e) swap(s, e);
        if(flag == 1) dir = e - s;
        else dir = Rot(e - s);
    }
    bool operator < (const Line &l) const {
        ll res = dir / l.dir; if(res) return res > 0;
        return tie(flag, s, e) < tie(l.flag, l.s, l.e);
    }
};

inline double solve_triangle(const Point &a, const Point &b, const Point &c){
    return abs(_CCW(a, b, c)) / hypot(a - b);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N; for(int i=1; i<=N; i++) cin >> A[i]; sort(A+1, A+N+1);
    for(int i=1; i<=N; i++) Ord[i] = Idx[i] = i;

    vector<Line> lines; lines.reserve(N*(N-1)/2);
    for(int i=1; i<=N; i++) for(int j=i+1; j<=N; j++) lines.emplace_back(i, j, 1), lines.emplace_back(i, j, -1);
    
    for(auto i:lines)
        cout<<i.dir.first<<" "<<i.dir.second<<" | "<<i.flag<<'\n';
    sort(all(lines));
    double mx = 0;
    for(const auto &line : lines){
        if(line.flag == 1){
            int a = line.i, b = line.j;
            cout<<a<<" "<<b<<'\n';
            swap(Idx[a], Idx[b]);
            swap(Ord[Idx[a]], Ord[Idx[b]]);
            a = Idx[line.i]; b = Idx[line.j]; if(a > b) swap(a, b);
            if(a-1 >= 1) mx = max(mx, solve_triangle(line.s, line.e, A[Ord[a-1]]));
            if(b+1 <= N) mx = max(mx, solve_triangle(line.s, line.e, A[Ord[b+1]]));
        }
        else{
            if(abs(Idx[line.i] - Idx[line.j]) == 1)
            {
                cout<<A[line.i].first<<" "<<A[line.i].second<<" | "<<A[line.j].first<<" "<<A[line.j].second<<'\n';
                mx = max(mx, hypot(A[line.i] - A[line.j]));
            }
        }
    }
    cout << fixed << setprecision(10) << mx / 2 << "\n";
}*/