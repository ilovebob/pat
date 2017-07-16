//
//  main.cpp
//  1116. Come on! Let's C (20)
//
//  Created by 祝暾 on 2017/7/16.
//  Copyright © 2017年 祝暾. All rights reserved.
//

//
//  main.cpp
//  1059. C语言竞赛(20)
//
//  Created by 祝暾 on 2017/5/7.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
using namespace std;
bool checknum(int n){
    for (int i=2; i<n-1; i++) {
        if (n%i==0) {
            return false;
        }
    }
    return true;
}
int main(int argc, const char * argv[]) {
    int n;
    long long k;
    int id[10000]={0};
    int check[10000]={0};
    string award[10000];
    int tmp;
    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>tmp;
        id[tmp]=1;
        if ((i+1)==1) {
            award[tmp]="Mystery Award";
        }else{
            if (checknum(i+1)==true) {
                award[tmp]="Minion";
            }else{
                award[tmp]="Chocolate";
            }
        }
    }
    cin>>k;
    string tmp1;
    for (long long i=0; i<k; i++) {
        cin>>tmp1;
        if (id[stoi(tmp1)]==1&&check[stoi(tmp1)]==0) {
            cout<<tmp1<<": "<<award[stoi(tmp1)]<<endl;
            check[stoi(tmp1)]=1;
        }else if (id[stoi(tmp1)]==0){
            cout<<tmp1<<": Are you kidding?"<<endl;
        }else {
            cout<<tmp1<<": Checked"<<endl;
        }
    }
    return 0;
}
