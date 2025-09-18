# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
vector<int> getPartialMatch(const string& N) {
	int m = N.size();
	vector<int> pi(m, 0);
	int begin = 1, matched = 0;
	while (begin + matched < m) {
		if (N[begin + matched] == N[matched]) {
			++matched;
			pi[begin + matched - 1] = matched;
		}
		else {
			if (matched == 0) ++begin;
			else {
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return pi;
}

vector<int> kmpSearch(const string& H, const string& N) {
	int n = H.size(), m = N.size();
	vector<int> ret;
	// pi[i] = N[,,i]의 접미사도 되고 접두사도 되는 문자열의 최대 길이
	vector<int> pi = getPartialMatch(N);
	int begin = 0, matched = 0;
	while (begin <= n - m) {
		//만약 H의 부분 문자열의 N과 같다면
		if (matched < m && H[begin + matched] == N[matched]) {
			//한 개가 일치하니 ++해준다
			++matched;
			//증가시켜줬을 때 m 즉 N과 같다면 그 시작위치를 ret에 넣어준다.
			if (matched == m) ret.push_back(begin);
		}
		else {
			//matched == 0인 경우는 한 글자도 일치하지 않고 불일치가 발생했을 때
			//바로 다음 시작 위치에서 부터 처음부터 검색을 재개하면 되기에 ++begin을 해준다
			if (matched == 0) ++begin;
			else {
				//begin을 옮겼다고 처음부터 다시 비교할 필요는 없다
				//이미 같은 걸 접미사와 접두사로 확인 했기 때문에
				//pi[matched -1]만큼은 항상 일치
				// matched를 pi[matched - 1]로 바꿔줌
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return ret;
}
void sol()
{
    int n,l,r;
    cin>>n>>l>>r;
    int k=l;
    string s;
    cin>>s;
    int div=n/k;
    for(int i=div;i>=1;i--)
    {
        string temp=s.substr(0,i);
        //cout<<temp<<'\n';
        string comp=s.substr(i+1,0);
        //auto v=kmpSearch(comp,temp);
        //for(auto i:v) cout<<i<<'\n';
    }
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        sol();
    }
}