#include<bits/stdc++.h>
using namespace std;

int M = 1e9+7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int x,n;
    cin >> n >> x;
    int v[n];
    for(int i=0 ; i<n ; ++i) {
    	cin >> v[i];
    }

    int dp[x+1];

    dp[0] = 1;
    for(int i=1 ; i<=x ; ++i) {
    	dp[i] = 0;
    	for(int j=0 ; j<n ; ++j) {
    		if(i-v[j] >= 0) {
    			dp[i] += dp[i-v[j]];
    			dp[i] %= M;
    		}
    	}
    }

    cout << dp[x];

  	return 0;
}