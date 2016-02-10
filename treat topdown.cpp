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
typedef long long ll;
vector<ll> all;
ll dp[2000][2000];
ll solve(ll start,ll last,ll age){
    if(start == last)
        return dp[start][last] = all[start]*age;
    if(dp[start][last] != -1)
        return dp[start][last];
    return dp[start][last] = max(all[start]*age + solve(start+1,last,age+1),all[last]*age + solve(start,last-1,age+1));
}
int main(){
	//freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
	ll n;
	cin >> n;
	all.resize(n);
	for(ll i = 0;i < n;++i)
        cin >> all[i];
    memset(dp,-1,sizeof(dp));
    cout << solve(0,n-1,1) << endl;
   	return 0;
}
