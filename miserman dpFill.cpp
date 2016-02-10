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
int main(){
	//freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
	ll n,m;
	cin >> n >> m;
	ll ip[n][m],dp[n][m];
	for(ll i = 0;i < n;++i)
        for(ll j = 0;j < m;++j)
            cin >> ip[i][j];
    for(ll j = 0;j < m;++j)
        dp[0][j] = ip[0][j];
    for(ll i = 1;i < n;++i){
        for(ll j = 0;j < m;++j){
            if(j == 0){
                dp[i][j] = min(dp[i-1][j],dp[i-1][j+1]) + ip[i][j];
            }
            else if(j != m-1){
                dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i-1][j+1])) + ip[i][j];
            }
            else{
                dp[i][j] = min(dp[i-1][j-1],dp[i-1][j]) + ip[i][j];
            }
        }
    }
    ll w = LLONG_MAX;
    for(ll j = 0;j < m;++j)
        w = min(w,dp[n-1][j]);
    cout << w << endl;
   	return 0;
}
