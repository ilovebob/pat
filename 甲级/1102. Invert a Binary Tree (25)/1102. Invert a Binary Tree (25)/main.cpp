//
//  main.cpp
//  1102. Invert a Binary Tree (25)
//
//  Created by 祝暾 on 2017/7/29.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
struct Tree {
    int left,right;
};
vector<int>in;
vector<int>level;
vector<Tree>tree;

void inorder(int index){
    if (tree[index].left!=-1) {
        inorder(tree[index].left);
    }
    in.push_back(index);
    if (tree[index].right!=-1) {
        inorder(tree[index].right);
    }
}
void levelorder(int root){
    queue<int>q;
    q.push(root);
    
    while (!q.empty()) {
        int index=q.front();
        q.pop();
        if (tree[index].left!=-1) {
            q.push(tree[index].left);
        }
        if (tree[index].right!=-1) {
            q.push(tree[index].right);
        }
        level.push_back(index);
    }
}
int main(int argc, const char * argv[]) {
    string temp;
    int n,root = 0;
    cin>>n;
    tree.resize(n);
    vector<bool> book(n);
    for (int i=0; i<n; i++) {
        cin>>temp;
        if (temp=="-") {
            tree[i].right=-1;
        }else{
            tree[i].right=temp[0]-'0';
            book[tree[i].right]=true;
        }
        cin>>temp;
        if (temp=="-") {
            tree[i].left=-1;
        }else{
            tree[i].left=temp[0]-'0';
            book[tree[i].left]=true;
        }
    }
    for (int i=0; i<n; i++) {
        if (book[i]==false) {
            root=i;
            break;
        }
    }
    levelorder(root);
    inorder(root);
    
    for (int i=0; i<level.size(); i++) {
        cout<<level[i];
        if (i!=level.size()-1) {
            cout<<" ";
        }else{
            cout<<endl;
        }
    }
    for (int i=0; i<in.size(); i++) {
        cout<<in[i];
        if (i!=in.size()-1) {
            cout<<" ";
        }else{
            cout<<endl;
        }
    }
    
    return 0;
}
