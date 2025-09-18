#include "kong.h"
#include <bits/stdc++.h>
using namespace std;
vector<int> idx[22222];
int kong(int n){
    vector<int> v;
    for(int i=1;i<=n;i++) v.push_back(i);
    int a;
    while(1)
    {
        vector<int> v2;
        for(int i=0;i<v.size()-1;i+=2)
        {
            if(compare(v[i],v[i+1])==1)
            {
                idx[v[i]].push_back(v[i+1]);
                a=v[i];
                v2.push_back(v[i]);
            }
        }
        if(v.size()%2)
            v2.push_back(v[v.size()-1]);
        if(v2.size()==1) break;
        v=v2;
    }
    int b=idx[a][0];
    for(int i=1;i<idx[a].size();i++)
        if(compare(b,idx[a][i])==-1) b=idx[a][i];
    return b;
}