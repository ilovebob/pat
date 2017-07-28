//
//  main.cpp
//  1040. Longest Symmetric String (25)
//
//  Created by 祝暾 on 2017/7/23.
//  Copyright © 2017年 祝暾. All rights reserved.
//。 DPDPDPDPDP！！

#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int dp[1010][1010];
int main(int argc, const char * argv[]) {
    string s;
    getline(cin, s);
    int ans=1;
    for (int i=0; i<s.length(); i++) {
        dp[i][i]=1;
        if (i<s.length()-1&&s[i]==s[i+1]) {
            dp[i][i+1]=1;
            ans=2;
        }
    }
    for (int L=3; L<=s.length(); L++) {
        for (int i=0; i+L-1<s.length(); i++) {
            int j=i+L-1;
            if (s[i]==s[j]&&dp[i+1][j-1]==1) {
                dp[i][j]=1;
                ans=L;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
