#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <iterator>
#include <iomanip>
#include <limits.h>
#define debug(v,len) for(long long int i=0;i<len;++i)cout<<v[i]<<" ";cout<<endl;
#define debugMatrix(name,row,col) for(long long int i=0;i<row;++i){for(long long int j=0;j<col;++j)cout<<name[i][j]<<" ";cout<<endl;}
#define print(v) cout<<v<<endl;
#define gcd(v,h) __gcd(v,h)
#define popcount(v) __builtin_popcount(v)
using namespace std;
int main(){
	//freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
        int horiUsed = 1,vertiUsed = 1;
        int m,n;
        long long answer = 0;
        cin >> m >> n;
        m--,n--;
        priority_queue<pair<int,char> > q;
        while(m--){
            int x;
            cin >> x;
            q.push(pair<int,char>(x,'v'));
        }
        while(n--){
            int x;
            cin >> x;
            q.push(pair<int,char>(x,'h'));
        }
        while(q.size() != 0){
            pair<int,char> x = q.top();
            q.pop();
            if(x.second == 'h'){
                answer += vertiUsed * x.first;
                horiUsed++;
            }
            else{
                answer += horiUsed * x.first;
                vertiUsed++;
            }
            //cout << answer << endl;
        }
        cout << answer << endl;
	}
   	return 0;
}
