//
//  main.cpp
//  1058. A+B in Hogwarts (20)
//
//  Created by 祝暾 on 2017/7/15.
//  Copyright © 2017年 祝暾. All rights reserved.
//


#include <iostream>
#include <string>
using namespace std;
int main(int argc, const char * argv[]) {
    string a,b;
    long long m,n,k;
    long long galleon;
    int sickle;
    int knut;
    cin>>a>>b;
    m=stol(a.substr(0,a.find('.')))*29*17+stol(a.substr(a.find('.')+1,a.find_last_of('.')))*29+stol(a.substr(a.find_last_of('.')+1,a.length()-1));
    n=stol(b.substr(0,b.find('.')))*29*17+stol(b.substr(b.find('.')+1,b.find_last_of('.')))*29+stol(b.substr(b.find_last_of('.')+1,b.length()-1));
    k=n+m;
    if (k>=0) {
        galleon=k/(17*29);
        k=k%(17*29);
        sickle=(int)k/29;
        knut=k%29;
    }else{
        cout<<"-";
        k=abs(k);
        galleon=k/(17*29);
        k=k%(17*29);
        sickle=(int)k/29;
        knut=k%29;
    }
    cout<<galleon<<"."<<sickle<<"."<<knut<<endl;
    return 0;
}
