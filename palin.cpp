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
string nxtPalin(string str){
    string temp = str;
    bool allNine = true;
    for(long long int i=0;i<str.length();++i)
        if(str[i] != '9')
            allNine = false;
    if(allNine){
        string answer = "";
        for(long long int i=0;i<str.length()-1;++i)
            answer += '0';
        return "1" + answer + "1";
    }
    long long int length = str.length();
    if(length%2 == 0){
        long long int pI = length/2 - 1,pJ = pI + 1;
        while(pI >= 0){
            if(str[pI] == str[pJ]){
                pI--,pJ++;continue;
            }
            else{
                if(str[pI] > str[pJ]){
                    str[pJ] = str[pI],pI--,pJ++;
                    long long int i = 1;
                        while(length/2 - 1 - i >= 0)
                            str[length/2+i] = str[length/2-i-1],i++;
                    str[length-1] = str[0];
                    break;
                }
                else{
                    if(str[length/2-1] != '9'){
                        str[length/2-1]++,str[length/2] = str[length/2-1];
                        long long int i = 1;
                        while(length/2 - 1 - i >= 0)
                            str[length/2+i] = str[length/2-i-1],i++;
                        str[length-1] = str[0];
                    }
                    else{
                        str[length/2-1] = '0';
                        str[length/2] = '0';
                        bool did = false;
                        long long int i=1;
                        while(length/2 - 1 - i >= 0 && !did){
                            if(str[length/2-i-1] != '9')
                                str[length/2-i-1]++,str[length/2+i] = str[length/2-i],i++,did = true;
                            else
                                str[length/2-i-1] = '0',str[length/2+i] = str[length/2-i],i++;
                        }
                        while(length/2 - 1 - i >= 0)
                            str[length/2+i] = str[length/2-i-1],++i;
                        str[length-1] = str[0];
                        if(!did)
                            str = "1" + str + "1";
                    }
                }
                break;
            }
        }
    }
    else{
        long long int pI = length/2 - 1,pJ = pI + 2;
        while(pI >= 0){
            if(str[pI] == str[pJ]){
                pI--,pJ++;
                continue;
            }
            else{
                    if(str[pI] > str[pJ]){
                    str[pJ] = str[pI],pI--,pJ++;long long int i = 1;
                    while(length/2 - i >= 0)
                        str[length/2+i] = str[length/2-i],i++;
                        str[length-1] = str[0];
                    }
            else{
                if(str[length/2] != '9'){
                    str[length/2]++;
                    long long int i = 1;
                    while(length/2 - i >= 0)
                        str[length/2+i] = str[length/2-i],i++;
                    str[length-1] = str[0];
                }
                else{
                    str[length/2] = '0';
                    bool did = false;
                    long long int i = 1;
                    while(length/2 - i >= 0 && !did){
                        if(str[length/2-i] != '9')
                            str[length/2-i]++,str[length/2+i] = str[length/2-i],i++,did = true;
                        else
                            str[length/2-i] = '0',str[length/2+i] = str[length/2-i],i++;
                    }
                    while(length/2  - i >= 0)
                        str[length/2+i] = str[length/2-i],i++;
                    str[length-1] = str[0];
                    if(!did)
                        str = "1" + str + "1";
                }
            }
        break;}}
    }
    if(str == temp){
        if(length%2 == 1){
            if(str[length/2] != '9')
                str[length/2]++;
            else{
                str[length/2] = '0';
                bool did = false;
                long long int i = 1;
                while(length/2 - i >= 0 && !did){
                    if(str[length/2-i] != '9')
                        str[length/2-i]++,str[length/2+i] = str[length/2-i],i++,did = true;
                    else
                        str[length/2-i] = '0',str[length/2+i] = str[length/2-i],i++;
                }
                str[length-1] = str[0];
                if(!did)
                    str = "1" + str + "1";
            }
        }
        else{
            if(str[length/2-1] != '9')
                str[length/2-1]++,str[length/2] = str[length/2-1];
            else{
                str[length/2-1] = '0';
                str[length/2] = '0';
                bool did = false;
                long long int i=1;
                while(length/2 - 1 - i >= 0 && !did){
                    if(str[length/2-i-1] != '9')
                        str[length/2-i-1]++,str[length/2+i] = str[length/2-i],i++,did = true;
                    else
                        str[length/2-i-1] = '0',str[length/2+i] = str[length/2-i],i++;
                }
                while(length/2 - 1 - i >= 0)
                    str[length/2+i] = str[length/2-i-1],i++;
                str[length-1] = str[0];
                if(!did)
                    str = "1" + str + "1";
            }
        }
    }
    return str;
}
int main(){
	//freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
	long long int t;
	cin >> t;
	while(t--){
        string str;
        cin >> str;
        cout << nxtPalin(str) << endl;
	}
   	return 0;
}
