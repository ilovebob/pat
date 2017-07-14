//
//  main.cpp
//  1052. Linked List Sorting (25)
//
//  Created by 祝暾 on 2017/7/14.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
struct Node{
    int pos;
    int key;
    int next;
}node[100000];
bool cmp(Node a,Node b){
    return a.key<b.key;
}
vector<Node>vec;
int main(int argc, const char * argv[]) {
    int n,start;
    cin>>n>>start;
    for (int i=0; i<n; i++) {
        int temp;
        cin>>temp;
        cin>>node[temp].key>>node[temp].next;
        node[temp].pos=temp;
    }
    for (int i=start; i!=-1; i=node[i].next) {
        vec.push_back(node[i]);
    }
    if (vec.size()==0) {
        cout<<"0 -1"<<endl;
    }else{
        sort(vec.begin(), vec.end(), cmp);
        printf("%d %05d\n",(int)vec.size(),vec[0].pos);
        for (int i=0; i<vec.size(); i++) {
            if (i==vec.size()-1) {
                printf("%05d %d -1\n",vec[i].pos,vec[i].key);
            }else
                printf("%05d %d %05d\n",vec[i].pos,vec[i].key,vec[i+1].pos);
        }
    }
    return 0;
}

