//
//  main.cpp
//  1088. Rational Arithmetic (20)
//
//  Created by 祝暾 on 2017/7/16.
//  Copyright © 2017年 祝暾. All rights reserved.
//

//
//  main.cpp
//  1034
//
//  Created by 祝暾 on 2017/5/1.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
struct Num{
    long long k;
    long long a;
    long long b;
};

//求最大公约数
long long  gongyue(long long a, long long b){
    while(b){
        if (b%a == 0){
            return abs(a);
        }
        else{
            long long temp = b%a;
            b = a;
            a = temp;
        }
    }
    return 0;
}
//输出格式
void pri(Num n){
    if (n.k<0) {
        if (n.a!=0) {
            cout<<"("<<n.k<<" "<<abs(n.a)<<"/"<<n.b<<")";
        }else{
            cout<<"("<<n.k<<")";
        }
    }else if (n.k>0){
        if (n.a!=0) {
            cout<<n.k<<" "<<n.a<<"/"<<n.b;
        }else{
            cout<<n.k;
        }
    }else{
        if (n.a<0) {
            cout<<"("<<n.a<<"/"<<n.b<<")";
        }else if (n.a>0){
            cout<<n.a<<"/"<<n.b;
        }else{
            cout<<"0";
        }
    }
}

int main(int argc, const char * argv[]) {
    string in1,in2;
    Num n1,n2,n3,n4,n5,n6;
    long long gongyueshu;
    cin>>in1>>in2;
    //字符串转数字
    int i=(int)in1.find('/');
    int j=(int)in2.find('/');
    if (in1[0]=='-') {
        n1.a=-(stol(in1.substr(1,i-1)));
        n1.b=(stol(in1.substr(i+1,in1.length()-i-1)));
    }else{
        n1.a=(stol(in1.substr(0,i)));
        n1.b=(stol(in1.substr(i+1,in1.length()-i-1)));
    }
    if (in2[0]=='-') {
        n2.a=-(stol(in2.substr(1,j-1)));
        n2.b=(stol(in2.substr(j+1,in2.length()-j-1)));
    }else{
        n2.a=(stol(in2.substr(0,j)));
        n2.b=(stol(in2.substr(j+1,in2.length()-j-1)));
    }
    
    
    if (n2.a!=0) {//如果第二数不为0
        //+
        n3.b=n1.b*n2.b;
        n3.a=n1.b*n2.a+n1.a*n2.b;
        if (n3.a!=0) {
            gongyueshu=gongyue(n3.a,n3.b);
            n3.a/=gongyueshu;
            n3.b/=gongyueshu;
        }
        n3.k=n3.a/n3.b;
        n3.a=n3.a%n3.b;
        //-
        n4.b=n1.b*n2.b;
        n4.a=n1.a*n2.b-n1.b*n2.a;
        if (n4.a!=0) {
            gongyueshu=gongyue(n4.a,n4.b);
            n4.a/=gongyueshu;
            n4.b/=gongyueshu;
        }
        n4.k=n4.a/n4.b;
        n4.a=n4.a%n4.b;
        //*
        n5.b=n1.b*n2.b;
        n5.a=n1.a*n2.a;
        if (n5.a!=0) {
            gongyueshu=gongyue(n5.a,n5.b);
            n5.a/=gongyueshu;
            n5.b/=gongyueshu;
        }
        n5.k=n5.a/n5.b;
        n5.a=n5.a%n5.b;
        ///
        if (n2.a<0) {
            n6.b=n1.b*abs(n2.a);
            n6.a=-n1.a*n2.b;
        }else{
            n6.b=n1.b*n2.a;
            n6.a=n1.a*n2.b;
        }
        if (n6.a!=0) {
            gongyueshu=gongyue(n6.a,n6.b);
            n6.a/=gongyueshu;
            n6.b/=gongyueshu;
        }
        n6.k=n6.a/n6.b;
        n6.a=n6.a%n6.b;
        //源操作数转换最简
        n1.k=n1.a/n1.b;
        n1.a=n1.a%n1.b;
        if (n1.a!=0) {
            gongyueshu=gongyue(n1.a, n1.b);
            n1.a/=gongyueshu;
            n1.b/=gongyueshu;
        }
        n2.k=n2.a/n2.b;
        n2.a=n2.a%n2.b;
        if (n2.a!=0) {
            gongyueshu=gongyue(n2.a, n2.b);
            n2.a/=gongyueshu;
            n2.b/=gongyueshu;
        }
        
        pri(n1);cout<<" + ";pri(n2);cout<<" = ";pri(n3);cout<<endl;
        pri(n1);cout<<" - ";pri(n2);cout<<" = ";pri(n4);cout<<endl;
        pri(n1);cout<<" * ";pri(n2);cout<<" = ";pri(n5);cout<<endl;
        pri(n1);cout<<" / ";pri(n2);cout<<" = ";pri(n6);cout<<endl;
        
    }else{                                                             // 如果第二数为0
        n1.k=n1.a/n1.b;
        n1.a=n1.a%n1.b;
        if (n1.a!=0) {
            gongyueshu=gongyue(n1.a, n1.b);
            n1.a/=gongyueshu;
            n1.b/=gongyueshu;
        }
        n2.k=n2.a/n2.b;
        n2.a=n2.a%n2.b;
        if (n2.a!=0) {
            gongyueshu=gongyue(n2.a, n2.b);
            n2.a/=gongyueshu;
            n2.b/=gongyueshu;
        }
        n3=n4=n1;
        n5.a=n5.k=0;
        pri(n1);cout<<" + ";pri(n2);cout<<" = ";pri(n3);cout<<endl;
        pri(n1);cout<<" - ";pri(n2);cout<<" = ";pri(n4);cout<<endl;
        pri(n1);cout<<" * ";pri(n2);cout<<" = ";pri(n5);cout<<endl;
        pri(n1);cout<<" / ";pri(n2);cout<<" = Inf"<<endl;
        
    }
    return 0;
}
