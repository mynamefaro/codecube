#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;char c;int x;
	cin >> N;
	vector <int> qs_left (N + 1,0) , qs_right (N + 1,0);
	for(int i = 1;i <= N;++i){
		cin >> c >> x;
		if(c == 'R'){
			qs_right[i] = x + qs_right[i - 1];
			qs_left[i] = qs_left[i - 1];
		}else{
			qs_left[i] = x + qs_left[i - 1];
			qs_right[i] = qs_right[i - 1];
		}
	}
	//HAN LEFT 
	int mx_right = 0, i_right = 1, j_right = N, i , j , right = 0;
	for(int k = 1;k <= N;++k){
		int x_left = qs_left[k] - qs_left[k - 1];
		int x_right = qs_right[k] - qs_right[k - 1];
		x = max(x_left , x_right);
		if(x == x_left) x*= -1;
		if(right == 0 && right + x > 0) i = k;
		right += x;
		right = max(right , 0);
		if(right >= mx_right){
			if(right > mx_right || k - i < j_right - i_right){
				i_right = i;
				j_right = k;
			}
			mx_right = right;
		}
	}
	//HAN RIGHT
	int mx_left = 0, i_left = 1, j_left = N, left = 0;
	for(int k = 1;k <= N;++k){
		int x_left = qs_left[k] - qs_left[k - 1];
		int x_right = qs_right[k] - qs_right[k - 1];
		x = max(x_left , x_right);
		if(x == x_right) x*= -1;
		if(left == 0 && left + x > 0) i = k;
		left += x;
		left = max(left , 0);
		if(left >= mx_left){
			if(left > mx_left || k - i < j_left - i_left){
				i_left = i;
				j_left = k;
			}
			mx_left = left;
		}
	}
	int sum_right = qs_right[i_left - 1] + qs_left[j_left] - qs_left[i_left - 1] + qs_right[N] - qs_right[j_left];
	int sum_left = qs_left[i_right - 1] + qs_right[j_right] - qs_right[i_right - 1] + qs_left[N] - qs_left[j_right];
	if(sum_right >= sum_left){
		printf("R %d %d %d",sum_right ,i_left , j_left);return 0;
	}
	printf("L %d %d %d",sum_left ,i_right , j_right);
}
