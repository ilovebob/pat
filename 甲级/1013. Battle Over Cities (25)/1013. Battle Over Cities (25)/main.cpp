//
//  main.cpp
//  1013. Battle Over Cities (25)
//
//  Created by 祝暾 on 2017/7/30.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <cstring>
#define maxn 1010
using namespace std;
bool v[maxn][maxn];
bool visit[maxn];
int n;
void dfs(int index){
    visit[index]=true;
    for (int i=1; i<=n; i++) {
        if (v[index][i]&&!visit[i]) {
            dfs(i);
        }
    }
}
int main(int argc, const char * argv[]) {
    int m,k,temp;
    cin>>n>>m>>k;
    int a,b;
    for (int i=0; i<m; i++) {
        cin>>a>>b;
        v[a][b]=v[b][a]=true;
    }
    for (int i=0; i<k; i++) {
        memset(visit, false, sizeof(bool)*maxn);
        cin>>temp;
        int ans=-1;
        visit[temp]=true;
        for (int j=1; j<=n; j++) {
            if (!visit[j]) {
                dfs(j);
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
