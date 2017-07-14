//
//  main.cpp
//  1037. Magic Coupon (25)
//
//  Created by 祝暾 on 2017/7/14.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(int argc, const char * argv[]) {
    int nc,np;
    cin>>nc;
    vector<int>coupon1,coupon2;
    vector<int>product1,product2;
    int temp;
    for (int i=0; i<nc; i++) {
        cin>>temp;
        if (temp>0) {
            coupon1.push_back(temp);
        }else if (temp<0){
            temp=0-temp;
            coupon2.push_back(temp);
        }
    }
    cin>>np;
    for (int i=0; i<np; i++) {
        cin>>temp;
        if (temp>0) {
            product1.push_back(temp);
        }else if (temp<0){
            temp=0-temp;
            product2.push_back(temp);
        }
    }
    sort(coupon1.begin(), coupon1.end(), cmp);
    sort(coupon2.begin(), coupon2.end(), cmp);
    sort(product1.begin(), product1.end(), cmp);
    sort(product2.begin(), product2.end(), cmp);
    long long ans=0;
    for (int i=0; i<coupon1.size()&&i<product1.size(); i++) {
        ans+=coupon1[i]*product1[i];
    }
    for (int i=0; i<coupon2.size()&&i<product2.size(); i++) {
        ans+=coupon2[i]*product2[i];
    }
    cout<<ans<<endl;
    return 0;
}
/*
 5
 1 2 4 -1 -2
 4
 7 6 -2 -3
*/
