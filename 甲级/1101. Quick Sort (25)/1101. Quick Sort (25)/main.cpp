//
//  main.cpp
//  1101. Quick Sort (25)
//
//  Created by 祝暾 on 2017/7/16.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int a[100001], b[100001];
int vec[100001];
int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>a[i];
        b[i]=a[i];
    }
    sort(a, a+n);
    int maxn=0;
    int cnt=0;
    for (int i=0; i<n; i++) {
        if (b[i]>maxn) {
            if (a[i]==b[i]) {
                vec[cnt++]=a[i];
            }
            maxn=b[i];
        }
    }
    cout<<cnt<<endl;
    for (int i=0; i<cnt; i++) {
        if (i==0) {
            cout<<vec[i];
        }else{
            cout<<" "<<vec[i];
        }
    }
    cout<<endl;
    return 0;
}
