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
int main(){
	//freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    while(n != 0){
        ll freq[20005] = {0};
        vector<ll> p1(n);
        ll total = 0;
        ll total1 = 0,total2 = 0;
        vector<ll> sum1(n+1);
        sum1[0] = 0;
        for(ll i = 0;i < n;++i)
            cin >> p1[i],total1 += p1[i],freq[p1[i]+10000]++,sum1[i+1] = sum1[i] + p1[i];
        ll m;
        cin >> m;
        vector<ll> sum2(m+1);
        sum2[0] = 0;
        vector<ll> p2(m);
        for(ll i = 0;i < m;++i)
            cin >> p2[i],total2 += p2[i],freq[p2[i]+10000]++,sum2[i+1] = sum2[i] + p2[i];
        ll st1 = 0,st2 = 0;
        ll l1 = 0,l2 = 0;
        for(ll i = 0;i < 20005;++i){
            if(freq[i] == 2){
                vector<ll>::iterator it = lower_bound(p1.begin() + l1,p1.end(),i-10000);
                vector<ll>::iterator it2 = lower_bound(p2.begin() + l2,p2.end(),i-10000);
                l1 = distance(p1.begin(),it);
                l2 = distance(p2.begin(),it2);
                ll s1 = sum1[l1+1];
                ll s2 = sum2[l2+1];
                s1 - st1 > s2 - st2 ? total += s1 - st1 : total += s2 - st2;
                st1 = s1,st2 = s2;
            }
        }
        sum1[n] - st1 > sum2[m] - st2 ? total += sum1[n] - st1 : total += sum2[m] - st2;
        cout << total << endl;
        cin >> n;
    }
   	return 0;
}
