//
//  main.cpp
//  1087. All Roads Lead to Rome (30)
//
//  Created by 祝暾 on 2017/7/19.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#define maxn 205
#define inf 0x3f3f3f3f
using namespace std;
int n,k;
string start;
int happy[maxn],e[maxn][maxn],dis[maxn];
bool visit[maxn];
vector<int>pre[maxn];
vector<int>path,temppath;
int dif_routes=0,max_happy=0;
double max_aver_happy=0.0;
map<string,int> m;
map<int,string> m2;
void dfs(int v){
    temppath.push_back(v);
    if (v==1) {
        int value=0;
        for (int i=0; i<temppath.size(); i++) {
            value+=happy[temppath[i]];
        }
        double tempaver=1.0*value/(temppath.size()-1);
        if (value>max_happy) {
            max_happy=value;
            max_aver_happy=tempaver;
            path=temppath;
        }else if (value==max_happy&&tempaver>max_aver_happy){
            max_aver_happy=tempaver;
            path=temppath;
        }
        temppath.pop_back();
        dif_routes++;
        return;
    }
    for (int i=0; i<pre[v].size(); i++) {
        dfs(pre[v][i]);
    }
    temppath.pop_back();
}
int main(int argc, const char * argv[]) {
    cin>>n>>k>>start;
    memset(e, inf, sizeof(int)*maxn*maxn);
    memset(dis, inf, sizeof(int)*maxn);
    m[start]=1;
    m2[1]=start;
    for (int i=1; i<n; i++) {
        string temp;
        cin>>temp>>happy[i+1];
        m[temp]=i+1;
        m2[i+1]=temp;
    }
    for (int i=0; i<k; i++) {
        string a,b;
        int temp;
        cin>>a>>b>>temp;
        e[m[b]][m[a]]=e[m[a]][m[b]]=temp;//!!!ALLWAYS WRONG!!!REMENBER
    }
    dis[1]=0;
    for (int i=0; i<n; i++) {
        int k=-1,mindis=inf;
        for (int j=1; j<=n; j++) {
            if (dis[j]<mindis&&!visit[j]) {
                mindis=dis[j];
                k=j;
            }
        }
        if (k==-1) {
            break;
        }
        visit[k]=true;
        for (int j=1; j<=n; j++) {
            if (!visit[j]&&e[k][j]!=inf) {
                if (dis[j]>dis[k]+e[k][j]) {
                    dis[j]=dis[k]+e[k][j];
                    pre[j].clear();
                    pre[j].push_back(k);
                }else if (dis[j]==dis[k]+e[k][j]){
                    pre[j].push_back(k);
                }
            }
        }
    }
    int rom=m["ROM"];
    dfs(rom);
    cout<<dif_routes<<" "<<dis[rom]<<" "<<max_happy<<" "<<(int)max_aver_happy<<endl;
    for (int i=(int)path.size()-1; i>=1; i--) {
        cout<<m2[path[i]]<<"->";
    }
    cout<<"ROM"<<endl;
    return 0;
}
/*
6 7 HZH
ROM 200
PKN 40
GDN 55
PRS 95
BLN 100
ROM GDN 1
BLN ROM 1
HZH PKN 1
PRS ROM 2
BLN HZH 2
PKN GDN 1
HZH PRS 1
*/
