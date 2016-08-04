#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
//Memoization 최대 10의 6승
int memo[1231231];
//num에서 1로만드는 최소 연산 return
int solve(int num){
	//1일 때 연산 No
	if (num == 1){
		return 0;
	}
	//2,3일 때 각각 2,3으로 나누어주면 됨
	if (num == 2 || num == 3){
		return 1;
	}
	//ret과 memo는 한 몸,ret을 건들면 memo[num]도 바뀜
	int &ret = memo[num];
	//초기화된 값이 아니라면 중복호출이므로
	if (ret != -1){
		return ret;
	}
	//1을 빼고 연산 횟수 1증가
	ret = solve(num - 1) + 1;
	//정수 num이 3으로 나누어 떨어지면
	//더 작은 연산 횟수를 ret에 저장
	if (num % 3 == 0){
		ret = min(ret, solve(num / 3) + 1);
	}
	if (num % 2 == 0){
		ret = min(ret, solve(num / 2) + 1);
	}
	return ret;
}
int main(void){
	int N;
	cin >> N;
	memset(memo, -1, sizeof(memo));
	printf("%d", solve(N));
}
