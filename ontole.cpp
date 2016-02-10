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
	long long int n;
	cin >> n;
	vector<long long int> will(n);
	long long int value = 0;
	for(long long int i=0;i<n;++i){
        cin >> will[i];
        value ^= will[i];
	}
	cout << value << endl;
   	return 0;
}
