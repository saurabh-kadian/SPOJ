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
        long long int r,c;
        cin >> r >> c;
        long long int matrix[r][c],sum[r][c];
        for(long long int i=0;i<r;++i)
            for(long long int j=0;j<c;++j)
                cin >> matrix[i][j],sum[i][j] = 0;
        for(long long int i=0;i<r;++i){
            for(long long int j = 0;j < c;++j){
                if(i == 0){
                    sum[i][j] = matrix[i][j];
                    continue;
                }
                if(j - 1 >= 0 && j + 1 >= c)
                    sum[i][j] = max(sum[i-1][j-1]+matrix[i][j],sum[i-1][j]+matrix[i][j]);
                else if(j + 1 < c && j - 1 < 0)
                    sum[i][j] = max(sum[i-1][j+1]+matrix[i][j],sum[i-1][j]+matrix[i][j]);
                else
                    sum[i][j] = max(sum[i-1][j]+matrix[i][j],max(sum[i-1][j-1]+matrix[i][j],sum[i-1][j+1]+matrix[i][j]));
            }
        }
        long long int maxi = 0;
        for(long long int j=0;j<c;++j)
            if(sum[r-1][j] > maxi)
                maxi = sum[r-1][j];
        //debugMatrix(sum,r,c);
        cout << maxi << endl;
	}
   	return 0;
}
