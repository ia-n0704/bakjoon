# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
void sol()
{
    int n;
    int arr[200010];
    int al[1000];
    cin>>n;
    fill(al,al+300,0);
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<n;i++)
    {
        for(int j='a';j<='z';j++)
        {
            if(al[j]==arr[i])
            {
                cout<<(char)j;
                al[j]++;
                break;
            }
        }
    }
    cout<<"\n";
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