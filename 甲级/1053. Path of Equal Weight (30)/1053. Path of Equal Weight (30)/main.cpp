//
//  main.cpp
//  1053. Path of Equal Weight (30)
//
//  Created by 祝暾 on 2017/7/27.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Node {
    int w;
    vector<int> child;
};
int target;
vector<Node>v;
vector<int>path;
bool cmp(int a,int b){
    return v[a].w>v[b].w;
}
void dfs(int index,int nodenum,int sum){
    if (sum>target) {
        return;
    }else if (sum==target){
        if (v[index].child.size()!=0) {
            return;
        }
        for (int i=0; i<nodenum; i++) {
            cout<<v[path[i]].w;
            if (i!=nodenum-1) {
                cout<<" ";
            }else{
                cout<<endl;
            }
        }
        return;
    }else{
        for (int i=0; i<v[index].child.size(); i++) {
            int temp=v[index].child[i];
            path[nodenum]=temp;
            dfs(temp, nodenum+1, sum+v[temp].w);
        }
    }
};
int main(int argc, const char * argv[]) {
    int n,m;
    cin>>n>>m>>target;
    v.resize(n);
    path.resize(n);
    for (int i=0; i<n; i++) {
        cin>>v[i].w;
    }
    for (int i=0; i<m; i++) {
        int temp,k;
        cin>>temp>>k;
        v[temp].child.resize(k);
        for (int j=0; j<k; j++) {
            cin>>v[temp].child[j];
        }
        sort(v[temp].child.begin(), v[temp].child.end(), cmp);
    }
    dfs(0, 1, v[0].w);
    return 0;
}
