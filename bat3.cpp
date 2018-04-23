#include <bits/stdc++.h>
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

ll robinAt;
map<pair<ll, ll>, ll> save;

ll dp(ll index, ll lastIndex, vector<ll> &peaks){
	if(index >= peaks.size())
		return 0;
	if(save.find(make_pair(index, lastIndex)) != save.end())
		return save[make_pair(index, lastIndex)];
	ll answer = 0;
	if(index == robinAt && peaks[index] < peaks[lastIndex]){
		// Take mini-bat or ignore
			// Took it
			ll take = 1;
			for(int i = index + 1;i < peaks.size();++i){
				// Jump to anyone of these
				take = max(take, 1 + dp(i, index, peaks));
			}
			ll noTake = dp(index + 1, lastIndex, peaks);
		answer = max(take, noTake);
	}
	// Check if downhill
	if(peaks[index] < peaks[lastIndex] || lastIndex == robinAt){
		answer = max(1 + dp(index + 1, index, peaks), dp(index + 1, lastIndex, peaks));
	}
	else
		answer = dp(index + 1, lastIndex, peaks);
	return save[make_pair(index, lastIndex)] = answer;
}

int main(){
	ll t = readInt();
	while(t--){
		save.clear();
		ll n = readInt();
		robinAt = readInt();
		robinAt++;
		vector<ll> peaks(n + 1);
		for(int i = 1;i < n + 1;++i)
			peaks[i] = readInt();
		peaks[0] = LLONG_MAX;
		// Batman can jump start from any hill
		ll answer = dp(1, 0, peaks);
		printf("%lld\n", answer);
	}
	return 0;
}