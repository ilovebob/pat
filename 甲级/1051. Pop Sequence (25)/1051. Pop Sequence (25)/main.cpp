//
//  main.cpp
//  1051. Pop Sequence (25)
//
//  Created by 祝暾 on 2017/7/25.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstring>
using namespace std;
bool num[1001];
int main(int argc, const char * argv[]) {
    int m,n,k;
    cin>>m>>n>>k;
    for (int i=0; i<k; i++) {
        memset(num, false, sizeof(bool)*1001);
        int temp,maxn=0;
        bool flag=true;
        for (int j=0; j<n; j++) {
            cin>>temp;
            num[temp]=true;
            if (temp>j+m) {
                flag=false;
            }
            if (temp>maxn) {
                maxn=temp;
            }else{
                for (int l=temp+1; l<maxn; l++) {
                    if (!num[l]) {
                        flag=false;
                    }
                }
            }
            
        }
        if (flag) {
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
        
    }
    return 0;
}
