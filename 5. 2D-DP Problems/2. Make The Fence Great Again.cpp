// Problem: https://codeforces.com/problemset/problem/1221/D
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<long long> a(n), b(n);
    for(long long i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }
    vector<vector<long long>> cost(3, vector<long long>(n, 1e18));
    vector<vector<long long>> fences(3, vector<long long>(n, 1e18));
    for(int i = 0; i < n; i++){
        fences[0][i] = a[i];
        fences[1][i] = a[i] + 1;
        fences[2][i] = a[i] + 2; 
    }
    for(int i = 0; i < n; i++){
        cost[0][i] = b[i] * 0;
        cost[1][i] = b[i] * 1;
        cost[2][i] = b[i] * 2;
    }
    vector<vector<long long>> dp(3, vector<long long>(n, 1e18));
    for(int i = 0; i < 3; i++){
	    dp[i][0] = cost[i][0];
	}
    for(int j = 1; j < n ; j++){
        for(int i = 0; i < 3; i++){
            long long prev_min = LLONG_MAX;
            for(int i_ = 0; i_ < 3; i_++){
                if(fences[i][j] != fences[i_][j - 1]){
                    prev_min = min(prev_min, dp[i_][j - 1]);
                }
            }
            dp[i][j] = prev_min + cost[i][j];
        }
    }
    long long mn = dp[0][n - 1];
	for(int i = 0; i < 3; i++){
	    mn = min(mn, dp[i][n - 1]);
	}
	cout << mn << endl;
}

int main() {
    int t; cin >> t;
    while(t--){
        solve();
    }
}
