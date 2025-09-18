#include <bits/stdc++.h>
using namespace std;

static const int MX=500010;

int nn, A[MX], B[MX];
int arr[MX];
static int cnt;

int compare(int i, int j){
	cnt++;
	return A[i]<B[j] ? -1 : 1;
}


int twolist(int n){
	int l=1,r=n;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(compare(mid,n-mid+1)==-1)
            l=mid+1;
        else
            r=mid-1;
    }

    if(compare(r,n-r)==1)
        return r;
    else return n+n-r;
}
int main(){
	scanf("%d", &nn);
	for(int i=1; i<=nn; i++) scanf("%d", &A[i]);
	for(int i=1; i<=nn; i++) scanf("%d", &B[i]);
    //cin>>nn;
    //for(int i=1;i<=2*nn;i++) arr[i]=i;
    //do
    //{
        /*for(int i=1;i<=2*nn;i++)
        {
            if(i<=nn) A[i]=arr[i];
            else
                B[i-nn]=arr[i];
        }
        int flag=0;
        for(int i=2;i<=nn;i++)
        {
            if(A[i]<A[i-1]) flag=1;
            if(B[i]<B[i-1]) flag=1;
        }
        if(flag) continue;

        cout<<nn<<'\n';
        for(int i=1;i<=nn;i++)
            cout<<A[i]<<" ";
        cout<<'\n';
        for(int i=1;i<=nn;i++)
            cout<<B[i]<<" ";
         cout<<'\n';
         int ans=twolist(nn);
         if(ans>nn)
         {
            if(B[ans-nn]!=nn) 
            {
                cout<<"!";
            }
         }
         else
         {
            if(A[ans]!=nn) cout<<"!";
         }*/
        printf("Your answer: %d\n", twolist(nn));
	    printf("Compare count: %d\n", cnt);
        cnt=0;
    //}while(next_permutation(arr+1,arr+2*nn+1));

	

	return 0;
}
