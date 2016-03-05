// Problem Prime Path - SPOJ
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool isPrime(ll n){
	if(n == 2 || n == 3)
		return true;
	if(n%2 == 0 || n%3 == 0)
		return false;
	for(ll i = 5;i*i <= n;i += 6)
		if(n%i == 0 || n%(i+2) == 0)
			return false;
	return true;
}

vector<long long int> primes;

void prime(){
    long long int n = 10000;
    bool all[n+2];
    for(long int i = 0 ; i < n+2 ; ++i)
        all[i] = true;
    for(long long int i = 2; i*i < n+2 ; ++i){
        if(all[i] == true){
            for(long long int j = i*i ; j < n+2 ; j += i)
                all[j] = false;
        }
    }
    for(long long int i = 1000; i < n+2 ; ++i)
        if(all[i] == true)
            primes.push_back(i);
}

bool checkEdge(ll a,ll b){
	int c = 0;
	ll a1 = a/1000,a2 = (a/100)%10,a3 = (a/10)%10,a4 = a%10;
	ll b1 = b/1000,b2 = (b/100)%10,b3 = (b/10)%10,b4 = b%10;
	if(a1 != b1)	c++;
	if(a2 != b2)	c++;
	if(a3 != b3)	c++;
	if(a4 != b4)	c++;
	if(c == 1)
		return true;
	else
		return false;
}

int main(){
	prime();
	//cout << primes.size() << endl;
	vector<set<ll> > all(10000);
	//cout << "INIT_DONE" << endl;
	for(ll i = 0;i < primes.size()-1;++i)
		for(ll j = 0;j < primes.size();++j)
			if(checkEdge(primes[i],primes[j])){
				all[primes[i]].insert(primes[j]);
				all[primes[j]].insert(primes[i]);
			}
	ll t;
	cin >> t;
	while(t--){
		ll x,y;
		cin >> x >> y;
		ll minY = LLONG_MAX;
		vector<bool> visited(10000,false);
		visited[x] = true;
		queue<pair<ll,ll> > Q;
		Q.push(make_pair(x,0));
		while(!Q.empty()){
			pair<ll,ll> fronter = Q.front();
			if(fronter.first == y){
				minY = min(minY,fronter.second);
			}
			for(set<ll>::iterator i = all[fronter.first].begin();i != all[fronter.first].end();++i){
				if(!visited[*i]){
					Q.push(make_pair(*i,fronter.second + 1));
					visited[*i] = true;
					//cout << fronter.first << " " << all[fronter.first][i] << endl;
				}
			}
			Q.pop();
			//cout << "Size " << Q.size() << endl;
		}
		if(minY == LLONG_MAX)
			cout << "Impossible\n";
		else
			cout << minY << endl;
	}
	//cout << "DONE\n";
	return 0;
}