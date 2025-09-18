#include <bits/stdc++.h>
using namespace std;
std::vector<std::vector<int>> sort_master(std::vector<int> A) {
	int n = (int)A.size();
    vector<vector<int>> res;
    int st=2,en=n-1;
    while(1)
    {
        if(en<=st)
        {
            res.push_back({0,0,en,en});
            break;
        }
        res.push_back({0,0,st,en});
        en-=2;
    }
	return res;
}
int main()
{
    int n;
    vector<int> v;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        v.push_back(a);
    }
    auto ans=sort_master(v);
    for(auto i:ans)
    {
        for(auto j:i)
            cout<<j<<" ";
        cout<<'\n';
    }
}