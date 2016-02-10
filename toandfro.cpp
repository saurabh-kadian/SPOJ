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
using namespace std;
int main(){
	//freopen("input.txt","r",stdin);
    long long int n;
    cin >> n;
    while(n){
        string str;
        cin >> str;
        long long int x = str.length()/n;
        vector<string> all;
        long long int ini = 0;
        for(long long int i=0;i<x;++i){
            all.push_back(str.substr(ini,n));
            if(i%2 == 1)
                reverse(all[i].begin(),all[i].end());
            ini += n;
        }
        for(long long int i=0;i<n;++i)
            for(long long int j=0;j<x;++j)
                cout << all[j][i];
        cout << "\n";
        cin >> n;
    }
	return 0;
}
