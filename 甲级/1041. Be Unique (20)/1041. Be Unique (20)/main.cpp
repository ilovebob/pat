//
//  main.cpp
//  1041. Be Unique (20)
//
//  Created by 祝暾 on 2017/7/14.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
using namespace std;
int a[100001];
int num[10001]={0};
int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>a[i];
        num[a[i]]++;
    }
    int i=0;
    for (; i<n; i++) {
        if (num[a[i]]==1) {
            cout<<a[i]<<endl;
            break;
        }
    }
    if (i==n) {
        cout<<"None"<<endl;
    }
    return 0;
}
