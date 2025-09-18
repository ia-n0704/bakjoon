/*#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int ans[50];
int arr[50];
int cnt;
void three(vector<int> v)
{
    int num[210] = { 0 };
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v.size(); j++) {
            num[i + j] += (v[i]) * (v[j]);
        }
    }
 
    int Len = v.size()*2;
    for (int i = Len - 1; i > 0; i--) {
        num[i - 1] += num[i] / 10;
        num[i] %= 10;
    }
 
    // 정답 출력
    for (int i = 0; i < Len; i++) {
        printf("%d", num[i]);
    }
    printf("\n");
}
void go(int idx)
{
    if(idx>1)
    {
        vector<int> v;
        for(int i=1;i<idx;i++) v.push_back(arr[i]);
        //int *num=three(v);
       // if(num[idx-1]!=ans[idx-1])
         //   return;
        //else cout<<arr[idx-1];
    }
    for(int i=1;i<=9;i++)
    {
        arr[idx]=i;
        go(idx+1);
        arr[idx]=0;
    }
}
void sol(ll n)
{
    cnt=0;
    printf("1");
    while(n)
    {
        cnt++;
        ans[cnt]=n%10;
        n/=10;
    }
    //go(1);
    vector<int> v;
    for(int i=1;i<=cnt;i++)
    {
        cout<<v[i];
        v.push_back(ans[i]);
    }
        
    three(v);
}
int main()
{
    //ios_base :: sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        printf("1");
        scanf("%lld",&n);
        cout<<1;
        cout<<n;
        sol(n);
    }
}*/


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int L;
ll ten[15], N, ans;
ll mul(ll a, ll b, ll md)
{
    int apos,bpos=0;
    ll ret=0,sa=0,sb=0;
    while(b / ten[bpos])
    {
        sb = b / ten[bpos];
        sb%=10;
        apos = 0;
        while(bpos + apos <= md)
        {
            sa = a / ten[apos];
            sa %= 10;
            ret += sb*sa*ten[bpos + apos]%ten[md];
            ret %= ten[md];
            apos++;
        }
        bpos++;
    }
    return ret%ten[md];
}
int back(int p, ll c) {
    if (p == L)
    {
        ans = c;
        return 1;
    }
    ll t, tt;
    for (ll i = 0; i < 10; i++)
    {
        tt = c + i*ten[p];
        t = mul(tt, tt, p + 1);
        t %= ten[p + 1];
        t = mul(t, tt, p + 1);
        t %= ten[p + 1];
        if (N%ten[p + 1] != t) continue;
        if (back(p + 1, c + i*ten[p])) return 1;
    }
    return 0;
}
int main() {
    int T;
    ll tmp;
    ten[0] = 1;
    for (int i = 1; i <15 ; i++) ten[i] = ten[i - 1] * 10;
    cin>>T;
    while (T--) {
        ans = 0;
        cin>>N;
        tmp = N, L = 0;
        while (tmp) tmp /= 10, L++;
        back(0, 0);
        cout<<ans%ten[L]<<'\n';
    }
}