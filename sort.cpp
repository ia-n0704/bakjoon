#include <bits/stdc++.h>
using namespace std;
vector<int> sort(vector<int> v)
{
    if(v.size()<=1) return v;
    int n=v.size();
    vector<int> l,r;
    int mid=n/2;
    for(int i=0;i<mid;i++) l.push_back(v[i]);
    for(int i=mid;i<n;i++) r.push_back(v[i]);
    l=sort(l);
    r=sort(r);
    int idx_l=0,idx_r=0;
    vector<int> ans;
    while(idx_l<l.size() && idx_r<r.size())
    {
        if(l[idx_l]>r[idx_r])
        {
            ans.push_back(r[idx_r]);
            idx_r++;
        }
        else
        {
            ans.push_back(l[idx_l]);
            idx_l++;
        }
    }
    for(int i=idx_l;i<l.size();i++) ans.push_back(l[i]);
    for(int i=idx_r;i<r.size();i++) ans.push_back(r[i]);
    return ans;
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
    v=sort(v);
    for(auto i:v) cout<<i<<" ";
}