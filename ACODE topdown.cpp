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
#include <iomanip>
#include <limits.h>
#define debug(v) for(long long int i=0;i<v.size();++i)cout<<v[i]<<" ";cout<<endl;
#define debugMatrix(name,row,col) for(long long int i=0;i<row;++i){for(long long int j=0;j<col;++j)cout<<name[i][j]<<" ";cout<<endl;}
#define variable(v) cout<<v<<endl;
using namespace std;
unsigned long long int answer = 0;
map<string,long long int> save;
long long int callRec(string str){
    if(str.length() == 3){
        stringstream ss(str);
        long long int x;
        ss >> x;
        if(x/10 <= 26 && str[2] == '0')
            return 1;
    }
    if(str.length() == 1 || str.length() == 0)
        return 1;
    if(str.length() == 2){
        if(str == "10" || str == "20")
            return 1;
        stringstream ss(str);
        long long int x;
        ss >> x;
        if(x <= 26)
            return 2;
        return 1;
    }
    if(str[0] == '1' || str[0] == '2'){
        if(str[2] == '0'){
            return callRec(str.substr(3));
        }
        else if(str[1] == '0'){
            string toSend = str.substr(2);
            long long int ans = 0;
            if(save[toSend] != 0)
                ans = save[toSend];
            else
                ans = callRec(toSend);
            save[str] = ans;
            return ans;
        }
        else{
            string toSend1 = str.substr(1),toSend2 = str.substr(2);
            long long int ans = 0,ans1 = 0;
            if(save[toSend1] != 0)
                ans = save[toSend1];
            else
                ans = callRec(toSend1);
            if(save[toSend2] != 0)
                ans1 = save[toSend2];
            else
                ans1 = callRec(toSend2);
            save[str] = ans + ans1;
            return ans + ans1;
        }
    }
    else{
        string toSend = str.substr(1);
        long long int ans = 0;
        if(save[toSend] != 0)
            ans =  save[toSend];
        else
            ans = callRec(toSend);
        save[str] = ans;
        return ans;
    }
}
int main(){
	//freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	/** TOP DOWN DP APPROACH :D */
    string str;
    cin >> str;
    while(str != "0"){
        long long int answer = 0;
        save.clear();
        answer = callRec(str);
        //for(map<string,long long int>::iterator it = save.begin();it != save.end();++it)
        //    cout << it->first << " " << it->second << endl;
        cout << answer << endl;
        cin >> str;
    }
   	return 0;
}
