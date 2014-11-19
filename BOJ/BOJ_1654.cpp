#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <limits>
using namespace std;

//Problem URL : https://www.acmicpc.net/problem/1654
//Problem type : bisection
//Input : n - 10,000 / m - 1,000,000
//Time limit : 1000ms
//Key concept : proper bisection

//const int INF = numeric_limits<int>::max();
int n, m, INF;
vector<int> sticks;

int solve(){
	int lo = 0, hi = INF;
	int iteration = 100;
	while (iteration--){
		int mid = (lo + hi) / 2;
		int cnt = 0;
		for (int i = 0; i < n; ++i) cnt += sticks[i] / mid;
		if (cnt < m) hi = mid - 1;
		else lo = mid + 1;
	}
	return hi;
}

int main(void){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d %d", &n, &m);
	sticks = vector<int>(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &sticks[i]);
		INF = max(INF, sticks[i]);
	}
	printf("%d\n", solve());
	return 0;
}