//
//  main.cpp
//  1033. To Fill or Not to Fill (25)
//
//  Created by 祝暾 on 2017/7/13.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
#define MAX 999999999
struct station {
    double price,dis;
};
bool cmp(station a,station b){
    return a.dis<b.dis;
}

int main(int argc, const char * argv[]) {
    double cmax, d, davg;
    int n;
    cin>>cmax>>d>>davg>>n;
    vector<station> vec(n+1);
    vec[0].price=0.0;
    vec[0].dis=d;
    for (int i=1; i<=n; i++) {
        cin>>vec[i].price>>vec[i].dis;
    }
    sort(vec.begin(), vec.end(), cmp);
    if (vec[0].dis!=0) {
        cout<<"The maximum travel distance = 0.00"<<endl;
        return 0;
    }
    double nowdis=0.0,maxdis=0.0,nowprice=vec[0].price,totalprice=0.0,leftdis=0.0;
    while (nowdis<d) {
        maxdis=nowdis+cmax*davg;
        double minpricedis=0,minprice=MAX;
        int flag=0;
        for (int i=1; i<=n&&vec[i].dis<=maxdis; i++) {
            if (vec[i].dis<=nowdis) {
                continue;
            }
            if (vec[i].price<nowprice) {
                totalprice+=(vec[i].dis-nowdis-leftdis)*nowprice/davg;
                leftdis=0.0;
                nowprice=vec[i].price;
                nowdis=vec[i].dis;
                flag=1;
                break;
            }
            if (vec[i].price<minprice) {
                minprice=vec[i].price;
                minpricedis=vec[i].dis;
            }
        }
        if (flag==0&&minprice!=MAX) {
            totalprice+=(nowprice*(cmax-leftdis/davg));
            leftdis=cmax*davg-(minpricedis-nowdis);
            nowprice=minprice;
            nowdis=minpricedis;
        }
        if (flag==0&&minprice==MAX) {
            nowdis+=cmax*davg;
            printf("The maximum travel distance = %.2f\n", nowdis);
            return 0;
        }
    }
    printf("%.2f\n", totalprice);
    return 0;
}
