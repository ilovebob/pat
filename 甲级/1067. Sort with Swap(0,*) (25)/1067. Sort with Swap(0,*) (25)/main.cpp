//
//  main.cpp
//  1067. Sort with Swap(0,*) (25)
//
//  Created by 祝暾 on 2017/7/15.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int main(int argc, const char * argv[]) {
    int n,temp,cnt=0,ans=0,index=1;
    cin>>n;
    vector<int> vec(n);
    for (int i=0; i<n; i++) {
        cin>>temp;
        vec[temp]=i;
        if (temp!=i&&temp!=0) {
            cnt++;
        }
    }
    while (cnt>0) {
        if (vec[0]==0) {
            while (index<n) {
                if (vec[index]!=index) {
                    swap(vec[index], vec[0]);
                    ans++;
                    break;
                }
                index++;
            }
        }
        while (vec[0]!=0) {
            swap(vec[vec[0]], vec[0]);
            ans++;
            cnt--;
        }
    }
    cout<<ans<<endl;
    return 0;
}
