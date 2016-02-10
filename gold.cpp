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
map<long long int,long long int> call;
long long int see(long long int n){
    if (call[n] != 0)
        return call[n];
    if (n == 1 || n == 0)
    {
        call[n] = n;
        return n;
    }
    long long total = see(n/2) + see(n/3) + see(n/4);
    if (total > n)
    {
        call[n] = total;
        return total;
    }
    else
    {
        call[n] = n;
        return n;
    }
}
int main(){
	//freopen("input.txt","r",stdin);
	vector<long long int> all;
	call[0] = 0;
	call[1] = 1;
	long long int n;
	while(scanf("%lld",&n) != EOF){
        long long int gold = see(n);
        cout << call[n] << endl;
	}
	return 0;
}
