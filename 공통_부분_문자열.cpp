#define private public
#include <bitset>
#undef private

#include <bits/stdc++.h>
#include <x86intrin.h>
using namespace std;


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


int lcs(string s,string t)
{
    bitset<sz> Alpha[100],arr,dp;
    for(int i=0;i<s.length();i++)
    {
        Alpha[s[i]-'A'][i]=1;
    }
    for(int i=0;i<t.length();i++)
    {
        arr=Alpha[t[i]-'A']|dp;
        dp=dp<<1;
        dp[0]=1;
        dp=arr&(arr^(arr-dp));
    }
    return dp.count();
}
int main()
{
    string s,t;
    cin>>s>>t;
    cout<<lcs(s,t);
}