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

	int pivot = input[Left + rand() % (Right - Left + 1)];
	//int pivot = input[(Left + Right) / 2];
	//int pivot = input[Left];
	//int pivot = input[Right];
	int low = Left, high = Right;
	while (low < high){
		while (input[low] < pivot) ++low;
		while (input[high] > pivot) --high;
		if (low > high) break;
		swap(input[low], input[high]);
		++low, --high;
	}
	quick_sort(input, Left, high);
	quick_sort(input, low, Right);
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