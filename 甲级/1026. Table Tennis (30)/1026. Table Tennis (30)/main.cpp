//
//  main.cpp
//  1026. Table Tennis (30)
//
//  Created by 祝暾 on 2017/7/13.
//  Copyright © 2017年 祝暾. All rights reserved.
//

/*#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct Player{
    int arriving_time;
    int playing_time;
    int vip;
}tempp;
int table[100][2]={0};
int tablenum[100]={0};
int vipflag=0;
int vipnum[10001]={0};
int served[10001]={0};
vector<Player>vec;
bool cmp(Player a,Player b){
    return a.arriving_time<b.arriving_time;
}
int main(int argc, const char * argv[]) {
    int n,k,m;
    int hh,mm,ss;
    cin>>n;
    for (int i=0; i<n; i++) {
        scanf("%d:%d:%d",&hh,&mm,&ss);
        cin>>tempp.playing_time>>tempp.vip;
        tempp.arriving_time=hh*3600+mm*60+ss;
        if (tempp.arriving_time>75600) {
            continue;
        }
        if (tempp.playing_time>120) {
            tempp.playing_time=120;
        }
        if (tempp.vip==1) {
            vipflag++;
        }
        vec.push_back(tempp);
    }
    cin>>k;
    for (int i=0; i<k; i++) {
        table[i][0]=28800;
    }
    cin>>m;
    for (int i=0; i<m; i++) {
        int temp;
        cin>>temp;
        table[temp-1][1]=1;
    }
    sort(vec.begin(), vec.end(), cmp);
    if (vipflag) {
        int j=0;
        for (int i=0; i<vec.size(); i++) {
            if (vec[i].vip) {
                vipnum[j++]=i;
            }
            if (j>vipflag) {
                break;
            }
        }
    }
    int l=0;
    int i=0;
    while (i<vec.size()) {
        int hh1,mm1,ss1;
        int hh2,mm2,ss2;
        int waittime=0;;
        int temp=0,minfinish=table[0][0];
        for (int j=1; j<k; j++) {
            if (minfinish>table[j][0]) {
                minfinish=table[j][0];
                temp=j;
            }
        }
        if (table[temp][0]>=75600) {
            break;
        }
        
        if (table[temp][1]&&vipflag!=0) {
            if (vec[vipnum[l]].arriving_time<=table[temp][0]&&served[vipnum[l]]==0) {
                hh1=vec[vipnum[l]].arriving_time/3600;
                mm1=vec[vipnum[l]].arriving_time/60-hh1*60;
                ss1=vec[vipnum[l]].arriving_time-hh1*3600-mm1*60;
                hh2=table[temp][0]/3600;
                mm2=table[temp][0]/60-hh2*60;
                ss2=table[temp][0]-hh2*3600-mm2*60;
                waittime=(int)(((double)table[temp][0]-vec[vipnum[l]].arriving_time)/60+0.5);
                printf("%02d:%02d:%02d %02d:%02d:%02d %d\n",hh1,mm1,ss1,hh2,mm2,ss2,waittime);
                tablenum[temp]++;
                served[vipnum[l]]=1;
                table[temp][0]+=vec[vipnum[l]].playing_time*60;
                vipflag--;
                l++;
                continue;
            }
        }
        for (; i<n; i++) {
            if (served[i]==0) {
                break;
            }
        }
        hh1=vec[i].arriving_time/3600;
        mm1=vec[i].arriving_time/60-hh1*60;
        ss1=vec[i].arriving_time-hh1*3600-mm1*60;
        if (vec[i].arriving_time<table[temp][0]&&served[i]==0) {
            hh2=table[temp][0]/3600;
            mm2=table[temp][0]/60-hh2*60;
            ss2=table[temp][0]-hh2*3600-mm2*60;
            waittime=(int)(((double)table[temp][0]-vec[i].arriving_time)/60+0.5);
            printf("%02d:%02d:%02d %02d:%02d:%02d %d\n",hh1,mm1,ss1,hh2,mm2,ss2,waittime);
            tablenum[temp]++;
            served[i]=1;
            table[temp][0]+=vec[i].playing_time*60;
            if (vec[i].vip==1) {
                l++;
                vipflag--;
            }
        }else if (vec[i].arriving_time>=table[temp][0]&&served[i]==0){
            printf("%02d:%02d:%02d %02d:%02d:%02d 0\n",hh1,mm1,ss1,hh1,mm1,ss1);
            tablenum[temp]++;
            served[i]=1;
            table[temp][0]=vec[i].arriving_time+vec[i].playing_time*60;
            if (vec[i].vip==1) {
                l++;
                vipflag--;
            }
        }
    }
    for (int i=0; i<k; i++) {
        if (i==k-1) {
            cout<<tablenum[i]<<endl;
        }else{
            cout<<tablenum[i]<<" ";
        }
    }
    return 0;
}
*/
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
struct person {
    int arrive, start, time;
    bool vip;
}tempperson;
struct tablenode {
    int end = 8 * 3600;
    int num;
    bool vip;
};
bool cmp1(person a, person b) {
    return a.arrive < b.arrive;
}
bool cmp2(person a, person b) {
    return a.start < b.start;
}
vector<person> player;
vector<tablenode> table;
void alloctable(int personid, int tableid) {
    if(player[personid].arrive <= table[tableid].end)
        player[personid].start = table[tableid].end;
    else
        player[personid].start = player[personid].arrive;
    table[tableid].end = player[personid].start + player[personid].time;
    table[tableid].num++;
}
int findnextvip(int vipid) {
    vipid++;
    while(vipid < player.size() && player[vipid].vip == false) {
        vipid++;
    }
    return vipid;
}
int main() {
    int n, k, m, viptable;
    cin>>n;
    for(int i = 0; i < n; i++) {
        int h, m, s, temptime, flag;
        scanf("%d:%d:%d %d %d", &h, &m, &s, &temptime, &flag);
        tempperson.arrive = h * 3600 + m * 60 + s;
        tempperson.start = 21 * 3600;
        if(tempperson.arrive >= 21 * 3600)
            continue;
        tempperson.time = temptime <= 120 ? temptime * 60 : 7200;
        tempperson.vip = ((flag == 1) ? true : false);
        player.push_back(tempperson);
    }
    cin>>k>>m;
    table.resize(k);
    for(int i = 0; i < m; i++) {
        cin>>viptable;
        table[viptable-1].vip = true;
    }
    sort(player.begin(), player.end(), cmp1);
    int i = 0, vipid = -1;
    vipid = findnextvip(vipid);
    while(i < player.size()) {
        int index = -1, minendtime = 999999999;
        for(int j = 0; j < k; j++) {
            if(table[j].end < minendtime) {
                minendtime = table[j].end;
                index = j;
            }
        }
        if(table[index].end >= 21 * 3600)
            break;
        if(player[i].vip == true && i < vipid) {
            i++;
            continue;
        }
        if(table[index].vip == true) {
            if(player[i].vip == true) {
                alloctable(i, index);
                if(vipid == i)
                    vipid = findnextvip(vipid);
                i++;
            } else {
                if(vipid < player.size() && player[vipid].arrive <= table[index].end) {
                    alloctable(vipid, index);
                    vipid = findnextvip(vipid);
                } else {
                    alloctable(i, index);
                    i++;
                }
            }
        } else {
            if(player[i].vip == false) {
                alloctable(i, index);
                i++;
            } else {
                int vipindex = -1, minvipendtime = 999999999;
                for(int j = 0; j < k; j++) {
                    if(table[j].vip == true && table[j].end < minvipendtime) {
                        minvipendtime = table[j].end;
                        vipindex = j;
                    }
                }
                if(vipindex != -1 && player[i].arrive >= table[vipindex].end) {
                    alloctable(i, vipindex);
                    if(vipid == i)
                        vipid = findnextvip(vipid);
                    i++;
                } else {
                    alloctable(i, index);
                    if(vipid == i)
                        vipid = findnextvip(vipid);
                    i++;
                }
            }
        }
    }
    sort(player.begin(), player.end(), cmp2);
    for(i = 0; i < player.size() && player[i].start < 21 * 3600; i++) {
        printf("%02d:%02d:%02d ", player[i].arrive / 3600, player[i].arrive % 3600 / 60, player[i].arrive % 60);
        printf("%02d:%02d:%02d ", player[i].start / 3600, player[i].start % 3600 / 60, player[i].start % 60);
        printf("%.0f\n", round((player[i].start - player[i].arrive) / 60.0));
    }
    for(int i = 0; i < k; i++) {
        if (i==k-1) {
            cout<<table[i].num<<endl;
        }else{
            cout<<table[i].num<<" ";
        }
    }
    return 0;
}
