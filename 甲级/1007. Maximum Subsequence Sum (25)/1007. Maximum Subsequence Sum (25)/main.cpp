//
//  main.cpp
//  1007. Maximum Subsequence Sum (25)
//
//  Created by 祝暾 on 2017/7/19.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int main(int argc, const char * argv[]) {
    int n,sum=-1,temp=0,left=0,right=0,tempindex=0;
    bool flag=false;
    cin>>n;
    vector<int>v(n);
    for (int i=0; i<n; i++) {
        cin>>v[i];
        if (v[i]>=0) {
            flag=true;
        }
        temp+=v[i];
        if (temp>sum) {
            sum=temp;
            left=tempindex;
            right=i;
        }else if (temp<0){
            temp=0;
            tempindex=i+1;
        }
    }
    if (flag) {
        cout<<sum<<" "<<v[left]<<" "<<v[right]<<endl;
    }else{
        cout<<"0 "<<v[0]<<" "<<v[n-1]<<endl;
    }
    return 0;
}
