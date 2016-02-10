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
        long long int x,y;
        cin >> x >> y;
        if((x == y && x%2 == 0))
            cout << x+y << endl;
        else if((x == y && x%2 == 1))
            cout << x+y-1 << endl;
        else if(x-y == 2 && x%2 == 0)
            cout << x+y << endl;
        else if(x-y == 2 && x%2 == 1)
            cout << x+y-1 << endl;
        else
            cout << "No Number" << endl;
	}
	return 0;
}
