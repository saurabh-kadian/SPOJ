#include <bits/stdc++.h>
#define eps (1e-10)
#define all(a) a.begin(),a.end()
#define debug(v,len) for(long long int i=0;i<len;++i)cout<<v[i]<<" ";cout<<endl;
#define debugMatrix(name,row,col) for(long long int i=0;i<row;++i){for(long long int j=0;j<col;++j)cout<<name[i][j]<<" ";cout<<endl;}
#define print(v) cout<<v<<endl;
#define gcd(v,h) __gcd(v,h)
#define popcount(v) __builtin_popcount(v)
#define sl(v) scanf("%lld",&v)
#define si(v) scanf("%d",&v)
#define toLow(v) transform(v.begin(),v.end(),v.begin(),::tolower)
using namespace std;
typedef long long ll;
int main(){
	//freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	vector<ll> power;
	ll two = 1;
	power.push_back(two);
	for(ll i = 1;i < 30;++i){
        two *= 2;
        power.push_back(two);
	}
	while(1){
        string str;
        cin >> str;
        if(str == "00e0")
            break;
        ll number = (str[0] - 48) * 10 + (str[1] - 48);
        ll powOfTen = str[3]-48;
        powOfTen = powl(10,powOfTen);
        number *= powOfTen;
        vector<ll>::iterator it = lower_bound(power.begin(),power.end(),number);
        if(*it != number)
            it--;
        cout << 2 * (number-*it) + 1 << endl;
	}
   	return 0;
}
