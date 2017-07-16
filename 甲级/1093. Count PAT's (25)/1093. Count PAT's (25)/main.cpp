//
//  main.cpp
//  1093. Count PAT's (25)
//
//  Created by 祝暾 on 2017/7/16.
//  Copyright © 2017年 祝暾. All rights reserved.
//

//
//  main.cpp
//  1040
//
//  Created by 祝暾 on 2017/5/5.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
int main(int argc, const char * argv[]) {
    string str;
    long long pat=0,at=0,t=0;
    cin>>str;
    for (int i=(int)str.length()-1; i>=0; i--) {
        if (str[i]=='T') {
            t++;
        }else if(str[i]=='A'){
            at+=t;
        }else{
            pat+=at;
        }
    }
    pat%=1000000007;
    cout<<pat<<endl;
    return 0;
}

