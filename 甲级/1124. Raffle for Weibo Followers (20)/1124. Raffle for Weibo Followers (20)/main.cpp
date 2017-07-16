//
//  main.cpp
//  1124. Raffle for Weibo Followers (20)
//
//  Created by 祝暾 on 2017/7/16.
//  Copyright © 2017年 祝暾. All rights reserved.
//
//
//  main.cpp
//  1069. 微博转发抽奖(20)
//
//  Created by 祝暾 on 2017/5/8.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc, const char * argv[]) {
    int n,m,s;
    string name[1001];
    cin>>n>>m>>s;
    vector<string> vec;
    for (int i=1; i<=n; i++) {
        cin>>name[i];
    }
    for (int i=s; i<=n; i+=m) {
        while (i<=n) {
            vector<string>::iterator result=find(vec.begin(), vec.end(), name[i]);
            if (result==vec.end()) {
                vec.push_back(name[i]);
                break;
            }else{
                i++;
            }
        }
        
    }
    if (vec.size()==0) {
        cout<<"Keep going..."<<endl;
    }else{
        for (int i=0; i<vec.size(); i++) {
            cout<<vec[i]<<endl;
        }
    }
    return 0;
}
