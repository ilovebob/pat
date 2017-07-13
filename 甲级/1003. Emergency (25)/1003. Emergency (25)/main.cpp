//
//  main.cpp
//  1003. Emergency (25)
//
//  Created by 祝暾 on 2017/5/8.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
using namespace std;
int n,m,c1,c2;
int teamnum[500]={0};
int map[500][500]={0};
int tmp1,tmp2;
int min;
void dijkstra(int s){
    
}
int main(int argc, const char * argv[]) {

    cin>>n>>m>>c1>>c2;
    for (int i=0; i<n; i++) {
        cin>>teamnum[i];
    }
    for (int i=0; i<m; i++) {
        cin>>tmp1>>tmp2;
        cin>>map[tmp1][tmp2];
        map[tmp2][tmp1]=map[tmp1][tmp2];
    }

    
    return 0;
}
