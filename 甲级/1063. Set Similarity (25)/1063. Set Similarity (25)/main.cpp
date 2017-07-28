//
//  main.cpp
//  1063. Set Similarity (25)
//
//  Created by 祝暾 on 2017/7/27.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
#include <iomanip>
using namespace std;

int main(int argc, const char * argv[]) {
    int n,m,k,temp,nc,nt,a,b;
    cin>>n;
    vector<set<int>> v(n);
    for (int i=0; i<n; i++) {
        cin>>m;
        set<int>s;
        for (int j=0; j<m; j++) {
            cin>>temp;
            s.insert(temp);
        }
        v[i]=s;
    }
    cin>>k;
    for (int i=0; i<k; i++) {
        cin>>a>>b;
        nc=0;
        nt=(int)v[b-1].size();
        for (auto it=v[a-1].begin(); it!=v[a-1].end(); it++) {
            if (v[b-1].find(*it)==v[b-1].end()) {
                nt++;
            }else{
                nc++;
            }
        }
        double ans=nc*100.0/nt;
        cout<<setprecision(1)<<fixed<<ans<<"%"<<endl;
    }
    return 0;
}
