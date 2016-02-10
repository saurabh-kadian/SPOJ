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
long long LCS(string str,string rev){
    long long x = str.length() + 1;
    vector<vector<long long> > matrix(x,vector<long long>(x));
    for(int i = 0;i < x;++i){
        for(int j = 0;j < x;++j){
            if(i == 0 || j == 0)
                matrix[i][j] = 0;
            else if(str[i-1] == rev[j-1])
                matrix[i][j] = matrix[i-1][j-1] + 1;
            else
                matrix[i][j] = max(matrix[i-1][j],matrix[i][j-1]);
        }
    }
    //debugMatrix(matrix,x,x);
    return matrix[x-1][x-1];
}
int main(){
	//freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
	long long t;
	cin >> t;
	while(t--){
        string str,rev;
        cin >> str;
        rev = str;
        reverse(rev.begin(),rev.end());
        //cout << LCS(str,rev) << endl;
        cout << str.length() - LCS(str,rev) << endl;
	}
   	return 0;
}
