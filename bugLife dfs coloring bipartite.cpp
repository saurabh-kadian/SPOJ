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
	//ios_base::sync_with_stdio(false);
	ll t;
	sl(t);
	for(ll q = 1;q <= t;++q){
        ll n,x;
        sl(n);sl(x);
        vector<bool> visited(n+1,false);
        visited[0] = true;
        vector<bool> done(n+1,true);
        bool graph[n+1][n+1];
        memset(graph,false,sizeof(graph));
        while(x--){
            ll a,b;
            sl(a);sl(b);
            graph[a][b] = true;
            graph[b][a] = true;
        }
        bool suspect = false;
        int color[n+1];         // 1 = white,2 = black
        fill(color,color+n+1,0);
        while(visited != done){
            stack<ll> dfs;
            for(ll i = 1;i < n+1;++i){
                if(!visited[i]){
                    dfs.push(i);
                    visited[i] = true;
                    color[i] = 1;
                    break;
                }
            }
            while(!dfs.empty()){
                ll top = dfs.top();
                bool change = false;
                for(ll i = 1;i < n+1 && !change;++i){
                    if(!visited[i] && graph[top][i]){
                        change = true;
                        visited[i] = true;
                        dfs.push(i);
                        color[i] = (color[top] == 1 ? 2 : 1);
                    }
                    else if(color[i] == color[top] && graph[top][i])
                        suspect = true;
                }
                if(!change)
                    dfs.pop();
                if(suspect)
                    break;
            }
            if(suspect)
                break;
        }
        printf("Scenario #%lld:\n",q);
        suspect == true ? printf("Suspicious bugs found!\n") : printf("No suspicious bugs found!\n") ;
	}
   	return 0;
}
