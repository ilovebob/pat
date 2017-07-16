//
//  main.cpp
//  1117. Eddington Number(25)
//
//  Created by 祝暾 on 2017/7/16.
//  Copyright © 2017年 祝暾. All rights reserved.
//

//
//  main.cpp
//  1060. 爱丁顿数(25)
//
//  Created by 祝暾 on 2017/5/7.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    int tmp;
    int i;
    vector<int> vec;
    for (int i=0; i<n; i++) {
        cin>>tmp;
        vec.push_back(tmp);
    }
    sort(vec.begin(), vec.end(), cmp);
    for (i=0; i<n; i++) {
        if (vec[i]<=(i+1)) {
            break;
        }
        
    }
    cout<<i<<endl;
    return 0;
}
