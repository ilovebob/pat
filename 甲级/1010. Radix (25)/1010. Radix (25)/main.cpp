//
//  main.cpp
//  1010. Radix (25)
//
//  Created by 祝暾 on 2017/7/12.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
long long map[256];
string n1,n2;
int tag;
long long radix;

long long convertToTen(string s,long long radix){
    long long ans=0;
    for (int i=0; i<s.length(); i++) {
        ans=ans*radix+map[s[i]];
    }
    return ans;
}

int cmp(string n2,long long radix,long long t){
    long long num=convertToTen(n2, radix);
    if (num<0) {
        return 1;
    }
    else if (num<t){
        return -1;
    }
    return (t==num)?0:1;
}

long long binarySearch(string n2,long long left,long long right,long long t){
    long long mid;
    while (left<=right) {
        mid=(left+right)/2;
        int flag=cmp(n2,mid,t);
        if (flag==0) {
            return mid;
        }else if (flag==1){
            right=mid-1;
        }else{
            left=mid+1;
        }
    }
    return -1;
}

long long findLargestDigit(string n2){
    long long ans=-1;
    for (int i=0; i<n2.length(); i++) {
        if (map[n2[i]]>ans) {
            ans=map[n2[i]];
        }
    }
    return ans+1;
}


int main(int argc, const char * argv[]) {
    cin>>n1>>n2>>tag>>radix;
    for (char c='0'; c<='9'; c++) {
        map[c]=c-'0';
    }
    for (char c='a'; c<='z'; c++) {
        map[c]=c-'a'+10;
    }
    if (tag==2) {
        swap(n1, n2);
    }
    long long t=convertToTen(n1, radix);
    long long low=findLargestDigit(n2);
    long long high=max(low,t)+1;
    long long ans=binarySearch(n2, low, high, t);
    if (ans==-1) {
        cout<<"Impossible"<<endl;
    }else{
        cout<<ans<<endl;
    }
    return 0;
}
