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

int main(){
    int n;
    cin >> n;
    vector<vector<int>> v;
    
    for(int i=0 ; i<n ; ++i) {
    	int x,y,z;
    	cin >> x >> y >> z;
    	v.push_back({x,y,z});
    }

    sort(all(v));

    map<int,int> mp;
    

  	return 0;
}