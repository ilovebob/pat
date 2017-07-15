//
//  main.cpp
//  1074. Reversing Linked List (25)
//
//  Created by 祝暾 on 2017/7/15.
//  Copyright © 2017年 祝暾. All rights reserved.
//

/*#include <iostream>
#include <cstdio>
using namespace std;
struct Node {
    int last,now,after,key;
}node[100000];
int main(int argc, const char * argv[]) {
    int start,n,k;
    cin>>start>>n>>k;
    for (int i=0; i<n; i++) {
        int temp;
        cin>>temp;
        cin>>node[temp].key>>node[temp].after;
        node[temp].now=temp;
    }
    int last=-1;
    int m = 0,l,last_node = 0;
    for (int i=start,j=1; i!=-1; i=node[i].after,j++) {
        if (j==k) {
            m=node[i].now;
            l=node[i].after;
        }
        if (node[i].after==-1) {
            last_node=node[i].now;
        }
        node[i].last=last;
        last=node[i].now;
    }
    for (int i=m; i!=node[m].after; ) {
        printf("%05d %d ",i,node[i].key);
        if (node[i].last==-1) {
            printf("%05d\n",last_node);
            i=last_node;
        }else{
            printf("%05d\n",node[i].last);
            i=node[i].last;
        }
    }
    printf("%05d %d -1\n",node[m].after,node[node[m].after].key);
    return 0;
}*/
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;

struct node
{
    int add;
    int data;
    int next;
};
int main()
{
    vector<node> vin(100000);//输入时暂存节点
    vector<node> vsorted;//暂存排序后的结果
    vector<node> vout;//最后的结果
    node temp;
    int first,N,K;
    
    scanf("%d%d%d",&first,&N,&K);
    
    for(int i = 0;i<N;i++)//输入
    {
        //cin>>temp.add>>temp.data>>temp.next;
        scanf("%d%d%d",&temp.add,&temp.data,&temp.next);
        vin[temp.add]=temp;
    }
    if(first == -1) //首地址为-1.直接输出
    {
        printf("-1\n");
    }
    else
    {
        int nextAdd = first;
        while(nextAdd !=-1)
        {
            vsorted.push_back(vin[nextAdd]);
            nextAdd = vin[nextAdd].next;
        }
        int Nnew = vsorted.size();//排序后的链的大小，不一定等于N，因为可能存在废点不在链上
        int right = K-1;
        while(right < Nnew)
        {
            for(int i=right;i>right-K;i--)
            {
                vout.push_back(vsorted[i]);
            }
            right += K;
        }
        for(int i = right-K+1;i<Nnew ;i++)
        {
            vout.push_back(vsorted[i]);
        }
        for(int i =0;i<Nnew-1;i++)
        {
            vout[i].next = vout[i+1].add;
            printf("%05d %d %05d\n",vout[i].add,vout[i].data,vout[i].next);
            //cout<<setw(5)<<setfill('0')<<vout[i].add<<" "<<vout[i].data<<" "<<setw(5)<<setfill('0')<<vout[i].next<<endl;
        }
        printf("%05d %d %d\n",vout[Nnew-1].add,vout[Nnew-1].data,-1);//最后地址-1 陷阱之一
        //cout<<setw(5)<<setfill('0')<<vout[Nnew-1].add<<" "<<vout[Nnew-1].data<<" "<<vout[Nnew-1].next<<endl;
    }
    system("pause");
    return 0;
}
