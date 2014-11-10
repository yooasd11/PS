#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Program name : merge sort
//Concept : divide & conquer
//Time complexity : O(nlogn)

vector<int> input;
int n;

//returns sorted vector
vector<int> merge_sort(int Left, int Right){
	//base case : only element
	if (Left == Right) return vector<int>(1, input[Left]);

	//dividing part
	int mid = (Left + Right) / 2;
	vector<int> leftPart = merge_sort(Left, mid);
	vector<int> rightPart = merge_sort(mid + 1, Right);

	//merging part
	vector<int> ret;
	int leftIdx = 0, rightIdx = 0;
	while (leftIdx < leftPart.size() || rightIdx < rightPart.size()){
		if (leftIdx >= leftPart.size()) ret.push_back(rightPart[rightIdx++]);
		else if (rightIdx >= rightPart.size()) ret.push_back(leftPart[leftIdx++]);
		else{
			if (leftPart[leftIdx] < rightPart[rightIdx]) ret.push_back(leftPart[leftIdx++]);
			else ret.push_back(rightPart[rightIdx++]);
		}
	}
	return ret;
}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &n);
	input = vector<int>(n);
	for (int i = 0; i < n; ++i) scanf("%d", &input[i]);
	vector<int> ans = merge_sort(0, n - 1);
	for (int i = 0; i < n; ++i) printf("%d\n", ans[i]);
	return 0;
}