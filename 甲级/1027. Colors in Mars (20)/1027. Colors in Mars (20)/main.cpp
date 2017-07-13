//
//  main.cpp
//  1027. Colors in Mars (20)
//
//  Created by 祝暾 on 2017/7/13.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int n,temp1,temp2;
    char map[13]={'0','1','2','3','4','5','6','7','8','9','A','B','C'};
    cout<<"#";
    for (int i=0; i<3; i++) {
        cin>>n;
        temp1=n/13;
        temp2=n%13;
        cout<<map[temp1]<<map[temp2];
    }
    cout<<endl;
    return 0;
}
