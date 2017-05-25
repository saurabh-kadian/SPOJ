#include <bits/stdc++.h>
#define debug(v,len) for(long long int i=0;i<len;++i)cout<<v[i]<<" ";cout<<endl;
#define debugMatrix(name,row,col) for(long long int i=0;i<row;++i){for(long long int j=0;j<col;++j)cout<<name[i][j]<<" ";cout<<endl;}
#define print(v) cout<<v<<endl;
#define gcd(v,h) __gcd(v,h)
#define popcount(v) __builtin_popcount(v)
#define sl(T) scanf("%lld",&T)
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll testCases;
	cin >> testCases;
	vll input(testCases);
	for(ll testCase = 1;testCase <= testCases;++testCase){
		cin >> input[testCase-1];
	}
	sort(input.begin(), input.end());
	ll n =  testCases;
	vector<ll> atimeb, eplusf, abc, efd;
	for(ll i = 0;i < n;++i)
		for(ll j = 0;j < n;++j)
			atimeb.push_back(input[i]*input[j]), eplusf.push_back(input[i]+input[j]);
	for(ll i = 0;i < n;++i){
		for(ll j = 0;j < atimeb.size();++j){
			abc.push_back(atimeb[j] + input[i]);
			if(input[i] != 0)
				efd.push_back(input[i] * eplusf[j]);
		}
	}
	// debug(abc, abc.size());
	// debug(efd, efd.size());
	sort(efd.begin(), efd.end());
	ll answer = 0;
	for(ll i = 0;i < abc.size();++i){
		answer += distance(lower_bound(efd.begin(), efd.end(), abc[i]), upper_bound(efd.begin(), efd.end(), abc[i]));
	}
	cout << answer << endl;
	return 0;
}