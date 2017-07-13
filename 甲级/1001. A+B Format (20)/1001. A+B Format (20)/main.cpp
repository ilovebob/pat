//
//  main.cpp
//  1001. A+B Format (20)
//
//  Created by 祝暾 on 2017/5/8.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
int main(int argc, const char * argv[]) {
    int a,b,c;
    cin>>a>>b;
    c=a+b;
    string str;
    str=to_string(c);
    int len=(int)str.length();
    if (str[0]=='-') {
        cout<<str[0];
        str=str.substr(1,len-1);
        len--;
    }
    int j=len%3;
    for (int i=0; i<len; i++) {
        if (j%3==1&&i!=len-1) {
            cout<<str[i]<<",";
        }else{
            cout<<str[i];
        }
        j=(j+2)%3;
    }
    cout<<endl;
    //cout<<str<<endl;
    return 0;
}
