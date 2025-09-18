# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
ll n;
pair<ll,ll> arr[2010];
ll sum[2010][2010];
ll ans1[2010][2010];
ll ans2[2010][2010];
pll temp;
ll res;
ll ccw(pll a,pll b,pll c)
{
    return (a.first*b.second+b.first*c.second+c.first*a.second)-(a.second*b.first+b.second*c.first+c.second*a.first);
}
bool compare(pair<pll,ll> x, pair<pll,ll> y)
{
    pll X={x.first.first-temp.first,x.first.second-temp.second};
    pll Y={y.first.first-temp.first,y.first.second-temp.second};
    if((X.first<0)!=(Y.first<0))
        return X.first<Y.first;
    if(X.first==0 && Y.first==0)
        return X.second<Y.second;
    return X.second*Y.first<X.first*Y.second;
}
int main()
{
    fastio;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i].first>>arr[i].second;
    ll res=0;
    for(int i=1;i<=n;i++)
    {
        temp=arr[i];
        vector<pair<pll,ll>> v;
        for(int j=1;j<=n;j++)
            if(i!=j) v.push_back({arr[j],j});
        sort(v.begin(),v.end(),compare);
        ll idx1=1,idx2=0;
        for(auto a:v)
        {
            while(ccw(arr[i],a.first,v[idx1%(n-1)].first)>=0 && idx2<n-1)
            {
                idx1++;
                idx2++;
            }
            ans1[i][a.second]=max(0ll,idx2-2);
            //cout<<ans1[i][a.second]<<'\n';
            idx2--;
        }
    }

    for(int i=1;i<=n;i++)
    {
        temp=arr[i];
        vector<pair<pll,ll>> v;
        for(int j=1;j<=n;j++)
            if(i!=j) v.push_back({arr[j],j});
        sort(v.begin(),v.end(),compare);
        ll sum=0;
        for(auto j:v)
            sum+=ans1[i][j.second];
        //cout<<sum<<'\n';
        ll idx1=-1,idx2=0;
        ll num1=0,num2=0;
        for(auto a:v)
        {
            while(ccw(arr[i],a.first,v[(idx1+1)%(n-1)].first)>=0 && idx2<n-1)
            {
                num1+=ans1[i][v[(idx1+1)%(n-1)].second];
                num2+=ans1[v[(idx1+1)%(n-1)].second][i];
                idx1++;
                idx2++;
            }
            num2-=ans1[a.second][i];
            ans2[i][a.second]=sum+num2-num1;
            num1-=ans1[i][a.second];
            idx2--;
        }
    }
    ll num=(n-2)*(n-3);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j) continue;
            res=max(res,(ans2[i][j]+ans2[j][i]-num)/2);
        }
    }
    cout<<res;
}




/*#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct Point {
    ll x, y, idx;
    Point operator + (const Point& rhs) const
    {
        return {x + rhs.x, y + rhs.y};
    }
    Point operator - (const Point& rhs) const
    {
        return {x - rhs.x, y - rhs.y};
    }

    bool operator < (const Point& rhs) const
    {
        return tie(x, y) < tie(rhs.x, rhs.y);
    }
};

int ccw(Point p1, Point p2, Point p3)
{
    ll ret = (p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y);
    if(ret > 0) return 1;
    if(ret < 0) return -1;
    return 0;
}

const int MAXN = 1005;

int N;
ll D[MAXN][MAXN], P[MAXN][MAXN], Q[MAXN][MAXN];

struct Comparator {
    Point p;
    Comparator(Point p) : p(p) {}
    bool operator () (const Point& p1, const Point& p2) const
    {
        if((p1 < p) != (p2 < p)) return p1 < p2;
        return ccw(p, p1, p2) > 0;
    }
};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N;
    vector<Point> dots(N);
    int _idx = 0;
    for(auto& [x, y, idx] : dots) cin >> x >> y, idx = _idx++;

    for(int i = 0; i < N; i++) {
        vector<Point> v;
        for(int j = 0; j < N; j++) {
            if(i == j) continue;
            v.push_back(dots[j]);
        }
        sort(v.begin(), v.end(), Comparator(dots[i]));

        int k = 1;
        for(int j = 0; j < N-1; j++) {
            while(ccw(dots[i], v[j], v[k%(N-1)]) >= 0 && k-j < N-1) k++;
            ll l = max(k - j - 2, 0);
            D[i][v[j].idx] = l;
        }
    }

    for(int i = 0; i < N; i++) {
        vector<Point> v;
        for(int j = 0; j < N; j++) {
            if(i == j) continue;
            v.push_back(dots[j]);
        }
        sort(v.begin(), v.end(), Comparator(dots[i]));

        ll s = 0;
        for(int j = 0; j < N-1; j++) {
            s += D[i][v[j].idx];
        }

        int k = 0;
        ll c1 = 0;
        ll c2 = 0;
        for(int j = 0; j < N-1; j++) {
            while(ccw(dots[i], v[j], v[(k+1)%(N-1)]) >= 0 && (k+1)-j+1 <= N-1) {
                k++;
                c1 += D[i][v[k%(N-1)].idx];
                c2 += D[v[k%(N-1)].idx][i];
            }
            c2 -= D[v[j].idx][i];
            P[i][v[j].idx] = c2 + s - c1;
            c1 -= D[i][v[j].idx];
        }
    }

    ll mx = -1;
    ll apb = (ll)(N-2) * (N-3) / 2;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(i == j) continue;

            ll s = P[i][j] + P[j][i];

            mx = max(mx, (s - 2*apb) / 2);
            if((s-2*apb)%2 != 0) assert(false);
        }
    }
    cout << mx;
}*/