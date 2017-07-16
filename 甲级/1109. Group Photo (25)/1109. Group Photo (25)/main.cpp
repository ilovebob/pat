//
//  main.cpp
//  1109. Group Photo (25)
//
//  Created by 祝暾 on 2017/7/16.
//  Copyright © 2017年 祝暾. All rights reserved.
//

//
//  main.cpp
//  1055. 集体照 (25)
//
//  Created by 祝暾 on 2017/5/7.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct student{
    string name;
    int height;
};
bool cmp(student a,student b){
    if (a.height!=b.height) {
        return a.height>b.height;
    }else{
        return a.name<b.name;
    }
    
}
int main(int argc, const char * argv[]) {
    int n,k,num,lastnum,l=0;
    vector<student>s;
    student tmp;
    string pos[10000];
    cin>>n>>k;
    num=n/k;
    lastnum=n/k+n%k;
    for (int i=0; i<n; i++) {
        cin>>tmp.name>>tmp.height;
        s.push_back(tmp);
    }
    sort(s.begin(), s.end(), cmp);
    if (lastnum%2==0) {
        pos[lastnum/2]=s[l++].name;
        for (int i=1; i<=lastnum/2-1; i++) {
            pos[lastnum/2-i]=s[l++].name;
            pos[lastnum/2+i]=s[l++].name;
        }
        pos[0]=s[l++].name;
    }else{
        pos[lastnum/2]=s[l++].name;
        for (int i=1; i<=lastnum/2; i++) {
            pos[lastnum/2-i]=s[l++].name;
            pos[lastnum/2+i]=s[l++].name;
        }
        
    }
    for (int i=0; i<k-1; i++) {
        if (num%2==0) {
            pos[num/2+lastnum+i*num]=s[l++].name;
            for (int j=1; j<=num/2-1; j++) {
                pos[num/2-j+lastnum+i*num]=s[l++].name;
                pos[num/2+j+lastnum+i*num]=s[l++].name;
            }
            pos[lastnum+i*num]=s[l++].name;
        }else{
            pos[num/2+lastnum+i*num]=s[l++].name;
            for (int j=1; j<=num/2; j++) {
                pos[num/2-j+lastnum+i*num]=s[l++].name;
                pos[num/2+j+lastnum+i*num]=s[l++].name;
            }
            
        }
    }
    for (int i=0; i<k; i++) {
        int m=0;
        if (i==0) {
            m=1;
        }
        if (m==1) {
            for (int i=0; i<lastnum-1; i++) {
                cout<<pos[i]<<" ";
            }
            cout<<pos[lastnum-1]<<endl;
        }else{
            for (int j=0; j<num-1; j++) {
                cout<<pos[j+lastnum+(i-1)*num]<<" ";
            }
            cout<<pos[num-1+lastnum+(i-1)*num]<<endl;
        }
    }
    return 0;
}

/*
 10 3
 Tom 188
 Mike 170
 Eva 168
 Tim 160
 Joe 190
 Ann 168
 Bob 175
 Nick 186
 Amy 160
 John 159
 */
/*
 Bob Tom Joe Nick
 Ann Mike Eva
 Tim Amy John
 */
