//
//  main.cpp
//  1096. Consecutive Factors (20)
//
//  Created by 祝暾 on 2017/7/16.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int n;
    cin>>n;
    int max = sqrt(n);
    for(int len = 12; len >= 1; len--) {
        for(int start = 2; start <= max; start++) {
            long long int ans = 1;
            for(int i = start; i - start < len; i++){
                ans *= i;
            }
            if(n % ans == 0) {
                cout<<len<<endl;
                cout<<start;
                for(int i = start + 1; i - start < len; i++){
                    cout<<"*"<<i;
                }
                cout<<endl;
                return 0;
            }
        }
    }
    printf("1\n%d", n);
    return 0;
}
