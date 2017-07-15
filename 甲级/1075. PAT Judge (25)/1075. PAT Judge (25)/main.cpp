//
//  main.cpp
//  1075. PAT Judge (25)
//
//  Created by 祝暾 on 2017/7/15.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
struct Student {
    int id;
    int score[6];//score[0]-totallscore
    int perfectnum;
    bool beshown;//decide to be shown
    int rank;
    Student(){
        score[0]=0;
        score[1]=score[2]=score[3]=score[4]=score[5]=-1;//not submit is -1
    }
}stu[10001];

bool cmp(Student a,Student b){
    if (a.score[0]==b.score[0]&&a.perfectnum==b.perfectnum) {
        return a.id<b.id;
    }else if (a.score[0]==b.score[0]){
        return a.perfectnum>b.perfectnum;
    }else{
        return a.score[0]>b.score[0];
    }
}
vector<Student>vec;
int main(int argc, const char * argv[]) {
    int n,k,m;
    int fullscore[6]={0};
    cin>>n>>k>>m;
    for (int i=1; i<=k; i++) {
        cin>>fullscore[i];
    }
    for (int i=0; i<m; i++) {
        int a,b,c;
        cin>>a>>b>>c;
        if (c==-1) {
            if (stu[a].score[b]==-1) {
                stu[a].score[b]=0;
            }
            continue;
        }
        if (stu[a].score[b]==-1) {
            stu[a].score[0]+=c;
            stu[a].score[b]=c;
            if (c==fullscore[b]) {
                stu[a].perfectnum++;
            }
        }else if (c>stu[a].score[b]) {
            stu[a].score[0]=stu[a].score[0]+c-stu[a].score[b];
            stu[a].score[b]=c;
            if (c==fullscore[b]) {
                stu[a].perfectnum++;
            }
        }
        stu[a].beshown=true;
    }
    for (int i=1; i<=n; i++) {
        if (stu[i].beshown) {
            stu[i].id=i;
            vec.push_back(stu[i]);
        }
    }
    sort(vec.begin(), vec.end(), cmp);
    if (vec.size()) {
        vec[0].rank=1;
    }
    for (int i=1; i<vec.size(); i++) {
        if (vec[i].score[0]==vec[i-1].score[0]) {
            vec[i].rank=vec[i-1].rank;
        }else{
            vec[i].rank=i+1;
        }
    }
    for (int i=0; i<vec.size(); i++) {
        printf("%d %05d %d",vec[i].rank,vec[i].id,vec[i].score[0]);
        for (int j=1; j<=k; j++) {
            if (vec[i].score[j]!=-1) {
                cout<<" "<<vec[i].score[j];
            }else{
                cout<<" -";
            }
        }
        cout<<endl;
    }
    return 0;
}
/*
 8 5 28
 20 25 25 30 42
 00002 2 12
 00007 4 17
 00005 1 19
 00007 2 25
 00007 2 25
 00005 1 20
 00002 2 2
 00005 1 15
 00001 1 18
 00004 3 25
 00002 2 25
 00005 3 22
 00006 4 -1
 00001 2 18
 00002 1 20
 00004 1 15
 00002 4 18
 00001 3 4
 00001 4 2
 00005 2 -1
 00004 2 0
 00006 5 42
 00008 1 -1
 00008 2 -1
 00006 5 12
 00006 5 22
 00006 5 11
 00006 5 42
*/
