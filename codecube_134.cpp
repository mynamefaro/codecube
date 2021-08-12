#include<bits/stdc++.h>
using lli=long long;
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	lli sumn=0;
	vector<lli> nn,mm;
	while(n--){
		lli x;
		scanf("%lld",&x);
		nn.push_back(x);
		sumn=sumn | x;
	}
	int m;
	scanf("%d",&m);
	lli summ=0;
	while(m--){
		lli x;
		scanf("%lld",&x);
		mm.push_back(x);
		summ=summ | x;
	}
	printf("%lld",sumn^summ);
	lli ans=0;
	for(auto nnn:nn){
		for(auto mmm:mm){
			ans+=(nnn^mmm);
		}
	}
	printf("%lld",ans);
}
