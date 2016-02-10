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
    // stack try
    ios_base::sync_with_stdio(false);
	string str;
	cin >> str;
	ll counter = 1;
	while(str[0] != '-'){
        stack<char> all;
        ll swaps = 0;
        for(ll i = 0;i < str.length();++i){
            if(str[i] == '{')
                all.push('{');
            else if(all.size() == 0)
                swaps++,all.push('{');
            else
                all.pop();
        }
        cout << counter << ". " << swaps + all.size()/2 << endl;
        counter++;
        cin >> str;
	}
   	return 0;
}
