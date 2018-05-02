#include <bits/stdc++.h>
#define debug(v,len) for(long long int i=0;i<len;++i)printf("%lld\n",v[i]);
#define debugMatrix(name,row,col) for(long long int i=0;i<row;++i){for(long long int j=0;j<col;++j)cout<<name[i][j]<<" ";cout<<endl;}
#define gcd(v,h) __gcd(v,h)
#define popcount(v) __builtin_popcount(v)
#define sl(T) scanf("%lld",&T)
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

ll allSet;
ll dpMaxVal[16][1<<16];
ll dpCount[16][1<<16];

pair<ll, ll> dp(ll lastIndex, ll bitmask, vector<ll> &arr){
	if(lastIndex != -1 && dpMaxVal[lastIndex][bitmask] != -1)
		return make_pair(dpMaxVal[lastIndex][bitmask], dpCount[lastIndex][bitmask]);

	// Choose which one ?
	ll maxi = 0;
	ll cnt = 1;
	for(int i = 0;i < arr.size();++i){
		if(!(bitmask & (1<<i))){
			// Choose this
			if((bitmask | (1<<i)) == allSet){
				ll last = (lastIndex == -1 ? 0 : arr[lastIndex]);
				pair<ll, ll> ret(0, 1);
				ll newAdd = 2 + arr[i] + abs(last - arr[i]) - last;
				if(newAdd + ret.first > maxi)
					maxi = newAdd + ret.first, cnt = ret.second;
				else if(newAdd + ret.first == maxi)
					cnt += ret.second;
			}
			else{
				ll last = (lastIndex == -1 ? 0 : arr[lastIndex]);
				pair<ll, ll> ret = dp(i, (bitmask | (1<<i)), arr);
				ll newAdd = 2 + arr[i] + abs(last - arr[i]) - last;
				if(newAdd + ret.first > maxi)
					maxi = newAdd + ret.first, cnt = ret.second;
				else if(newAdd + ret.first == maxi)
					cnt += ret.second;
			}
		}
	}
	
	if(lastIndex == -1)
		return make_pair(maxi, cnt);
	dpMaxVal[lastIndex][bitmask] = maxi;
	dpCount[lastIndex][bitmask] = cnt;
	return make_pair(dpMaxVal[lastIndex][bitmask], dpCount[lastIndex][bitmask]);
}

int main(){

	ll n;
	scanf("%lld", &n);
	while(n != 0){
		allSet = (1<<n) - 1;

		memset(dpMaxVal, -1, sizeof(dpMaxVal));
		memset(dpCount ,  0, sizeof(dpCount) );

		vector<ll> arr(n);
		for(int i = 0;i < n;++i)
			scanf("%lld", &arr[i]);

		ll bitmask = 0;
		pair<ll,ll> answer = dp(-1, bitmask,arr);
		printf("%lld %lld\n", answer.first, answer.second);
		
		scanf("%lld", &n);
	}

	return 0;
}
