//
//  main.cpp
//  1036. Boys vs Girls (25)
//
//  Created by 祝暾 on 2017/7/14.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
struct Student {
    string name, gender, ID;
    int grade;
}tempstu;
vector<Student>male,female;
bool flag;
bool cmp(Student a,Student b){
    if (flag) {
        return a.grade<b.grade;
    }else{
        return a.grade>b.grade;
    }
}
int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>tempstu.name>>tempstu.gender>>tempstu.ID>>tempstu.grade;
        if (tempstu.gender=="F") {
            female.push_back(tempstu);
        }else if (tempstu.gender=="M"){
            male.push_back(tempstu);
        }
    }
    bool flag1=false;
    int female_grade=0,male_grade=0;
    flag=false;
    if (female.size()==0) {
        cout<<"Absent"<<endl;
        flag1=true;
    }else{
        sort(female.begin(), female.end(), cmp);
        cout<<female[0].name<<" "<<female[0].ID<<endl;
        female_grade=female[0].grade;
    }
    flag=true;
    if (male.size()==0) {
        cout<<"Absent"<<endl;
        flag1=true;
    }else{
        sort(male.begin(), male.end(), cmp);
        cout<<male[0].name<<" "<<male[0].ID<<endl;
        male_grade=male[0].grade;
    }
    if (flag1) {
        cout<<"NA"<<endl;
    }else{
        cout<<female_grade-male_grade<<endl;
    }
    
    return 0;
}
