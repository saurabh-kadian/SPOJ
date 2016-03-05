// Problem SPOJ - Fibonacci Sum
// Sigma(1 to n) of F(n) = F(n+2) - 1, where F(n) is the nth fibonacci number, F(0) = 1
// Given F(0) = 0, we have use F(n) = F(n+2) + 1
// Matrix exponentiation method is used
// Matrix (1 1 1 0)^n  = ( F(n+1) F(n) F(n) F(n-1) )
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mat[2][2];
ll mod = 1000000007;
void square(){
	ll cal[2][2];
	cal[0][0] = mat[0][0]*mat[0][0] + mat[0][1]*mat[1][0];
	cal[0][1] = mat[0][0]*mat[0][1] + mat[0][1]*mat[1][1];
	cal[1][0] = mat[1][0]*mat[0][0] + mat[1][1]*mat[1][0];
	cal[1][1] = mat[1][0]*mat[0][1] + mat[1][1]*mat[1][1];
	mat[0][0] = cal[0][0];mat[1][0] = cal[1][0];mat[0][1] = cal[0][1];mat[1][1] = cal[1][1];
	mat[0][0] = mat[0][0]%mod;
	mat[0][1] = mat[0][1]%mod;
	mat[1][0] = mat[1][0]%mod;
	mat[1][1] = mat[1][1]%mod;
}
void multi(ll org[2][2]){
	ll cal[2][2];
	cal[0][0] = org[0][0]*mat[0][0] + org[0][1]*mat[1][0];
	cal[0][1] = org[0][0]*mat[0][1] + org[0][1]*mat[1][1];
	cal[1][0] = org[1][0]*mat[0][0] + org[1][1]*mat[1][0];
	cal[1][1] = org[1][0]*mat[0][1] + org[1][1]*mat[1][1];
	mat[0][0] = cal[0][0];mat[1][0] = cal[1][0];mat[0][1] = cal[0][1];mat[1][1] = cal[1][1];
	mat[0][0] = mat[0][0]%mod;
	mat[0][1] = mat[0][1]%mod;
	mat[1][0] = mat[1][0]%mod;
	mat[1][1] = mat[1][1]%mod;
}
void exponentiation(ll power){
	if(power == 1)
		return ;
	if(power%2 == 0){
		square();
		exponentiation(power/2);
	}
	else{
		ll temp[2][2];
		temp[0][0] = mat[0][0];
		temp[1][1] = mat[1][1];
		temp[1][0] = mat[1][0];
		temp[0][1] = mat[0][1];
		square();
		exponentiation(power/2);
		multi(temp);
	}
}
int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n,m;
		cin >> n;
		cin >> m;
		// call sum(m) - sum(n)
		// reset mat
		mat[0][0] = mat[1][0] = mat[0][1] = 1;
		mat[1][1] = 0;
		/*
		// test start
		exponentiation(n);
		cout << mat[0][1] << endl;
		continue;
		// test close
		*/
		exponentiation(m+2);
		ll value = mat[0][1];
		// reset mat
		mat[0][0] = mat[1][0] = mat[0][1] = 1;
		mat[1][1] = 0;
		exponentiation(n+1);
		//cout << mat[1][0] << " " << value << endl;
		cout << (value%mod - mat[1][0]%mod + mod)%mod << endl;
	}
	return 0;
}