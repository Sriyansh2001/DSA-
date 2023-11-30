#include<bits/stdc++.h>
using namespace std;
#define fr(i,L,R) for (int i = L; i < R; i++)
#define fb(i,L,R) for (int i = L; i > R; i--)
#define ll long long int
#define INF 1001001001
#define PI 3.1415926535897932384626
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define pb push_back
#define M 1000000007
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
typedef map<int,int> mpi;
typedef map<int,vector<int>> mpvi;

vvi dp;

int solve(vector<string> &v,int i,int j,vector<vector<int>> &dp) {
	if( i == (int)v.size()-1 && j == (int)v.size()-1) {
		if(v[i][j] == '*') return 0;
		return 1;
	}
	if( i<0 || j<0 || i>= (int)v.size() || j >= (int)v.size()) {
		return 0;
	}
	if(dp[i][j] != -1) {
		return dp[i][j];
	}
	if(v[i][j] == '*') {
		return dp[i][j] = 0;
	}
	return dp[i][j] = (solve(v,i+1,j,dp)+solve(v,i,j+1,dp))%M;
}

int main(){
    int n;
    cin >> n;
    vector<string> v(n);
    fr(i,0,n) cin >> v[i];
    dp.resize(n,vi(n,-1));
    cout << solve(v,0,0,dp);
  	return 0;
}