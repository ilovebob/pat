//
//  main.cpp
//  1118. Birds in Forest (25)
//
//  Created by 祝暾 on 2017/8/1.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#define maxn 10010
using namespace std;
int pre[maxn];
int ans[maxn];
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
void join(int a,int b){
    int fa=find(a);
    int fb=find(b);
    if (fa!=fb) {
        pre[fa]=fb;
    }
}
int main(int argc, const char * argv[]) {
    int n,k,q;
    scanf("%d",&n);
    for (int i=0; i<maxn; i++) {
        pre[i]=i;
    }
    for (int i=0; i<n; i++) {
        scanf("%d",&k);
        int temp1,temp2;
        scanf("%d",&temp1);
        visit[temp1]=true;
        for (int j=1; j<k; j++) {
            scanf("%d",&temp2);
            join(temp2, temp1);
            visit[temp2]=true;
        }
    }
    int cnt1=0,cnt2=0;
    for (int i=0; i<maxn; i++) {
        if (visit[i]) {
            ans[find(i)]++;
            cnt1++;
        }
    }
    for (int i=0; i<maxn; i++) {
        if (ans[i]!=0) {
            cnt2++;
        }
    }
    printf("%d %d\n",cnt2,cnt1);
    scanf("%d",&q);
    for (int i=0; i<q; i++) {
        int temp1,temp2;
        scanf("%d %d",&temp1,&temp2);
        if (find(temp1)==find(temp2)) {
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
    return 0;
}
