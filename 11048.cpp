#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;
int N, M;
int field[1001][1001];
int memo[1001][1001];
//(1,1)에서 (x,y)까지 가져올 수 있는 사탕의 최댓값
int solve(int x, int y){
	if (x < 1 || y < 1){
		return 0;
	}
	int &ret = memo[x][y];
	if (ret != -1){
		return ret;
	}
	ret = max(solve(x - 1, y), solve(x, y - 1)) + field[x][y];
	return ret;
}
int main(void){
	cin >> N; cin >> M;
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= M; j++){
			cin >> field[i][j];
			memo[i][j] = -1;
		}
	}
	int answer = solve(N, M);
	printf("%d", answer);
}
