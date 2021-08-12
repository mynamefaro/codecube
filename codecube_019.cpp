#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	vector <int> arr(n,0);
	for(int i=0;i<n;++i) scanf("%d",&arr[i]);
	while(k--){
		bool foundfront=false;
		for(int i=0;i<n-1;++i){
			if(arr[i]>arr[i+1]){
				arr.erase(arr.begin()+i);
				foundfront=true;
				break;
			}
		}
		if(foundfront) continue;
		arr.pop_back();
	}
	for(int i=0;i<arr.size();++i){
		printf("%d ",arr[i]);
	}
}
