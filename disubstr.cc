// Problem - Distinct Substring
// Uses - Suffix Arrays and finding LCP
// Distinct substrings are those which are not included in the LCP
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// returns suffix arrays
vector<string> suffix(string s){
	vector<string > suffixArr;
	for(ll i = 0;i < s.length();++i)
		suffixArr.push_back(s.substr(i));
	sort(suffixArr.begin(),suffixArr.end());
	return suffixArr;
}
// returns length of LCP
ll LCP(string a,string b){
	ll i = 0;
	while(i < a.length() && i < b.length() && a[i] == b[i])
		i++;
	return i;
}
int main(){
	ll t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		vector<string > suffixArr = suffix(s);
		ll answer = suffixArr[0].length();
		for(ll i = 1;i < suffixArr.size();++i){
			answer += suffixArr[i].length() - LCP(suffixArr[i],suffixArr[i-1]);
			//cout << LCP(suffixArr[i],suffixArr[i-1]) << endl;
		}
		cout << answer << endl;
	}
	return 0;
}