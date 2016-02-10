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
    ll k,l,q;
    cin >> k >> l >> q;
    // A wins = true, B wins = false
    bool dp[1000005];
    dp[0] = false;
    for(ll i = 1;i < 1000005;++i){
        dp[i] = false;
        if(i - k >= 0 && dp[i-k] == false) dp[i] = true;
        else if(i - l >= 0 && dp[i-l] == false) dp[i] = true;
        else if(dp[i-1] == false) dp[i] = true;
    }
    string answer = "";
    while(q--){
        ll toCheck;
        cin >> toCheck;
        dp[toCheck] ? answer += 'A' : answer += 'B';
    }
    cout << answer << endl;
   	return 0;
}
