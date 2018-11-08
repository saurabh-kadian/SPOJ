// UVa number - name
#include <bits/stdc++.h>
#define debug(v,len) for(long long int i=0;i<len;++i)cout<<v[i]<<" ";cout<<endl;
#define debugMatrix(name,row,col) for(long long int i=0;i<row;++i){for(long long int j=0;j<col;++j)cout<<name[i][j]<<" ";cout<<endl;}
#define print(v) cout<<v<<endl;
#define gcd(v,h) __gcd(v,h)
#define popcount(v) __builtin_popcount(v)
#define sl(T) scanf("%lld",&T)
using namespace std;
typedef long long ll;

map<pair<ll, pair<ll, bool> >, ll> save;

ll solve(ll index, ll till, bool pickedLast, ll& cap, vector<ll>& val){
    if(index >= val.size())
        return 0;
    if(val[index] + till > cap)
        return solve(index + 1, till, false, cap, val);

    if(save.find(make_pair(index, make_pair(till, pickedLast))) != save.end())
        return save[make_pair(index, make_pair(till, pickedLast))];
    // can't pick
        if(pickedLast)
            return save[make_pair(index, make_pair(till, pickedLast))] = solve(index + 1, till, false, cap, val);
    // can pick
        else
            return save[make_pair(index, make_pair(till, pickedLast))] = max(solve(index + 1, till, false, cap, val), solve(index + 1, till + val[index], true, cap, val) + val[index]);
}

ll solveBottomUp(ll s, vector<ll> val){
    // vector<vector<vector<ll> > > dp(val.size(), vector<vector<ll> >(cap, vector<ll>(2, 0)));
    ll cap = s + 5;
    ll dp[val.size()][cap][2];
    for(int i = 0;i < val.size();++i)
        for(int j = 0;j < cap;++j)
            for(int k = 0;k < 2;++k)
                dp[i][j][k] = 0;
    for(int i = 0;i < val.size();++i){
        for(int j = 0;j < cap;++j){
            if(i == 0)
                dp[i][j][0] = 0, dp[i][j][1] = (j - val[i] >= 0 ? val[i] : 0);
            else{
                dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1]);
                dp[i][j][1] = (j - val[i] >= 0 ? dp[i - 1][j - val[i]][0] + val[i] : dp[i-1][j][0]);
            }
        }
    }
    // for(int i = 0;i < val.size();++i)
    //     for(int j = 0;j < cap;++j)
    //         for(int k = 0;k < 2;++k)
    //             cout << "(" << i << "," << j << "," << k << ") : " << dp[i][j][k] << endl;

    return max(dp[val.size()-1][s][0], dp[val.size()-1][s][1]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
    for(ll q = 1;q <= t;++q){
        save.clear();
        ll n,cap;
        cin >> n >> cap;
        vector<ll> val(n);
        for(ll i = 0;i < n;++i)
            cin >> val[i];
        // cout << "Scenario #" << q << ": " << solve(0, 0, false, cap, val) << endl;
        cout << "Scenario #" << q << ": " << solveBottomUp(cap, val) << endl;
    }
    return 0;
}
