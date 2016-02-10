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
	ios_base::sync_with_stdio(false);
	while(1){
        ll budget,party;
        cin >> budget >> party;
        if(budget == 0 && party == 0)
            break;
        vll cost(party+1),fun(party+1);
        for(ll i = 1;i < party+1;++i)
            cin >> cost[i] >> fun[i];
        ll dp[party+1][budget+1];
        for(ll i = 0;i < party+1;++i){
            for(ll j = 0;j < budget+1;++j){
                if(i == 0 || j == 0)
                    dp[i][j] = 0;//,costdp[i][j] = 0;
                else if(j-cost[i] >= 0)
                    dp[i-1][j] >= fun[i] + dp[i-1][j-cost[i]] ?
                        dp[i][j] = dp[i-1][j]://,costdp[i][j] = costdp[i-1][j] :
                        dp[i][j] = fun[i] + dp[i-1][j-cost[i]];//,costdp[i][j] = costdp[i-1][j-cost[i]] + cost[i];
                else
                    dp[i][j] = dp[i-1][j];//,costdp[i][j] = costdp[i-1][j];
            }
        }
        ll costFinal = 0;
        for(ll j = budget-1;j >= 0 && (costFinal = j) && dp[party][budget] == dp[party][j];--j);
        cout << costFinal+1 << " " << dp[party][budget] << endl;
	}
   	return 0;
}
