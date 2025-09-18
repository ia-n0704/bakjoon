#include <bits/stdc++.h>
using namespace std;
int lis[2024];
int lds[2024];
vector<int> lisV;
vector<int> ldsV;
int main() {
	int t[2024]={-1};
	int n;
	scanf("%d", &n);
	for (int i=0;i<n;i++)
		scanf("%d",&t[i]);
	for (int idx=0;idx<n;idx++) {
		lisV.push_back(t[idx]);
		ldsV.push_back(t[idx]);
		for (int i=idx+1;i<n;i++) {
			if (t[i]>lisV.back())
				lisV.push_back(t[i]);
			else if(t[i]>lisV.front()) {
				int it=lower_bound(lisV.begin()+1,lisV.end(),t[i])-lisV.begin();
				lisV[it]= t[i];
			}
			if (t[i]<ldsV.back())
				ldsV.push_back(t[i]);
			else if (t[i]<ldsV.front()) {
				int it=upper_bound(ldsV.begin()+1,ldsV.end(),t[i],greater<int>())-ldsV.begin();
				ldsV[it]=t[i];
			}
		}
		lis[idx]=lisV.size();
		lisV.clear();
		lds[idx]=ldsV.size();
		ldsV.clear();
	}
	int m=0;
	if (n!=0)
		m=lis[0]+lds[0]-1;

	for (int i=1;i<n;i++) {
		m=max(m,lis[i]+lds[i]-1);
	}
	printf("%d", m);
}