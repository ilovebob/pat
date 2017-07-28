//
//  main.cpp
//  1090. Highest Price in Supply Chain (25)
//
//  Created by 祝暾 on 2017/7/28.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#define maxn 100010
using namespace std;
int n, maxdepth = 0, maxnum = 0, temp, root;
vector<int> v[maxn];
void dfs(int index,int depth){
    if (v[index].size()==0) {
        if (maxdepth==depth) {
            maxnum++;
        }else if (maxdepth<depth){
            maxdepth=depth;
            maxnum=1;
        }
        return;
    }
    for (int i=0; i<v[index].size(); i++) {
        dfs(v[index][i], depth+1);
    }
}
int main(int argc, const char * argv[]) {
    double p,r;
    cin>>n>>p>>r;
    int temp;
    for (int i=0; i<n; i++) {
        cin>>temp;
        if (temp==-1) {
            root=i;
        }else{
            v[temp].push_back(i);
        }
    }
    dfs(root, 0);
    cout<<fixed<<setprecision(2)<<p*pow(1+r/100, maxdepth);
    cout<<" "<<maxnum<<endl;
    return 0;
}
