//
//  main.cpp
//  1092. To Buy or Not to Buy (20)
//
//  Created by 祝暾 on 2017/7/16.
//  Copyright © 2017年 祝暾. All rights reserved.
//

//
//  main.cpp
//  1039
//
//  Created by 祝暾 on 2017/5/5.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
int main(int argc, const char * argv[]) {
    string a,b;
    int flag=1;
    int all=0;
    int num1[128]={0};
    int num2[128]={0};
    cin>>a>>b;
    for (int i=0; i<(int)a.length(); i++) {
        num1[(int)a[i]]++;
    }
    for (int i=0; i<(int)b.length(); i++) {
        num2[(int)b[i]]++;
    }
    for (int i=0; i<128; i++) {
        if (num1[i]<num2[i]) {
            flag=0;
        }
    }
    if (flag) {
        for (int i=0; i<128; i++) {
            all+=(num1[i]-num2[i]);
        }
        cout<<"Yes ";
    }else{
        for (int i=0; i<128; i++) {
            if ((num2[i]-num1[i])>0) {
                all+=(num2[i]-num1[i]);
            }
        }
        cout<<"No ";
    }
    cout<<all<<endl;
    
    return 0;
}

