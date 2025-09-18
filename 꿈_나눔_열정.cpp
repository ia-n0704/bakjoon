#include <bits/stdc++.h>
using namespace std;
struct dimi
{
    int dream,passion,share;
    int sum;
    int idx;
};
bool compare(dimi a,dimi b)
{
    return a.sum<b.sum;
}
dimi arr[100010];
dimi jw;
int main()
{
    int n,m;
    cin>>n>>m;
    cin>>jw.dream>>jw.passion>>jw.share;
    jw.sum=jw.dream+jw.passion+jw.share;
    jw.idx=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i].dream>>arr[i].passion>>arr[i].share;
        arr[i].sum=arr[i].dream+arr[i].passion+arr[i].share;
        arr[i].idx=i+1;
    }
    sort(arr,arr+n,compare);
    cout<<0<<" ";
    m--;
    vector<int> ans;
    for(int i=n-1;i>=0;i--)
    {
        if(arr[i].sum<=jw.sum && m)
        {
            ans.push_back(arr[i].idx);
            m--;
        }
    }
    for(auto i:ans) cout<<i<<" ";
}