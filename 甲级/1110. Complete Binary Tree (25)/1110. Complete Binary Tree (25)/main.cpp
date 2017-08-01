//
//  main.cpp
//  1110. Complete Binary Tree (25)
//
//  Created by 祝暾 on 2017/7/30.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
struct Tree {
    int left,right;
};
vector<Tree> tree;
vector<bool> book;
int main(int argc, const char * argv[]) {
    int n,root=0;
    cin>>n;
    string temp;
    tree.resize(n);
    book.resize(n);
    for (int i=0; i<n; i++) {
        cin>>temp;
        if (temp!="-") {
            tree[i].left=stoi(temp);
            book[tree[i].left]=true;
        }else{
            tree[i].left=-1;
        }
        cin>>temp;
        if (temp!="-") {
            tree[i].right=stoi(temp);
            book[tree[i].right]=true;
        }else{
            tree[i].right=-1;
        }
    }
    for (int i=0; i<n; i++) {
        if (!book[i]) {
            root=i;
            break;
        }
    }
    queue<int>q;
    q.push(root);
    int countnum=0;
    int lastnode=0;
    while (!q.empty()) {
        int index=q.front();
        q.pop();
        if (index!=-1) {
            lastnode=index;
            countnum++;
        }else{
            if (countnum==n) {
                cout<<"YES "<<lastnode<<endl;
            }else{
                cout<<"NO "<<root<<endl;
            }
            return 0;
        }
        q.push(tree[index].left);
        q.push(tree[index].right);
    }
    return 0;
}
