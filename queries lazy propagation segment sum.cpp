#include <bits/stdc++.h>
#define debug(v,len) for(long long int i=0;i<len;++i)cout<<v[i]<<" ";cout<<endl;
#define debugMatrix(name,row,col) for(long long int i=0;i<row;++i){for(long long int j=0;j<col;++j)cout<<name[i][j]<<" ";cout<<endl;}
#define print(v) cout<<v<<endl;
#define gcd(v,h) __gcd(v,h)
#define popcount(v) __builtin_popcount(v)
#define sl(T) scanf("%lld",&T)
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
// For range minimum queries. Can be used for sum of range,max of range,min of range
// using 0 as root, left child = 2*i + 1,right = 2*i + 2,parent = (i-1)/2
// lazy propagation and also range update and point updates both.
class segmentTree{
    public:
        // Size and Tree
        ll segmentSize;                                         // segment tree size
        vll segment;                                            // segment tree
        vll lazy;                                               // lazy tree
        // Functions/Operations
        segmentTree(ll n){
            ll x = 1;
            while(x < n)
                x <<= 1;                                        // if size = 2^x -> 2*size - 1 = segment size
            x *= 2; x--; segmentSize = x;                       // else say 2^x > size then 2*2^x - 1 = segment size
            segment.resize(segmentSize,0);
            lazy.resize(segmentSize,0);                         // same tree as segment 0 depicts nothing left of update
        }
        ll rangeMin(ll rangeStart,ll rangeEnd,ll low,ll high,ll pos){
            if(low > high)   return 0;                  // break condition
            if(lazy[pos] != 0){                                 // node has not yet been updated
                segment[pos] += lazy[pos]*(high-low+1);                      // update segment node -> from lazy tree
                if(low != high){                                // not a leaf
                    lazy[2*pos + 1] += lazy[pos];               // propagate this node to left child and right
                    lazy[2*pos + 2] += lazy[pos];               // update till here else we have to go till leaf
                }                                               // 0 means node = updated else not updated
                lazy[pos] = 0;                                  // current node is updated mark 0
            }
            if(rangeStart > high || rangeEnd < low)     return 0;       // no overlap return
            if(rangeStart <= low && high <= rangeEnd)   return segment[pos];    // return answer
            ll middle = (low+high)/2;                                           // find segment divide point
            return rangeMin(rangeStart,rangeEnd,low,middle,2*pos+1) +
                       rangeMin(rangeStart,rangeEnd,middle+1,high,2*pos+2);    // find minimum
        }
        void rangeUpdateTree(ll rangeStart,ll rangeEnd,ll increaseBy,ll low ,ll high ,ll pos){
            if(low > high)  return ;                            // break condition
            if(lazy[pos] != 0){                                 // node has not yet been updated
                segment[pos] += lazy[pos]*(high-low+1);                      // update segment node -> from lazy tree
                if(low != high){                                // not a leaf
                    lazy[2*pos + 1] += lazy[pos];               // propagate this node to left child and right
                    lazy[2*pos + 2] += lazy[pos];               // update till here else we have to go till leaf
                }                                               // 0 means node = updated else not updated
                lazy[pos] = 0;                                  // current node is updated mark 0
            }
            if(rangeStart > high || rangeEnd < low) return ;    // no overlap return
            if(rangeStart <= low && high <= rangeEnd){          // in between range update all
                segment[pos] += (high-low+1)*increaseBy;                     // increase segment node
                if(low != high){                                // not leaf node
                    lazy[2*pos + 1] += increaseBy;              // propagate to children node
                    lazy[2*pos + 2] += increaseBy;
                }
                return ;
            }
            ll middle = (low+high)/2;                           // find segment division point
            rangeUpdateTree(rangeStart,rangeEnd,increaseBy,low,middle,2*pos+1);
            rangeUpdateTree(rangeStart,rangeEnd,increaseBy,middle+1,high,2*pos+2);
            segment[pos] = segment[2*pos+1] + segment[2*pos+2];
        }
};
int main(){
	//freopen("input.txt","r",stdin);
    //ios_base::sync_with_stdio(false);
    ll w;
    sl(w);
    while(w--){
    ll n,q;
    sl(n);sl(q);
    segmentTree ST(n);                             // make instance
    while(q--){
        ll t,a,b,c;
        sl(t);//cin >> t;
        if(t == 0){                                          // update range
            sl(a);sl(b);sl(c);//cin >> a >> b >> c;
            a--,b--;
            ST.rangeUpdateTree(a,b,c,0,n-1,0);
        }
        else if(t == 1){                                     // find query min
            sl(a);sl(b);//cin >> a >> b;
            a--,b--;
            printf("%lld\n",ST.rangeMin(a,b,0,n-1,0));
        }
        //debug(ST.segment,ST.segment.size());
        //debug(ST.lazy,ST.lazy.size());
    }
    }
   	return 0;
}
