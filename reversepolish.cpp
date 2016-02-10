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
	// freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
    long long int t;
    cin >> t;
    char arr[] = {'+','-','*','/','^'};
    while(t--){
        string str;
        string ans = "";
        cin >> str;
        stack<char> s;
        for(int i=0;i<str.length();++i){
            if(str[i] >= 'a' && str[i] <= 'z'){
                ans += str[i];
                continue;
            }
            if(str[i] == '('){
               s.push(str[i]);
               continue;
            }
            if(str[i] == ')'){
                while(!s.empty()){
                    if(s.top() == '('){
                        s.pop();
                        break;
                    }
                    while(s.top() != '('){
                        ans += s.top();
                        s.pop();
                        if(s.empty())
                            break;
                    }
                }
                continue;
            }
            int j=0;
            for(j=0;j<5;++j)
                if(str[i] == arr[j])
                    break;
            while(!s.empty()){
                char c = s.top();
                if(c == '(')
                    break;
                int x = 0;
                for(x=0;x<5;++x)
                    if(c == arr[x])
                        break;
                if(x >= j){
                    ans += s.top();
                    s.pop();
                }
                else
                    break;
            }
            s.push(str[i]);
        }
        while(!s.empty()){
            ans += s.top();
            s.pop();
        }
        cout << ans << endl;
    }
	return 0;
}
