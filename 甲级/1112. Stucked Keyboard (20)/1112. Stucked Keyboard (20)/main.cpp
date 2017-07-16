//
//  main.cpp
//  1112. Stucked Keyboard (20)
//
//  Created by 祝暾 on 2017/7/16.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
int arr[256];
int main(int argc, const char * argv[]) {
    string s,ans;
    int k;
    cin>>k>>s;
    int temp=1;
    for (int i=1; i<s.size(); i++) {
        if (s[i]==s[i-1]) {
            temp++;
        }else {
            if (temp%k!=0) {
                arr[s[i-1]]=2;
            }else if (temp%k==0&&arr[s[i-1]]!=2) {
                arr[s[i-1]]=1;
            }
            temp=1;
        }
        
    }
    if (temp%k==0&&arr[s[s.size()-1]]!=2) {
        arr[s[s.size()-1]]=1;
    }
    if (temp%k!=0) {
        arr[s[s.size()-1]]=2;
    }else if (temp%k==0&&arr[s[s.size()-1]]!=2) {
        arr[s[s.size()-1]]=1;
    }

    bool flag[256]={false};
    for (int i=0; i<s.size(); i++) {
        if (arr[s[i]]==1&&flag[s[i]]==false) {
            cout<<s[i];
            flag[s[i]]=true;
        }
    }
    cout<<endl;

    temp=1;
    for (int i=0; i<s.size(); i++) {
        if (arr[s[i]]==1&&temp==k) {
            cout<<s[i];
            temp=1;
        }else if (arr[s[i]]==1){
            temp++;
        }else{
            cout<<s[i];
        }
    }
    cout<<endl;
    return 0;
}
