//
//  main.cpp
//  1065. A+B and C (64bit) (20)
//
//  Created by 祝暾 on 2017/7/15.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
using namespace std;
bool compare(long long a,long long b,long long c){
    if ((a>=0&&b>=0&&c>=0)||(a<0&&b<0&&c<0)) {
        return a>(c-b);
    }else if ((a>=0&&b<0)||(a<0&&b>=0)){
        return (a+b)>c;
    }else if(c<0){
        return true;
    }else {
        return false;
    }
}
int main(int argc, const char * argv[]) {
    int n;
    long long a,b,c;
    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>a>>b>>c;
        cout<<"Case #"<<i+1<<": ";
        if (compare(a, b, c)) {
            cout<<"true"<<endl;
        }else{
            cout<<"false"<<endl;
        }
    }
    return 0;
}
