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
	while(n != -1){
        vector<long long int> all;
        float total = 0;
        for(long long int i=0;i<n;++i){
            long long int temp;
            cin >> temp;
            total += temp;
            all.push_back(temp);
        }
        total /= (float)n;
        if(total != (long long int)total)
            cout << "-1" << endl;
        else{
        long long int moves = 0;
        for(long long int i=0;i<n;++i){
            if(all[i] < total)
                moves += total-all[i];
        }
        cout << moves << endl;
        }
        cin >> n;
	}
	return 0;
}
