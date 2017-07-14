//
//  main.cpp
//  1059. Prime Factors (25)
//
//  Created by 祝暾 on 2017/7/15.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
bool flagArray[500000];
void init_prime(){
    int i,j;
    memset(flagArray, true, sizeof(flagArray));
    flagArray[0]=flagArray[1]=false;
    for( i = 2; i * i < 500000; i++)
        if(flagArray[i])
        {
            for( j = i; j*i <= 500000; j++)
            {
                flagArray[j*i] = false;
            }
        }
}
int main(int argc, const char * argv[]) {
    init_prime();
    long int a;
    cin>>a;
    cout<<a<<"=";
    if(a == 1){
        cout<<"1"<<endl;
        return 0;
    }
    bool state = false;
    for(int i = 2; a >= 2;i++) {
        int cnt = 0, flag = 0;
        while(flagArray[i]&& a % i == 0) {
            cnt++;
            a = a / i;
            flag = 1;
        }
        if(flag) {
            if(state) cout<<"*";
            cout<<i;
            state = true;
        }
        if(cnt >= 2)
            cout<<"^"<<cnt;
    }
    cout<<endl;
    return 0;
}
