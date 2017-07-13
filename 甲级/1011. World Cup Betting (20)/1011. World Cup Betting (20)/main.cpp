//
//  main.cpp
//  1011. World Cup Betting (20)
//
//  Created by 祝暾 on 2017/7/12.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <iomanip>
using namespace std;
int main(int argc, const char * argv[]) {
    double w,t,l;
    double profit=1.0;
    for (int i=0; i<3; i++) {
        cin>>w>>t>>l;
        if (l>=t&&l>=w) {
            cout<<"L ";
            profit*=l;
            continue;
        }
        if (t>=w&&t>=l) {
            cout<<"T ";
            profit*=t;
            continue;
        }
        if (w>=t&&w>=l) {
            cout<<"W ";
            profit*=w;
            continue;
        }
    }
    cout<<setprecision(2)<<fixed<<(profit*0.65-1)*2<<endl;
    return 0;
}
