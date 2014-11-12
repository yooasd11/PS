#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>
using namespace std;
 
//Problem URL : http://www.acmicpc.net/problem/10216
//Problem type : graph (counting connectd components)
//Input : 3000
//Time limit : 8000ms
//Solution : Union & Find

//union & find
class DisjointSet{
public:
    vector<int> parent, rank;
    DisjointSet(int n) : parent(n+1), rank(n, 1) {
        for (int i = 0; i<n; ++i) parent[i] = i;
    }
 
    int find(int u){
        if (u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }
 
    bool merge(int u, int v){
        u = find(u); v = find(v);
        if (u == v) return false;
        if (rank[u]>rank[v]) swap(u, v);
        parent[u] = v;
        if (rank[u] == rank[v]) ++rank[v];
        return true;
    }
};
 
int t, n;
map<int, int> ans;
vector< pair<pair<int, int>, int> > input;
 
bool check(int u, int v){
    int x1 = input[u].first.first, y1 = input[u].first.second, r1 = input[u].second;
    int x2 = input[v].first.first, y2 = input[v].first.second, r2 = input[v].second;
    int dist = (x1 - x2) * (x1 - x2) + (y1 - y2)*(y1 - y2);
    if (dist <= (r1 + r2) * (r1 + r2)) return true;
    return false;
}
 
void solve(DisjointSet& ds){
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            if (i == j) continue;
            if (check(i, j)) ds.merge(i, j);
        }
    }
    for (int i = 0; i < n; ++i) ans[ds.find(i)]++;
}
 
int main(){
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d", &t);
    while (t--){
        ans.clear();
        scanf("%d", &n);
        DisjointSet DS(n + 1);
        input = vector< pair< pair<int, int>, int> >(n + 1);
        for (int i = 0; i < n; ++i)
            scanf("%d %d %d", &input[i].first.first, &input[i].first.second, &input[i].second);
        solve(DS);
        printf("%d\n", ans.size());
    }
    return 0;
}