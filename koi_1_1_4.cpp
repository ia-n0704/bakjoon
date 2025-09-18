#include <bits/stdc++.h>
using namespace std;
int arr[20]={0,2,9,5,1,6,8,7,3,4};
vector<int> res;
int main()
{
    for(int i=1;i<=511;i++)
    {
        int cnt=0;
        for(int j=1;j<=511;j*=2) if(i&j) cnt++;
        if(cnt==4)
        {
            vector<int> v;
            for(int j=1;j<=9;j++)
            {
                if(i&(1<<(j-1)))
                {
                    v.push_back(arr[j]);
                }
            }
            int t=4;
            int p=0;
            for(auto i:v)
            {
                t--;
                int num=1;
                for(int r=1;r<=t;r++)
                {
                    num*=10;
                }
                p+=num*i;
            }
            res.push_back(p);
        }
    }
    sort(res.begin(),res.end());
    reverse(res.begin(),res.end());
    for(int i=0;i<49;i++) cout<<res[i]<<" ";
    cout<<res[48];
}
