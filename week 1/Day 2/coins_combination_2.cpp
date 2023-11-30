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

int solution(vector<int> &v,int i,int sum) {
	if(sum <= 0) {
		return sum == 0;
	}
	if(i == (int)v.size()) return 0;
	if(dp[sum] != -1) {
		return dp[sum];
	}
	int res = 0;
	for(int j=i ; j<(int)v.size() ; ++j) {
		res = (res + solution(v,j,sum-v[i]));
	}
	return dp[sum] = res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin >> n >> k;
    vi v(n);
    fr(i,0,n) cin >> v[i];
    dp.resize(k+1,-1);
    cout << solution(v,0,k);
  	return 0;
}