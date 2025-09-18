#include <bits/stdc++.h>
using namespace std;

// FFT - Polynomial Multiply
// Time Complexity : O(N log N)

typedef complex<double> cpx;
typedef vector<cpx> poly;
typedef long long ll;
const double pi = acos(-1);

void fft(poly &f, bool inv = 0){
    int n = f.size(), j = 0;
    vector<cpx> root(n >> 1);
    for(int i=1; i<n; i++){
        int bit = (n >> 1);
        while(j >= bit) j -= bit, bit >>= 1;
        j += bit;
        if(i < j) swap(f[i], f[j]);
    }
    double ang = 2 * pi / n; if(inv) ang *= -1;
    for(int i=0; i<n/2; i++) root[i] = cpx(cos(ang*i), sin(ang*i));
    for(int i=2; i<=n; i<<=1){
        int step = n / i;
        for(int j=0; j<n; j+=i){
            for(int k=0; k<i/2; k++){
                cpx u = f[j | k], v = f[j | k | i/2] * root[step * k];
                f[j | k] = u + v; f[j | k | i/2] = u - v;
            }
        }
    }
    if(inv) for(int i=0; i<n; i++) f[i] /= n;
}
vector<ll> multiply(const vector<ll> &_a, const vector<ll> &_b){
    poly a, b; a.reserve(_a.size()); b.reserve(_b.size());
    for(auto i : _a) a.push_back(i);
    for(auto i : _b) b.push_back(i);
    int n = 1;
    while(n < a.size() + b.size()) n <<= 1;
    a.resize(n); b.resize(n);
    cpx w(cos(2*pi/n), sin(2*pi/n));
    fft(a); fft(b);
    for(int i=0; i<n; i++) a[i] *= b[i];
    vector<ll> ret(n); fft(a, 1);
    for(int i=0; i<n; i++) ret[i] = round(a[i].real());
    while(ret.size() > 1 && !ret.back()) ret.pop_back();
    return ret;
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string a,b;
    cin>>a>>b;
    if(a=="0" || b=="0")
    {
        cout<<0;
        return 0;
    }
    vector<ll> A,B;
    for(int i=a.length()-1;i>=0;i--)
        A.push_back(a[i]-'0');
    for(int i=b.length()-1;i>=0;i--)
        B.push_back(b[i]-'0');
    vector<ll> res=multiply(A,B);
    for (int i = 0; i < a.size()+b.size()-2; i++) {
        res[i + 1] += res[i] / 10;
        res[i] = res[i] % 10;
    }
    int cnt = res.size() - 1;
    while (res[cnt] == 0) {
        cnt--;
        if (cnt == 0) break;
    }
    for(int i=cnt;i>=0;i--)
        cout<<res[i];
}