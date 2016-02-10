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
	long long n;
	cin >> n;
	while(n){
        cout << (n*(n+1)*(2*n+1))/6 << endl;
        cin >> n;
	}
	return 0;
}
