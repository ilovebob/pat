//
//  main.cpp
//  1094. The Largest Generation (25)
//
//  Created by 祝暾 on 2017/7/28.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
#define maxn 101
using namespace std;
int n,m;
vector<int>v[maxn];
int layer[maxn];
void dfs(int index,int level){
    layer[level]++;
    for (int i=0; i<v[index].size(); i++) {
        dfs(v[index][i], level+1);
    }
}
int lev[maxn];
void bfs(){
    queue<int> q;
    q.push(1);
    lev[1] = 1;
    while (!q.empty()) {
        int index=q.front();
        q.pop();
        layer[lev[index]]++;
        for (int i=0; i<v[index].size(); i++) {
            lev[v[index][i]]=lev[index]+1;
            q.push(v[index][i]);
        }
        
    }
}
int main(int argc, const char * argv[]) {
    cin>>n>>m;
    int k;
    for (int i=0; i<m; i++) {
        int temp1,temp2;
        cin>>temp1>>k;
        for (int j=0; j<k; j++) {
            cin>>temp2;
            v[temp1].push_back(temp2);
        }
    }
    //dfs(1, 1);
    bfs();
    int maxnum=0,maxlevel=1;
    for (int i=0; i<100; i++) {
        if (layer[i]>maxnum) {
            maxnum=layer[i];
            maxlevel=i;
        }
    }
    cout<<maxnum<<" "<<maxlevel<<endl;
    return 0;
}
