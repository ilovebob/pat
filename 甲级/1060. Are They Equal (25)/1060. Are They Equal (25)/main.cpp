//
//  main.cpp
//  1060. Are They Equal (25)
//
//  Created by 祝暾 on 2017/7/15.
//  Copyright © 2017年 祝暾. All rights reserved.
// 测试点：0 ， 0.0，0.0123，05.032，00.020

#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int n;
string changetostandrad(string s){
    stringstream ss;
    string ss1;
    string temp;
    int i=0;
    if (n==0) {
        temp="0*10^0";
    }else{
        temp="0.";
        if (s[0]=='0') {
            i=1;
            while (s[i]=='0') {
                i++;
            }
            if (i>=s.size()) {
                for (int j=0; j<n; j++) {
                    temp+='0';
                }
                temp+="*10^0";
                return temp;
            }
        }
        int a=0;
        if (s[i]=='.') {
            i++;
            while (s[i]=='0') {
                i++;
                a--;
            }
            if (i>=s.size()) {
                for (int j=0; j<n; j++) {
                    temp+='0';
                }
                temp+="*10^0";
                return temp;
            }
            for (int j=0; j<n; j++) {
                if (i>=s.size()) {
                    temp+="0";
                }else{
                    temp+=s[i];
                }
                i++;
            }
            temp+="*10^";
            ss<<a;
            ss>>ss1;
            temp+=ss1;
        }else{
            temp+=s[i++];
            a=1;
            bool flag=true;
            int j=0;
            for (; i<s.size(); i++) {
                if (s[i]!='.'&&flag) {
                    if (j<n-1) {
                        temp+=s[i];
                        j++;
                    }
                    a++;
                    
                }
                if (s[i]!='.'&&flag==false) {
                    if (j<n-1) {
                        temp+=s[i];
                        j++;
                    }else{
                        break;
                    }
                }
                if (s[i]=='.') {
                    flag=false;
                    continue;
                }
            }
            for (; j<n-1; j++) {
                temp+="0";
            }
            temp+="*10^";
            ss<<a;
            ss>>ss1;
            temp+=ss1;
        }

    }
    return temp;
}
int main(int argc, const char * argv[]) {
    string s1,s2;
    string ans1,ans2;
    cin>>n>>s1>>s2;
    ans1=changetostandrad(s1);
    ans2=changetostandrad(s2);
    if (ans1==ans2) {
        cout<<"YES "<<ans1<<endl;
    }else{
        cout<<"NO "<<ans1<<" "<<ans2<<endl;
    }
    return 0;
}
