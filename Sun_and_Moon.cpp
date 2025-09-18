#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b){
	while(b!=0){
		int r = a%b;
		a= b;
		b= r;
	}
	return a;
}

int lcm(int a, int b){
    return a * b / gcd(a,b);
}
int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    a=abs(b-a);
    c=abs(d-c);
    cout<<lcm(a,c);
}