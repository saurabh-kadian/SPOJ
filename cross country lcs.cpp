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
#include <bits/stdc++.h>
#include <limits.h>
#define debug(v,len) for(long long int i=0;i<len;++i)cout<<v[i]<<" ";cout<<endl;
#define debugMatrix(name,row,col) for(long long int i=0;i<row;++i){for(long long int j=0;j<col;++j)cout<<name[i][j]<<" ";cout<<endl;}
#define print(v) cout<<v<<endl;
#define gcd(v,h) __gcd(v,h)
#define popcount(v) __builtin_popcount(v)
using namespace std;
typedef long long ll;
vector<ll> agens;
ll LCS(vector<ll> other){
    ll dp[agens.size()+1][other.size()+1];
    for(ll i = 0;i < agens.size() + 1;++i){
        for(ll j = 0;j < other.size() + 1;++j){
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(agens[i-1] == other[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[agens.size()][other.size()];
}
int main(){
	//freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    ll t;
    cin >> t;
    while(t--){
        ll x,answer = LLONG_MIN;
        agens.clear();
        cin >> x;
        while(x)
            agens.push_back(x),cin >> x;
        ll y;
        cin >> y;
        while(y){
            ll x = y;
            vector<ll> check;
            while(x)
                check.push_back(x),cin >> x;
            answer = max(answer,LCS(check));
            cin >> y;
        }
        cout << answer << endl;
    }
   	return 0;
}
