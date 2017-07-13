//
//  main.cpp
//  1028. List Sorting (25)
//
//  Created by 祝暾 on 2017/7/13.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <algorithm>
#include <string.h>
#include <cstdio>
using namespace std;
struct Student {
    int id;
    char name[10];
    int grade;
}student[100001];
int c;
int cmp1(Student a,Student b){
    if (c==1) {
        return a.id<b.id;
    }else if (c==2){
        return strcmp(a.name, b.name)<=0;
    }else{
        return a.grade<=b.grade;
    }
}
int main(int argc, const char * argv[]) {
    int n;
    scanf("%d%d", &n, &c);
    for (int i=0; i<n; i++) {
        scanf("%d %s %d",&student[i].id,student[i].name,&student[i].grade);
    }
    sort(student,student+n, cmp1);
    for (int i=0; i<n; i++) {
        printf("%06d %s %d\n",student[i].id,student[i].name,student[i].grade);
    }
    return 0;
}
