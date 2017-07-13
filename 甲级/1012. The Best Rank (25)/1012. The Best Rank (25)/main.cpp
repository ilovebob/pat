//
//  main.cpp
//  1012. The Best Rank (25)
//
//  Created by 祝暾 on 2017/7/12.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
int exist[1000000];
int flag;
struct Student{
    int id,best;
    int score[4],rank[4];
}student[2005];
bool cmp(Student a,Student b){
    return a.score[flag]>b.score[flag];
}
int main(int argc, const char * argv[]) {
    int n,m;
    int id;
    cin>>n>>m;
    for (int i=0; i<n; i++) {
        cin>>student[i].id>>student[i].score[1]>>student[i].score[2]>>student[i].score[3];
        student[i].score[0]=(student[i].score[1]+student[i].score[2]+student[i].score[3])/3.0+0.5;
    }
    for (flag=0; flag<4; flag++) {
        sort(student, student+n, cmp);
        student[0].rank[flag]=1;
        for (int i=1; i<n; i++) {
            if (student[i].score[flag]==student[i-1].score[flag]) {
                student[i].rank[flag]=student[i-1].rank[flag];
            }else{
                student[i].rank[flag]=i+1;
            }
        }
    }
    for (int i=0; i<n; i++) {
        exist[student[i].id]=i+1;
        student[i].best=0;
        int min=student[i].rank[0];
        for (int j=1; j<4; j++) {
            if (student[i].rank[j]<min) {
                min=student[i].rank[j];
                student[i].best=j;
            }
        }
    }
    char c[4]={'A','C','M','E'};
    for (int i=0; i<m; i++) {
        cin>>id;
        if (exist[id]) {
            cout<<student[exist[id]-1].rank[student[exist[id]-1].best]<<" "<<c[student[exist[id]-1].best]<<endl;
        }else{
            cout<<"N/A"<<endl;
        }
    }
    return 0;
}
