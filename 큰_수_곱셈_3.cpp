# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef complex<double> cpx;
typedef vector<cpx> poly;
typedef long long ll;
const double pi = acos(-1);

void fft(vector<cpx> & a, bool invert=0) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * pi / len * (invert ? -1 : 1);
        cpx wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cpx w(1);
            for (int j = 0; j < len / 2; j++) {
                cpx u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (cpx & x : a)
            x /= n;
    }
}
vector<int> multiply(const vector<int> &_a, const vector<int> &_b){

    poly a, b; 
    for(auto i : _a) a.push_back(i);
    for(auto i : _b) b.push_back(i);
    int n = 1;
    int sza=a.size(),szb=b.size();
    while(n < sza+szb) n <<= 1;
    a.resize(n); b.resize(n);
    cpx w(cos(2*pi/n), sin(2*pi/n));
    fft(a); fft(b);
    for(int i=0; i<n; i++) a[i] *= b[i];
    vector<int> ret(n); fft(a, 1);
    for(int i=0; i<n; i++) ret[i] = round(a[i].real());
    int szr=ret.size();
    while(szr > 1 && !ret.back()) ret.pop_back();
    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string a,b;
    cin>>a>>b;
    int sza=a.size(),szb=b.size();
    if(a=="0" || b=="0")
    {
        cout<<0;
        return 0;
    }
    vector<int> A,B;
    for(int i=sza-1;i>=0;i--)
        A.push_back(a[i]-'0');
    for(int i=szb-1;i>=0;i--)
        B.push_back(b[i]-'0');
    vector<int> res=multiply(A,B);
    int szr=res.size();
    for (int i = 0; i < szr-1; i++) {
        res[i + 1] += res[i] / 10;
        res[i] = res[i] % 10;
    }
    int cnt = szr - 1;
    /*while (res[cnt] == 0) {
        cnt--;
        if (cnt == 0) break;
    }*/
    for(int i=cnt;i>=0;i--)
        cout<<res[i];
}