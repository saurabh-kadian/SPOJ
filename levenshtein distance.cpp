#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <cstdlib>
#include <string>
#include <cmath>
using namespace std;
static int matrix[2002][2002] = {0};
int main(){
	//freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
        string a,b;
        cin >> a >> b;
        for(int i=0;i<=a.length();++i)
            for(int j=0;j<=b.length();++j)
                matrix[i][j] = 0;
        for(int i=0;i<=a.length();++i){
            for(int j=0;j<=b.length();++j){
                if(i == 0 || j == 0)
                    matrix[i][j] = max(i,j);
                else if(a[i-1] == b[j-1])
                    matrix[i][j] = matrix[i-1][j-1];
                else
                    matrix[i][j] = min(matrix[i-1][j] + 1,min(matrix[i][j-1] + 1,matrix[i-1][j-1] + 1));
            }
        }
        cout << matrix[a.length()][b.length()] << endl;
	}
   	return 0;
}
