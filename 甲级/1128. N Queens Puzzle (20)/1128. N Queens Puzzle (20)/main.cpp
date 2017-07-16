//
//  main.cpp
//  1128. N Queens Puzzle (20)
//
//  Created by 祝暾 on 2017/7/16.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int main(int argc, const char * argv[]) {
    int n,k;
    cin>>k;
    for (int i=0; i<k; i++) {
        cin>>n;
        bool ans=true;
        vector<int> a(n);
        for (int j=0; j<n; j++) {
            cin>>a[j];
            for (int m=0; m<j; m++) {
                if (a[j]==a[m]||abs(a[j]-a[m])==abs(j-m)) {
                    ans=false;
                }
            }
        }
        cout << (ans == true ? "YES\n" : "NO\n");
    }
    return 0;
}
