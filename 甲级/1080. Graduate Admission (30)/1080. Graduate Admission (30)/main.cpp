//
//  main.cpp
//  1080. Graduate Admission (30)
//
//  Created by 祝暾 on 2017/7/15.
//  Copyright © 2017年 祝暾. All rights reserved.
//

//
//  main.cpp
//  题目1005：Graduate Admission
//
//  Created by 祝暾 on 2017/5/24.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string>
using namespace std;
struct Student{
    int ge;
    int gi;
    double fg;
    int choice[5];
    int dex;
}student[40000];
bool cmp(Student a,Student b){
    if (a.fg==b.fg) {
        return a.ge>b.ge;
    }else{
        return a.fg>b.fg;
    }
}
int school[100][40000]={0};
int schoolnum[100][2]={0};
int schooltmp[100][2]={0};
vector<Student> vec;

int main(int argc, const char * argv[]) {
    int n,m,k;
    while (1) {
        if (scanf("%d %d %d",&n,&m,&k)==EOF) {
            break;
        }
        for (int i=0; i<m; i++) {
            cin>>schoolnum[i][0];
        }
        for (int i=0; i<n; i++) {
            cin>>student[i].ge>>student[i].gi;
            for (int j=0; j<k; j++) {
                cin>>student[i].choice[j];
            }
            student[i].fg=(double)(student[i].ge+student[i].gi)/2;
            student[i].dex=i;
            vec.push_back(student[i]);
        }
        sort(vec.begin(), vec.end(), cmp);
        for (int i=0; i<n; i++) {
            for (int j=0; j<k; j++) {
                if (schoolnum[vec[i].choice[j]][0]>0||(vec[i].fg==schooltmp[vec[i].choice[j]][0]&&vec[i].ge==schooltmp[vec[i].choice[j]][1])) {
                    school[vec[i].choice[j]][vec[i].dex]=1;
                    schoolnum[vec[i].choice[j]][0]--;
                    schoolnum[vec[i].choice[j]][1]++;
                    schooltmp[vec[i].choice[j]][0]=vec[i].fg;
                    schooltmp[vec[i].choice[j]][1]=vec[i].ge;
                    break;
                }
            }
        }
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (school[i][j]==1) {
                    if ((--schoolnum[i][1])!=0) {
                        cout<<j<<" ";
                    }else
                        cout<<j;
                    school[i][j]=0;
                }
                
            }
            cout<<endl;
        }
        schoolnum[100][2]={0};
        schooltmp[100][2]={0};
        vec.clear();
    }
    return 0;
}
/*
 11 6 3
 2 1 2 2 2 3
 100 100 0 1 2
 100 100 0 3 5
 100 90 0 3 4
 90 100 1 2 0
 90 90 5 1 3
 80 90 1 0 2
 80 80 0 1 2
 80 80 0 1 2
 80 70 1 3 2
 70 80 1 2 3
 100 100 0 2 4
 */

