#include <bits/stdc++.h>
using namespace std;
int prime[100010];
vector<int> v;
int main()
{
    for(int i=2;i<=100000;i++)
    {
        if(prime[i]) continue;
        v.push_back(i);
        for(int j=i*2;j<=100000;j+=i)
            prime[j]=1;
    }
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        vector<int> ans;
        cin>>n;
        for(int i=0;i<v.size();i++)
        {
            int num=0;
            while(n%v[i]==0)
            {
                num++;
                n/=v[i];
            }
            for(int j=30;j>=0;j--)
            {
                if(num>=(1<<j))
                {
                    num-=(1<<j);
                    //cout<<v[i]<<" "<<(1<<j)<<" | ";
                    ans.push_back(pow(v[i],(1<<j)));
                }
            }
        }
        if(n!=1) ans.push_back(n);
        sort(ans.begin(),ans.end());
        for(auto i:ans) cout<<i<<" ";
        cout<<'\n';
    }
}