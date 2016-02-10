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
	long long int groups = 0;
	bool chain[30001] = {false};
	while(n--){
        long long int i;
        cin >> i;
        if(chain[i-1] == false && chain[i+1] == false)
            chain[i]=true,groups++;
        else if(chain[i-1] == true && chain[i+1] == true)
            chain[i]=true,groups--;
        else if((chain[i-1] == true && chain[i+1] == false) || (chain[i-1] == false && chain[i+1] == true))
            chain[i]=true;
        cout << groups << endl;
	}
	cout << "Justice\n";
	return 0;
}
