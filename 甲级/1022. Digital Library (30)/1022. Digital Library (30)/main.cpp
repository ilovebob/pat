//
//  main.cpp
//  1022. Digital Library (30)
//
//  Created by 祝暾 on 2017/7/13.
//  Copyright © 2017年 祝暾. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
#include <set>
#include <cstdio>
using namespace std;
map<string, set<int>>title,author,keyword,publish,year;
void query(map<string, set<int>>&m,string str){
    if (m.find(str)!=m.end()) {
        for (set<int>::iterator it=m[str].begin(); it!=m[str].end(); it++) {
            printf("%07d\n",*it);
        }
    }else{
        printf("Not Found\n");
    }
}
int main(int argc, const char * argv[]) {
    int n,m,id,num;
    cin>>n;
    string tit,aut,key,pub,yea;
    for (int i=0; i<n; i++) {
        cin>>id;
        getchar();
        getline(cin, tit);
        title[tit].insert(id);
        getline(cin, aut);
        author[aut].insert(id);
        while (cin>>key) {
            keyword[key].insert(id);
            char c;
            c=getchar();
            if (c=='\n') {
                break;
            }
        }
        getline(cin, pub);
        publish[pub].insert(id);
        getline(cin, yea);
        year[yea].insert(id);
    }
    cin>>m;
    for (int i=0; i<m; i++) {
        scanf("%d: ",&num);
        string temp;
        getline(cin, temp);
        cout<<num<<": "<<temp<<endl;
        switch (num) {
            case 1:
                query(title, temp);
                break;
            case 2:
                query(author, temp);
                break;
            case 3:
                query(keyword, temp);
                break;
            case 4:
                query(publish, temp);
                break;
            case 5:
                query(year, temp);
                break;
            default:
                break;
        }
    }
    return 0;
}
