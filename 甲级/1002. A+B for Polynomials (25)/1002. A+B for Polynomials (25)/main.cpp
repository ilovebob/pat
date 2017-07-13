//
//  main.cpp
//  1002. A+B for Polynomials (25)
//
//  Created by 祝暾 on 2017/5/8.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <stdio.h>
using namespace std;
int main(int argc, const char * argv[]) {
    int k1,k2;
    double a1[1001]={0},a2[1001]={0};
    cin>>k1;
    int n,totall=0;
    double a;
    for (int i=0; i<k1; i++) {
        cin>>n>>a;
        a1[n]=a;
    }
    cin>>k2;
    for (int i=0; i<k2; i++) {
        cin>>n>>a;
        a2[n]=a;
    }
    for (int i=0; i<1001; i++) {
        a1[i]+=a2[i];
        if (a1[i]!=0) {
            totall++;
        }
    }
    if (totall==0) {
        cout<<totall<<endl;
    }else{
        cout<<totall<<" ";
        for (int i=1000; i>=0; i--) {
            if (a1[i]!=0) {
                if (totall!=1) {
                    printf("%d %.1f ",i,a1[i]);
                }else{
                    printf("%d %.1f\n",i,a1[i]);
                }
                totall--;
            }
        }
    }
    
    return 0;
}
