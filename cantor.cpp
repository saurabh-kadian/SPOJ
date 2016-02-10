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
#include <limits.h>
using namespace std;
int main(){
	//freopen("input.txt","r",stdin);
    long long int t;
    cin >> t;
    while(t--){
        long long int x,number;
        cin >> x;
        number = x;
        long long int i = 1;
        for(i=1;i<1000000;++i)
            if((i*(i-1))/2 < x && x <= (i*(i+1))/2)
                break;
        long long int subsetNumber = i;
        vector<pair<long long int,long long int> > all(subsetNumber+1);
        all[0].first = all[0].second = 0;
        if(i%2 == 0)
            for(long long int j = 1;j <= subsetNumber/2 ;++j)
                all[j].first = j,all[j].second = subsetNumber-j+1
                    ,all[subsetNumber-j+1].first = subsetNumber-j+1,all[subsetNumber-j+1].second = j;
        else
            for(long long int j = 1;j <= subsetNumber/2 ;++j)
                all[j].first = subsetNumber-j+1,all[j].second = j
                    ,all[subsetNumber-j+1].first = j,all[subsetNumber-j+1].second = subsetNumber-j+1;
        x -= (i*(i-1))/2;
        if(x == (subsetNumber-(subsetNumber/2)) && subsetNumber%2 == 1)
            cout << "TERM " << number << " IS " << (subsetNumber+1)/2 << "/" << (subsetNumber+1)/2 << endl;
        else
            cout << "TERM " << number << " IS " << all[x].first << "/" << all[x].second << endl;
    }
   	return 0;
}
