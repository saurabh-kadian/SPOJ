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
	long long int a,b,c;
	cin >> a >> b >> c;
	while(a|b|c){
        if(b-a == c-b){
            cout << "AP " << c+(c-b) << endl;
        }
        else if(b/a == c/b){
            cout << "GP " << c*(c/b) << endl;
        }
        cin >> a >> b >> c;
	}
	return 0;
}
