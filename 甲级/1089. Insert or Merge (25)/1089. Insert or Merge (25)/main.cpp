//
//  main.cpp
//  1089. Insert or Merge (25)
//
//  Created by 祝暾 on 2017/7/16.
//  Copyright © 2017年 祝暾. All rights reserved.
//
//
//  main.cpp
//  1035
//
//  Created by 祝暾 on 2017/5/4.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
int cmp(int a,int b){
    return a<b;
}
int main(int argc, const char * argv[]) {
    int n,j,k;
    int oldarr[101],newarr[101];
    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>oldarr[i];
    }
    for (int i=0; i<n; i++) {
        cin>>newarr[i];
    }
    for (j=0; j<n-1&&newarr[j]<=newarr[j+1]; j++);
    for (k=j+1; k<n&&oldarr[k]==newarr[k]; k++);
    if (k==n) {
        cout<<"Insertion Sort"<<endl;
        sort(oldarr, oldarr+j+2, cmp);
    }else{
        cout<<"Merge Sort"<<endl;
        int m=1,flag=1;
        while (flag) {
            flag=0;
            for (int i=0; i<n; i++) {
                if (oldarr[i]!=newarr[i]) {
                    flag=1;
                }
            }
            m=m<<1;
            for (int i=0; i<n/m; i++) {
                sort(oldarr+i*m, oldarr+(i+1)*m, cmp);
            }
            sort(oldarr+n/m*m, oldarr+n, cmp);
        }
    }
    for (int i=0; i<n-1; i++) {
        cout<<oldarr[i]<<" ";
    }
    cout<<oldarr[n-1]<<endl;
    return 0;
}

