#include <bits/stdc++.h>
#define debug(v,len) for(long long int i=0;i<len;++i)cout<<v[i]<<" ";cout<<endl;
#define debugMatrix(name,row,col) for(long long int i=0;i<row;++i){for(long long int j=0;j<col;++j)cout<<name[i][j]<<" ";cout<<endl;}
#define print(v) cout<<v<<endl;
#define gcd(v,h) __gcd(v,h)
#define popcount(v) __builtin_popcount(v)
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
bool isCPP(string x){
	if(x[0] == '_')
		return false;
	for(ll i = 0;i < x.length()-1;++i){
		if(x[i] == '_' && (x[i+1] >= 'A' && x[i+1] <= 'Z'))
			return false;
		if(x[i] == '_' && (x[i+1] == '_'))
			return false;
		if(!((x[i] >= 'a' && x[i] <= 'z') || (x[i] == '_')))
			return false;
	}
	if(!(x[x.length()-1] >= 'a' && x[x.length()-1] <= 'z'))
			return false;
	return true;
}
bool isJAVA(string x){
	if(x[0] >= 'A' && x[0] <= 'Z')
		return false;
	for(ll i = 0;i < x.length()-1;++i){
		if(x[i] == '_')
			return false;
		if(!((x[i] >= 'a' && x[i] <= 'z') || (x[i] >= 'A' && x[i] <= 'Z')))
			return false;
	}
	if(!((x[x.length()-1] >= 'a' && x[x.length()-1] <= 'z') || (x[x.length()-1] >= 'A' && x[x.length()-1] <= 'Z')))
		return false;
	return true;
}
string convertToCPP(string x){
	for(ll i = 1;i < x.length();++i){
		if(x[i] >= 'A' && x[i] <= 'Z'){
			string firstHalf = x.substr(0,i);
			string secondHalf = x.substr(i);
			secondHalf[0] += 32;
			x = firstHalf + '_' + secondHalf;
		}
	}
	return x;
}
string convertToJAVA(string x){
	for(ll i = 0;i < x.length()-1;++i){
		if(x[i] == '_'){
			string firstHalf = x.substr(0,i);
			string secondHalf = x.substr(i+1);
			secondHalf[0] -= 32;
			x = firstHalf + secondHalf;
		}
	}
	if(x[x.length()-1] == '_')
		x.erase(x.begin() + x.length()-1);
	return x;
}
int main(){	
	while(!cin.eof()){
		string x;
		cin >> x;
		if(isCPP(x)){
			cout << convertToJAVA(x) << endl;
		}
		else if(isJAVA(x)){
			cout << convertToCPP(x) << endl;
		}
		else{
			cout << "Error!" << endl;
		}
	}
	return 0;
}