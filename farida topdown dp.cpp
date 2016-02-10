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
#include <bits/stdc++.h>
#define debug(v,len) for(long long int i=0;i<len;++i)cout<<v[i]<<" ";cout<<endl;
#define debugMatrix(name,row,col) for(long long int i=0;i<row;++i){for(long long int j=0;j<col;++j)cout<<name[i][j]<<" ";cout<<endl;}
#define print(v) cout<<v<<endl;
#define gcd(v,h) __gcd(v,h)
#define popcount(v) __builtin_popcount(v)
using namespace std;
typedef long long ll;
vector<ll> all;
//map<ll,ll> save;
ll dp[10005];
ll solve(ll start){
    if(start >= all.size())
        return 0;
    if(dp[start] != -1)
        return dp[start];
    return dp[start] = max(solve(start+1),all[start] + solve(start + 2));
}
int main(){
	ios_base::sync_with_stdio(false);
	ll t,m = 0;
	cin >> t;
	while(t--){
        ll n;
        cin >> n;
        //save.clear();
        fill(dp,dp+10005,-1);
        m++;
        all.resize(n);
        for(int i = 0;i < n;++i)
            cin >> all[i];
        cout << "Case " << m << ": " << solve(0) << endl;
	}
   	return 0;
}
