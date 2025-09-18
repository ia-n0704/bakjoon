#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    for(n=1;n<=1024;n++)
    {
        for(int i=0;i<n;i++)
        {
            int l=0,r=n-1;
            int num=0;
            int mx=0;
            while(l<r && r>mx)
            {
                int mid=(l+r)/2;
                cnt++;
                if(i<=mid)
                    r=mid;
                else
                    l=mid+1;
            }
            mx=max(mx,l);
            if(mx!=i) cout<<mx<<" "<<i<<'\n';
        }        
    }
}