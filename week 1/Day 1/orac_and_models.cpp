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

int dp[100001];
int v[100001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
    	cin >> n;
    	fr(i,1,n+1) cin >> v[i];
    	for(int i=0 ; i<=n ; ++i) {
    		dp[i] = 1;
    	}
    	int ans = 1;

    	for(int i=1 ; i<=n ; ++i) {
    		for(int j=2*i ; j<=n ; j+=i) {
    			if(v[i] < v[j]) {
    				dp[j] = max(dp[j],dp[i]+1);
    			}
    		}
    		ans=max(ans,dp[i]);
    	}

    	cout << ans << "\n";
  	}
  	return 0;
}