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
int main(){
	//freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    long long int t;
    cin >> t;
    while(t != 0){
        vector<long long int> all(t);
        for(long long int i=0;i<t;++i)
            cin >> all[i];
        vector<long long int> copyAll = all;
        bool can = true;
        stack<long long int> road;
        vector<long long int> moved;
        for(long long int i=0;i<all.size();++i){
            if(i != all.size()-1){
                if(all[i] > all[i+1]){
                    if(road.size() > 0 && all[i] > road.top()){
                        while(road.size() > 0 && all[i] > road.top())
                            moved.push_back(road.top()),road.pop();
                        road.push(all[i]);
                    }
                    else
                        road.push(all[i]);
                }
                else{
                    while(road.size() > 0 && all[i] > road.top())
                        moved.push_back(road.top()),road.pop();
                    moved.push_back(all[i]);
                }
            }
            else{
                if(road.size() > 0 && all[i] > road.top()){
                    while(road.size() > 0 && all[i] > road.top())
                        moved.push_back(road.top()),road.pop();
                    road.push(all[i]);
                }
                else{
                    while(road.size() > 0 && all[i] > road.top())
                        moved.push_back(road.top()),road.pop();
                    moved.push_back(all[i]);
                }
            }
        }
        while(road.size())
            moved.push_back(road.top()),road.pop();
        sort(copyAll.begin(),copyAll.end());
        for(long long int i=0;i<copyAll.size();++i)
            if(moved[i] != copyAll[i]){
                can = false;break;}
        if(can)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
        cin >> t;
    }
   	return 0;
}
