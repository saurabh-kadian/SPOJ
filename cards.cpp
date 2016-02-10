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
	vector<long long int> levelCards;
	vector<long long int> previous;
	levelCards.push_back(0);
	levelCards.push_back(2);
	previous.push_back(0);
	previous.push_back(2);
	while(t--){
        long long int n;
        cin >> n;
        if(n < levelCards.size()){
            cout << levelCards[n] << endl;
            continue;
        }
        long long int lastNeed = previous[previous.size()-1],
                        last = levelCards[levelCards.size()-1],counter = levelCards.size()-1;
        for(;counter <= n;++counter){
            lastNeed += 3;
            last += lastNeed;
            last %= 1000007;
            lastNeed %= 1000007;
            previous.push_back(lastNeed);
            levelCards.push_back(last);
        }
        cout << levelCards[n] << endl;
	}
   	return 0;
}
