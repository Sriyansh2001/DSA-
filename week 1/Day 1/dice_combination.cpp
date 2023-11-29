#include<bits/stdc++.h>
using namespace std;
int M = 1e9+7;

long long solve(int n,vector<int> &dp) {
	if(n <= 0) {
		return n == 0;
	}

	if(dp[n] != -1) {
		return dp[n];
	}

	int res = 0;
	for(int i=1 ; i<=6 ; ++i) {
		res = (res + solve(n-i,dp))%M;
	}

	return dp[n] = res;
}

int main(){
    int n;
    cin >> n;
    vector<int> dp(n+1,-1);

    cout << solve(n,dp);

  	return 0;
}