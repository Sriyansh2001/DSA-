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

int mx = 0;
vector<long long> dp;

long long solve(vector<long long> &v,int i) {
	if(i >= mx+1) {
		return 0;
	}
	if(dp[i] != -1) {
		return dp[i];
	}
	return dp[i] = max(solve(v,i+2)+v[i],solve(v,i+1));
}

int main(){
    int n;
    cin >> n;
    vi v(n);
    fr(i,0,n) cin >> v[i];
    vector<long long> k(1e5+1,0);
    fr(i,0,n) {
    	k[v[i]]+=v[i];
    	mx = max(mx,v[i]);
    }
    dp.resize(mx+2,-1);
    cout << solve(k,0);
  	return 0;
}