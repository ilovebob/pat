//
//  main.cpp
//  1055. The World's Richest (25)
//
//  Created by 祝暾 on 2017/7/14.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
struct Richer{
    char name[10];
    int age;
    int money;
}tempricher;
bool cmp(Richer a,Richer b){
    if (a.money==b.money&&a.age==b.age) {
        return (strcmp(a.name, b.name) < 0);
    }else if (a.money==b.money){
        return a.age<b.age;
    }
    return a.money>b.money;
}
vector<Richer>vec,v;
vector<int> book(205, 0);
int main(int argc, const char * argv[]) {
    int n,k;
    int num,small_age,big_age;
    scanf("%d %d", &n, &k);
    for (int i=0; i<n; i++) {
        scanf("%s %d %d", tempricher.name, &tempricher.age, &tempricher.money);
        vec.push_back(tempricher);
    }
    sort(vec.begin(), vec.end(), cmp);
    for (int i=0; i<n; i++) {
        if (book[vec[i].age]<100) {
            v.push_back(vec[i]);
            book[vec[i].age]++;
        }
    }
    for (int i=0; i<k; i++) {
        int sum=0;
        scanf("%d %d %d", &num, &small_age, &big_age);
        vector<Richer> t;
        for(int j = 0; j < v.size(); j++) {
            if(v[j].age >= small_age && v[j].age <= big_age)
                t.push_back(v[j]);
        }
        printf("Case #%d:\n", i + 1);
        for (int j=0; j<t.size()&&j<num; j++) {
            printf("%s %d %d\n", t[j].name, t[j].age, t[j].money);
            sum=1;
        }
        if (sum==0) {
            printf("None\n");
        }
        
    }
    return 0;
}
