//
//  main.cpp
//  1111. Online Map (30)
//
//  Created by 祝暾 on 2017/7/19.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define maxn 510
#define inf 0x3f3f3f3f
using namespace std;
int n,m;
int e[maxn][maxn],dis[maxn],Time[maxn],w[maxn][maxn],dispre[maxn],weight[maxn];
bool visit[maxn];
vector<int>dispath,timepath,temppath,timepre[maxn];
int start,dest,minnode=inf;

void dfsdist(int v){
    dispath.push_back(v);
    if (v==start) {
        return;
    }
    dfsdist(dispre[v]);
}
void dfstimepath(int v){
    temppath.push_back(v);
    if (v==start) {
        if (temppath.size()<minnode) {
            minnode=(int)temppath.size();
            timepath=temppath;
        }
        temppath.pop_back();
        return;
    }
    for (int i=0; i<timepre[v].size(); i++) {
        dfstimepath(timepre[v][i]);
    }
    temppath.pop_back();
}
int main(int argc, const char * argv[]) {
    cin>>n>>m;
    memset(e, inf, sizeof(int)*maxn*maxn);
    memset(dis, inf, sizeof(int)*maxn);
    memset(Time, inf, sizeof(int)*maxn);
    memset(w, inf, sizeof(int)*maxn*maxn);
    memset(weight, inf, sizeof(int)*maxn);
    int v1,v2,one_way,lenth,t;
    for (int i=0; i<m; i++) {
        cin>>v1>>v2>>one_way>>lenth>>t;
        e[v1][v2]=lenth;
        w[v1][v2]=t;
        if (!one_way) {
            e[v2][v1]=lenth;
            w[v2][v1]=t;
        }
    }
    cin>>start>>dest;

    dis[start]=0;
    for (int i=0; i<n; i++) {
        int k=-1,mindis=inf;
        for (int j=0; j<n; j++) {
            if (!visit[j]&&mindis>dis[j]) {
                mindis=dis[j];
                k=j;
            }
        }
        if (k==-1) {
            break;
        }
        visit[k]=true;
        for (int j=0; j<n; j++) {
            if (!visit[j]&&e[k][j]!=inf) {
                if (dis[j]>dis[k]+e[k][j]) {
                    dis[j]=dis[k]+e[k][j];
                    dispre[j]=k;
                    weight[j]=weight[k]+w[k][j];
                }else if (dis[j]==dis[k]+e[k][j]&&weight[j]>weight[k]+w[k][j]){
                    dispre[j]=k;
                    weight[j]=weight[k]+w[k][j];
                }
            }
        }
    }
    dfsdist(dest);
    Time[start]=0;
    memset(visit, false, sizeof(bool)*maxn);
    for (int i=0; i<n; i++) {
        int k=-1,mindis=inf;
        for (int j=0; j<n; j++) {
            if (!visit[j]&&mindis>Time[j]) {
                mindis=Time[j];
                k=j;
            }
        }
        if (k==-1) {
            break;
        }
        visit[k]=true;
        for (int j=0; j<n; j++) {
            if (!visit[j]&&w[k][j]!=inf) {
                if (Time[j]>Time[k]+w[k][j]) {
                    Time[j]=Time[k]+w[k][j];
                    timepre[j].clear();
                    timepre[j].push_back(k);
                }else if (Time[j]==Time[k]+w[k][j]){
                    timepre[j].push_back(k);
                }
            }
        }
    }
    dfstimepath(dest);
    cout<<"Distance = "<<dis[dest];
    if (dispath==timepath) {
        cout<<"; Time = "<<Time[dest]<<": ";
    }else{
        cout<<": ";
        for (int i=(int)dispath.size()-1; i>0; i--) {
            cout<<dispath[i]<<" -> ";
        }
        cout<<dispath[0]<<endl;
        cout<<"Time = "<<Time[dest]<<": ";
    }
    for (int i=(int)timepath.size()-1; i>0; i--) {
        cout<<timepath[i]<<" -> ";
    }
    cout<<timepath[0]<<endl;

    return 0;
}
