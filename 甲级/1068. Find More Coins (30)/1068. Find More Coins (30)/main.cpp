//
//  main.cpp
//  1068. Find More Coins (30)
//
//  Created by 祝暾 on 2017/7/27.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#define maxn 10010
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int dp[maxn];
int w[maxn];
bool choice[maxn][maxn];
int main(int argc, const char * argv[]) {
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++) {
        cin>>w[i];
    }
    sort(w+1, w+n+1, cmp);
    for (int i=1; i<=n; i++) {
        for (int j=m; j>=w[i]; j--) {
            if (dp[j]<=dp[j-w[i]]+w[i]) {
                dp[j]=dp[j-w[i]]+w[i];
                choice[i][j]=true;
            }
        }
    }
    if (dp[m]!=m) {
        cout<<"No Solution"<<endl;
    }else{
        int index=m,before=n;
        vector<int> arr;
        while (index>0) {
            if (choice[before][index]) {
                arr.push_back(w[before]);
                index-=w[before];
            }
            before--;
        }
        for (int i=0; i<arr.size(); i++) {
            cout<<arr[i];
            if (i!=arr.size()-1) {
                cout<<" ";
            }else{
                cout<<endl;
            }
        }
    }
    
    return 0;
}
