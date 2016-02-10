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
	set<long long int> will;
	bool isRepeat = false;
	while(!isRepeat){
        long long int total = 0;
        while(n/10){
            total += (n%10) * (n%10);
            n /= 10;
        }
        total += n*n;
        set<long long int>::iterator found = will.find(total);
        if(found != will.end())
            isRepeat = true;
        will.insert(total);
        n = total;
        if(n == 1)
            break;
	}
	if(isRepeat)
        cout << -1 << endl;
    else
        cout << will.size() << endl;
   	return 0;
}
