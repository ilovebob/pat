//
//  main.cpp
//  1100. Mars Numbers (20)
//
//  Created by 祝暾 on 2017/7/16.
//  Copyright © 2017年 祝暾. All rights reserved.
//

//
//  main.cpp
//  1044. 火星数字(20)
//
//  Created by 祝暾 on 2017/5/6.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
int main(int argc, const char * argv[]) {
    string a[13]={"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
    string b[13]={"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
    int n;
    cin>>n;
    for (int i=0; i<=n; i++) {
        string x,y;
        int j,k,l,m=0;
        getline(cin, x);
        if (x[0]>='0'&&x[0]<='9') {
            k=stoi(x);
            j=k/13;
            k=k%13;
            if (j==0) {
                cout<<a[k]<<endl;
            }else if (k==0){
                cout<<b[j]<<endl;
            }else{
                cout<<b[j]<<" "<<a[k]<<endl;
            }
        }else if (x[0]>='a'&&x[0]<='z'){
            if (x.find(' ')!=string::npos) {
                j=(int)x.find(' ');
                y=x.substr(0,j);
                x=x.substr(j+1,x.length()-j);
                for (int l=0; l<13; l++) {
                    if (b[l]==y) {
                        m=l*13;
                    }
                }
                for (int l=0; l<13; l++) {
                    if (a[l]==x) {
                        m+=l;
                    }
                }
                cout<<m<<endl;
                
            }else{
                for (l=0; l<13; l++) {
                    if (a[l]==x) {
                        m=l;
                    }
                }
                if (l==13) {
                    for (int l=0; l<13; l++) {
                        if (b[l]==x) {
                            m=l*13;
                        }
                    }
                }
                cout<<m<<endl;
            }
        }
    }
    return 0;
}
