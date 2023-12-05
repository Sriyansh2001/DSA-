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

long long solve(int n,int m) {
	if(m == 0) {
		return 1;
	}
	long long ans = 0;
	for(int j=1 ; j<=n ; ++j) {
		ans = ans + solve(n,m-1) * j;
		ans %= M;
	}
	return ans;
}

int main(){
    int n,m;
    cin >> n >> m;
    cout << solve(n,m);
  	return 0;
}