//
//  main.cpp
//  1043. Is It a Binary Search Tree (25)
//
//  Created by 祝暾 on 2017/7/31.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
bool ismirror;
vector<int> pre;
vector<int> post;
void getpost(int root,int tail){
    if (root>tail) {
        return;
    }
    int i=root+1,j=tail;
    if (!ismirror) {
        while (i<=tail&&pre[root]>pre[i]) {
            i++;
        }
        while (j>=root+1&&pre[root]<=pre[j]) {
            j--;
        }
    }else{
        while (i<=tail&&pre[root]<=pre[i]) {
            i++;
        }
        while (j>=root+1&&pre[root]>pre[j]) {
            j--;
        }
    }
    if (i-j!=1) {
        return;
    }
    getpost(root+1, j);
    getpost(i, tail);
    post.push_back(pre[root]);
}
int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    pre.resize(n);
    for (int i=0; i<n; i++) {
        cin>>pre[i];
    }
    getpost(0, n-1);
    if (post.size()!=n) {
        ismirror=true;
        post.clear();
        getpost(0, n-1);
    }
    if (post.size()==n) {
        cout<<"YES"<<endl;
        for (int i=0; i<n; i++) {
            cout<<post[i];
            if (i!=n-1) {
                cout<<" ";
            }else{
                cout<<endl;
            }
        }
        
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}
