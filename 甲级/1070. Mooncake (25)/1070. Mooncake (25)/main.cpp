//
//  main.cpp
//  1070. Mooncake (25)
//
//  Created by 祝暾 on 2017/7/27.
//  Copyright © 2017年 祝暾. All rights reserved.
//

//
//  main.cpp
//  1020
//
//  Created by 祝暾 on 2017/4/20.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
using namespace std;

struct Yuebing{
    double kucun;
    double toall;
};
struct Danjia{
    double dan;
    int num;
};
int main(int argc, const char * argv[]) {
    int n,xuqiu;
    Yuebing yuebing[1000];
    Danjia danjia[1000];
    int j;
    double tmp1;
    int tmp2;
    double zongjia=0;
    cin>>n>>xuqiu;
    for (int i=0; i<n; i++) {
        cin>>yuebing[i].kucun;
    }
    for (int i=0; i<n; i++) {
        cin>>yuebing[i].toall;
        danjia[i].dan=(double)yuebing[i].toall/yuebing[i].kucun;
        danjia[i].num=i;
    }
    
    for (int i=1; i<n; i++) {
        tmp1=danjia[i].dan;
        tmp2=danjia[i].num;
        for (j=i; j>0&&danjia[j-1].dan<tmp1; j--) {
            danjia[j].dan=danjia[j-1].dan;
            danjia[j].num=danjia[j-1].num;
        }
        danjia[j].dan=tmp1;
        danjia[j].num=tmp2;
    }
    for (int i=0;i<n; i++) {
        if (xuqiu<yuebing[danjia[i].num].kucun) {
            zongjia+=(danjia[i].dan*xuqiu);
            break;
        }else{
            xuqiu-=yuebing[danjia[i].num].kucun;
            zongjia+=yuebing[danjia[i].num].toall;
        }
    }
    printf("%.2f\n",zongjia);
    return 0;
}
