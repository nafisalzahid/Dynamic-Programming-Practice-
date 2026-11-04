// Problem: the minimum cost to paint a row of n houses with 3 colors (Red, Blue, Green) such that no two adjacent houses share the same color
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<vector<int>> cost(3, vector<int>(n));
	for(int i = 0; i < 3; i++){
	    for(int j = 0; j < n; j++){
	        cin >> cost[i][j];
	    }
	}
	vector<vector<int>> dp(3, vector<int>(n));
	for(int i = 0; i < 3; i++){
	    dp[i][0] = cost[i][0];
	}
	for(int j = 1; j < n; j++){
	    for(int k = 0; k < 3; k++){
	        dp[k][j] = INT_MAX;
	    }
	    for(int i = 0; i < 3; i++){
	        int min_prev = INT_MAX;
	        for(int i_ = 0; i_ < 3; i_++){
	            if(i_ != i){
	                min_prev = min(min_prev, dp[i_][j - 1]);
	            }
	        }
	        dp[i][j] = min_prev + cost[i][j];
	    }
	}
	int mn = dp[0][n - 1];
	for(int i = 0; i < 3; i++){
	    mn = min(mn, dp[i][n - 1]);
	}
	cout << mn << endl;
}

// Example Test Case:
// 3
// 14 11 14
// 2 14 3
// 11 5 10
// Ans: 10
