//
//  main.cpp
//  1079. Total Sales of Supply Chain (25)
//
//  Created by 祝暾 on 2017/7/27.
//  Copyright © 2017年 祝暾. All rights reserved.
//  DFS!!

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;
double ans=0.0,p,r;
struct node {
    double data;
    vector<int> child;
};
vector<node>v;
void dfs(int index,int depth){
    if (v[index].child.size()==0) {
        ans+=v[index].data*pow(1+r, depth);
        return;
    }else{
        for (int i=0; i<v[index].child.size(); i++) {
            dfs(v[index].child[i], depth+1);
        }
    }
}
int main(int argc, const char * argv[]) {
    int n,k;
    cin>>n>>p>>r;
    r/=100;
    v.resize(n);
    for (int i=0; i<n; i++) {
        cin>>k;
        if (k==0) {
            cin>>v[i].data;
        }else{
            int temp;
            for (int j=0; j<k; j++) {
                cin>>temp;
                v[i].child.push_back(temp);
            }
        }
    }
    dfs(0, 0);
    cout<<setprecision(1)<<fixed<<ans*p<<endl;
    return 0;
}
