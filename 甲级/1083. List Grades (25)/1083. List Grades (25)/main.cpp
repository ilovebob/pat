//
//  main.cpp
//  1083. List Grades (25)
//
//  Created by 祝暾 on 2017/7/16.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct Student {
    string name,id;
    int grade;
}tempstu;
bool cmp(Student a,Student b){
    return a.grade>b.grade;
}
vector<Student>vec,t;
int main(int argc, const char * argv[]) {
    int n,min,max;
    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>tempstu.name>>tempstu.id>>tempstu.grade;
        vec.push_back(tempstu);
    }
    cin>>min>>max;
    for (int i=0; i<n; i++) {
        if (vec[i].grade<=max&&vec[i].grade>=min) {
            t.push_back(vec[i]);
        }
    }
    sort(t.begin(), t.end(), cmp);
    if (t.size()==0) {
        cout<<"NONE"<<endl;
    }else{
        for (int i=0; i<t.size(); i++) {
            cout<<t[i].name<<" "<<t[i].id<<endl;
        }
    }
    
    return 0;
}
