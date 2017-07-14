//
//  main.cpp
//  1049. Counting Ones (30)
//
//  Created by 祝暾 on 2017/7/14.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
using namespace std;
int main() {
    int n, left = 0, right = 0, flag = 1, now = 1, ans = 0;
    cin>>n;
    while(n / flag) {
        left = n / (flag * 10);
        now = n / flag % 10;
        right = n % flag;
        if(now == 0) ans += left * flag;
        else if(now == 1) ans += left * flag + right + 1;
        else ans += (left + 1) * flag;
        flag = flag * 10;
    }
    cout<<ans<<endl;
    return 0;
}
