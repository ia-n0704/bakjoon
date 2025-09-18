# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int arr[3010];
int n;
vector<vector<int>> v[3010];
vector<int> ans[3010];
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    for(int i=0;i<2*n-1;i++)
        cin>>arr[i];
    for(int i=0;i<2*n-1;i++)
    {
        vector<int> T;
        T.push_back(arr[i]);
        v[0].push_back(T);
        ans[0].push_back(arr[i]);
    }
    int idx=1;
    while(n>1)
    {
        int temp=0;
        int cnt=0;
        for(int i=1;i<v[idx-1].size()-1;i+=2)
        {
            int a=ans[idx-1][temp];
            int b=ans[idx-1][i];
            int c=ans[idx-1][i+1];
            int anum=a%2,bnum=b%2,cnum=c%2;
            vector<int> T;
            if(anum==bnum)
            {
                //cout<<i<<" |1 "<<a<<" "<<b<<" "<<c<<'\n';
                ans[idx].push_back((a+b)/2);
                for(auto x:v[idx-1][temp])
                    T.push_back(x);
                for(auto x:v[idx-1][i])
                    T.push_back(x);
                v[idx].push_back(T);
                temp=i+1;
                cnt++;
            }
            else if(anum==cnum)
            {
                //cout<<i<<" |2 "<<a<<" "<<b<<" "<<c<<'\n';
                ans[idx].push_back((a+c)/2);
                for(auto x:v[idx-1][temp])
                    T.push_back(x);
                for(auto x:v[idx-1][i+1])
                    T.push_back(x);
                v[idx].push_back(T);
                temp=i;
                cnt++;
            }
            else if(bnum==cnum)
            {
                //cout<<" |3 "<<a<<" "<<b<<" "<<c<<'\n';
                ans[idx].push_back((c+b)/2);
                for(auto x:v[idx-1][i+1])
                    T.push_back(x);
                for(auto x:v[idx-1][i])
                    T.push_back(x);
                v[idx].push_back(T);
                cnt++;
                temp=temp;
            }
        }
        /*for(int j=0;j<v[idx].size();j++)
        {
            for(auto x:v[idx][j])
                cout<<x<<" ";
            cout<<'\n';
        }
        for(auto x:ans[idx])
            cout<<x<<' ';
        cout<<'\n'<<'\n';*/
        n/=2;
        idx++;
    }
    for(auto x:v[idx-1][0])
        cout<<x<<" ";
}