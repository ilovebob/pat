//
//  main.cpp
//  1004. Counting Leaves (30)
//
//  Created by 祝暾 on 2017/7/19.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int level[100], book[100], maxlevel = -1;
vector<int> v[100];
void BFS(){
    queue<int> q;
    q.push(1);
    level[1]=0;
    while (!q.empty()) {
        int index=q.front();
        q.pop();
        maxlevel=max(level[index], maxlevel);
        if (!v[index].size()) {
            book[level[index]]++;
        }
        for (int i=0; i<v[index].size(); i++) {
            q.push(v[index][i]);
            level[v[index][i]]=level[index]+1;
        }
    }
}
void DFS(int index, int level) {
    if(v[index].size() == 0) {
        book[level]++;
        maxlevel = max(maxlevel, level);
        return ;
    }
    for(int i = 0; i < v[index].size(); i++)
        DFS(v[index][i], level + 1);
}
int main() {
    int n, m, k, node, c;
    cin>>n>>m;
    for(int i = 0; i < m; i++) {
        cin>>node>>k;
        for(int j = 0; j < k; j++) {
            cin>>c;
            v[node].push_back(c);
        }
    }
    //BFS();
    DFS(1, 0);
    cout<<book[0];
    for(int i = 1; i <= maxlevel; i++){
        cout<<" "<<book[i];
    }
    cout<<endl;
    return 0;
}
