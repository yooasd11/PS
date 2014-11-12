#include <vector>
using namespace std;

class DisjointSet{
public:
	vector<int> parent, rank;
	DisjointSet(int n) : parent(n), rank(n, 1) {
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