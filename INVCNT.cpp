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
long long int inv = 0;
vector<long long int> doMerge(vector<long long int> f,vector<long long int> s){
    vector<long long int> answer;
    long long int i = 0,j = 0;
    while(i != f.size() && j != s.size()){
        if(f[i] <= s[j])
            answer.push_back(f[i]),i++;
        else
            answer.push_back(s[j]),j++,inv += f.size()-i;
    }
    if(i == f.size())
        while(j != s.size())
            answer.push_back(s[j]),j++;
    else
        while(i != f.size())
            answer.push_back(f[i]),++i;
    return answer;
}
vector<long long int> mergeSort(vector<long long int> arr){
    long long int answer = 0;
    if(arr.size() == 1)
        return arr;
    vector<long long int> f,s;
    long long int lby2 = arr.size()/2,i = 0;
    for(;i < lby2;++i)
        f.push_back(arr[i]);
    for(;i < arr.size();++i)
        s.push_back(arr[i]);
    f = mergeSort(f);
    s = mergeSort(s);
    arr = doMerge(f,s);
    return arr;
}
int main(){
	ios_base::sync_with_stdio(false);
    long long int t;
    cin >> t;
    while(t--){
        inv = 0;
        long long int n;
        cin >> n;
        vector<long long int> arr(n);
        for(long long int i = 0;i < n;++i)
            cin >> arr[i];
        arr = mergeSort(arr);
        //debug(arr);
        cout << inv << endl;
    }
   	return 0;
}
