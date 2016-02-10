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
typedef vector<ll> vll;
int main(){
    //freopen("input.txt","r",stdin);
	ll n;
	while(scanf("%lld",&n) > 0){
        vll color(n);
        ll dp[n][n],cdp[n][n];
        memset(dp,0,sizeof(dp));
        memset(cdp,0,sizeof(cdp));
        for(ll i = 0;i < n;++i)
            cin >> color[i],cdp[i][i] = color[i];
        for(ll size = 1;size < n;++size){
            for(ll i = 0;i < n;++i){
                ll j = i + size;
                ll thisColor = 0,minVal = LLONG_MAX;
                if(j > n-1)
                    break;
                for(ll k = i;k < j;++k)
                    if(dp[i][k] + dp[k+1][j] + cdp[i][k]*cdp[k+1][j] < minVal)
                        minVal = dp[i][k] + dp[k+1][j] + cdp[i][k]*cdp[k+1][j],thisColor = (cdp[i][k] + cdp[k+1][j] )%100;
                dp[i][j] = minVal,cdp[i][j] = thisColor;
            }
            //debugMatrix(dp,n,n);
            //debugMatrix(cdp,n,n);
        }
        cout << dp[0][n-1] << endl;
	}
   	return 0;
}
