//
//  main.cpp
//  1113. Integer Set Partition (25)
//
//  Created by 祝暾 on 2017/7/16.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
//#include <vector>
#include <algorithm>
using namespace std;
int num[100000];
int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>num[i];
    }
    sort(num, num+n);
    int ans=0;
    for (int i=0; i<n/2; i++) {
        ans+=abs(num[n-1-i]-num[i]);
    }
    if (n%2==0) {
        cout<<"0 "<<ans<<endl;;
    }else{
        cout<<"1 "<<ans+abs(num[n/2])<<endl;
    }
    return 0;
}
