#include <iostream>
#include <queue>
#include <functional>
#include <vector>
using namespace std;

#define MAX_NOD 10000000

//dist must be initialized by infinite value
vector<int> dist;
vector< pair<int,int> > adj[MAX_NOD];

void dijkstra(int u){
	priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;
	dist[u] = 0;
	pq.push(pair<int, int>(0, u));
	while (!pq.empty()){
		int cost = pq.top().first;
		int here = pq.top().second;
		pq.pop();
		//dist[here] is minimum value already, so if this edge has bigger weight, no need to check
		if (dist[here] < cost) continue;
		for (int i = 0; i<adj[here].size(); ++i){
			int there = adj[here][i].second;
			int nextDist = cost + adj[here][i].first;
			if (dist[there]>nextDist){
				dist[there] = nextDist;
				pq.push(pair<int, int>(nextDist, there));
			}
		}
	}
}