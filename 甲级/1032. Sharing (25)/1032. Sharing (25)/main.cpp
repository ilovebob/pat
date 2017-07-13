//
//  main.cpp
//  1032. Sharing (25)
//
//  Created by 祝暾 on 2017/7/13.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <cstdio>
struct NODE {
    bool flag;
    int nextpos;
}node[100000];
int main(int argc, const char * argv[]) {
    int n1,n2,n,a,b;
    char temp;
    scanf("%d %d %d",&n1,&n2,&n);
    for (int i=0; i<n; i++) {
        scanf("%d %c %d",&a,&temp,&b);
        node[a].nextpos=b;
    }
    for (int i=n1; i!=-1; i=node[i].nextpos) {
        node[i].flag=true;
    }
    for (int i=n2; i!=-1; i=node[i].nextpos) {
        if (node[i].flag==true) {
            printf("%05d\n",i);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}
