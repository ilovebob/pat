//
//  main.cpp
//  1114. Family Property (25)
//
//  Created by 祝暾 on 2017/7/16.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <algorithm>
#define maxn 10010
using namespace std;
struct Person {
    int id,fid,mid;
    int cid[10];
    int set,area;
}person[maxn/10];
struct Ans {
    int id,popu;
    double set,area;
    bool flag=false;
}ans[maxn];
int pre[maxn];
bool visit[maxn];
int find(int x){
    int r=x;
    while (r!=pre[r]) {
        r=pre[r];
    }
    int i=x,j;
    while (i!=r) {
        j=pre[i];
        pre[i]=r;
        i=j;
    }
    return r;
}
void join(int x,int y){
    int fx=find(x),fy=find(y);
    //int fx=pre[x],fy=pre[y];
    if (fx>fy) {
        pre[fx]=fy;
    }else if (fx<fy){
        pre[fy]=fx;
    }
}
bool cmp(Ans a,Ans b){
    if (a.area==b.area) {
        return a.id<b.id;
    }else{
        return a.area>b.area;
    }
}
int main(int argc, const char * argv[]) {
    int n,k,cnt=0;
    scanf("%d",&n);
    for (int i=0; i<maxn; i++) {
        pre[i]=i;
    }
    for (int i=0; i<n; i++) {
        scanf("%d %d %d %d",&person[i].id,&person[i].fid,&person[i].mid,&k);
        visit[person[i].id]=true;
        if (person[i].fid!=-1) {
            visit[person[i].fid]=true;
            join(person[i].fid, person[i].id);
        }
        if (person[i].mid!=-1) {
            visit[person[i].mid]=true;
            join(person[i].mid, person[i].id);
        }
        for (int j=0; j<k; j++) {
            scanf("%d",&person[i].cid[j]);
            visit[person[i].cid[j]]=true;
            join(person[i].cid[j], person[i].id);
        }
        scanf("%d %d",&person[i].set,&person[i].area);
    }
    for (int i=0; i<n; i++) {
        int id=find(person[i].id);
        ans[id].id=id;
        ans[id].set+=person[i].set;
        ans[id].area+=person[i].area;
        ans[id].flag=true;
    }
    for (int i=0; i<maxn; i++) {
        if (visit[i]) {
            ans[find(i)].popu++;
        }
        if (ans[i].flag) {
            cnt++;
        }
    }
    for (int i=0; i<maxn; i++) {
        if (ans[i].flag) {
            ans[i].set/=(double)ans[i].popu;
            ans[i].area/=(double)ans[i].popu;
        }
    }
    sort(ans, ans+maxn, cmp);
    printf("%d\n",cnt);
    for (int i=0; i<cnt; i++) {
        printf("%04d %d %.3f %.3f\n",ans[i].id,ans[i].popu,ans[i].set,ans[i].area);
    }
    return 0;
}
