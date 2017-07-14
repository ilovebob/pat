//
//  main.cpp
//  1048. Find Coins (25)
//
//  Created by 祝暾 on 2017/7/14.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int n,m;
    cin>>n>>m;
    int temp;
    int coin[1001]={0};
    for (int i=0; i<n; i++) {
        cin>>temp;
        coin[temp]++;
    }
    int i;
    for (i=0; i<=m/2+1; i++) {
        if (coin[i]>0) {
            coin[i]--;
            if (coin[m-i]>0) {
                cout<<i<<" "<<m-i<<endl;
                return 0;
            }
            coin[i]++;
        }
    }
    if (i>m/2) {
        cout<<"No Solution"<<endl;
    }
    return 0;
}
