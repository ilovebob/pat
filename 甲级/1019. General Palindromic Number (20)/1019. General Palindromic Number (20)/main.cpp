//
//  main.cpp
//  1019. General Palindromic Number (20)
//
//  Created by 祝暾 on 2017/7/12.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
using namespace std;
int res[32];
int k=0;
int n,b;
int convertToRadix(int s,int radix){
    int ans=0;
    while (s) {
        ans=ans*radix+s%radix;
        res[k++]=s%radix;
        s=s/radix;
    }
    if (ans==n) {
        return 1;
    }else{
        return 0;
    }
}
int main(int argc, const char * argv[]) {
    cin>>n>>b;
    if (convertToRadix(n, b)==1) {
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    k--;
    for (; k>=1; k--) {
        cout<<res[k]<<" ";
    }
    cout<<res[0]<<endl;
    return 0;
}
