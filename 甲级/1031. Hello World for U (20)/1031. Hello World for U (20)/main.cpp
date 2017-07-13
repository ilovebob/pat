//
//  main.cpp
//  1031. Hello World for U (20)
//
//  Created by 祝暾 on 2017/7/13.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;
char pri[27][28];
int main(int argc, const char * argv[]) {
    memset(pri, ' ', sizeof(pri));
    string s;
    int n1,n2;
    cin>>s;
    n1=((int)s.length()+2)/3;
    n2=(int)s.length()-2*n1+2;
    for (int i=0; i<n1; i++) {
        pri[i][0]=s[i];
    }
    int j=0;
    for (int i=1; i<n2; i++) {
        pri[n1-1][i]=s[n1+j++];
    }
    j=0;
    for (int i=n1-2; i>=0; i--) {
        pri[i][n2-1]=s[n1+n2-1+j++];
    }
    for (int i=0; i<n1; i++) {
        for (int j=0; j<n2; j++) {
            cout<<pri[i][j];
        }
        cout<<endl;
    }
    return 0;
}
