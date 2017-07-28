//
//  main.cpp
//  1056. Mice and Rice (25)
//
//  Created by 祝暾 on 2017/7/25.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
struct Node{
    int weight;
    int index,index1;
    int rank;
};
bool cmp(Node a, Node b) {
    return a.index1 < b.index1;
}
int main(int argc, const char * argv[]) {
    int np,ng;
    cin>>np>>ng;
    vector<int> v(np);
    for (int i=0; i<np; i++) {
        cin>>v[i];
    }
    vector<Node> w(np);
    queue<Node> q;
    for (int i=0; i<np; i++) {
        int temp;
        cin>>temp;
        w[i].weight=v[temp];
        w[i].index=i;
        w[i].index1=temp;
        q.push(w[i]);
    }
    while (!q.empty()) {
        int size=(int)q.size();
        if (size==1) {
            Node temp=q.front();
            w[temp.index].rank=1;
            break;
        }
        int rank=size/ng;
        if (size%ng!=0) {
            rank++;
        }
        Node maxnode;
        int maxweight=-1, cnt=0;
        for (int i=0; i<size; i++) {
            Node temp=q.front();
            w[temp.index].rank=rank+1;
            q.pop();
            cnt++;
            if (temp.weight>maxweight) {
                maxweight=temp.weight;
                maxnode=temp;
            }
            if (cnt==ng||i==size-1) {
                cnt=0;
                maxweight=-1;
                q.push(maxnode);
            }
        }
    }
    sort(w.begin(), w.end(), cmp);
    for(int i = 0; i < np; i++) {
        if (i!=np-1) {
            cout<<w[i].rank<<" ";
        }else{
            cout<<w[i].rank<<endl;
        }
    }
    return 0;
}
