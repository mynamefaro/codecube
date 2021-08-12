#include<bits/stdc++.h>
using namespace std;
using lli=long long;
int P=1e9+7;
bool notprime[1000004];
vector <int> prime;
int memo[100002];
lli hashm[1000004];
int factor(int n){
	int m=n;
	if(n==1) return 1;
	if(memo[m]==0){
		int ans=1;
		for(auto p:prime){
			if(n<p) break;
			int cnt=1;
			while(n%p==0){
				n/=p;
				++cnt;
			}
			ans*=cnt;
		}
		memo[m]=ans;
	}
	return memo[m];
	//return ans;
}
bool check(int l,int arrn[],int n){
	lli hash=0;
	int PP=1;
	for(int i=0;i<l;++i){
		hash*=P;
		hash+=factor(arrn[i]);
		if(i>0) PP*=P;
	}
	for(int i=l-1;i<n;++i){
		if(i>=l){
			hash-=(factor(arrn[i-l]))*PP;
			hash*=P;
			hash+=factor(arrn[i]);
		}
		if(hash==hashm[l]) return true;
	}
	return false;
}
int main(){
	prime.push_back(2);
	notprime[2]=true;
	for(int i=3;i<=100000;i+=2){
		if(!notprime[i]){
			prime.push_back(i);
			for(int j=3*i;j<=100000;j+=(2*i)) notprime[j]=true;
		}
	}
	int n,m;
	scanf("%d%d",&n,&m);
	int ans=0;int a=0;
	int arrn[n],arrm[m];
	for(int i=0;i<n;++i){
		scanf("%d",&arrn[i]);
	}
	lli hash=0;
	for(int i=0;i<m;++i){
		scanf("%d",&arrm[i]);
		hash*=P;
		hash+=factor(arrm[i]);
		hashm[i+1]=hash;
	}
	int ans=0;
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid,arrn,n)){
			l=mid+1;
			ans=max(ans,mid);
		}else{
			r=mid-1;
		}
	}
	printf("%d",ans);
}

