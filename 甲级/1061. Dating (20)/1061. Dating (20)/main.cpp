//
//  main.cpp
//  1061. Dating (20)
//
//  Created by 祝暾 on 2017/7/15.
//  Copyright © 2017年 祝暾. All rights reserved.
//

//
//  main.cpp
//  1014
//
//  Created by 祝暾 on 2017/4/19.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    string str0,str1,str2,str3;
    cin>>str0>>str1>>str2>>str3;
    int i=0;
    string Day[7]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
    for (; i<str0.length()&&i<str1.length(); i++) {
        if (str0[i]==str1[i]&&str0[i]>='A'&&str0[i]<='G') {
            cout<<Day[str0[i]-'A'];
            break;
        }
    }
    for (i++; i<str0.length()&&i<str1.length(); i++) {
        if (str0[i]==str1[i]) {
            if (str0[i]>='A'&&str0[i]<='N') {
                cout<<" "<<(int)(str0[i]-'A'+10);
                break;
            }else if(str0[i]>='0'&&str0[i]<='9'){
                cout<<" 0"<<(int)(str0[i]-'0');
                break;
            }
        }
    }
    for (int i=0;  i<str2.length()&&i<str3.length(); i++) {
        if (str2[i]==str3[i]){
            if ((str2[i]>='a'&&str2[i]<='z')||(str2[i]>='A'&&str2[i]<='Z')) {
                if (i<10) {
                    cout<<":0"<<i<<endl;
                }else
                    cout<<":"<<i<<endl;
                break;
            }
        }
    }
    return 0;
}
