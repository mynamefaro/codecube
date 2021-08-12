#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k,q;
	scanf("%d%d%d",&n,&k,&q);
	vector <int> arr[k+1];
	for(int i=1;i<=n;++i){
		int x;
		scanf("%d",&x);
		if(x<=k) arr[x].push_back(i);
	}
	while(q--){
		int l,r;
		scanf("%d%d",&l,&r);
		bool ans=true;
		for(int i=1;i<=k;++i){
			if(l>arr[i].back()) ans=false;
			auto it=upper_bound(arr[i].begin(),arr[i].end(),l-1);
			if(*it>r){
				//cout << i << " " << *it << endl;
				ans=false;
			}
			if(!ans) break;
		}
		if(ans){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
}
