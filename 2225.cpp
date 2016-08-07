#include <stdio.h>
#include <iostream>
#include <string.h>
#define mod 1000000000
using namespace std;
int N, K;
int memo[201][201];
int solve(int n, int k){
	if (n == 0 && k == 0){
		return 1;
	}
	else if (n < 0 || k < 0){
		return 0;
	}
	int &ret = memo[n][k];
	if (ret != -1){
		return ret;
	}
	ret = 0;
	for (int i = 0; i <= N; i++){
		ret += solve(n - i, k - 1);
		if (ret < mod){
			ret += mod;
			ret %= mod;
		}
		else{
			ret %= mod;
		}
	}
	return ret;
}
int main(void){
	cin >> N; cin >> K;
	memset(memo, -1, sizeof(memo));
	printf("%d", solve(N, K));
}
