#include <bits/stdc++.h>
using namespace std;
using lli = long long;

lli table_a[100002] , table_b[100002];

int main(){
	lli N , H , W;
	cin >> N >> H >> W;
	lli x;
	lli mx_a = -2e9 , mx_b = -2e9;
	for(int i = 1;i <= N;++i){
		cin >> x;
		table_a[i] = x + table_a[i - 1];
		lli consider = table_a[i];
		if(i - H > 0) consider -= table_a[i - H];
		mx_a = max(mx_a , consider);
	}
	for(int i = 1;i <= N;++i){
		cin >> x;
		table_b[i] = x + table_b[i - 1];
		lli consider = table_b[i];
		if(i - W > 0) consider -= table_b[i - W];
		mx_b = max(mx_b , consider);
	}
	cout << (mx_a * W) + (mx_b * H);
}
