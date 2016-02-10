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
ll dp[100][100];
ll solve(ll n,ll k){
    if(n == 0)
        return 0;
    if(k == 0)
        return 1;
    if(dp[n][k] != -1)
        return dp[n][k];
    ll answer = 0;
    if(k > (n*(n-1))/2)
        return 0;
    for(ll i = max((ll)0,k - n + 1);i <= min(k,((n*(n-1))/2));++i)
        answer += solve(n-1,i);
    return dp[n][k] = answer;
}
int main(){
	ios_base::sync_with_stdio(false);
	ll t;
	cin >> t;
	while(t--){
        memset(dp,-1,sizeof(dp));
        ll n,k;
        cin >> n >> k;
        cout << solve(n,k) << endl;
	}
   	return 0;
}
