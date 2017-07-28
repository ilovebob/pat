//
//  main.cpp
//  1018. Public Bike Management (30)
//
//  Created by 祝暾 on 2017/7/18.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define MAXN 510
#define INF 0x3f3f3f3f
using namespace std;

int cmax, n, sp, m;
int minNeed = INF, minBack = INF;
int graph[MAXN][MAXN], dis[MAXN], weight[MAXN];
bool visit[MAXN];
vector<int> pre[MAXN];
vector<int> path, temppath;
void dfs(int s){
    if (s==0) {
        temppath.push_back(s);
        int need=0,back=0;
        for (int i=(int)temppath.size()-1; i>=0; i--) {
            if (weight[temppath[i]]>0) {
                back+=weight[temppath[i]];
            }else{
                if (back>(0-weight[temppath[i]])) {
                    back+=weight[temppath[i]];
                }else{
                    need+=(0-weight[temppath[i]]-back);
                    back=0;
                }
            }
        }
        if (minNeed>need) {
            minNeed=need;
            path=temppath;
            minBack=back;
        }else if(minNeed==need&&minBack>back){
            minBack=back;
            path=temppath;
        }
        temppath.pop_back();
        return;
    }
    temppath.push_back(s);
    for (int i=0; i<pre[s].size(); i++) {
        dfs(pre[s][i]);
    }
    temppath.pop_back();
}
int main(int argc, const char * argv[]) {
    cin>>cmax>>n>>sp>>m;
    memset(graph, INF, sizeof(int)*MAXN*MAXN);
    memset(dis, INF, sizeof(int)*MAXN);
    memset(visit, false, sizeof(bool)*MAXN);
    for (int i=1; i<=n; i++) {
        cin>>weight[i];
        weight[i]=weight[i]-cmax/2;
    }
    int a,b;
    for (int i=0; i<m; i++) {
        cin>>a>>b;
        cin>>graph[a][b];
        graph[b][a]=graph[a][b];
    }
    dis[0]=0;
    for (int i=0; i<=n; i++) {
        int k=-1,mindis=INF;
        for (int j=0; j<n; j++) {
            if (!visit[j]&&dis[j]<mindis) {
                k=j;
                mindis=dis[j];
            }
        }
        if (k==-1) {
            break;
        }
        visit[k]=true;
        for (int j=0; j<=n; j++) {
            if (!visit[j]&&graph[k][j]!=INF) {
                if (dis[j]>dis[k]+graph[k][j]) {
                    dis[j]=dis[k]+graph[k][j];
                    pre[j].clear();
                    pre[j].push_back(k);
                }else if (dis[j]==dis[k]+graph[k][j]){
                    pre[j].push_back(k);
                }
            }
        }
    }
    dfs(sp);
    cout<<minNeed<<" 0";
    for (int i=(int)path.size()-2; i>=0; i--) {
        cout<<"->"<<path[i];
    }
    cout<<" "<<minBack<<endl;
    return 0;
}
