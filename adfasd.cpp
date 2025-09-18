#include "testlib.h"
#include <iostream>
 
using namespace std;
 
int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    int n = opt<int>(1),m = opt<int>(2);
    println(n);
    int sz = 0;
    for(int i = 0; i < n; i++){
        int q=rnd.next(1,100);
        if(q<=m){
            cout<<2<<' '<<sz<<' '<<rnd.next(-1000000000,1000000000)<<'\n';
            sz++;
        }
        else{
            cout<<1<<' '<<(i%2?1:2)<<'\n';
        }
    }
}