//
//  main.cpp
//  1021. Deepest Root (25)
//
//  Created by 祝暾 on 2017/7/31.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#define maxn 10010
using namespace std;
int n,maxdepth=0;
vector<vector<int>> v;
bool visit[maxn];
set<int> s;
vector<int> temp;
void dfs(int index,int depth){
    if (depth>maxdepth) {
        temp.clear();
        temp.push_back(index);
        maxdepth=depth;
    }else if (depth==maxdepth){
        temp.push_back(index);
    }
    visit[index]=true;
    for (int i=0; i<v[index].size(); i++) {
        if (!visit[v[index][i]]) {
            dfs(v[index][i], depth+1);
        }
    }
}
int main(int argc, const char * argv[]) {
    cin>>n;
    int a,b,cnt=0;
    v.resize(n+1);
    for (int i=1; i<n; i++) {
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int s1=0;
    for (int i=1; i<=n; i++) {
        if (!visit[i]) {
            dfs(i, 1);
            if (i==1) {
                for (int j=0; j<temp.size(); j++) {
                    s.insert(temp[j]);
                }
                s1=temp[0];
            }
            cnt++;
        }
    }
    if (cnt>=2) {
        cout<<"Error: "<<cnt<<" components"<<endl;
    }else{
        temp.clear();
        maxdepth=0;
        memset(visit, false, sizeof(bool)*maxn);
        dfs(s1, 1);
        for (int j=0; j<temp.size(); j++) {
            s.insert(temp[j]);
        }
        for (set<int>::iterator it=s.begin(); it!=s.end(); it++) {
            cout<<*it<<endl;
        }
    }
    return 0;
}
