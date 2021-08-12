#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int memo[1000001][2][3];
bool visited[1000001][2][3];

int N;

vector <int> arr (1 , 0);

int solve(int n , int e , int z){
	if(n > N) return 0;
	if(!visited[n][e][z]){
		visited[n][e][z] = true;
		int a = arr[n];
		if(e > 0) a*=-1;
		memo[n][e][z] = a + solve(n + 1,(e + 1) % 2,z);
		if(z > 0) memo[n][e][z] = min(memo[n][e][z] , a + solve(n + 1 , e , z - 1));
	}
	return memo[n][e][z];
}

int main(){
	cin >> N;
	int x;int mx = -2e9;
	int sum = 0;
	for(int i = 1;i <= N;++i){
		cin >> x;
		arr.push_back(x);
	}
	cout << solve(1 , 1 , 2);
}
