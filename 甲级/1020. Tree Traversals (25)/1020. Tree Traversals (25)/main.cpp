//
//  main.cpp
//  1020. Tree Traversals (25)
//
//  Created by 祝暾 on 2017/7/12.
//  Copyright © 2017年 祝暾. All rights reserved.
//  别人写的！！
//https://www.liuchuo.net/archives/2100

#include <iostream>
#include <vector>
using namespace std;
vector<int> post, in, level(100000, -1);
void lev(int root, int start, int end, int index) {
    if(start > end) return ;
    int i = start;
    while(i < end && in[i] != post[root]) i++;
    level[index] = post[root];
    lev(root - 1 - end + i, start, i - 1, 2 * index + 1);
    lev(root - 1, i + 1, end, 2 * index + 2);
}
int main() {
    int n, cnt = 0;
    cin>>n;
    post.resize(n);
    in.resize(n);
    for(int i = 0; i < n; i++){
        cin>>post[i];
    }
    for(int i = 0; i < n; i++){
        cin>>in[i];
    }
    lev(n-1, 0, n-1, 0);
    for(int i = 0; i < level.size(); i++) {
        if(level[i] != -1 && cnt != n - 1) {
            cout<<level[i]<<" ";
            cnt++;
        } else if(level[i] != -1){
            cout<<level[i]<<endl;
            break;
        }
    }
    return 0;
}
