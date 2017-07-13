//
//  main.cpp
//  1017. Queueing at Bank (25)
//
//  Created by 祝暾 on 2017/7/12.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Customer{
    int time,serve;
}tempCus;
bool cmp(Customer a,Customer b){
    return a.time<b.time;
}
int main(int argc, const char * argv[]) {
    int n,k;
    cin>>n>>k;
    vector<Customer>vec;
    int hh,mm,ss,servetime;
    for (int i=0; i<n; i++) {
        scanf("%d:%d:%d %d", &hh, &mm, &ss, &servetime);
        if (servetime>60) {
            servetime=60;
        }
        int cometime=hh*60*60+mm*60+ss;
        if (cometime>61200) {
            continue;
        }
        tempCus.time=cometime;
        tempCus.serve=servetime*60;
        vec.push_back(tempCus);
    }
    sort(vec.begin(), vec.end(), cmp);
    vector<int>window(k,28800);
    double res=0.0;
    for (int i=0; i<vec.size(); i++) {
        int temp=0,minfinish=window[0];
        for (int j=1; j<k; j++) {
            if (minfinish>window[j]) {
                minfinish=window[j];
                temp=j;
            }
        }
        if (window[temp]>vec[i].time) {
            res+=(window[temp]-vec[i].time);
            window[temp]+=vec[i].serve;
        }else{
            window[temp]=vec[i].time+vec[i].serve;
        }
    }
    if (vec.size()==0) {
        cout<<"0.0"<<endl;
    }else{
        printf("%.1f\n",res/60.0/vec.size());
    }
    return 0;
}
