//
//  main.cpp
//  1126. Eulerian Path (25)
//
//  Created by 祝暾 on 2017/7/30.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>>v;
vector<bool>visit;
int cnt=0;
void dfs(int index){
    visit[index]=true;
    cnt++;
    for (int i=0; i<v[index].size(); i++) {
        if (!visit[v[index][i]]) {
            dfs(v[index][i]);
        }
    }
}
int main(int argc, const char * argv[]) {
    int n,m,odd=0;
    cin>>n>>m;
    v.resize(n+1);
    visit.resize(n+1);
    for (int i=0; i<m; i++) {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i=1; i<=n; i++) {
        cout<<v[i].size();
        if (i!=n) {
            cout<<" ";
        }else{
            cout<<endl;
        }
        if (v[i].size()%2==1) {
            odd++;
        }
    }
    dfs(1);
    if (cnt!=n||odd>2) {
        cout<<"Non-Eulerian"<<endl;
    }else if (odd==2){
        cout<<"Semi-Eulerian"<<endl;
    }else{
        cout<<"Eulerian"<<endl;
    }
    return 0;
}
