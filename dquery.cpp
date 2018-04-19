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

struct pairTurnedStruct
{
	ll first, second, id;
};

struct compare{
	int blockSize;
	compare(int blockSize){
		this->blockSize = blockSize;
	}
	bool operator()(pairTurnedStruct x, pairTurnedStruct y){
		// True if first is smaller
		if(x.first/blockSize < y.first/blockSize)
			return true;
		else if(y.first/blockSize < x.first/blockSize)
			return false;
		else if(x.second < y.second)
			return true;
		else
			return false;
	}
};

// trying out MO's Algorithm
int main(){
	ll N;
	scanf("%lld", &N);
	int arr[N];
	for(int i = 0;i < N;++i)
		scanf("%lld", &arr[i]);

	ll q;
	scanf("%lld", &q);
	pairTurnedStruct query[q];
	//vector<pair<pair<ll,ll>, ll> > query(q);
	
	for(int i = 0;i < q;++i){
		scanf("%lld %lld", &query[i].first, &query[i].second);
		query[i].id = i;
	}
	sort(query, query + q, compare(sqrt(N)));
    
    /* DEBUG
    for(int i = 0;i < q;++i)
		cout << query[i].first.first << " " <<  query[i].first.second << " " << query[i].second << endl;
	   DEBUG */

	ll ans = 0;
	ll freq[1000005] = {0};
	ll moL = 0, moR = -1;
	ll answer[q];
	// The range is [L, R]
	for(int i = 0;i < q;++i){
		query[i].first--;
		query[i].second--;
		// while moR <
		while(moR > query[i].second){
			if(freq[arr[moR]] > 1)
				freq[arr[moR]]--;
			else if(freq[arr[moR]] == 1)
				freq[arr[moR]]--, ans--;
			moR--;
		}

		// while moR >
		while(moR < query[i].second){
			moR++;
			if(freq[arr[moR]] == 0)
				freq[arr[moR]]++, ans++;
			else
				freq[arr[moR]]++;
		}

		// while moL >
		while(moL > query[i].first){
			moL--;
			if(freq[arr[moL]] == 0)
				ans++, freq[arr[moL]]++;
			else
				freq[arr[moL]]++;
		}

		// while moL <
		while(moL < query[i].first){
			if(freq[arr[moL]] > 1)
				freq[arr[moL]]--;
			else if(freq[arr[moL]] == 1)
				freq[arr[moL]]--, ans--;
			moL++;
		}
		answer[query[i].id] = ans;
	}
	debug(answer, q);
	return 0;
}
