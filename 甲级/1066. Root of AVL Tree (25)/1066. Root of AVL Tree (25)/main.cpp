//
//  main.cpp
//  1066. Root of AVL Tree (25)
//
//  Created by 祝暾 on 2017/8/1.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
struct node {
    int val;
    struct node *left,*right;
    int height;
};
int getHeight(node *root){
    if (root==NULL) {
        return -1;
    }else{
        return root->height;
    }
}
node *rotateLeft(node *root){
    node *k=root->right;
    root->right=k->left;
    k->left=root;
    root->height=max(getHeight(root->left), getHeight(root->right))+1;
    k->height=max(getHeight(k->left), getHeight(k->right))+1;
    return k;
}
node *rotateRight(node *root){
    node *k=root->left;
    root->left=k->right;
    k->right=root;
    root->height=max(getHeight(root->left), getHeight(root->right))+1;
    k->height=max(getHeight(k->left), getHeight(k->right))+1;
    return k;
}
node *rotateLeftRight(node *root) {
    root->left=rotateLeft(root->left);
    return rotateRight(root);
}
node *rotateRightLeft(node *root) {
    root->right = rotateRight(root->right);
    return rotateLeft(root);
}
node *insert(node *root, int val) {
    if(root==NULL) {
        root=new node();
        root->val=val;
        root->left=root->right=NULL;
    } else if(val<root->val) {
        root->left=insert(root->left,val);
        if(getHeight(root->left)-getHeight(root->right)==2){
            if (val<root->left->val) {
                root=rotateRight(root);
            }else{
                root=rotateLeftRight(root);
            }
        }
    } else {
        root->right=insert(root->right, val);
        if(getHeight(root->right)-getHeight(root->left)==2){
            if (val>root->right->val) {
                root=rotateLeft(root);
            }else{
                root=rotateRightLeft(root);
            }
        }
    }
    root->height=max(getHeight(root->left), getHeight(root->right))+1;
    return root;
}
int main(int argc, const char * argv[]) {
    int n,val;
    scanf("%d",&n);
    node *root=NULL;
    for (int i=0; i<n; i++) {
        scanf("%d",&val);
        root=insert(root, val);
    }
    printf("%d\n",root->val);
    return 0;
}
