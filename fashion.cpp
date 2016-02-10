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
	long long int t;
	cin >> t;
	while(t--){
        long long int n;
        cin >> n;
        vector<long long int> men;
        vector<long long int> women;
        for(long long int i=0;i<n;++i){
            long long int temp;
            cin >> temp;
            men.push_back(temp);
        }
        for(long long int i=0;i<n;++i){
            long long int temp;
            cin >> temp;
            women.push_back(temp);
        }
        sort(men.begin(),men.end());sort(women.begin(),women.end());
        long long int sum = 0;
        for(long long int i=0;i<n;++i)
            sum += men[i]*women[i];
        cout << sum << endl;
	}
	return 0;
}
