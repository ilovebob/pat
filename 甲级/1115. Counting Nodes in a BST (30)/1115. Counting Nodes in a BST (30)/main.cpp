//
//  main.cpp
//  1115. Counting Nodes in a BST (30)
//
//  Created by 祝暾 on 2017/7/30.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <vector>
#define maxn 1010
using namespace std;
struct node {
    int w;
    struct node *left,*right;
};
node *build(node *root,int w){
    if (root==NULL) {
        root=new node();
        root->w=w;
        root->left=root->right=NULL;
    }else{
        if (w<=root->w) {
            root->left=build(root->left, w);
        }else{
            root->right=build(root->right, w);
        }
    }
    return root;
}
vector<int> cnt(maxn);
int maxdepth=-1;
void dfs(node *root,int depth){
    if (root==NULL) {
        if (depth>maxdepth) {
            maxdepth=depth;
        }
    }else{
        cnt[depth]++;
        dfs(root->left, depth+1);
        dfs(root->right, depth+1);
    }
}
int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    int temp;
    node *root=NULL;
    for (int i=0; i<n; i++) {
        cin>>temp;
        root=build(root, temp);
    }
    dfs(root, 0);
    cout<<cnt[maxdepth-1]<<" + "<<cnt[maxdepth-2]<<" = "<<cnt[maxdepth-1]+cnt[maxdepth-2]<<endl;
    return 0;
}
