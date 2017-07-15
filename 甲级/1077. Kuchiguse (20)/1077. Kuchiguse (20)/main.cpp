//
//  main.cpp
//  1077. Kuchiguse (20)
//
//  Created by 祝暾 on 2017/7/15.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
int main(int argc, const char * argv[]) {
    string ans;
    int n;
    cin>>n;
    getchar();
    for (int i=0; i<n; i++) {
        string s;
        getline(cin, s);
        for (int j=0; j<s.length()/2; j++) {
            swap(s[j], s[s.length()-1-j]);
        }
        if (i==0) {
            ans=s;
            continue;
        }else{
            int minlen=s.length()<ans.length()?s.length():ans.length();
            for (int j=0; j<minlen; j++) {
                if (ans[j]!=s[j]) {
                    ans=ans.substr(0,j);
                    break;
                }
            }
        }
        if (ans.length()==0) {
            break;
        }
    }
    if (ans.length()==0) {
        cout<<"nai"<<endl;
    }else{
        for (int i=ans.length()-1; i>=0; i--) {
            cout<<ans[i];
        }
        cout<<endl;
    }
    return 0;
}
