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
#define sl(t) scanf("%lld",&t)
using namespace std;
typedef long long ll;
ll dMat[200][200];
int main(){
	//freopen("input.txt","r",stdin);
    //ios_base::sync_with_stdio(false);
	ll t;
	//cin >> t;
	sl(t);
	while(t--){
        ll n,m;
        //cin >> n >> m;
        sl(n);sl(m);
        char x = 'w';
        ll w = 0;
        pair<ll,ll> white[n*m];
        for(ll i = 0;i < n;++i){
            for(ll j = 0;j < m;++j){
               cin >> x;
               if(x == '1')
                    white[w].first = i,white[w].second = j,w++,dMat[i][j] = LLONG_MIN;
               else
                    dMat[i][j] = LLONG_MAX;
            }
        }
        for(ll i = 0;i < w;++i){
            queue<pair<ll,ll> > levelBFS;
            levelBFS.push(pair<ll,ll>(white[i]));
            dMat[white[i].first][white[i].second] = 0;
            while(!levelBFS.empty()){
                pair<ll,ll> top = levelBFS.front();
                levelBFS.pop();
                ll dist = dMat[top.first][top.second] + 1;
                if(top.first + 1 < n && dist < dMat[top.first+1][top.second]){
                    levelBFS.push(pair<ll,ll>(top.first+1,top.second));
                    dMat[top.first+1][top.second] = dist;
                }
                if(top.first - 1 >= 0 && dist < dMat[top.first-1][top.second]){
                    levelBFS.push(pair<ll,ll>(top.first-1,top.second));
                    dMat[top.first-1][top.second] = dist;
                }
                if(top.second + 1 < m && dist < dMat[top.first][top.second+1]){
                    levelBFS.push(pair<ll,ll>(top.first,top.second+1));
                    dMat[top.first][top.second+1] = dist;
                }
                if(top.second - 1 >= 0 && dist < dMat[top.first][top.second-1]){
                    levelBFS.push(pair<ll,ll>(top.first,top.second-1));
                    dMat[top.first][top.second-1] = dist;
                }
            }
        }
        debugMatrix(dMat,n,m);
    }
   	return 0;
}
