#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

//Problem URL : http://www.acmicpc.net/problem/7578
//Problem type : idea
//Input : 500,000
//Time limit : 1000ms
//Solution : solvable using binary indexed tree (merge sort as well)
//           checking if bigger number appears in the past, finally get answer by range sum
 
typedef long long ll;
vector<ll> input, indexTree;
int t, n, pos;
int index[1000001];
 
void update(int key){
    key += pos;
    indexTree[key]++;
    for (int i = key / 2; i > 0; i /= 2) indexTree[i] = indexTree[2 * i] + indexTree[2 * i + 1];
}
 
ll rangeSum(int Left){
    Left += pos + 1;
    int Right = n + pos;
    ll ret = 0;
    while (Left < Right){
        if (Left % 2 == 1) ret += indexTree[Left++];
        if (Right % 2 == 0) ret += indexTree[Right--];
        Left /= 2;
        Right /= 2;
    }
    if (Left == Right) ret += indexTree[Left];
    return ret;
}
 
void init(){
    pos = 1;
    scanf("%d", &n);
    input = vector<ll>(n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &input[i]);
        index[input[i]] = i;
    }
 
    for (int i = 0; i < n; ++i) scanf("%lld", &input[i]);
 
    while (pos < n) pos *= 2;
    indexTree = vector<ll>(4 * n, 0);
}
 
ll solve(){
    ll ret = 0;
    for (int i = 0; i < n; ++i){
        int idx = index[input[i]];
        ret += rangeSum(idx);
        update(idx);
    }
    return ret;
}
 
int main(){
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
    init();
    printf("%lld\n", solve());
    return 0;
}