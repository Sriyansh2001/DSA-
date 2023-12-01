#include<bits/stdc++.h>
using namespace std;

long long solve(vector<vector<int>> &v,int i,int value,vector<vector<long long>> &dp) {
	if(value == 0) return 0;
	if(i == v.size()) return 1e10+10;
	if(dp[i][value] != -1) {
		return dp[i][value];
	}
	long long ans = solve(v,i+1,value-v[i][1],dp)+v[i][0];
	return dp[i][value] = min(ans,solve(v,i+1,value,dp));	
}

int main(){
    int n,k;
    cin >> n >> k;
    vector<vector<int>> v;
    for(int i=0 ; i<n ; ++i) {
    	int x,y;
    	cin >> x >> y;
    	v.push_back({x,y});
    }
    int mx = 1e5;	
    vector<vector<long long>> dp(n+1,vector<long long> (mx+1,-1));
    int ans = 0;
    for(int i=mx ; i>=0 ; --i) {
    	if(solve(v,0,i,dp) <= k) {
    		ans = i;
    		break;
    	}
    }
    cout << ans << "\n";
  	return 0;
}