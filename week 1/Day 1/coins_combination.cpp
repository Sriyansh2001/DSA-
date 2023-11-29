#include<bits/stdc++.h>
using namespace std;

int M = 1e9+7;

long long solution(vector<int> &v,int sum,vector<int> &dp) {
	if(sum <= 0) {
		return sum == 0;
	}

	if(dp[sum] != -1) {
		return dp[sum];
	}

	int result = 0;

	for(int i=0 ; i<v.size() ; ++i) {
		result = (result + solution(v,sum-v[i],dp))%M;
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

    cout << solution(v,x,dp);

  	return 0;
}