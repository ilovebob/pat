//
//  main.cpp
//  1085. Perfect Sequence (25)
//
//  Created by 祝暾 on 2017/7/16.
//  Copyright © 2017年 祝暾. All rights reserved.
//

//
//  main.cpp
//  1030
//
//  Created by 祝暾 on 2017/5/1.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include<algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    int n,k=1,p;
    long long max,min;
    long long num[100000];
    cin>>n>>p;
    for (int i=0; i<n; i++) {
        cin>>num[i];
    }
    sort(num, num+n);
    for (int i=0; i<n; i++) {
        min=num[i];
        max=min*p;
        for (int j=i+k; j<n; j++) {
            if (num[j]<=max) {
                if (k<(j-i+1)) {
                    k=(j-i+1);
                }
            }else
                break;
        }
    }
    cout<<k<<endl;
    return 0;
}
/*
 10 8
 2 3 20 4 5 1 6 7 8 9
 */

