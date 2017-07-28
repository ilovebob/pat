//
//  main.cpp
//  1076. Forwards on Weibo (30)
//
//  Created by 祝暾 on 2017/7/27.
//  Copyright © 2017年 祝暾. All rights reserved.
//  BFS!

#include <iostream>
#include <vector>
#include <queue>
#define maxn 1010
using namespace std;
int n,l,m,k;
struct node {
    int id;
    int layer;
};
vector<vector<int>> v;
int bfs(node tnode){
    bool flag[maxn]={false};
    queue<node> q;
    q.push(tnode);
    flag[tnode.id]=true;
    int cnt=0;
    while (!q.empty()) {
        node top=q.front();
        q.pop();
        int topid=top.id;
        for (int i=0; i<v[topid].size(); i++) {
            int nextid=v[topid][i];
            if (!flag[nextid]&&top.layer<l) {
                node nextnode;
                nextnode.id=nextid;
                nextnode.layer=top.layer+1;
                q.push(nextnode);
                flag[nextid]=true;
                cnt++;
            }
        }
    }
    return cnt;
};
int main(int argc, const char * argv[]) {
    cin>>n>>l;
    v.resize(n+1);
    for (int i=0; i<n; i++) {
        cin>>m;
        int temp;
        for (int j=0; j<m; j++) {
            cin>>temp;
            v[temp].push_back(i+1);
        }
    }
    cin>>k;
    int tid;
    for (int i=0; i<k; i++) {
        cin>>tid;
        node tnode;
        tnode.id=tid;
        tnode.layer=0;
        int ans=bfs(tnode);
        cout<<ans<<endl;
    }
    return 0;
}
