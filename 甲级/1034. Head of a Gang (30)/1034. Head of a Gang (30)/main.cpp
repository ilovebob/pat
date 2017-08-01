//
//  main.cpp
//  1034. Head of a Gang (30)
//
//  Created by 祝暾 on 2017/7/31.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <map>
#include <string>
#define maxn 2010
using namespace std;
int g[maxn][maxn],w[maxn];
bool visit[maxn];
map<string, int> stringtoint,ans;
map<int, string> inttostring;
int n,k,idnum=1;
int trans(string s){
    if (stringtoint[s]==0) {
        stringtoint[s]=idnum;
        inttostring[idnum]=s;
        idnum++;
    }
    return stringtoint[s];
}
void dfs(int index,int &head,int &numsum,int &totalweight){
    visit[index]=true;
    numsum++;
    if (w[index]>w[head]) {
        head=index;
    }
    for (int i=1; i<idnum; i++) {
        if (g[index][i]>0) {
            totalweight+=g[index][i];
            g[index][i]=g[i][index]=0;
            if (!visit[i]) {
                dfs(i, head, numsum, totalweight);
            }
        }
    }
}
void dfstrave(){
    for (int i=1; i<idnum; i++) {
        if (!visit[i]) {
            int head=i,numsum=0,totalweight=0;
            dfs(head, head, numsum, totalweight);
            if (numsum>2&&totalweight>k) {
                ans[inttostring[head]]=numsum;
            }
        }
    }
}
int main(int argc, const char * argv[]) {
    cin>>n>>k;
    string s1,s2;
    int time;
    for (int i=0; i<n; i++) {
        cin>>s1>>s2>>time;
        int n1=trans(s1);
        int n2=trans(s2);
        w[n1]+=time;
        w[n2]+=time;
        g[n1][n2]+=time;
        g[n2][n1]+=time;
    }
    dfstrave();
    cout<<ans.size()<<endl;
    for (map<string, int>::iterator it=ans.begin(); it!=ans.end(); it++)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }
    return 0;
}
