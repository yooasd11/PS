#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

//Problem URL : http://www.acmicpc.net/problem/7578
//Problem type : idea
//Input : 500,000
//Time limit : 1000ms
//Solution : solvable using merge sort (binary indexed tree as well)

typedef long long ll;
vector<int> input;
int index[1000001];
int n;
ll ans;

vector<int> merge_sort(int Left, int Right){
	if (Left == Right) return vector<int>(1, input[Left]);

	int mid = (Left + Right) / 2;
	vector<int> leftPart = merge_sort(Left, mid);
	vector<int> rightPart = merge_sort(mid + 1, Right);

	vector<int> ret;
	int leftIdx = 0, rightIdx = 0;
	while (leftIdx < leftPart.size() || rightIdx < rightPart.size()){
		if (leftIdx >= leftPart.size()) ret.push_back(rightPart[rightIdx++]);
		else if (rightIdx >= rightPart.size()) ret.push_back(leftPart[leftIdx++]);
		else{
			if (leftPart[leftIdx] < rightPart[rightIdx]) ret.push_back(leftPart[leftIdx++]);
			else {
				//the number of inversions
				ans += (ll)leftPart.size() - (ll)leftIdx;
				ret.push_back(rightPart[rightIdx++]);
			}
		}
	}
	return ret;
}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ans = 0;
	scanf("%d", &n);
	int num;
	for (int i = 0; i < n; ++i){
		scanf("%d", &num);
		index[num] = i;
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", &num);
		input.push_back(index[num]);
	}
	vector<int> sorted = merge_sort(0, n - 1);
	printf("%lld\n", ans);
	return 0;
}