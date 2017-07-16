//
//  main.cpp
//  1105. Spiral Matrix (25)
//
//  Created by 祝暾 on 2017/7/16.
//  Copyright © 2017年 祝暾. All rights reserved.
//

//
//  main.cpp
//  1050. 螺旋矩阵(25)
//
//  Created by 祝暾 on 2017/5/6.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(int argc, const char * argv[]) {
    int N,m=0,n=0,k=0;
    int num[10000]={0};
    int ans[10000]={0};
    cin>>N;
    for (int i=0; i<N; i++) {
        cin>>num[i];
    }
    sort(num, num+N, cmp);
    for (int i=N,j=1; i>=j; i--) {
        j=N/i;
        if (i*j==N&&(i-j)>=0) {
            m=i;
            n=j;
        }
    }
    for (int i=0; i<((double)m/2+0.5)&&k!=N; i++) {
        for (int j=i*(n+1); j<i*n+n-i&&k!=N; j++) {
            ans[j]=num[k++];
        }
        for (int j=(i+1)*n+n-i-1; j<m*n-n*i-i&&k!=N; j+=n) {
            ans[j]=num[k++];
        }
        for (int j=m*n-n*i-i-2; j>=(m-1-i)*n+i&&k!=N; j--) {
            ans[j]=num[k++];
        }
        for (int j=(m-2-i)*n+i; j>i*(n+1)&&k!=N; j-=n) {
            ans[j]=num[k++];
        }
    }
    if (N==1) {
        cout<<num[0]<<endl;
    }else{
        for (int i=0; i<m; i++) {
            for (int j=0; j<n-1; j++) {
                cout<<ans[j+n*i]<<" ";
            }
            cout<<ans[n*(i+1)-1]<<endl;
        }
    }
    //cout<<m<<" "<<n<<endl;
    return 0;
}
