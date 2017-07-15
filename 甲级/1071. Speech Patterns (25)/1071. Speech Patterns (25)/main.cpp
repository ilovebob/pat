//
//  main.cpp
//  1071. Speech Patterns (25)
//
//  Created by 祝暾 on 2017/7/15.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <map>
#include <string>
#include <cctype>
using namespace std;
int main() {
    string s, t;
    getline(cin, s);
    map<string, int> m;
    for (int i=0;i<s.length();i++) {
        if (isalnum(s[i])) {
            s[i]=tolower(s[i]);
            t+=s[i];
        }else{
            if (t.length()) {
                m[t]++;
            }
            t="";
        }
    }
    if (t.length()) {
        m[t]++;
    }
    int max = 0;
    for(map<string, int>::iterator it = m.begin(); it != m.end(); it++) {
        if(it->second > max) {
            max = it->second;
            t = it->first;
        }
    }
    cout << t << " " << max;
    return 0;
}
