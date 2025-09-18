#include <bits/stdc++.h>
using namespace std;
int A[200010],B[100010];
bool compare(int x,int y)
{
    if(A[x]<B[y]) return 1;
    else return 0;
}
int search(int N,int K)
{
    int n=N,k=K;
    int idx_A=0,idx_B=0;
    while(k>1 && idx_A<n && idx_B<n)
    {
        int temp=k/2;
        if(idx_A+temp-1>=n) temp=n-idx_A;
        if(idx_B+temp-1>=n) temp=n-idx_B;
        int temp_idx_A=min(n-1,idx_A+temp-1);
        int temp_idx_B=min(n-1,idx_B+temp-1);
        if(compare(temp_idx_A,temp_idx_B)==0)
        {
            k-=(temp_idx_B-idx_B+1);
            idx_B=temp_idx_B+1;
        }
        else
        {
            k-=(temp_idx_A-idx_A+1);
            idx_A=temp_idx_A+1;
        }
    }
    //cout<<idx_A<<" "<<idx_B<<" "<<k<<'\n';
    if(k>1)
    {
        if(idx_A>=n) return n+idx_B+k-1;
        else return idx_A+k-1;
    }
    if(compare(idx_A,idx_B)) return idx_A;
    else return n+idx_B;
}
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> v;
    for(int i=0;i<n;i++) cin>>A[i];
    for(int i=0;i<n;i++) cin>>B[i];
    for(int i=0;i<n;i++)
    {
        v.push_back(A[i]);
        v.push_back(B[i]);
    }
    sort(v.begin(),v.end());
    cout<<search(n,k);
    cout<<'\n'<<v[k-1];
}