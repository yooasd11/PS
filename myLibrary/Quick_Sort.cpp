#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

//Program name : quick sort
//Concept : divide & conquer
//Time complexity : O(n^2) (but O(nlogn) on everage)
//using random pivot

vector<int> input;
int n;

void quick_sort(vector<int>& input, int Left, int Right){
	if (Left >= Right) return;
	int pivot = Right;
	int low = Left, high = Right - 1;
	while (low < high){
		while (input[low] <= input[pivot] && low < high) low++;
		while (input[high] >= input[pivot] && low < high) high--;
		swap(input[low], input[high]);
	}
	if (input[pivot] <= input[high]) swap(input[pivot], input[high]);
	else low++;
	quick_sort(input, Left, low - 1);
	quick_sort(input, high + 1, Right);
}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &n);
	input = vector<int>(n);
	for (int i = 0; i < n; ++i) scanf("%d", &input[i]);
	quick_sort(input, 0, n - 1);
	for (int i = 0; i < n; ++i) printf("%d\n", input[i]);
	return 0;
}