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
	ll t;
	cin >> t;
	while(t--){
        ll order;
        cin >> order;
        vector<pair<pair<ll,ll>,ll> > input(order+1);
        vector<ll> answer(order+1);
        answer[0] = 0;
        input[0] = make_pair(make_pair(-1,-1),0);
        for(ll i = 1;i <= order;++i){
            ll a,b,c;
            cin >> a >> b >> c;
            input[i] = make_pair(make_pair(a+b,a),c);
        }
        sort(input.begin(),input.end());
        //for(ll i = 1;i <= order;++i)
        //    cout << input[i].first.second << " " << input[i].first.first << " " << input[i].second << endl;
        for(ll i = 1;i <= order;++i){
            // the job finishes at input[i].first.first
            ll x = 0;
            bool choose = false;
            ll val = 0;
            for(ll j = i-1;j > 0 && !choose;--j){
                if(input[j].first.first <= input[i].first.second)
                    x = j,choose = true;
            }
            if(!choose)
                x = 0;
            answer[i] = max(answer[i-1],answer[x] + input[i].second);
            //cout << answer[i] << " ";
        }
        cout << answer[order] << endl;
	}
   	return 0;
}
