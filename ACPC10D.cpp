#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll rows;
	ll count = 1;
	cin >> rows;
	while(rows != 0){
		vector<vector<ll> > grid(rows, vector<ll>(3));
		vector<vector<ll> > dp(rows, vector<ll>(3));
		for(ll i = 0;i < rows;++i){
			for(int ii = 0;ii < 3;++ii){
				cin >> grid[i][ii];
				dp[i][ii] = grid[i][ii];
			}
		}
		// Start from (0,1)

		// Movements to the right or below(left, mid, right)
		for(ll i = 0;i < rows;++i){
			for(ll j = 0;j < 3;++j){
				if(i == 0 && j == 0)
					dp[i][j] = INT_MAX;
				else if(i == 0 && j == 1)
					continue;
				else if(i == 0)
					dp[i][j] = dp[i][j-1] + dp[i][j];
				else if(j == 0)
					dp[i][j] = min(dp[i-1][j], dp[i-1][j+1]) + dp[i][j];
				else if(j == 1)
					dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j+1]))) + dp[i][j];
				else if(j == 2)
					dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j])) + dp[i][j];
			}
		}
		
		cout << count << ". " << dp[rows-1][1] << endl;
		count++;
		cin >> rows;
	}
	return 0;
}
