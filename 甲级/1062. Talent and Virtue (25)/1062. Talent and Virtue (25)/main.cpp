//
//  main.cpp
//  1062. Talent and Virtue (25)
//
//  Created by 祝暾 on 2017/7/15.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <string>
#include<vector>
#include<algorithm>
using namespace std;
struct Student{
    int xuehao;
    int descore;
    int caiscore;
};
bool cmp(Student a,Student b){
    int suma = a.descore+a.caiscore;
    int sumb = b.descore+b.caiscore;
    if(suma!=sumb){
        return suma>sumb;
    }
    else{
        if(a.descore!=b.descore){
            return a.descore>b.descore;
        }
        else{
            return a.xuehao<b.xuehao;
        }
    }
}
vector<Student> v1,v2,v3,v4;
int main(int argc, const char * argv[]) {
    int n=0,l=0,h=0;
    scanf("%d %d %d",&n,&l,&h);
    Student student;
    int count=0;
    for (int i=0; i<n; i++) {
        cin>>student.xuehao>>student.descore>>student.caiscore;
        if (student.descore>=l&&student.caiscore>=l) {
            count++;
            if (student.descore>=h&&student.caiscore>=h) {
                v1.push_back(student);
            }else if (student.descore>=h&&student.caiscore>=l){
                v2.push_back(student);
            }else if (student.descore>=l&&student.caiscore>=l&&student.descore>=student.caiscore){
                v3.push_back(student);
            }else {
                v4.push_back(student);
            }
        }
        
    }
    cout<<count<<endl;
    sort(v1.begin(),v1.end(),cmp);
    sort(v2.begin(),v2.end(),cmp);
    sort(v3.begin(),v3.end(),cmp);
    sort(v4.begin(),v4.end(),cmp);
    
    for (int i=0; i<v1.size(); i++) {
        cout<<v1[i].xuehao<<" "<<v1[i].descore<<" "<<v1[i].caiscore<<endl;
    }
    for (int i=0; i<v2.size(); i++) {
        cout<<v2[i].xuehao<<" "<<v2[i].descore<<" "<<v2[i].caiscore<<endl;
    }
    for (int i=0; i<v3.size(); i++) {
        cout<<v3[i].xuehao<<" "<<v3[i].descore<<" "<<v3[i].caiscore<<endl;
    }
    for (int i=0; i<v4.size(); i++) {
        cout<<v4[i].xuehao<<" "<<v4[i].descore<<" "<<v4[i].caiscore<<endl;
    }
    return 0;
}
