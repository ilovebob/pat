//
//  main.cpp
//  1009. Product of Polynomials (25）
//
//  Created by 祝暾 on 2017/7/12.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <iomanip>
using namespace std;
double d[1001];
double a[2001]={0};
int fla[101];
int main(int argc, const char * argv[]) {
    int k1,k2,k3=0;
    int n;
    double an;
    //bool flag=true;
    cin>>k1;
    for (int i=0; i<k1; i++) {
        cin>>fla[i];
        cin>>d[fla[i]];
    }
    cin>>k2;
    for (int i=0; i<k2; i++) {
        cin>>n>>an;
        for (int i=0; i<k1; i++) {
            if (a[n+fla[i]]==0) {
                k3++;
            }
            a[n+fla[i]]+=d[fla[i]]*an;
            if (a[n+fla[i]]==0) {
                k3--;
            }
        }
    }
    cout<<k3<<" ";
    for (int i=2000; i>=0; i--) {
        if (a[i]==0) {
            continue;
        }
        //flag=false;
        k3--;
        if (k3) {
            cout<<setprecision(1)<<fixed<<i<<" "<<a[i]<<" ";
        }else{
            cout<<setprecision(1)<<fixed<<i<<" "<<a[i]<<endl;
        }
    }
    return 0;
}
