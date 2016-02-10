#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <cstdlib>
#include <string>
#include <cmath>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <iterator>
#include <iomanip>
#include <limits.h>
#define debug(v) for(long long int i=0;i<v.size();++i)cout<<v[i]<<" ";cout<<endl;
#define debugMatrix(name,row,col) for(long long int i=0;i<row;++i){for(long long int j=0;j<col;++j)cout<<name[i][j]<<" ";cout<<endl;}
#define variable(v) cout<<v<<endl;
using namespace std;
int main(){
	//freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
	long long int t;
	cin >> t;
	while(t--){
        long long int n,k;
        long long int answer = 1;
        vector<long long int> deno;
        cin >> n >> k;
        if(k > n/2)
            k = n - k,k++;
        for(long long int i = 1;i <= k - 1;++i){
            answer *= n - k + i;
            answer /= i;
        }
        cout << answer << endl;
	}
   	return 0;
}
