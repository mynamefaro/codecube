#include <bits/stdc++.h>
using namespace std;
int main(){
	unordered_map <int , vector<int>> arr_c;
	int N , L , R , C , Q;
	scanf("%d %d",&N ,&Q);
	for(int i = 1;i <= N;++i){
		scanf("%d",&C);
		arr_c[C].push_back(i);
	}
	while(Q--){
		scanf("%d %d %d",&L ,&R ,&C);
		if(arr_c.count(C) == 0){
			printf("0\n");
		}else{
			int left = -1, right = -1;
			int l,r;
			vector <int> arr = arr_c[C];
			l = 0;r = arr.size() - 1;
			while(l <= r){
				int mid = (l + r)/2;
				if(arr[mid] >= L && (arr[mid - 1] < L || mid == 0) && arr[mid] <= R){
					left = mid;
					break;
				}
				if(arr[mid] <= L) l = mid + 1;
				if(arr[mid] > L) r = mid - 1;
			}
			l = 0;r = arr.size() - 1;
			while(l <= r){
				int mid = (l + r)/2;
				if(arr[mid] <= R && (arr[mid + 1] > R || mid == arr.size() - 1) && arr[mid] >= L){
					right = mid;
					break;
				}
				if(arr[mid] < R) l = mid + 1;
				if(arr[mid] >= R) r = mid - 1;
			}
			if(left == -1 || right == -1){
				printf("0\n");
			}else{
				printf("%d\n",right - left + 1);
			}
		}
	}
}
