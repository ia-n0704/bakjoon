
#include <bits/stdc++.h>
using namespace std;
static int n,a[1555];
static int total_queries=0,result;

int query(int i,int v){
	if(i<0||i>=n||v<0||v>=n){
        
		//printf("-1"); exit(0);
	}
	total_queries++;
	return (a[i]<=v);
}

int get_maximum(int n){
    int l=0,r=n-1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        int flag=0;
        for(int i=0;i<n;i++)
        {
            if(query(i,mid)==0)
            {
                flag=1;
                break;
            }
        }
        if(flag) l=mid+1;
        else r=mid-1;
    }
    return l;
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	result=get_maximum(n);
	printf("%d\n%d\n",result,total_queries);
}