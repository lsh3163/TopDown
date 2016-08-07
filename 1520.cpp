#include <stdio.h>
#include <iostream>
using namespace std;
//세로의 크기,가로의 크기
int M, N;
int field[501][501];
int memo[501][501];
int x_move[] = { 1, 0, -1, 0 };
int y_move[] = { 0, 1, 0, -1 };
int solve(int x, int y){
	if (x == M && y == N){
		return 1;
	}
	int &ret = memo[x][y];
	if (ret != -1){
		return ret;
	}
	ret = 0;
	for (int i = 0; i < 4; i++){
		int nx = x + x_move[i];
		int ny = y + y_move[i];
		if (nx <= M && ny <= N && nx >= 1 && ny >= 1){
			if (field[x][y] > field[nx][ny]){
				ret += solve(nx, ny);
			}
		}
	}
	return ret;
}
int main(void){
	cin >> M; cin >> N;
	for (int i = 1; i <= M; i++){
		for (int j = 1; j <= N; j++){
			cin >> field[i][j];
			memo[i][j] = -1;
		}
	}
	int answer = solve(1, 1);
	printf("%d", answer);
}
