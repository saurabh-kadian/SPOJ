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
using namespace std;
typedef long long ll;
int main(){
	//freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	ll t;
	cin >> t;
	while(t--){
        double a,b,c,A,B,C;
        cin >> a >> b >> c >> C >> B >> A;
        double a1,b1,c1;
        a1 = b*b + c*c - A*A;
        b1 = a*a + c*c - B*B;
        c1 = a*a + b*b - C*C;
        double V = (1.0/12.0) * (sqrt(4*a*a*b*b*c*c - a*a*a1*a1 - b*b*b1*b1 - c*c*c1*c1 + a1*b1*c1));
        printf("%0.4lf\n",V);
	}
   	return 0;
}
