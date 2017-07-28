//
//  main.cpp
//  1014. Waiting in Line (30)
//
//  Created by 祝暾 on 2017/7/20.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
struct Node{
    int poptime,endtime;
    queue<int> q;
};
int main(int argc, const char * argv[]) {
    int n,m,k,q,index=1;
    cin>>n>>m>>k>>q;
    vector<int> time(k + 1), result(k + 1);
    vector<Node> windows(n+1);
    vector<bool> flag(k+1,false);
    for (int i=1; i<=k; i++) {
        cin>>time[i];
    }
    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++) {
            if (index<=k) {
                windows[j].q.push(time[index]);
                if (windows[j].endtime>=540) {
                    flag[index]=true;
                }
                windows[j].endtime+=time[index];
                if (i==1) {
                    windows[j].poptime=windows[j].endtime;
                }
                result[index] = windows[j].endtime;
                index++;
            }
        }
    }
    while (index<=k) {
        int temp=1,minpop=windows[1].poptime;
        for (int i=2; i<=n; i++) {
            if (windows[i].poptime<minpop) {
                temp=i;
                minpop=windows[i].poptime;
            }
        }
        windows[temp].q.pop();
        windows[temp].q.push(time[index]);
        windows[temp].poptime+=windows[temp].q.front();
        if (windows[temp].endtime>=540) {
            flag[index]=true;
        }
        windows[temp].endtime+=time[index];
        result[index]=windows[temp].endtime;
        index++;
    }
    
    for (int i=0; i<q; i++) {
        int temp,temptime;
        cin>>temp;
        temptime=result[temp];
        if (flag[temp]) {
            cout<<"Sorry"<<endl;
        }else{
            printf("%02d:%02d\n",(temptime+480)/60,(temptime+480)%60);
        }
    }
    return 0;
}
