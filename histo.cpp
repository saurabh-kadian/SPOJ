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
	ll n;
	cin >> n;
	while(n != 0){
		vll arr(n);
		for(ll i = 0;i < n;++i)
			cin >> arr[i];
		// referred geeksforgeeks
		stack<pair<ll,ll> > st;
		st.push(make_pair(arr[0], 0));
		ll maxi = arr[0];
		for(ll i = 1;i < n;++i){
			if(st.empty() || arr[i] >= st.top().first){
				st.push(make_pair(arr[i], i));
			}
			else{
				while(st.size() > 1 && st.top().first > arr[i]){
					pair<ll,ll> save = st.top();
					st.pop();
					maxi = max(maxi, (i - st.top().second - 1) * save.first);
				}
				if(st.size() == 1 && st.top().first > arr[i]){
					pair<ll,ll> save = st.top();
					st.pop();
					maxi = max(maxi, i * save.first);
				}
				st.push(make_pair(arr[i],i));
			}
		}
		while(st.size() > 1){
			pair<ll,ll> save = st.top();
			st.pop();
			maxi = max(maxi, (n - st.top().second - 1) * save.first);
		}
		pair<ll,ll> save = st.top();
		st.pop();
		maxi = max(maxi, n * save.first);
		cout << maxi << endl;
		cin >> n;
	}
	return 0;
}