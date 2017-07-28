//
//  main.cpp
//  1030. Travel Plan (30)
//
//  Created by 祝暾 on 2017/7/18.
//  Copyright © 2017年 祝暾. All rights reserved.
//  where N (<=500) is the number of cities (and hence the cities are numbered from 0 to N-1); M is the number of highways; S and D are the starting and the destination cities, respectively.

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define maxn 510
#define inf 0x3f3f3f3f
using namespace std;
int n,m,s,d;
int graph[maxn][maxn],dis[maxn],cost[maxn][maxn];
bool visit[maxn];
int mincost=inf;
vector<int>pre[maxn];
vector<int>path,temppath;
void dfs(int v){
    if (s==v) {
        temppath.push_back(v);
        int tempcost=0;
        for (int i=(int)temppath.size()-1; i>0; i--) {
            tempcost+=cost[temppath[i]][temppath[i-1]];
        }
        if (tempcost<mincost) {
            mincost=tempcost;
            path=temppath;
        }
        temppath.pop_back();
        return;
    }
    temppath.push_back(v);
    for (int i=0; i<pre[v].size(); i++) {
        dfs(pre[v][i]);
    }
    temppath.pop_back();
}
int main(int argc, const char * argv[]) {
    cin>>n>>m>>s>>d;
    int a,b;
    memset(graph, inf, sizeof(int)*maxn*maxn);
    memset(cost, inf, sizeof(int)*maxn*maxn);
    memset(dis, inf, sizeof(int)*maxn);
    memset(visit, false, sizeof(bool)*maxn);
    for (int i=0; i<m; i++) {
        cin>>a>>b;
        cin>>graph[a][b]>>cost[a][b];
        graph[b][a]=graph[a][b];
        cost[b][a]=cost[a][b];
    }
    dis[s]=0;
    pre[s].push_back(s);
    for (int i=0; i<n; i++) {
        int k=-1,mindis=inf;
        for (int j=0; j<n; j++) {
            if (mindis>dis[j]&&!visit[j]) {
                mindis=dis[j];
                k=j;
            }
        }
        if (k==-1) {
            break;
        }
        visit[k]=true;
        for (int j=0; j<n; j++) {
            if (!visit[j]&&graph[k][j]!=inf) {
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
    dfs(d);
    for (int i=(int)path.size()-1; i>=0; i--) {
        cout<<path[i]<<" ";
    }
    cout<<dis[d]<<" "<<mincost<<endl;
    
    return 0;
}
