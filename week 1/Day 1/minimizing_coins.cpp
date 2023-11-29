#include<bits/stdc++.h>
using namespace std;

int solution(vector<int> &coins,int ind,int sum,vector<int> &dp) {
	if(sum == 0) {
		return 0;
	}
	if(sum < 0) {
		return 1e6+10;
	}

	if(dp[sum] != -1) {
		return dp[sum];
	}

	int result = INT_MAX;

	for(int i=ind ; i<coins.size() ; ++i) {
		result = min(result,solution(coins,ind,sum-coins[i],dp)+1);
	}

	return dp[sum] = result;

}

int main(){
	int n,x;
	cin >> n >> x;

	vector<int> v(n);
	for(int i=0 ; i<n ; ++i) {
		cin >> v[i];
	}  

	vector<int> dp(x+1, -1);

	int result = solution(v,0,x,dp);

	cout << ( result > 1e6 ? -1 : result );

  	return 0;
}