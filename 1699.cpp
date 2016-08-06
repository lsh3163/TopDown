#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <climits>
#include <algorithm>
using namespace std;

//주여진 자연수=>제곱수의 합으로 나타내야됨
int N;
vector<int> Number;
int memo[100001];
//solve의 역할 : value 의 제곱수들의 합 중 
//항의 개수 최소값 return
int solve(int value){
	if (value < 1){
		return 0;
	}
	int &ret = memo[value];
	if (ret != -1){
		return ret;
	}
	ret = 100000;
	for (int i = 1; i*i <= value; i++){
		ret = min(ret, solve(value - i*i) + 1);
	}
	return ret;
}
int main(void){
	cin >> N;
	//index 0엔 0
	Number.push_back(0);
	//각 index의 제곱값이 Number에 들어감
	for (int i = 1; i*i <= N; i++){
		Number.push_back(i*i);
	}
	memset(memo, -1, sizeof(memo));
	printf("%d", solve(N));
}
