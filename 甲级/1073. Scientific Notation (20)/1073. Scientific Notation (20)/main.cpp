//
//  main.cpp
//  1073. Scientific Notation (20)
//
//  Created by 祝暾 on 2017/7/15.
//  Copyright © 2017年 祝暾. All rights reserved.
//

//
//  main.cpp
//  1024
//
//  Created by 祝暾 on 2017/4/21.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

int main() {
    string str,str1,str2;
    int pose=0;
    int count=0;
    cin>>str;
    if (str[0]=='-') {
        cout<<"-";
    }
    pose=(int)str.find('E');
    str1=str.substr(pose+2,(int)str.length()-pose-1);
    count=pose-3;
    int j=atoi(str1.c_str());
    if (j==0) {
        for (int i=1; i<pose; i++) {
            cout<<str[i];
        }
    }else if (str[pose+1]=='-') {
        cout<<"0.";
        for (int i=1; i<j; i++) {
            cout<<"0";
        }
        cout<<str[1];
        for (int i=3; i<pose; i++) {
            cout<<str[i];
        }
    }
    else{
        cout<<str[1];
        if (j>=(pose-3)) {
            for (int i=3; i<pose; i++) {
                cout<<str[i];
                j--;
            }
            for (int i=0; i<j; i++) {
                cout<<"0";
            }
        }else{
            int i;
            for (i=3; i<j+3; i++) {
                cout<<str[i];
            }
            cout<<".";
            for (; i<pose; i++) {
                cout<<str[i];
            }
        }
        
    }
    cout<<endl;
    return 0;
}

