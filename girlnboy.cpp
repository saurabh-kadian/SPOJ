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
	long long int b,g;
	cin >> g >> b;
	while(g != -1 && b != -1){
        long long int t = b;
        b = max(b,g);
        g = min(t,g);
        if(g == 0){
            cout << b << endl;
        }
        else if(b == g){
            cout << 1 << endl;
        }
        else{
            long long int mini = LLONG_MAX;
            for(long long int i=1;i <= b;++i){
                long long int temp = g,temp2 = b;
                vector<long long int> part;
                while(temp--)
                    temp2 -= i,part.push_back(i);
                part.push_back(temp2);
                long long int l = (*(max_element(part.begin(),part.end()))) ;
                if( l < mini)
                    mini = l;
            }
            cout << mini << endl;
        }
        cin >> g >> b;
	}
   	return 0;
}
