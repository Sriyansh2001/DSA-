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

vector<vector<int>> dp;

bool solve(vector<int> &v,int i,int sum) {
	if(sum <= 0) {
		return sum == 0;
	}
	if(i < 0) {
		return false;
	}
	if(dp[i][sum] != -1) {
		return dp[i][sum];
	}
	return dp[i][sum] = (int)(solve(v,i-1,sum) || solve(v,i-1,sum-v[i]));
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0 ; i<n ; ++i) {
    	cin >> v[i];
    }
    int mx = 1e5+1;
    dp.resize(n+1 , vector<int> (mx+1,-1));
    vector<int> res;
    for(int i=1 ; i<mx ; ++i) {
    	if(solve(v,n-1,i)) {
    		res.push_back(i);
    	}
    }
    cout << res.size() << "\n";
    for(auto i:res) {
    	cout << i << " ";
    }
    cout << "\n";
  	return 0;
}