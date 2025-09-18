#include <bits/stdc++.h>
using namespace std;
void hanoi(int n,int x,int y)
{
	if(n==0) return;
	hanoi(n-1,x,6-x-y);
	cout<<x<<" "<<y<<'\n';
	hanoi(n-1,6-x-y,y);
}
int main() {
	int n;
	scanf("%d",&n);
	hanoi(n,1,3);
}
