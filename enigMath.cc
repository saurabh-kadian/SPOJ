#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ll t;
	cin >> t;
	while(t--){
		ll a,b,gcd;
		cin >> a >> b;
		gcd = __gcd(a,b);
		cout << b/gcd << " " << a/gcd << endl; 
	}
	return 0;
}