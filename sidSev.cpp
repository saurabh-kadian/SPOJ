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
        double a,h,theta;
        double pi = 3.14159265;
        cin >> a >> h >> theta;
        double res = tan(theta*pi/180.0);
        double x = a*res;
        double area = (0.5*x*a);
        area += ((h-x)*a);
        double ans = area/a;
        cout << ceil(ans) << endl;
	}
	return 0;
}
