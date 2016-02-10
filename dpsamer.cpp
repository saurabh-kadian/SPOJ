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
void LCS(string a,string b,int k){
    int matrix[a.length()+1][b.length()+1];
    int segment[a.length()+1][b.length()+1];
    for(int i = 0;i < a.length()+1;++i){
        for(int j = 0;j < b.length()+1;++j){
            if(i == 0 || j == 0){
                matrix[i][j] = 0,segment[i][j] = 0;
                continue;
            }
            matrix[i][j] = max(matrix[i-1][j],matrix[i][j-1]);
            if(a[i-1] == b[j-1])
                segment[i][j] = segment[i-1][j-1] + 1;
            else
                segment[i][j] = 0;
            if(segment[i][j] >= k)
                for(int q = k;q <= segment[i][j];++q)
                    matrix[i][j] = max(matrix[i][j],matrix[i-q][j-q] + q);
        }
    }
    cout << matrix[a.length()][b.length()] << endl;
    //debugMatrix(matrix,a.length()+1,b.length()+1);
    //cout << endl;
    //debugMatrix(segment,a.length()+1,b.length()+1);
}
int main(){
	//freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    //LCS("lovxxelyxxxxx","xxxxxxxlovely",3);
    //cout << endl;
    //LCS("abc","abbc",2);
    int k;
    cin >> k;
    while(k != 0){
        string a,b;
        cin >> a >> b;
        LCS(a,b,k);
        cin >> k;
    }
   	return 0;
}
