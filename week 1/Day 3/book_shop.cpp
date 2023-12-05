#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

long long solve(vector<int> &book,vector<int> &price,int i,int x) {
    if(i == -1) {
        return 0;
    }
    if(dp[i][x] != -1) {
        return dp[i][x];
    }
    if(x - price[i] >= 0) {
        return dp[i][x] = max(solve(book,price,i-1,x),solve(book,price,i-1,x-price[i])+book[i]);
    }
    return dp[i][x] = solve(book,price,i-1,x);
}

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> book(n),page(n);
    for(int i=0 ; i<n ; ++i) {
    	cin >> book[i];
    }
    for(int i=0 ; i<n ; ++i) {
        cin >> page[i];
    }
    dp.resize(n+1,vector<int> (k+1,0));

    for(int i=1 ; i<=n ; ++i) {
        for(int j=1 ; j<=k ; ++j) {
            if(j - book[i-1] >= 0) {
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-book[i-1]]+page[i-1]);
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout << dp[n][k];

  	return 0;
}