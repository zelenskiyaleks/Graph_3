#include <iostream>
#include <algorithm> 
#include <vector>
#include <queue>
using namespace std;

class Edge {
public:
	int two_node;
	int weight;
};

class MyCompare {
public:
	bool operator()(const Edge& l, const Edge& r) {
		return l.weight > r.weight;
	}
};

int main() {
	int n, m;
	cin >> n >> m;
	int a, b, c;
	vector<vector< pair<int, int> > > graph(n, vector< pair<int, int> >());
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		graph[a - 1].push_back(make_pair(b - 1, c));
		graph[b - 1].push_back(make_pair(a - 1, c));
	}
	priority_queue<Edge, vector<Edge>, MyCompare> pryma_edges;
	int weight_min = 0;
	vector<bool> used(n, false);
	used[0] = true;
	for (int i = 0; i < graph[0].size(); ++i) {
		Edge edge_0;
		edge_0.two_node = graph[0][i].first;
		edge_0.weight = graph[0][i].second;
		pryma_edges.push(edge_0);
	}
	int k = 0;
	while (k < n - 1) {
		Edge edge = pryma_edges.top();
		pryma_edges.pop();
		if (used[edge.two_node] == false) {
			weight_min += edge.weight;
			k++;
			int to = edge.two_node;
			used[to] = true;
			for (int i = 0; i < graph[to].size(); ++i) {
				Edge edge_to;
				edge_to.two_node = graph[to][i].first;
				edge_to.weight = graph[to][i].second;
				if (used[edge_to.two_node] == false) { pryma_edges.push(edge_to); }
			}
		}
	}
	cout << weight_min << endl;
	return 0;
}