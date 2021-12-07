#include<bits/stdc++.h>
using namespace std;
using lli=long long;
int A[100005],B[100005],buf[30];
int main(){
	int a,b;
	lli ans=0;
	scanf("%d",&a);
	for(int i=1;i<=a;++i)
	{
		scanf("%d",&A[i]);
	} 
	scanf("%d",&b);
	for(int i=1;i<=b;++i)
	{
		scanf("%d",&B[i]);
	}
	
	//for any B i th
	for(int j=0;j<28;++j){
		for(int i=1;i<=b;++i)
		{
			if(!(B[i]&(1<<j))){
				++buf[j];
			}
		}
	}
	//for any A i th
	for(int i=1;i<=a;++i)
	{
		for(int j=0;j<28;++j)
		{
			if(!(A[i]&(1<<j))){
				ans+=(lli)(b-buf[j])*(lli)(1<<j);
			}else{
				ans+=(lli)(buf[j])*(lli)(1<<j);
			}
		}
	}
	printf("%lld",ans);
}

