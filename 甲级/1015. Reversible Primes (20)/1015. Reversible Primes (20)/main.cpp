//
//  main.cpp
//  1015. Reversible Primes (20)
//
//  Created by 祝暾 on 2017/7/12.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <cstring>
using namespace std;

const int MAX=100000;
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

int convertToRadix(int s,int radix){
    int ans=0;
    while (s) {
        ans=ans*radix+s%radix;
        s=s/radix;
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    int n,d;
    init_prime();
    while (cin>>n) {
        if (n<0) {
            break;
        }
        cin>>d;
        if (!flagArray[n]) {
            cout<<"No"<<endl;
            continue;
        }
        if (flagArray[convertToRadix(n, d)]) {
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
    
    return 0;
}
