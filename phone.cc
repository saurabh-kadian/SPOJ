#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll LCP(string a,string b){
	ll i = 0;
	while(i < a.length() && i < b.length() && a[i] == b[i])
		i++;
	return i;
}
int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		vector<string> all(n);
		for(ll i = 0;i < n;++i)
			cin >> all[i];
		sort(all.begin(),all.end());
		bool breaker = false;
		for(ll i = 0;i < n-1 && !breaker;++i){
			ll val = LCP(all[i],all[i+1]);
			breaker = (val == all[i].length() || val == all[i+1].length() ? true : false);
		}
		if(breaker)
			cout << "NO\n";
		else
			cout << "YES\n";
	}
	return 0;
}