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
	ll testCases;
	cin >> testCases;
	for(ll testCase = 1;testCase <= testCases;++testCase){
		string str;
		cin >> str;
		set<string> first, last;
		string rev = str;
		reverse(rev.begin(), rev.end());
		for(ll size = 1;size <= str.size();++size){
			for(ll start = 0;start <= str.size()-size;++start){
				first.insert(str.substr(start, size));
				last.insert(rev.substr(start, size));
			}
		}
		if(first == last)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}