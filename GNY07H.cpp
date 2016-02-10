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
int main(){
	//freopen("input.txt","r",stdin);
	// http://math.stackexchange.com/questions/664113/count-the-ways-to-fill-a-4-times-n-board-with-dominoes
    ios_base::sync_with_stdio(false);
	vector<long long> a(4);
	a[0] = 1,a[1] = 1,a[2] = 5,a[3] = 11;
	for(int i = 4;1;++i){
        long long t = a[i-1] + a[i-2] * 5 + a[i-3] - a[i-4];
        if(t > a[a.size()-1])
            a.push_back(t);
        else
            break;
	}
	//debug(a,a.size());
   	long long x;
   	cin >> x;
   	for(int i = 1;i <= x;++i){
        long long y;
        cin >> y;
        cout << i << " " << a[y] << endl;
   	}
   	return 0;
}
