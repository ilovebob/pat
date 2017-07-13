//
//  main.cpp
//  1035. Password (20)
//
//  Created by 祝暾 on 2017/7/14.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
struct Account {
    string name,password;
    bool flag;
}account[1000];
int main(int argc, const char * argv[]) {
    int n1,n2=0;
    cin>>n1;
    for (int i=0; i<n1; i++) {
        cin>>account[i].name>>account[i].password;
        for (int j=0; j<account[i].password.length(); j++) {
            if (account[i].password[j]=='1') {
                account[i].password[j]='@';
                account[i].flag=true;
            }
            if (account[i].password[j]=='0') {
                account[i].password[j]='%';
                account[i].flag=true;
            }
            if (account[i].password[j]=='l') {
                account[i].password[j]='L';
                account[i].flag=true;
            }
            if (account[i].password[j]=='O') {
                account[i].password[j]='o';
                account[i].flag=true;
            }
        }
        if (account[i].flag) {
            n2++;
        }
    }
    if (n2!=0) {
        cout<<n2<<endl;
        for (int i=0; i<n1&&n2!=0; i++) {
            if (account[i].flag) {
                cout<<account[i].name<<" "<<account[i].password<<endl;
                n2--;
            }
        }
    }else if(n1!=1){
        cout<<"There are "<<n1<<" accounts and no account is modified"<<endl;
    }else{
        cout<<"There is 1 account and no account is modified"<<endl;
    }
    
    return 0;
}
