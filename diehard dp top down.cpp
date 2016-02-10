#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <iterator>
#include <iomanip>
#include <limits.h>
#define debug(v,len) for(long long int i=0;i<len;++i)cout<<v[i]<<" ";cout<<endl;
#define debugMatrix(name,row,col) for(long long int i=0;i<row;++i){for(long long int j=0;j<col;++j)cout<<name[i][j]<<" ";cout<<endl;}
#define print(v) cout<<v<<endl;
#define gcd(v,h) __gcd(v,h)
#define popcount(v) __builtin_popcount(v)
using namespace std;
typedef long long ll;
ll dpFire[1005][1005];
ll dpWater[1005][1005];
ll dpAir[1005][1005];
ll fire(ll h,ll a);
ll water(ll h,ll a);
ll air(ll h,ll a);
ll fire(ll h,ll a){
    if(h - 20 <= 0)
        return 0;
    if(dpFire[h][a] != -1)
        return dpFire[h][a];
    return dpFire[h][a] = max(1 + air(h - 20,a + 5),1 + water(h - 20,a + 5));
}
ll water(ll h,ll a){
    if(h - 5 <= 0 || a - 10 <= 0)
        return 0;
    if(dpWater[h][a] != -1)
        return dpWater[h][a];
    return dpWater[h][a] = max(1 + fire(h-5,a-10),1 + air(h-5,a - 10));
}
ll air(ll h,ll a){
    if(dpAir[h][a] != -1)
        return dpAir[h][a];
    return dpAir[h][a] = max(1 + fire(h+3,a+2),1 + water(h+3,a +2));
}
int main(){
	ios_base::sync_with_stdio(false);
    ll t;
    cin >> t;
    while(t--){
        ll h,a;
        cin >> h >> a;
        memset(dpFire,-1,sizeof(dpFire));
        memset(dpWater,-1,sizeof(dpWater));
        memset(dpAir,-1,sizeof(dpAir));
        cout << max(fire(h,a),max(air(h,a),water(h,a))) << endl;
    }
   	return 0;
}
