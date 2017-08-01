//
//  main.cpp
//  1131. Subway Map (30)
//
//  Created by 祝暾 on 2017/7/30.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <vector>
#define maxn 10010
using namespace std;
vector<vector<int>> v(maxn);
int line[maxn][maxn],visit[maxn];
vector<int>path,temppath;
int caltrans(vector<int> patha){
    int cnt=-1,pre=0;
    for (int i=1; i<patha.size(); i++) {
        if (line[patha[i-1]][patha[i]]!=pre) {
            cnt++;
        }
        pre=line[patha[i-1]][patha[i]];
    }
    return cnt;
}
void dfs(int index,int end,int cnt,int &mincnt,int &mintrans){
    if (index==end) {
        if (cnt<mincnt||(cnt==mincnt&&caltrans(temppath)<mintrans)) {
            mincnt=cnt;
            mintrans=caltrans(temppath);
            path=temppath;
        }
        return;
    }
    for (int i=0; i<v[index].size(); i++) {
        if (visit[v[index][i]]==0) {
            visit[v[index][i]]=1;
            temppath.push_back(v[index][i]);
            dfs(v[index][i], end, cnt+1, mincnt, mintrans);
            temppath.pop_back();
            visit[v[index][i]]=0;
        }
    }
}
int main(int argc, const char * argv[]) {
    int n,m,k;
    cin>>n;
    for (int i=1; i<=n; i++) {
        cin>>m;
        int a = 0,b;
        if (m!=0) {
            cin>>a;
        }
        for (int j=1; j<m; j++) {
            cin>>b;
            v[a].push_back(b);
            v[b].push_back(a);
            line[a][b]=line[b][a]=i;
            a=b;
        }
    }
    cin>>k;
    int begin,end;
    for (int i=0; i<k; i++) {
        cin>>begin>>end;
        int mincnt=maxn,mintrans=maxn;
        temppath.clear();
        temppath.push_back(begin);
        visit[begin]=1;
        dfs(begin, end, 0, mincnt, mintrans);
        visit[begin]=0;
        cout<<mincnt<<endl;
        int preLine=0, preTransfer=begin;
        for (int j=1; j<path.size(); j++) {
            if (line[path[j-1]][path[j]]!=preLine) {
                if (preLine!=0) {
                    printf("Take Line#%d from %04d to %04d.\n", preLine, preTransfer, path[j-1]);
                }
                preLine = line[path[j-1]][path[j]];
                preTransfer = path[j-1];
            }
        }
        printf("Take Line#%d from %04d to %04d.\n", preLine, preTransfer, end);
    }
    return 0;
}
