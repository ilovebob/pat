//
//  main.cpp
//  1038. Recover the Smallest Number (30)
//
//  Created by 祝暾 on 2017/7/14.
//  Copyright © 2017年 祝暾. All rights reserved.
//
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool cmp(string a, string b) {
    return a + b < b + a; //The Key Code
}
string str[10010];
int main() {
    int n;
    cin>>n;
    for(int i = 0; i < n; i++)
        cin >> str[i];
    sort(str, str + n, cmp);
    string s;
    for(int i = 0; i < n; i++)
        s += str[i];
    while(s.length() != 0 && s[0] == '0')
        s.erase(s.begin());
    if(s.length() == 0)
        cout << 0;
    else
        cout << s;
    return 0;
}
