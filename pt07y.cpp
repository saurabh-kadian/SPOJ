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
#define debug(v) for(long long int i=0;i<v.size();++i)cout<<v[i]<<" ";cout<<endl;
#define debugMatrix(name,row,col) for(long long int i=0;i<row;++i){for(long long int j=0;j<col;++j)cout<<name[i][j]<<" ";cout<<endl;}
#define variable(v) cout<<v<<endl;
using namespace std;
vector<int> disJoint;
bool findIndex(int node,int node1){
    if(disJoint[node] == disJoint[node1])
        return true;
    return false;
}
void doUnion(int node,int node1){
    for(int i = 1;i < disJoint.size();++i)
        if(disJoint[i] == disJoint[node])
            disJoint[i] = disJoint[node1];
    return ;
}
int main(){
	//freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
	/** will use BFS,
            trying DFS (Try sometime later, seems like #weakSpot),
                trying union find disjoint set DS ( Princeton University Excellent resource ) */
	int nodes,edges,m;
	cin >> nodes >> edges;
	bool initialChecks = false;
	for(int i = 0;i < nodes + 1;++i)
        disJoint.push_back(i);
    bool cycle = false;
	while(edges--){
        int a,b;
        cin >> a >> b;
        if(a == b)
            initialChecks = true;
        if(findIndex(a,b)){
            cycle = true;
            break;
        }
        else
            doUnion(a,b);
	}
	if(initialChecks || m > nodes - 1){
        cout << "NO" << endl;
        return 0;
    }
    if(cycle)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
   	return 0;
}
