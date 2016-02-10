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
	double total = 1;
	for(long long int i=1;i*i<=n;++i){
        for(long long int j=i;j<=n-i;j+=1){
            if(j*i <= n)
                total++;//,cout << i << "*" << j << endl;
        }
	}
	cout << total << endl;
	return 0;
}
