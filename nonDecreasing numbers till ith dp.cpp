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
	ios_base::sync_with_stdio(false);
    ll t;
    cin >> t;
    while(t--){
        ll p,n;
        cin >> p >> n;
        vector<ll> dp(10,1);
        for(ll i = 2;i <= n;++i){
            vector<ll> temp = dp;
            for(ll j = 0;j < 10;++j)
                for(ll k = j+1;k < 10;++k)
                    temp[k] += dp[j];
            dp = temp;
        }
        ll answer = 0;
        for(ll j = 0;j < 10;++j)
            answer += dp[j];
        cout <<  p << " " << answer << endl;
    }
   	return 0;
}
