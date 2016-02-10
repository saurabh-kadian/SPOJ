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
	long long int a,d;
	cin >> a >> d;
	while(a != 0 && d != 0){
        vector<long long int> attack(a),defend(d);
        for(long long int i=0;i<a;++i)
            cin >> attack[i];
        for(long long int i=0;i<d;++i)
            cin >> defend[i];
        sort(attack.begin(),attack.end());
        sort(defend.begin(),defend.end());
        if(attack[0] < defend[1])
            cout << "Y\n";
        else
            cout << "N\n";
        cin >> a >> d;
	}
   	return 0;
}
