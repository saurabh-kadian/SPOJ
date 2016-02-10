#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cstdlib>
using namespace std;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    long long int n;
    while(!(cin >> n).eof()){
    string needle,haystack;
    cin >> needle;
    cin >> haystack;
    size_t start = haystack.find(needle);
    if(start == string::npos){
        cout << "\n";
        continue;
    }
    while(start != string::npos){
        cout << start << "\n";
        start = haystack.find(needle,start+1);
    }
    cout << "\n";
    }
    return 0;
}
