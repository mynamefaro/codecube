#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	int sum[n+1][n+1],arr[n];
	
	for(int i=1;i<=n;++i){
		scanf("%d",&arr[i]);
	}
	priority_queue<int> mx;
	priority_queue<int,vector<int>,greater<int>> mn;
	for(int i=1;i<=n;++i){
		
		int summax=0,summin=0;
		int m=0,mm=0;
		mx.push(0);
		mn.push(2e9);
		for(int j=i;j<=n;++j){
			if(arr[j]<=mx.top() and arr[j]<=mn.top()){
				if(mx.size()-mn.size()==1){
					summin+=mx.top();
					summax-=mx.top();
					mn.push(mx.top());
					mx.pop();
					
				}
				summax+=arr[j];
				mx.push(arr[j]);
			}else if(arr[j]>=mx.top() and arr[j]>=mn.top()){
				if(mn.size()==mx.size()){
					summax+=mn.top();
					summin-=mn.top();
					mx.push(mn.top());
					mn.pop();
				}
				summin+=arr[j];
				mn.push(arr[j]);
			}else if(arr[j]>=mx.top() and arr[j]<=mn.top()){
				if(mx.size()-mn.size()==1){
					mn.push(arr[j]);
					summin+=arr[j];
				}else if(mx.size()==mn.size()){
					mx.push(arr[j]);
					summax+=arr[j];
				}
			}
			if(mx.size()-mn.size()==1){
				mm=m;
				m=mx.top();
			}else if(mx.size()==mn.size()){
				mm=m;
				m=(mx.top()+mn.top())/2;
			}
			sum[i][j]=(m*mx.size())-summax - (m*mn.size())+summin;
			//printf("%d ",sum[i][j]);
		}
		while(!mn.empty()) mn.pop();
		while(!mx.empty()) mx.pop();
		//printf("\n");
	}
	int DP[k+1][n+1]; //K x N
	for(int j=1;j<=n;++j) DP[1][j]=sum[1][j];
	
	for(int i=2;i<=k;++i){
		for(int j=i;j<=n;++j){
			int mn=2e9;
			for(int l=j;l>=i;--l){
				mn=min(mn,sum[l][j]+DP[i-1][l-1]);
			}
			DP[i][j]=mn;
			//printf("%d ",DP[i][j]);
		}
		//cout << endl;
	} 
	printf("%d",DP[k][n]);
}
