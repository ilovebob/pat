//
//  main.cpp
//  1023. Have Fun with Numbers (20)
//
//  Created by 祝暾 on 2017/7/13.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
char num[22];
int c=0;
int flag[10]={0};
int flag2[10]={0};

int main(int argc, const char * argv[]) {
    scanf("%s",num);
    for (int i=(int)strlen(num)-1; i>=0; i--) {
        int temp=num[i]-'0';
        flag[temp]++;
        temp=temp*2+c;
        c=temp/10;
        temp%=10;
        num[i]=temp+'0';
        flag[temp]--;
    }
    int flag1=0;
    for (int i=0; i<10; i++) {
        if (flag[i]!=0) {
            flag1=1;
            break;
        }
    }
    if (c==1||flag1==1) {
        cout<<"No"<<endl;
    }else{
        cout<<"Yes"<<endl;
    }
    if (c) {
        cout<<c;
    }
    for (int i=0; i<(int)strlen(num); i++) {
        cout<<num[i];
    }
    cout<<endl;
    return 0;
}
