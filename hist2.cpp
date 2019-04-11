#include <bits/stdc++.h>
#define debug(v,len) for(long long int i=0;i<len;++i)printf("%lld\n",v[i]);
#define debugMatrix(name,row,col) for(long long int i=0;i<row;++i){for(long long int j=0;j<col;++j)cout<<name[i][j]<<" ";cout<<endl;}
#define gcd(v,h) __gcd(v,h)
#define popcount(v) __builtin_popcount(v)
#define sl(T) scanf("%lld",&T)
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

bitset<16> allSet(string("1111111111111111"));

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

struct Comparer {
    bool operator() (const pair<ll, bitset<16> > &b1, const pair<ll, bitset<16> > &b2) const {
        if(b1.first == b2.first)
        	return b1.second.to_ulong() < b2.second.to_ulong();
    	else
    		return b1.first < b2.first;
    }
};

map<pair<ll, bitset<16> >, pair<ll, ll>, Comparer> save;

pair<ll, ll> dp(ll lastIndex, bitset<16> bitmask, vector<ll> &arr){
	if(bitmask == allSet)
		return pair<ll,ll>(0, 1);
	if(save.find(make_pair(lastIndex, bitmask)) != save.end())
		return save[make_pair(lastIndex, bitmask)];
	// Choose which one ?
	map<ll, ll> internal;
	internal[0] = 1;
	for(int i = 0;i < arr.size();++i){
		if(!bitmask.test(i)){
			// Choose this
			bitmask.set(i);
			ll last = (lastIndex == -1 ? 0 : arr[lastIndex]);
			pair<ll, ll> ret = dp(i, bitmask, arr);
			ll newAdd = 2 + arr[i] + abs(last - arr[i]) - last;
			internal[newAdd + ret.first] += ret.second;
			bitmask.reset(i);
		}
	}
	return save[make_pair(lastIndex, bitmask)] = make_pair(internal.rbegin() -> first, internal.rbegin() -> second);
}

int main(){

	ll n = readInt();
	while(n != 0){
		save.clear();
		vector<ll> arr(n);
		for(int i = 0;i < n;++i)
			arr[i] = readInt();
		// sort(arr.begin(), arr.end());
		bitset<16> bitmask;
		pair<ll,ll> answer = dp(-1, bitmask,arr);
		printf("%lld %lld\n", answer.first, answer.second);
		n = readInt();
	}

	return 0;
}
