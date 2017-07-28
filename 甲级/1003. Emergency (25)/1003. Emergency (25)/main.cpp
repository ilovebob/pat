//
//  main.cpp
//  1003. Emergency (25)
//
//  Created by 祝暾 on 2017/5/8.
//  Copyright © 2017年 祝暾. All rights reserved.
//  Dijkstra!!

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define maxn 510
#define INF 0x3f3f3f3f
int n,m,c1,c2;
int graph[maxn][maxn];
bool vis[maxn];
int num[maxn];
int dist[maxn];
int weight[maxn];
int w[maxn];
void dijkstra(int s){
    memset(dist, 0x3f, sizeof(int)*maxn);
    memset(vis, false, sizeof(vis));
    dist[s]=0;
    w[s]=weight[s];
    num[s]=1;
    for (int i=0; i<n; i++) {
        int k=-1,minv=INF;
        for (int j=0; j<n; j++) {
            if (!vis[j]&&dist[j]<minv) {
                k=j;
                minv=dist[j];
            }
        }
        if (k==-1) {
            break;
        }
        vis[k]=true;
        for (int j=0; j<n; j++) {
            if (!vis[j]&&graph[k][j]!=INF) {
                if (dist[k]+graph[k][j]<dist[j]) {
                    dist[j]=dist[k]+graph[k][j];
                    num[j]=num[k];
                    w[j]=w[k]+weight[j];
                }else if (dist[k]+graph[k][j]==dist[j]){
                    num[j]+=num[k];
                    if (w[k]+weight[j]>w[j]) {
                        w[j]=w[k]+weight[j];
                    }
                }
                
            }
        }
    }
}
int main(int argc, const char * argv[]) {
    int tmp1,tmp2;
    cin>>n>>m>>c1>>c2;
    for (int i=0; i<n; i++) {
        cin>>weight[i];
    }
    memset(graph, INF, sizeof(int)*maxn*maxn);
    for (int i=0; i<m; i++) {
        cin>>tmp1>>tmp2;
        cin>>graph[tmp1][tmp2];
        graph[tmp2][tmp1]=graph[tmp1][tmp2];
    }
    dijkstra(c1);
    cout<<num[c2]<<" "<<w[c2]<<endl;
    return 0;
}
