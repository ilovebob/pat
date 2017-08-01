//
//  main.cpp
//  1122. Hamiltonian Cycle (25)
//
//  Created by 祝暾 on 2017/7/30.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
#define maxn 2010
using namespace std;
bool g[maxn][maxn]={{false}};
int main(int argc, const char * argv[]) {
    int N,m,k;
    cin>>N>>m;
    for (int i=0; i<m; i++) {
        int a,b;
        cin>>a>>b;
        g[a][b]=g[b][a]=true;
    }
    cin>>k;
    for (int i=0; i<k; i++) {
        bool flag=true;
        int n,temp;
        cin>>n;
        vector<int> v(n);
        set<int> s;
        for (int j=0; j<n; j++) {
            cin>>temp;
            v[j]=temp;
            s.insert(temp);
        }
        if (n!=N+1||s.size()!=N||v[0]!=v[n-1]) {
            flag=false;
        }else{
            for (int l=0; l<N; l++) {
                if (!g[v[l]][v[l+1]]) {
                    flag=false;
                    break;
                }
            }
        }
        if (flag) {
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
