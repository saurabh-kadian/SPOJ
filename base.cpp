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
int main(){
	//freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
	while(!cin.eof()){
        string n;
        int a,b;
        cin >> n >> a >> b;
        map<char,int> g10;
        map<int,char> tenG;
        string answer = "";
        g10['0'] = 0;g10['1'] = 1;
        g10['2'] = 2;g10['3'] = 3;
        g10['4'] = 4;g10['5'] = 5;
        g10['6'] = 6;g10['7'] = 7;
        g10['8'] = 8;g10['9'] = 9;
        g10['A'] = 10;g10['B'] = 11;
        g10['C'] = 12;g10['D'] = 13;
        g10['E'] = 14;g10['F'] = 15;

        tenG[0] = '0';tenG[1] = '1';
        tenG[2] = '2';tenG[3] = '3';
        tenG[4] = '4';tenG[5] = '5';
        tenG[6] = '6';tenG[7] = '7';
        tenG[8] = '8';tenG[9] = '9';
        tenG[10] = 'A';tenG[11] = 'B';
        tenG[12] = 'C';tenG[13] = 'D';
        tenG[14] = 'E';tenG[15] = 'F';

        long long int power = 1,number = power * g10[n[n.length()-1]];
        for(int i = n.length()-2;i >= 0;--i)
            power *= a,number += power * g10[n[i]];
        while(number){
            answer = tenG[number%b] + answer;
            number /= b;
        }
        if(answer.length() > 7)
            cout << setw(7) << "ERROR" << endl;
        else
            cout << setw(7) << answer << endl;
	}
   	return 0;
}
