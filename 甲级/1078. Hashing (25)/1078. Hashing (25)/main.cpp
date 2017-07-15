//
//  main.cpp
//  1078. Hashing (25)
//
//  Created by 祝暾 on 2017/7/15.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <cstring>
using namespace std;

const int MAX=10010;
bool flagArray[MAX+1];
int j;

void init_prime(){
    int i;
    memset(flagArray, true, sizeof(flagArray));
    flagArray[0]=flagArray[1]=false;
    for(i=2; i<sqrt((double)MAX); i++)
    {
        if(flagArray[i])
        {
            for( j = i; j*i <= MAX; j++)
            {
                flagArray[j*i] = false;
            }
        }
    }
}
bool hashTable[MAX];
int main(int argc, const char * argv[]) {
    init_prime();
    int ms,n;
    cin>>ms>>n;
    while (flagArray[ms]==false) {
        ms++;
    }
    int temp;
    for (int i=0; i<n; i++) {
        cin>>temp;
        int index=temp%ms;
        if (hashTable[index]==false) {
            hashTable[index]=true;
            if (i!=0) {
                cout<<" ";
            }
            cout<<temp%ms;
        }else{
            int flag = 0;
            for(int step = 1; step < ms; step++) {
                index = (temp + step * step) % ms;
                if(hashTable[index] == false) {
                    hashTable[index] = true;
                    flag = 1;
                    if (i!=0) {
                        cout<<" ";
                    }
                    cout<<index;
                    break;
                }
            }
            if(flag == 0) {
                if (i!=0) {
                    cout<<" ";
                }
                cout<<"-";
            }
        }
    }
    cout<<endl;
    return 0;
}
