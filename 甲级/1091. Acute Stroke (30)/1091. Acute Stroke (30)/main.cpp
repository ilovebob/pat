//
//  main.cpp
//  1091. Acute Stroke (30)
//
//  Created by 祝暾 on 2017/7/28.
//  Copyright © 2017年 祝暾. All rights reserved.
//  BFS!

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct node {
    int x,y,z;
};
int n,m,l,t;
int X[6] = {1, 0, 0, -1, 0, 0};
int Y[6] = {0, 1, 0, 0, -1, 0};
int Z[6] = {0, 0, 1, 0, 0, -1};
int arr[1300][130][80];
bool visit[1300][130][80];
bool judge(int x,int y,int z){
    if (x<0||x>=m||y<0||y>=n||z<0||z>=l||arr[x][y][z]==0||visit[x][y][z]==true) {
        return false;
    }
    return true;
}
int bfs(int x,int y,int z){
    int cnt=0;
    queue<node>q;
    node temp;
    temp.x=x;
    temp.y=y;
    temp.z=z;
    q.push(temp);
    visit[x][y][z]=true;
    while (!q.empty()) {
        node top=q.front();
        q.pop();
        cnt++;
        for (int i=0; i<6; i++) {
            int tx=top.x+X[i];
            int ty=top.y+Y[i];
            int tz=top.z+Z[i];
            if (judge(tx, ty, tz)) {
                visit[tx][ty][tz]=true;
                temp.x=tx;
                temp.y=ty;
                temp.z=tz;
                q.push(temp);
            }
        }
    }
    if (cnt>=t) {
        return cnt;
    }
    return 0;
}
int main(int argc, const char * argv[]) {
    cin>>m>>n>>l>>t;
    for (int i=0; i<l; i++) {
        for (int j=0; j<m; j++) {
            for (int k=0; k<n; k++) {
                cin>>arr[j][k][i];
            }
        }
    }
    int ans=0;
    for (int i=0; i<l; i++) {
        for (int j=0; j<m; j++) {
            for (int k=0; k<n; k++) {
                if (arr[j][k][i]==1&&visit[j][k][i]==false) {
                    ans+=bfs(j, k, i);
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
