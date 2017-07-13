//
//  main.cpp
//  1008. Elevator (20)
//
//  Created by 祝暾 on 2017/7/12.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int N;
    cin>>N;
    int sum=N*5;
    int befroe=0;
    int now;
    for (int i=0; i<N; i++) {
        cin>>now;
        if (now>befroe) {
            sum+=(now-befroe)*6;
        }else if (now<befroe){
            sum+=(befroe-now)*4;
        }
        befroe=now;
    }
    cout<<sum<<endl;
    return 0;
}
