//
//  main.cpp
//  Spell It Right
//
//  Created by 祝暾 on 2017/7/12.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
string map[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
int main(int argc, const char * argv[]) {
    string s;
    cin>>s;
    int sum=0;
    for (int i=0; i<s.length(); i++) {
        sum+=s[i]-'0';
    }
    int a[4];
    int i=0;
    while (sum!=0) {
        a[i++]=sum%10;
        sum/=10;
    }
    i--;
    for (; i>=1; i--) {
        cout<<map[a[i]]<<" ";
    }
    cout<<map[a[i]]<<endl;
    return 0;
}
