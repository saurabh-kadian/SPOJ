#include <bits/stdc++.h>
#define debugSTL14(v) for(auto it = v.begin();it != v.end();++it)cout << *it << endl;
#define debug(v,len) for(long long int i=0;i<len;++i)printf("%lld\n",v[i]);
#define debugMatrix(name,row,col) for(long long int i=0;i<row;++i){for(long long int j=0;j<col;++j)cout<<name[i][j]<<" ";cout<<endl;}
#define print(v) cout<<v<<endl;
#define gcd(v,h) __gcd(v,h)
#define popcount(v) __builtin_popcount(v)
#define sl(T) scanf("%lld",&T)
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int readInt () {
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}

map<ll, ll> save;

ll dp(ll index, vector<ll> &next){
	if(index >= next.size())
		return 0;
	if(save.find(index) != save.end())
		return save[index];
	if(next[index] == next.size())
		return save[index] = max((ll)1, dp(index + 1, next));
	return save[index] = max(1 + dp(next[index], next), dp(index + 1, next));
}

int main(){
	ll t = readInt();
	while(t--){
		save.clear();
		ll n = readInt();
		vector<pair<ll,ll> > V(n);
		for(int i = 0;i < n;++i)
			V[i].second = readInt(), V[i].first = readInt();
		sort(V.begin(), V.end());
		vector<ll> next(n);
		ll last = 1;
		for(int i = 0;i < n;++i){
			while(V[i].first > V[last].second && last < n)
				last++;
			next[i] = last;
		}
		// debug(next, next.size());
		printf("%lld\n", dp(0, next));
		// for(auto i = save.begin();i != save.end();++i)
		// 	cout << i->first << " " << i->second << endl;
	}
}