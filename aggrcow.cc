#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool checkIfPossible(ll minDiff,vector<ll> stalls,ll cows){
	ll alloted = 1;
	ll last = stalls[0];
	for(ll i = 1;i < stalls.size();++i){
		if(stalls[i] - last >= minDiff){
			alloted++;
			if(alloted == cows)
				return true;
			last = stalls[i];
		}
	}
	return false;
}
ll answer(vector<ll> stalls,ll cows){
	ll start = 0,end = stalls[stalls.size()-1];
	while(start < end){
		ll mid = (start+end)/2;
		if(checkIfPossible(mid,stalls,cows)){
			start = mid+1;
		}
		else{
			end = mid;
		}
	}
	return start-1;
}
int main(){
	//freopen("input.txt","r",stdin);
	ll t;
	cin >> t;
	while(t--){
		ll stalls,cows;
		cin >> stalls >> cows;
		vector<ll> stallPosi(stalls);
		//vector<bool> filled(stalls);
		for(ll i = 0;i < stalls;++i){
			cin >> stallPosi[i];
		}
		sort(stallPosi.begin(),stallPosi.end());
		cout << answer(stallPosi,cows) << endl;
	}	
	return 0;
}
