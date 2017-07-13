//
//  main.cpp
//  Sign In and Sign Out (25)
//
//  Created by 祝暾 on 2017/7/12.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
struct Person{
    string ID;
    int in_time;
    int out_time;
};
bool cmp1(Person a,Person b){
    return a.in_time<b.in_time;
}
bool cmp2(Person a,Person b){
    return a.out_time>b.out_time;
}
vector<Person>vec;
int main(int argc, const char * argv[]) {
    int M;
    cin>>M;
    string s;
    Person p;
    for (int i=0; i<M; i++) {
        cin>>p.ID>>s;
        p.in_time=(((s[0]-'0')*10+(s[1]-'0'))*60+(s[3]-'0')*10+(s[4]-'0'))*60+(s[6]-'0')*10+(s[7]-'0');
        cin>>s;
        p.out_time=(((s[0]-'0')*10+(s[1]-'0'))*60+(s[3]-'0')*10+(s[4]-'0'))*60+(s[6]-'0')*10+(s[7]-'0');
        vec.push_back(p);
    }
    sort(vec.begin(), vec.end(), cmp1);
    cout<<vec[0].ID<<" ";
    sort(vec.begin(), vec.end(), cmp2);
    cout<<vec[0].ID<<endl;
    return 0;
}
