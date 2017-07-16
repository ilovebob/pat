//
//  main.cpp
//  1097. Deduplication on a Linked List (25)
//
//  Created by 祝暾 on 2017/7/16.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;
const int maxn=100000;
struct Node{
    int pos;
    int key;
    int next;
    int num;
    Node(){
        num=maxn*2;
    }
}node[maxn];
bool cmp(Node a,Node b){
    return a.num<b.num;
}
bool flagArray[maxn];
int main(int argc, const char * argv[]) {
    int start,n;
    int cnt1=0,cnt2=0;
    cin>>start>>n;
    for (int i=0; i<n; i++) {
        int temp;
        cin>>temp;
        cin>>node[temp].key>>node[temp].next;
        node[temp].pos=temp;
    }
    for (int i=start; i!=-1; i=node[i].next) {
        if (flagArray[abs(node[i].key)]==false) {
            flagArray[abs(node[i].key)]=true;
            node[i].num=cnt1++;
        }else{
            node[i].num=maxn+cnt2++;
        }
    }
    sort(node, node+maxn,cmp);
    int cnt=cnt1+cnt2;
    for (int i=0; i<cnt; i++) {
        if (i!=cnt1-1&&i!=cnt-1) {
            printf("%05d %d %05d\n",node[i].pos,node[i].key,node[i+1].pos);
        }else{
            printf("%05d %d -1\n",node[i].pos,node[i].key);
        }
    }
    return 0;
}
