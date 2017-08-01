//
//  main.cpp
//  1107. Social Clusters (30)
//
//  Created by 祝暾 on 2017/7/31.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#define maxn 1010
using namespace std;
vector<int>ans;
int pre[maxn];
int cmp(int a, int b){
    return a>b;
}
int find(int x)
{
    int r=x;
    while (pre[r]!=r){
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

void join(int x,int y)
{
    int fx=find(x),fy=find(y);
    if(fx!=fy)
        pre[fx]=fy;
}
int main(int argc, const char * argv[]) {
    int n, k, t, cnt=0;
    int course[maxn]={0};
    scanf("%d",&n);
    ans.resize(n+1);
    for (int i=1; i<=n; i++) {
        pre[i]=i;
    }
    for (int i=1; i<=n; i++) {
        scanf("%d:",&k);
        for (int j=0; j<k; j++) {
            scanf("%d",&t);
            if (course[t]==0) {
                course[t]=i;
            }
            join(i, find(course[t]));
        }
    }
    for (int i=1; i<=n; i++) {
        ans[find(i)]++;
    }
    for (int i=1; i<=n; i++) {
        if (ans[i]!=0) {
            cnt++;
        }
    }
    printf("%d\n", cnt);
    sort(ans.begin(), ans.end(), cmp);
    for (int i=0; i<cnt; i++) {
        if (i!=cnt-1) {
            printf("%d ",ans[i]);
        }else{
            printf("%d\n",ans[i]);
        }
    }
    return 0;
}
