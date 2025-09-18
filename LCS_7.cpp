#define private public
#include <bitset>
#undef private

#include <bits/stdc++.h>
#include <x86intrin.h>
using namespace std;

#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

string p,q;
vector<char> ans;

//https://gist.github.com/cgiosy/a441de545c9e96b1d7b02cc7a00561f9
template<size_t _Nw> void _M_do_sub(_Base_bitset<_Nw> &A, const _Base_bitset<_Nw> &B) {
	for(int i=0, c=0; i<_Nw; i++)
		c=_subborrow_u64(c, A._M_w[i], B._M_w[i], (unsigned long long*)&A._M_w[i]);
}
template<> void _M_do_sub(_Base_bitset<1> &A, const _Base_bitset<1> &B) {
	A._M_w-=B._M_w;
}
template<size_t _Nb> bitset<_Nb>& operator-=(bitset<_Nb> &A, const bitset<_Nb> &B) {
	_M_do_sub(A, B);
	return A;
}
template<size_t _Nb> inline bitset<_Nb> operator-(const bitset<_Nb> &A, const bitset<_Nb> &B) {
	bitset<_Nb> C(A);
	return C-=B;
}

template<size_t _Nw> void _M_do_add(_Base_bitset<_Nw> &A, const _Base_bitset<_Nw> &B) {
	for(int i=0, c=0; i<_Nw; i++)
		c=_addcarry_u64(c, A._M_w[i], B._M_w[i], (unsigned long long*)&A._M_w[i]);
}
template<> void _M_do_add(_Base_bitset<1> &A, const _Base_bitset<1> &B) {
	A._M_w+=B._M_w;
}
template<size_t _Nb> bitset<_Nb>& operator+=(bitset<_Nb> &A, const bitset<_Nb> &B) {
	_M_do_add(A, B);
	return A;
}
template<size_t _Nb> inline bitset<_Nb> operator+(const bitset<_Nb> &A, const bitset<_Nb> &B) {
	bitset<_Nb> C(A);
	return C+=B;
}
template<size_t sz = 50000>
vector<int> lcs(string s,string t)
{
    bitset<sz> Alpha[100],arr,dp;
    for(int i=0;i<t.length();i++)
    {
        Alpha[t[i]-'A'][i]=1;
    }
    for(int i=0;i<s.length();i++)
    {
        arr=Alpha[s[i]-'A']|dp;
        dp=dp<<1;
        dp[0]=1;
        dp=arr&(arr^(arr-dp));
    }
    vector<int> res(t.length()+2);
    for(int i=0;i<t.length();i++)
        res[i+1]=res[i]+dp[i];
    return res;
}
vector<int> LCS(string a, string b){
	if (b.length()+5 < 100) return lcs<200>(a, b);
	if (b.length()+5 < 500) return lcs<1000>(a, b);
	if (b.length()+5 < 1000) return lcs<2000>(a, b);
	if (b.length()+5 < 5000) return lcs<10000>(a, b);
	if (b.length()+5 < 10000) return lcs<20000>(a, b);
	return lcs<50005>(a, b);
}
void dnc(int s,int e,int l,int r)
{
    if(s==e)
    {
        for(int i=l;i<=r;i++)
        {
            if(p[s]==q[i])
            {
                ans.push_back(p[s]);
                break;
            }
        }
        return;
    }
    int mid=(s+e)/2;
    string first=p.substr(s,mid-s+1);
    string second=p.substr(mid+1,e-mid+1);
    string temp=q.substr(l,(r-l+1));
    vector<int> v1,v2;
    v1=LCS(first,temp);
    reverse(temp.begin(),temp.end());
    reverse(second.begin(),second.end());
    v2=LCS(second,temp);
    reverse(v2.begin(),v2.end());
    int mx=-1;
    int num=0;
    for(int i=l-1;i<=r;i++)
    {
        if(mx<=v1[i-l+1]+v2[i-l+2])
        {
            num=i;
            mx=v1[i-l+1]+v2[i-l+2];
        }
    }
    dnc(s,mid,l,num);
    dnc(mid+1,e,num+1,r);
}
int main()
{
    fastio;
    cin>>p>>q;
    dnc(0,p.length()-1,0,q.length()-1);
    cout<<ans.size()<<'\n';
    for(auto i:ans)
        cout<<i;
}