#include <bits/stdc++.h>
using namespace std;
using pii = pair<int , int>;

vector <int> arr;
int N;

int query(int i){
	int mx = -2e9;int k;
	for(int j = i + 1;j < N;++j){
		if(arr[j] > arr[i]) return j;	
		if(mx < arr[j]){
			mx = arr[j];
			k = j;
		}
	}
	return k;
}
int main(){
	cin >> N;int x;
	for(int i = 0;i < N;++i){
		cin >> x;arr.push_back(x);
	}

	int i = 0 , j , mx;
	while(i < N - 1){
		j = query(i);
		for(int r = 1;r <= j - i;++r) printf("%d ",min(arr[j] , arr[i]));
		i = j;
	}
}
