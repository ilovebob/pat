//
//  main.cpp
//  1042. Shuffling Machine (20)
//
//  Created by 祝暾 on 2017/7/14.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int cnt;
    cin>>cnt;
    int start[55], end[55], scan[55];
    for (int i=1; i<55; i++) {
        cin>>scan[i];
        end[i]=i-1;
    }
    for (int i=0; i<cnt; i++) {
        for(int j = 1; j < 55; j++) {
            start[j] = end[j];
        }
        for(int k = 1; k < 55; k++) {
            end[scan[k]] = start[k];
        }
    }
    char c[6] = {"SHCDJ"};
    for(int i = 1; i < 55; i++) {
        end[i] = end[i];
        printf("%c%d", c[end[i] / 13], end[i] % 13 + 1);
        if(i != 54) printf(" ");
    }
    return 0;
}
