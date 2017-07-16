//
//  main.cpp
//  1084. Broken Keyboard (20)
//
//  Created by 祝暾 on 2017/7/16.
//  Copyright © 2017年 祝暾. All rights reserved.
//
//
//  main.cpp
//  1029
//
//  Created by 祝暾 on 2017/5/1.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
int main(int argc, const char * argv[]) {
    string in,out;
    int i=0,j=0,len;
    cin>>in>>out;
    len=(int)in.length();
    string bad;
    for (; i<len; i++) {
        if (in[i]==out[j]) {
            j++;
        }else{
            if (in[i]<='z'&&in[i]>='a') {
                in[i]-=32;
            }
            if (bad.find(in[i])==string::npos) {
                bad+=in[i];
            }
        }
    }
    cout<<bad<<endl;
    return 0;
}
/*
 7_This_is_a_test
 hssaes
 _hs_s_a_es
 */
