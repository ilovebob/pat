//
//  main.cpp
//  1050. String Subtraction (20)
//
//  Created by 祝暾 on 2017/7/14.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <string>
#include <string.h>
using namespace std;
bool map[256]={false};
int main(int argc, const char * argv[]) {
    string s1,s2;
    getline(cin, s1);
    getline(cin, s2);
    for (int i=0; i<s2.length(); i++) {
        map[s2[i]]=true;
    }
    for (int i=0; i<s1.length(); i++) {
        if (map[s1[i]]==false) {
            cout<<s1[i];
        }
    }
    cout<<endl;
    return 0;
}
