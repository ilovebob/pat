//
//  main.cpp
//  1104. Sum of Number Segments (20)
//
//  Created by 祝暾 on 2017/7/16.
//  Copyright © 2017年 祝暾. All rights reserved.
//

//
//  main.cpp
//  1049. 数列的片段和(20)
//
//  Created by 祝暾 on 2017/5/6.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <stdio.h>
using namespace std;
int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    double all=0;
    double a;
    for (int i=0; i<n; i++) {
        cin>>a;
        all+=(a*(i+1)*(n-i));
    }
    printf("%.2f\n",all);
    return 0;
}
