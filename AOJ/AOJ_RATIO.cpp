#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

//Problem URL : https://algospot.com/judge/problem/read/RATIO
//Problem type : bisection
//Input : n - 2,000,000,000
//Time limit : 1000ms
//Key concept : math does NOT work!


typedef long long ll;
int n, m;
const ll INF = 2000000000;

int ratio(ll b, ll a){
	return (a * 100) / b;
}

int solve(ll games, ll won){
	if (ratio(games, won) == ratio(games + INF, won + INF)) return -1;
	ll lo = 0, hi = INF;
	int cnt = 100;
	while (cnt--){
		ll mid = (lo + hi) / 2;
		if (ratio(games, won) == ratio(games + mid, won + mid)) lo = mid;
		else hi = mid;
	}
	return hi;
}

int main(void){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	while (cin>>n>>m)
		printf("%d\n", solve(n, m));
	return 0;
}