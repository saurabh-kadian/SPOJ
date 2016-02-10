#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <cstdlib>
#include <string>
#include <cmath>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <iterator>
#include <iomanip>
#include <limits.h>
#include <bits/stdc++.h>
#define debug(name,size) for(long long int i=0;i<size;++i)cout<<name[i]<<" ";cout<<endl;
#define debugMatrix(name,row,col) for(long long int i=0;i<row;++i){for(long long int j=0;j<col;++j)cout<<name[i][j]<<" ";cout<<endl;}
using namespace std;
vector<int> graph[10002];
int main(){
    //freopen("input.txt","r",stdin);
    //ios_base::sync_with_stdio(false);
    int nodes;
    scanf("%d",&nodes);
    //vector<vector<int> > graph(nodes + 1,vector<int>(nodes+1,0));
    for(int i = 0;i < nodes - 1;++i){
        int a,b;
        scanf("%d %d",&a,&b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<bool> toVisit(nodes+1,true);
    toVisit[0] = toVisit[1] = false;
    queue<int> BFS;
    BFS.push(1);
    int lastNodeIndex = 0;
    int distance[nodes + 1];
    fill(distance,distance + nodes + 1,0);
    while(!BFS.empty()){
        int front = BFS.front();
        for(int i = 0;i < graph[front].size();++i)
            if(toVisit[graph[front][i]])
                BFS.push(graph[front][i]),toVisit[graph[front][i]] = false,distance[graph[front][i]] = distance[front] + 1;
        BFS.pop();
    }
    lastNodeIndex = 0;
    int val = INT_MIN;
    for(int i = 1;i < nodes + 1;++i)
        val <= distance[i] ? lastNodeIndex = i,val = distance[i] : val = val;
    vector<bool> toVisit1(nodes+1,true);
    toVisit1[0] = toVisit1[lastNodeIndex] = false;
    queue<int> BFSlevel;
    BFSlevel.push(lastNodeIndex);
    fill(distance,distance + nodes + 1,0);
    while(BFSlevel.size()){
        int front = BFSlevel.front();
        BFSlevel.pop();
        for(int i = 0;i < graph[front].size();++i){
            //debug(toVisit1,nodes+1);
            //cout << graph[front][i] << endl <<
            //toVisit1[graph[front][i]] << endl;
            if(toVisit1[graph[front][i]]){
                BFSlevel.push(graph[front][i]);
                toVisit1[graph[front][i]] = false;
                distance[graph[front][i]] = distance[front] + 1;
                //cout << graph[front][i] << " by " << front << endl;
            }
        }
    }
    //debug(distance,nodes+1);
    lastNodeIndex = *max_element(distance,distance+nodes+1);
    printf("%d\n",lastNodeIndex);
    return 0;
}
