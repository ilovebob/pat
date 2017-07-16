//
//  main.cpp
//  1082. Read Number in Chinese (25)
//
//  Created by 祝暾 on 2017/7/15.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
string c[5]= {"Shi", "Bai", "Qian", "Wan", "Yi"};
string t[10]= {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
int a, flag = 0;
void read(int num){
    int flag1 = 0, flag2 = 0, flag3 = 0;
    if(num / 1000){
        cout<<t[num / 1000]<<" "<<c[2];
        flag1 = 1;
    }
    if(flag == 1 && flag1 == 0){
        cout<<"ling ";
    }
    if(num / 100 % 10){
        if(flag1 == 1){
            cout<<" ";
        }
        cout<<t[num / 100%10]<<" "<<c[1];
        flag2 = 1;
    }
    if(flag1 == 1 && flag2 == 0 && num % 100 != 0){
        cout<<" ling";
    }
    if(num / 10 % 10) {
        if(flag1 == 1 || flag2 == 1){
            cout<<" ";
        }
        cout<<t[num / 10 % 10]<<" "<<c[0];
        flag3 = 1;
    }
    if(flag2 == 1 && flag3 == 0 && num % 10 != 0){
        cout<<" ling";
    }
    if(num % 10) {
        if(flag1 == 1 || flag2 == 1 || flag3 == 1){
            cout<<" ";
        }
        cout<<t[num % 10];
    }
    
}
int main(int argc, const char * argv[]) {
    int flag1 = 0, flag2 = 0;
    cin>>a;
    if(a < 0) {
        cout<<"Fu ";
        a = 0 - a;
    }
    if(a == 0){
        cout<<"ling";
    }
    if(a > 99999999) {
        int temp = a / 100000000;
        read(temp);
        cout<<" "<<c[4];
        a = a % 100000000;
        flag1 = 1;
    }
    if(a > 9999) {
        int temp = a / 10000;
        if(flag1 == 1) {
            cout<<" ";
            flag = 1;
        }
        read(temp);
        cout<<" "<<c[3];
        a = a % 10000;
        flag2 = 1;
    }
    flag = 0;
    if((flag1 == 1 || flag2 == 1) && a != 0) {
        flag = 1;
        cout<<" ";
    }
    read(a);
    cout<<endl;
    return 0;
}
