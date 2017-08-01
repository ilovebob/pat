//
//  main.cpp
//  1106. Lowest Price in Supply Chain (25)
//
//  Created by 祝暾 on 2017/7/29.
//  Copyright © 2017年 祝暾. All rights reserved.
//

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
int n, mindepth = maxn, minnum = 0, temp, root;
vector<int> v[maxn];
void dfs(int index,int depth){
    if (v[index].size()==0) {
        if (mindepth==depth) {
            minnum++;
        }else if (mindepth>depth){
            mindepth=depth;
            minnum=1;
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
    int temp,k;
    for (int i=0; i<n; i++) {
        cin>>temp;
        for (int j=0; j<temp; j++) {
            cin>>k;
            v[i].push_back(k);
        }
    }
    dfs(0, 0);
    cout<<fixed<<setprecision(4)<<p*pow(1+r/100, mindepth);
    cout<<" "<<minnum<<endl;
    return 0;
}
