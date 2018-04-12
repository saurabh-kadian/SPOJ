#include <bits/stdc++.h>
#define debug(v,len) for(long long int i=0;i<len;++i)cout<<v[i]<<" ";cout<<endl;
#define debugMatrix(name,row,col) for(long long int i=0;i<row;++i){for(long long int j=0;j<col;++j)cout<<name[i][j]<<" ";cout<<endl;}
#define print(v) cout<<v<<endl;
#define gcd(v,h) __gcd(v,h)
#define popcount(v) __builtin_popcount(v)
#define sl(T) scanf("%lld",&T)
using namespace std;
typedef int ll;
typedef vector<ll> vll;

ll A[50005];
ll N;

struct segTreeW{
	ll segTreeSum;
	ll segTreeMax;
	ll segTreePrefix;
	ll segTreeSuffix;	
};

struct segTreeW segTree[3*50005];

struct tempNode{
	ll sum, maxi, prefix, suffix;
};

void buildTree(ll rangeStart, ll rangeEnd, ll index){
	if(rangeStart == rangeEnd){
		segTree[index].segTreeSuffix = segTree[index].segTreePrefix = segTree[index].segTreeMax = segTree[index].segTreeSum = A[rangeStart];
		return ;
	}

	ll leftChild = 2*index + 1;
	ll rightChild = 2*index + 2;
	ll mid = (rangeStart + rangeEnd)/2;
	buildTree(rangeStart, mid, leftChild);
	buildTree(mid + 1, rangeEnd, rightChild);

	segTree[index].segTreeSum = segTree[leftChild].segTreeSum + segTree[rightChild].segTreeSum;
	segTree[index].segTreePrefix = max(segTree[leftChild].segTreePrefix, segTree[leftChild].segTreeSum + segTree[rightChild].segTreePrefix);
	segTree[index].segTreeSuffix = max(segTree[rightChild].segTreeSuffix, segTree[rightChild].segTreeSum + segTree[leftChild].segTreeSuffix);
	segTree[index].segTreeMax = max(segTree[leftChild].segTreeMax, max(segTree[rightChild].segTreeMax,
							segTree[leftChild].segTreeSuffix + segTree[rightChild].segTreePrefix));
	return ;
}

tempNode answer(ll wantedLeft, ll wantedRight, ll rangeStart, ll rangeEnd, ll index){
	ll mid = (rangeStart + rangeEnd)/2;
	tempNode final;
	
	if(rangeStart == wantedLeft && rangeEnd == wantedRight){
		final.sum = segTree[index].segTreeSum;
		final.maxi = segTree[index].segTreeMax;
		final.prefix = segTree[index].segTreePrefix;
		final.suffix = segTree[index].segTreeSuffix;
		return final;
	}
	else if(wantedRight <= (rangeStart + rangeEnd)/2)									// Is in the left section
		return answer(wantedLeft, wantedRight, rangeStart, mid, 2 * index + 1);
	else if(wantedLeft >= (rangeStart + rangeEnd)/2 + 1)								// Is in the right section
		return answer(wantedLeft, wantedRight, mid + 1, rangeEnd, 2 * index + 2);
	else{
		tempNode left, right;
		left = answer(wantedLeft, mid, rangeStart, mid, 2*index + 1);
		right = answer(mid + 1, wantedRight, mid + 1, rangeEnd, 2*index + 2);
		final.sum = left.sum + right.sum;
		final.prefix = max(left.prefix, left.sum + right.prefix);
		final.suffix = max(right.suffix, right.sum + left.suffix);
		final.maxi = max(left.maxi, max(right.maxi, left.suffix + right.prefix));
		return final;
	}
}

int main(){
	scanf("%d", &N);
	for(ll i = 0;i < N;++i)
		scanf("%d", &A[i]);
	buildTree(0, N-1, 0);
	ll q;
	scanf("%d", &q);
	while(q--){
		ll u,v;
		scanf("%d %d", &u, &v);
		u--,v--;
		tempNode ans = answer(u, v, 0, N-1, 0);
		printf("%d\n", ans.maxi);
	}

	return 0;
}
