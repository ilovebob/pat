//
//  main.cpp
//  1054. The Dominant Color (20)
//
//  Created by 祝暾 on 2017/7/14.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <map>
using namespace std;
map<int,int> ma;
int main(int argc, const char * argv[]) {
    int n,m;
    cin>>n>>m;
    int temp;
    int half=n*m/2;
    for (int i=0; i<n*m; i++) {
        cin>>temp;
        ma[temp]++;
        if (ma[temp]>half) {
            cout<<temp<<endl;
            return 0;
        }
    }
    return 0;
}
