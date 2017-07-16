//
//  main.cpp
//  1120. Friend Numbers (20)
//
//  Created by 祝暾 on 2017/7/16.
//  Copyright © 2017年 祝暾. All rights reserved.
//

//
//  main.cpp
//  1064. 朋友数(20)
//
//  Created by 祝暾 on 2017/5/7.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int biaoji[37]={0};
    int n,j=0;
    cin>>n;
    for (int i=0; i<n; i++) {
        int tmp,id=0;
        cin>>tmp;
        if (tmp<10) {
            id=tmp;
        }else{
            while (tmp!=0) {
                id+=tmp%10;
                tmp/=10;
            }
        }
        if (biaoji[id]==0) {
            biaoji[id]=1;
            j++;
        }
    }
    cout<<j<<endl;
    for (int i=0; i<37; i++) {
        if (biaoji[i]==1) {
            if (j==1) {
                cout<<i<<endl;
            }else{
                cout<<i<<' ';
                j--;
            }
        }
    }
    return 0;
}
