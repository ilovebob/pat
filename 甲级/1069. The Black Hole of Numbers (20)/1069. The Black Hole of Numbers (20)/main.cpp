//
//  main.cpp
//  1069. The Black Hole of Numbers (20)
//
//  Created by 祝暾 on 2017/7/15.
//  Copyright © 2017年 祝暾. All rights reserved.
//

//
//  main.cpp
//  1019
//
//  Created by 祝暾 on 2017/4/20.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
using namespace std;
int sort1(int *n){
    int i,j;
    for (i=1; i<4; i++) {
        int tmp=n[i];
        for (j=i; j>0&&n[j-1]<tmp; j--) {
            n[j]=n[j-1];
        }
        n[j]=tmp;
    }
    return (n[0]*1000+n[1]*100+n[2]*10+n[3]);
}
int sort2(int *n){
    int i,j;
    for (i=1; i<4; i++) {
        int tmp=n[i];
        for (j=i; j>0&&n[j-1]>tmp; j--) {
            n[j]=n[j-1];
        }
        n[j]=tmp;
    }
    return (n[0]*1000+n[1]*100+n[2]*10+n[3]);
}
int main(int argc, const char * argv[]) {
    int n[4];
    int num;
    int a,b,c;
    cin>>num;
    for (int i=3; i>=0; i--) {
        n[i]=num%10;
        num/=10;
    }
    if (n[0]==n[1]&&n[0]==n[2]&&n[0]==n[3]) {
        cout<<n[0]<<n[0]<<n[0]<<n[0]<<" - "<<n[0]<<n[0]<<n[0]<<n[0]<<" = 0000"<<endl;
        return 0;
    }
    while (1) {
        a=sort1(n);
        b=sort2(n);
        num=c=a-b;
        for (int i=3; i>=0; i--) {
            n[i]=num%10;
            num/=10;
        }
        if (99<b&&b<1000) {
            cout<<a<<" - 0"<<b;
        }else if (9<b&&b<100){
            cout<<a<<" - 00"<<b;
        }else if (b<10){
            cout<<a<<" - 000"<<b;
        }else
            cout<<a<<" - "<<b;
        
        if (99<c&&c<1000) {
            cout<<" = 0"<<c<<endl;
        }else if (9<c&&c<100){
            cout<<" = 00"<<c<<endl;
        }else if (c<10){
            cout<<" = 000"<<c<<endl;
        }else
            cout<<" = "<<c<<endl;
        
        if (c==6174) {
            break;
        }
    }
    
    return 0;
}
