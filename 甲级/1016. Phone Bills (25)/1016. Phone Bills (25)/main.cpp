//
//  main.cpp
//  1016. Phone Bills (25)
//
//  Created by 祝暾 on 2017/7/12.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
using namespace std;
int rate[25]={0};
struct Bill{
    string name;
    int status,time,month,day,hour,minute;
};
bool cmp(Bill a,Bill b){
    return a.name==b.name?a.time<b.time:a.name<b.name;
}
double billfromzero(Bill call){
    double total=rate[call.hour]*call.minute+rate[24]*60*call.day;
    for (int i=0; i<call.hour; i++) {
        total+=rate[i]*60;
    }
    return total/100.0;
}
int main(int argc, const char * argv[]) {
    for (int i=0; i<24; i++) {
        cin>>rate[i];
        rate[24]+=rate[i];
    }
    int n;
    cin>>n;
    vector<Bill> data(n);
    for (int i=0; i<n; i++) {
        cin>>data[i].name;
        scanf("%d:%d:%d:%d", &data[i].month, &data[i].day, &data[i].hour, &data[i].minute);
        string temp;
        cin>>temp;
        data[i].status=(temp=="on-line")?1:0;
        data[i].time=data[i].day * 24 * 60 + data[i].hour * 60 + data[i].minute;
    }
    sort(data.begin(), data.end(), cmp);
    map<string,vector<Bill>> customer;
    for (int i=1; i<n; i++) {
        if (data[i].name==data[i-1].name&&data[i].status==0&&data[i-1].status==1) {
            customer[data[i-1].name].push_back(data[i-1]);
            customer[data[i].name].push_back(data[i]);
        }
    }
    for (auto it :customer) {
        vector<Bill> temp=it.second;
        cout<<it.first;
        printf(" %02d\n",temp[0].month);
        double total=0.0;
        for (int i=1; i<temp.size(); i+=2) {
            double t=billfromzero(temp[i])-billfromzero(temp[i-1]);
            printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n",temp[i - 1].day, temp[i - 1].hour, temp[i - 1].minute, temp[i].day, temp[i].hour, temp[i].minute, temp[i].time - temp[i - 1].time, t);
            total+=t;
        }
        printf("Total amount: $%.2f\n",total);
    }
    return 0;
}
