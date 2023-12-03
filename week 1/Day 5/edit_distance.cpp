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

int editDistance(string &s1,string &s2,int i,int j) {
	if(i == s1.length()) {
		return s2.length()-j;
	}
	if(j == s2.length()) {
		return s1.length()-i;
	}
	if(dp[i][j] != -1) {
		return dp[i][j];
	}
	if(s1[i] == s2[j]) {
		return editDistance(s1,s2,i+1,j+1);
	}
	int add = editDistance(s1,s2,i+1,j);
	int replace = editDistance(s1,s2,i+1,j+1);
	int remove = editDistance(s1,s2,i,j+1);
	return dp[i][j] =  min(add, min(replace , remove))+1;
}

int main(){
	string s1,s2;
	cin >> s1 >> s2;
	dp.resize(s1.length()+1, vector<int> (s2.length()+1,-1));
	cout << editDistance(s1,s2,0,0);
  	return 0;
}