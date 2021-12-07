#include<bits/stdc++.h>
using namespace std;
using lli=long long;
const int N = 1002;

lli mod = 1e9+7;
lli DP[4][N][N],ans;
int main(){
	int n;
	scanf("%d",&n);
	char arr[n+1][n+1];
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j) cin >> arr[i][j];
	}

	DP[0][1][1]=DP[1][1][n]=DP[2][n][1]=DP[3][n][n]=1;
	
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(arr[i][j]=='0' or (i==1 and j==1)) continue;
			DP[0][i][j]=(DP[0][i-1][j]+DP[0][i][j-1])%mod;
		}
	}
	
	for(int i=1;i<=n;++i){
		for(int j=n;j>=1;--j){
			if(arr[i][j]=='0' or (i==1 and j==n)) continue;
			DP[1][i][j]=(DP[1][i-1][j]+DP[1][i][j+1])%mod;
		}
	}
	
	for(int i=n;i>=1;--i){
		for(int j=1;j<=n;++j){
			if(arr[i][j]=='0' or (i==n and j==1)) continue;
			DP[2][i][j]=(DP[2][i+1][j]+DP[2][i][j-1])%mod;
		}
	}
	
	for(int i=n;i>=1;--i){
		for(int j=n;j>=1;--j){
			if(arr[i][j]=='0' or (i==n and j==n)) continue;
			DP[3][i][j]=(DP[3][i+1][j]+DP[3][i][j+1])%mod;
		}
	}
	
	for(int i=2;i<n;++i){
		for(int j=2;j<n;++j){
			if(arr[i][j]=='0') continue;
			ans=(ans+(((DP[0][i][j-1]*DP[1][i-1][j])%mod)*((DP[2][i+1][j]*DP[3][i][j+1])%mod)))%mod;
			ans=(ans+(((DP[0][i-1][j]*DP[1][i][j+1])%mod)*((DP[2][i][j-1]*DP[3][i+1][j])%mod)))%mod;
		}
	}
	/*for(int k=0;k<4;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j) cout << DP[k][i][j] << " ";
			cout << endl;
		}
		cout << endl;
	}*/
	printf("%lld",ans);
}
