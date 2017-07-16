//
//  main.cpp
//  1125. Chain the Ropes (25)
//
//  Created by 祝暾 on 2017/7/16.
//  Copyright © 2017年 祝暾. All rights reserved.
//

//
//  main.cpp
//  1070. 结绳(25)
//
//  Created by 祝暾 on 2017/5/8.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(int a,int b){
    return a<b;
}
int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    int len;
    int tmp;
    vector<int> vec;
    for (int i=0; i<n; i++) {
        cin>>tmp;
        vec.push_back(tmp);
    }
    sort(vec.begin(), vec.end(), cmp);
    len=vec[0];
    for (int i=1; i<vec.size(); i++) {
        len=(len+vec[i])/2;
    }
    cout<<len<<endl;
    return 0;
}
