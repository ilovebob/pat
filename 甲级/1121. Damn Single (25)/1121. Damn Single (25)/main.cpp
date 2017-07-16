//
//  main.cpp
//  1121. Damn Single (25)
//
//  Created by 祝暾 on 2017/7/16.
//  Copyright © 2017年 祝暾. All rights reserved.
//

//
//  main.cpp
//  1065. 单身狗(25)
//
//  Created by 祝暾 on 2017/5/8.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    string biaoji[100001];
    int iscoouple[100001]={0};
    int issingle[100001]={0};
    int ishere[100001]={0};
    int n,m;
    cin>>n;
    string tmp1,tmp2;
    for (int i=0; i<n; i++) {
        cin>>tmp1>>tmp2;
        biaoji[stol(tmp1)]=tmp2;
        biaoji[stol(tmp2)]=tmp1;
        iscoouple[stol(tmp1)]=1;
        iscoouple[stol(tmp2)]=1;
    }
    cin>>m;
    for (int i=0; i<m; i++) {
        string id;
        cin>>id;
        ishere[stol(id)]=1;
        if (iscoouple[stol(id)]==0) {
            issingle[stol(id)]=1;
        }else{
            if (ishere[stol(biaoji[stol(id)])]==1){
                issingle[stol(biaoji[stol(id)])]=0;
            }else{
                issingle[stol(id)]=1;
            }
        }
    }
    int len=0;
    for (int i=0; i<100000; i++) {
        if (issingle[i]==1) {
            len++;
        }
    }
    cout<<len<<endl;
    for (int i=0; i<100000; i++) {
        if (issingle[i]==1) {
            if (len==1) {
                printf("%05d\n",i);
            }else{
                printf("%05d ",i);
                len--;
            }
        }
    }
    return 0;
}

