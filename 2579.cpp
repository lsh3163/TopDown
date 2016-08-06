#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int memo[301][3];
vector<int> stair;
int solve(int idx, int count){
	if (idx == 0){
		return 0;
	}
	int &ret = memo[idx][count];
	if (ret != -1){
		return ret;
	}
	ret = 0;
	if (count == 1){
		ret = solve(idx - 2, 0) + stair[idx];
		return ret;
	}
	ret = max(ret, solve(idx - 1, count + 1)+stair[idx]);
	ret = max(ret, solve(idx - 2, 0) + stair[idx]);
	return ret;
}
int main(void){
	memset(memo, -1, sizeof(memo));
	cin >> N;
	stair.resize(N+1);
	for (int i = 1; i <= N; i++){
		cin >> stair[i];
	}
	printf("%d", solve(N, 0));
}
