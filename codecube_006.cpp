#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int main(){
	int N;cin >> N;
	lli x;lli mx = -2e9;
	lli sum = 0;
	vector <lli> table (N + 2,0);
	for(int i = 1;i <= N;++i){
		cin >> x;
		if(i % 2 > 0) x*= -1;
		sum += x;
		table[i] = max(table[i - 1] + x , x);
		mx = max(mx , table[i]);
	}
	if(mx < 0) mx = 0;
	cout << sum - (2 * mx);
}
