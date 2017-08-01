//
//  main.cpp
//  1130. Infix Expression (25)
//
//  Created by 祝暾 on 2017/7/30.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct node {
    string s;
    int left,right;
};
vector<node>v;
vector<bool> visit;
int root=0;
string dfs(int index){
    string temp;
    if (index!=root&&(v[index].left!=-1||v[index].right!=-1)) {
        temp="(";
    }
    if (v[index].left!=-1) {
        temp+=dfs(v[index].left);
    }
    temp+=v[index].s;
    if (v[index].right!=-1) {
        temp+=dfs(v[index].right);
    }
    if (index!=root&&(v[index].left!=-1||v[index].right!=-1)) {
        temp+=")";
    }
    return temp;
}
int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    v.resize(n+1);
    visit.resize(n+1);
    for (int i=1; i<=n; i++) {
        cin>>v[i].s>>v[i].left>>v[i].right;
        if (v[i].left!=-1) {
            visit[v[i].left]=true;
        }
        if (v[i].right!=-1) {
            visit[v[i].right]=true;
        }
    }
    for (int i=1; i<=n; i++) {
        if (!visit[i]) {
            root=i;
        }
    }
    string ans=dfs(root);
    cout<<ans<<endl;
    return 0;
}
