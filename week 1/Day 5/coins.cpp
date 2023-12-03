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

vector<vector<double>> dp;

double solve(vector<double> &v,int i,int tail) {
	if(i == v.size()) {
		return 1;
	}
	if(dp[i][tail] != -1) {
		return dp[i][tail];
	}
	if(tail > 0) {
		return dp[i][tail] = solve(v,i+1,tail-1)*(1-v[i])+solve(v,i+1,tail)*v[i];
	}
	return dp[i][tail] = solve(v,i+1,tail)*v[i];
}

int main(){
    int n;
    cin >> n;
    vector<double> v(n);
    for(int i=0 ; i<n ; ++i) {
    	cin >> v[i];
    }
    int tail = 0;
    if(n%2 == 0) {
    	tail = (n/2)-1;
    }
    else {
    	tail = n/2;
    }
    dp.resize(n+1,vector<double> (tail+1,-1));
    cout << solve(v,0,tail) << "\n";
  	return 0;
}