//
//  main.cpp
//  1044. Shopping in Mars (25)
//
//  Created by 祝暾 on 2017/7/31.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector<int>sum,ans;
int n,m;
int twosearch(int i){
    int left=i,right=n;
    while (left<right) {
        int middle=(left+right)/2;
        if (sum[middle]-sum[i-1]>=m) {
            right=middle;
        }else{
            left=middle+1;
        }
    }
    return right;
}
int main(int argc, const char * argv[]) {
    scanf("%d%d", &n,&m);
    sum.resize(n+1);
    for (int i=1; i<=n; i++) {
        scanf("%d", &sum[i]);
        sum[i]+=sum[i-1];
    }
    int minans=sum[n];
    for (int i=1; i<=n; i++) {
        int j=twosearch(i),tempans=sum[j]-sum[i-1];
        if (tempans<=minans&&tempans>=m) {
            if (tempans<minans) {
                ans.clear();
                minans=tempans;
            }
            ans.push_back(i);
            ans.push_back(j);
        }
    }
    for (int i=0; i<ans.size(); i+=2) {
        printf("%d-%d\n", ans[i], ans[i+1]);
    }
    return 0;
}
