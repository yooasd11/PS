#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <cstdio>
#include <vector>
#include <numeric>
using namespace std;

//Problem URL : http://www.acmicpc.net/problem/9335
//Problem type : brute force
//Input : 20
//Time limit : 2000ms
//Key concept : none
 
const int INF = numeric_limits<int>::max() - 50;
int t, n;
vector<int> adj[21];
 
int solve(int k, vector<bool> visited){
    bool flag = true;
    for (int i = 1; i <= n; ++i) if (!visited[i]) flag = false;
    if (flag) return 0;
    if (k > n) return INF;
 
    vector<bool> visited1 = visited;
    visited1[k] = true;
    for (int i = 0; i < adj[k].size(); ++i){
        int here = adj[k][i];
        visited1[here] = true;
    }
    return min(solve(k + 1, visited), 1 + solve(k + 1, visited1));
}
 
int main(){
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d", &t);
    while (t--){
        scanf("%d", &n);
        vector<bool> visited = vector<bool>(n + 1, false);
        for (int i = 1; i <= n; ++i){
            int m;
            scanf("%d", &m);
            adj[i] = vector<int>(m);
            for (int j = 0; j < m; ++j) scanf("%d", &adj[i][j]);
        }
        printf("%d\n", solve(1, visited));
    }
    return 0;
}