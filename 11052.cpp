#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int memo[1001];
int Price[1001];
//solve의 정의 붕어빵의 개수가 N일 때의 최대수익
int solve(int N){
	//붕어빵의 개수 가 0이면 최대수익은 당빠 0
	if (N == 0){
		return 0;
	}
	//memo와 ret은 하나 ret을 건들면 memo[N]도...
	int &ret = memo[N];
	//초기화된 값이 아니면 중복호출
	if (ret != -1){
		return ret;
	}
	//return ret이 아니면 0으로 우선 바꿔준 뒤
	ret = 0;
	//1부터 N까지 반복문을 돌며 N-i개 붕어빵일 때 Price[i](i개)가격을 더하며 최대값을 구함
	for (int i = 1; i <= N; i++){
		ret = max(ret, solve(N - i) + Price[i]);
	}
	return ret;
}

int main(void){
	int N;
	cin >> N;
	memset(memo, -1, sizeof(memo));
	for (int i = 1; i <= N; i++){
		cin >> Price[i];
	}
	printf("%d", solve(N));
}

