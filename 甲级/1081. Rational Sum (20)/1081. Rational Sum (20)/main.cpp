//
//  main.cpp
//  1081. Rational Sum (20)
//
//  Created by 祝暾 on 2017/7/15.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
long long gcd(long long a, long long b) {
    return b == 0 ? abs(a) : gcd(b, a % b);
}
int main() {
    long long n, a, b, suma = 0, sumb = 1, gcdvalue;
    cin>>n;
    for(int i = 0; i < n; i++) {
        scanf("%lld/%lld", &a, &b);
        gcdvalue = gcd(a, b);
        a = a / gcdvalue;
        b = b / gcdvalue;
        suma = a * sumb + suma * b;
        sumb = b * sumb;
        gcdvalue = gcd(suma, sumb);
        sumb = sumb / gcdvalue;
        suma = suma / gcdvalue;
    }
    long long integer = suma / sumb;
    suma = suma - (sumb * integer);
    if(integer != 0) {
        cout<<integer;
        if(suma != 0){
            cout<<" ";
        }
    }
    if(suma != 0)
        cout<<suma<<"/"<<sumb<<endl;
    if(integer == 0 && suma == 0)
        cout<<"0"<<endl;
    return 0;
}
