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
bool isPrime(long long int n) {
    if (n <= 3) {
        return n > 1;
    } else if (n % 2 == 0 || n % 3 == 0) {
        return false;
    } else {
        for (long long int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) {
                return false;
            }
        }
        return true;
    }
}
int main(){
	//freopen("input.txt","r",stdin);
    long long int t;
    cin >> t;
    while(t--){
        long long int a,b;
        cin >> a >> b;
        while(a!=b){
            if(isPrime(a))
                cout << a << endl;
            a++;
        }
        if(isPrime(b))
            cout << b << endl;
        cout << "\n";
    }
	return 0;
}
