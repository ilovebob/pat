//
//  main.cpp
//  1025. PAT Ranking (25)
//
//  Created by 祝暾 on 2017/7/13.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
struct Student{
    string ID;
    int score;
    int final_rank,location_num,local_rank;
}tempStu;
bool cmp(Student a,Student b){
    if (a.score==b.score) {
        return a.ID<b.ID;
    }else{
        return a.score>b.score;
    }
}
vector<Student>local,fina;
int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    int sum=0;
    for (int i=0; i<n; i++) {
        int k;
        cin>>k;
        sum+=k;
        local.clear();
        tempStu.location_num=i+1;
        for (int j=0; j<k; j++) {
            cin>>tempStu.ID>>tempStu.score;
            local.push_back(tempStu);
        }
        sort(local.begin(), local.end(), cmp);
        for (int j=0; j<local.size(); j++) {
            if (j==0) {
                local[0].local_rank=1;
            }else{
                if (local[j].score==local[j-1].score) {
                    local[j].local_rank=local[j-1].local_rank;
                }else{
                    local[j].local_rank=j+1;
                }
            }
            tempStu=local[j];
            fina.push_back(tempStu);
        }
    }
    sort(fina.begin(), fina.end(), cmp);
    fina[0].final_rank=1;
    cout<<sum<<endl;
    cout<<fina[0].ID<<" "<<1<<" "<<fina[0].location_num<<" "<<fina[0].local_rank<<endl;
    for (int i=1; i<fina.size(); i++) {
        if (fina[i].score==fina[i-1].score) {
            fina[i].final_rank=fina[i-1].final_rank;
        }else{
            fina[i].final_rank=i+1;
        }
        cout<<fina[i].ID<<" "<<fina[i].final_rank<<" "<<fina[i].location_num<<" "<<fina[i].local_rank<<endl;
    }
    return 0;
}
