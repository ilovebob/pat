//
//  main.cpp
//  1046. Shortest Distance (20)
//
//  Created by 祝暾 on 2017/7/14.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;
int dis[100002];
int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    int sum=0;
    for (int i=1; i<=n; i++) {
        int temp;
        cin>>temp;
        sum += temp;
        dis[i] = sum;
    }
    int m,e1,e2;
    cin>>m;
    for (int i=0; i<m; i++) {
        cin>>e1>>e2;
        if (e1>e2) {
            swap(e1, e2);
        }
        int temp = dis[e2 - 1] - dis[e1 - 1];
        cout<<min(temp, sum - temp)<<endl;
    }
    return 0;
}
