//
//  main.cpp
//  1103. Integer Factorization (30)
//
//  Created by 祝暾 on 2017/7/29.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int n,k,p,maxfacsum=-1;
vector<int>v,ans,tempans;
void init(){
    for (int temp=0,index=1; temp<=n; index++) {
        v.push_back(temp);
        temp=pow(index, p);
    }
}
void dfs(int index,int tempk,int tempsum,int facsum){
    if (tempk==k&&tempsum==n) {
        if (facsum>maxfacsum) {
            maxfacsum=facsum;
            ans=tempans;
        }
    }
    if (tempk>k||tempsum>n) {
        return;
    }
    if (index>=1) {
        tempans.push_back(index);
        dfs(index, tempk+1, tempsum+v[index], facsum+index);
        tempans.pop_back();
        dfs(index-1, tempk, tempsum, facsum);
    }
}
int main(int argc, const char * argv[]) {
    cin>>n>>k>>p;
    init();
    dfs((int)v.size()-1, 0, 0, 0);
    if (maxfacsum==-1) {
        cout<<"Impossible"<<endl;
    }else{
        cout<<n<<" = ";
        for(int i = 0; i < ans.size(); i++) {
            if(i != 0){
                cout<<" + ";
            }
            cout<<ans[i]<<"^"<<p;
        }
        cout<<endl;
    }
    return 0;
}
