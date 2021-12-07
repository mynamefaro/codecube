#include<bits/stdc++.h>
using namespace std;
using lli=long long;
int fac[100002],P=1e9+7;
bool check(int mid,lli hash,int N[],int n,int m){
	if(mid==0) return true;
	lli H=0,pow=1;
	for(int i=0;i<mid;++i){
		H*=P;
		H+=N[i];
		if(i>0) pow*=P;
	}
	if(H==hash) return true;
	for(int i=mid;i<n-m+mid;++i){
		H-=N[i-mid]*pow;
		H*=P;
		H+=N[i];
		if(H==hash) return true;
	}
	return false;
}
int main(){
	for(int i=2;i<=100001;++i){
		for(int j=i;j<=100001;j+=i){
			++fac[j];
		}
	}
	int n,m;
	scanf("%d%d",&n,&m);
	int ans=0;
	lli H[n+1];
	int N[n],M[m];
	int l=1,r=m;
	H[0]=(long long) 0;
	for(int i=0;i<n;++i){
		scanf("%d",&N[i]);
		N[i]=fac[N[i]];
	}
	for(int i=0;i<m;++i){
		scanf("%d",&M[i]);
		M[i]=fac[M[i]];
		H[i+1]=H[i]*P;
		H[i+1]+=M[i];
	}
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid,H[mid],N,n,m)){
			l=mid+1;
			ans=max(ans,mid);
		}else{
			r=mid-1;
		}
	}
	printf("%d",ans);
}
