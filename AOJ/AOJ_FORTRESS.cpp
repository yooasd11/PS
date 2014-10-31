#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int t, n, root, mmax;
class wall{
public:
	int x, y, r;
	vector<int> children;
	wall() { children.clear(); }
	wall(int X, int Y, int R)
		:x(X), y(Y), r(R) {
		children.clear();
	}
};
vector<wall> walls;
vector<bool> visited;

bool isChildOf(wall& w1, wall& w2){
	int dist = (w1.x - w2.x) * (w1.x - w2.x) + (w1.y - w2.y) * (w1.y - w2.y);
	int R = w2.r * w2.r;
	if (dist < R) return true;
	return false;
}

void update(wall& newWall, int here){
	if (here == -1) {
		walls.push_back(newWall);
		root = 0;
		return;
	}
	bool flag = 1;
	for (int i = 0; i < walls[here].children.size(); ++i){
		int child = walls[here].children[i];
		if (isChildOf(newWall, walls[child])) {
			update(newWall, child);
			flag = 0;
		}
	}
	if (flag){
		walls[here].children.push_back(walls.size());
		walls.push_back(newWall);
	}
}

int dfs(int here){
	visited[here] = true;
	if (walls[here].children.empty()) return 0;
	int ret = 0;
	vector<int> v;
	for (int i = 0; i<walls[here].children.size(); ++i){
		int there = walls[here].children[i];
		if (!visited[there]){
			int d = dfs(there) + 1;
			v.push_back(d);
		}
	}
	sort(v.begin(), v.end());
	ret = v.back();
	if (v.size() >= 2)
		mmax = max(mmax, v.back() + v[v.size() - 2]);
	//return 값은 트리의 높이다.
	return ret;
}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		root = -1;
		mmax = 0;
		walls.clear();
		visited = vector<bool>(n, 0);
		for (int i = 0; i < n; ++i){
			int x, y, r;
			scanf("%d %d %d", &x, &y, &r);
			wall newWall = wall(x, y, r);
			update(newWall, root);
		}
		int R = dfs(0);
		R = max(mmax, R);
		printf("%d\n", R);
	}
	return 0;
}