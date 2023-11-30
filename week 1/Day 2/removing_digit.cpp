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

vi dp;

int solve(int n) {
	if(n == 0) {
		return 0;
	}
	if(dp[n] != -1) {
		return dp[n];
	}
	int ans = INT_MAX;
	int k = n;
	while(k != 0) {
		int x = (k%10);
		if(x != 0)
			ans = min(ans,solve(n-x)+1);
		k/=10;
	}
	return dp[n] = ans;
}

int main(){
    int n;
    cin >> n;
    dp.resize(n+1,-1);
    cout << solve(n);
  	return 0;
}