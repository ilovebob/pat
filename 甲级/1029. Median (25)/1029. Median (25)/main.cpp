//
//  main.cpp
//  题目1004：Median
//
//  Created by 祝暾 on 2017/5/24.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <stdio.h>
using namespace std;
int main(int argc, const char * argv[]) {
    long int m,n,middle;
    long int arr1[1000001];
    cin>>m;
    for (long int i=0; i<m; i++) {
        cin>>arr1[i];
    }
    cin>>n;
    long int tmp,ans=0;
    long int j=0;
    middle=(double)(m+n)/2+0.5;
    if (n==0) {
        ans=arr1[middle-1];
    }else{
        for (long int i=0; i<n; i++) {
            cin>>tmp;
            if (middle<=0) {
                continue;
            }
            for (; j<m; j++) {
                if (arr1[j]<=tmp) {
                    middle--;
                    if (middle==0) {
                        ans=arr1[j];
                    }
                }else{
                    break;
                }
            }
            middle--;
            if (middle==0) {
                ans=tmp;
            }
        }

    }
    cout<<ans<<endl;

    return 0;
}
