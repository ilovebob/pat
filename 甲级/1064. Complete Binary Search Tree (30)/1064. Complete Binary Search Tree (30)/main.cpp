//
//  main.cpp
//  1064. Complete Binary Search Tree (30)
//
//  Created by 祝暾 on 2017/8/1.
//  Copyright © 2017年 祝暾. All rights reserved.
//  题目要求对给定的序列建立完全二叉搜索树，所谓完全二叉搜索树就是要满足完全二叉树的搜索树。我们知道，完全二叉树的结点i如果从1开始编号，那么左儿子为2*i，右儿子为2*i+1；而二叉搜索树的中序遍历为升序，因此只需要对输入序列按照升序排序，然后对完全二叉树进行中序遍历，填入相应的元素即可

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> node;
vector<int> tree;
int Index=1,n;
void buildTree(int root){
    if (root>n) {
        return;
    }
    buildTree(root*2);
    tree[root]=node[Index++];
    buildTree(root*2+1);
}
int main(int argc, const char * argv[]) {
    scanf("%d",&n);
    node.resize(n+1);
    tree.resize(n+1);
    for (int i=1; i<=n; i++) {
        scanf("%d",&node[i]);
    }
    sort(node.begin(), node.end());
    buildTree(1);
    for (int i=1; i<=n; i++) {
        if (i!=n) {
            printf("%d ",tree[i]);
        }else{
            printf("%d\n",tree[i]);
        }
    }
    return 0;
}
