#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <iterator>
#include <iomanip>
#include <limits.h>
#define debug(v,len) for(long long int i=0;i<len;++i)cout<<v[i]<<" ";cout<<endl;
#define debugMatrix(name,row,col) for(long long int i=0;i<row;++i){for(long long int j=0;j<col;++j)cout<<name[i][j]<<" ";cout<<endl;}
#define print(v) cout<<v<<endl;
#define gcd(v,h) __gcd(v,h)
#define popcount(v) __builtin_popcount(v)
using namespace std;
int main(){
	//freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
	long long cap,take;
	cin >> cap >> take;
	long long weight[take],value[take];
	for(long long i = 0;i < take;++i)
        cin >> weight[i] >> value[i];
    //long long maxWeight = *max_element(weight,weight+take);
    long long knapsack[take+1][cap+1];
    for(long long i = 0;i < take + 1;++i){
        for(long long j = 0;j < cap+1;++j){
            if(i == 0 || j == 0)
                knapsack[i][j] = 0;
            else if(j - weight[i-1] >= 0)
                knapsack[i][j] = max(knapsack[i-1][j],knapsack[i-1][j-weight[i-1]] + value[i-1]);
            else
                knapsack[i][j] = knapsack[i-1][j];
        }
    }
    //debugMatrix(knapsack,take+1,cap+1);
    cout << knapsack[take][cap] << endl;
   	return 0;
}
