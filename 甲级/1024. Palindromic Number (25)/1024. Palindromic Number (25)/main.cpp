//
//  main.cpp
//  1024. Palindromic Number (25)
//
//  Created by 祝暾 on 2017/7/13.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string s;
void add(){
    string t=s;
    reverse(t.begin(), t.end());
    int c=0;
    for (int i=0 ; i<s.length(); i++) {
        int temp=s[i]+t[i]+c-2*'0';
        c=temp/10;
        temp%=10;
        s[i]=temp+'0';
    }
    if (c) {
        s+='1';
    }
    reverse(s.begin(), s.end());
}
int main(int argc, const char * argv[]) {
    int n,i;
    cin>>s>>n;
    for (i=0; i<n; i++) {
        string t=s;
        reverse(t.begin(), t.end());
        if (s==t) {
            break;
        }else add();
    }
    cout<<s<<endl;
    cout<<i<<endl;
    return 0;
}
