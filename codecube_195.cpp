#include<bits/stdc++.h>
using namespace std;
using lli=long long;
int main(){
	int m,k;
	scanf("%d%d",&m,&k);
	vector<int>A ,qs;
	int x;
	for(int i=0;i<m;++i){
		scanf("%d",&x);
		A.push_back(x);
	}
	A.push_back(0);
	sort(A.begin(),A.end());
	for(int i=1;i<=m;++i){
		qs.push_back(A[i]-A[i-1]-1);
		if(qs.size()>1) qs[qs.size()-1]+=qs[qs.size()-2];
	}
	//for(auto xx:qs) cout<<xx<<" ";
	while(k--){
		scanf("%d",&x);
		int j=upper_bound(qs.begin(),qs.end(),x-1)-qs.begin();
		printf("%d ",x+j);
	}
}
