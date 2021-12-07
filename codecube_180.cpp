#include<bits/stdc++.h>
using namespace std;
using lli=long long;
lli table[2][50005];

int main(){
	int n,k,m;
	scanf("%d%d%d",&n,&k,&m);
	lli arr[n+1];
	arr[0]=0;
	for(int i=1;i<=n;++i){
		scanf("%lld",&arr[i]);
		table[0][i]+=arr[i]+table[0][i-1];
	}
	for(int i=1;i<=k;++i){
		lli mx=-2e18;
		for(int j=0;j<=n;++j){
			table[i%2][j]=-2e18;
			if(j==0) continue;
			if(m<=j){
				table[i%2][j]=max(table[i%2][j] , table[(i-1)%2][0]);
			}
			if(j>m){
				mx=max(mx , table[(i-1)%2][j-m-1]+arr[j-m]);
			}
			/*for(int k=1;k<=j-m;++k){
				table[i%2][j]=max(table[i%2][j] , table[(i-1)%2][k-1]+arr[k]);
			}*/
			table[i%2][j]=max(table[i%2][j] , table[i%2][j-1]+arr[j]);
			table[i%2][j]=max(table[i%2][j] , mx);
			//printf("%lld ",table[i][j]);
		}
		//printf("\n");
	}
	printf("%lld",table[k%2][n]);	
}
