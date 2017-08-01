//
//  main.cpp
//  1098. Insertion or Heap Sort (25)
//
//  Created by 祝暾 on 2017/7/31.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>a,b;
void downAdjust(int high){
    int i=1,j=i*2;
    while (j<=high) {
        if (j+1<=high&&b[j]<b[j+1]) {
            j++;
        }
        if (b[i]<b[j]) {
            swap(b[i], b[j]);
            i=j;
            j=i*2;
        }else{
            break;
        }
    }
}
int main(int argc, const char * argv[]) {
    int n;
    scanf("%d",&n);
    a.resize(n+1);
    b.resize(n+1);
    for (int i=1; i<=n; i++) {
        scanf("%d",&a[i]);
    }
    for (int i=1; i<=n; i++) {
        scanf("%d",&b[i]);
    }
    int p=2;
    while (p<=n&&b[p-1]<=b[p]) {
        p++;
    }
    int index=p;
    while (p<=n&&a[p]==b[p]) {
        p++;
    }
    if (p==n+1) {
        printf("Insertion Sort\n");
        sort(b.begin()+1, b.begin()+index+1);
        for (int i=1; i<=n; i++) {
            if (i!=n) {
                printf("%d ",b[i]);
            }else{
                printf("%d\n",b[i]);
            }
        }
    }else{
        printf("Heap Sort\n");
        p=n;
        while (p>=2&&b[p]>=b[p-1]) {
            p--;
        }
        swap(b[1], b[p]);
        downAdjust(p-1);
        for (int i=1; i<=n; i++) {
            if (i!=n) {
                printf("%d ",b[i]);
            }else{
                printf("%d\n",b[i]);
            }
        }
    }
    return 0;
}
