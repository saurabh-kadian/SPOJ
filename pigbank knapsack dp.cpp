#include <bits/stdc++.h>
using namespace std;
typedef int ll;
typedef vector<ll> vll;
int main(){
    //freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	ll t;
	cin >> t;
	while(t--){
        ll e,f;
        cin >> e >> f;
        ll limit = f - e;
        ll n;
        cin >> n;
        ll dp[10000 + 2];
        vll v(n),w(n);
        fill(dp,dp + 10000 + 2,INT_MAX);
        for(ll i = 0;i < n;++i)
            cin >> v[i] >> w[i],w[i] < limit + 1 ? dp[w[i]] = min(dp[w[i]],v[i]) : limit = f - e;
        for(ll i = 1;i < limit + 1;++i){
            for(ll j = 0;j < n;++j)
                if(i - w[j] > 0 && dp[i-w[j]] != INT_MAX)
                    dp[i] = min(dp[i],dp[i-w[j]]+v[j]);
        }
        ll x = dp[limit];
        if(x == INT_MAX)
            cout << "This is impossible." << endl;
        else
            cout << "The minimum amount of money in the piggy-bank is " << x << ".\n";
	}
   	return 0;
}
