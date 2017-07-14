//
//  main.cpp
//  1039. Course List for Student (25)
//
//  Created by 祝暾 on 2017/7/14.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int getid(char *s){
    int id=0;
    for (int i=0; i<3; i++) {
        id=id*26+s[i]-'A';
    }
    id=id*10+s[3]-'0';
    return id;
}
const int MAX=26*26*26*10+10;
vector<int>vec[MAX];
int main(int argc, const char * argv[]) {
    int n,k,no,num;
    char name[5];
    scanf("%d %d", &n, &k);
    for (int i=0; i<k; i++) {
        scanf("%d %d", &no, &num);
        for (int j=0; j<num; j++) {
            scanf("%s", name);
            int temp=getid(name);
            vec[temp].push_back(no);
        }
    }
    for (int i=0; i<n; i++) {
        scanf("%s", name);
        int temp=getid(name);
        sort(vec[temp].begin(), vec[temp].end());
        cout<<name<<" "<<vec[temp].size();
        for (int j=0; j<vec[temp].size(); j++) {
            cout<<" "<<vec[temp][j];
        }
        cout<<endl;
    }
    return 0;
}
