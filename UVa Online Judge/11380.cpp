#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

class Graph {
    class Edge {
        int a, b, capacity, flow;
    public:
        Edge(int a, int b, int capacity) : a(a), b(b), capacity(capacity), flow(0) {}
        int other(int v) const {
            return v == a ? b : a;
        }
        int capacityTo(int v) const {
            return v == b ? capacity - flow : flow;
        }
        void addFlowTo(int v, int f) {
            flow += (v == b ? f : -f);
        }
    };
    vector<Edge> edges;
    vector<vector<int>> g;
    vector<bool> used;
    vector<int> edgeTo;
    void bfs(int v) {
        queue<int> q;
        used[v] = 1;
        q.push(v);
        while (!q.empty()) {
            v = q.front();
            q.pop();
            for (int e : g[v]) {
                int to = edges[e].other(v);
                if (!used[to] && edges[e].capacityTo(to)) {
                    edgeTo[to] = e;
                    used[to] = 1;
                    q.push(to);
                }
            }
        }
    }
    bool hasPath(int from, int to) {
        fill(used.begin(), used.end(), 0);
        bfs(from);
        return used[to];
    }
    int bottleneckCapacity(int from, int to) {
        int bCapacity = 1e9;
        for (int v = to; v != from; v = edges[edgeTo[v]].other(v))
            bCapacity = min(bCapacity, edges[edgeTo[v]].capacityTo(v));
        return bCapacity;
    }
    void addFlow(int from, int to, int flow) {
        for (int v = to; v != from; v = edges[edgeTo[v]].other(v))
            edges[edgeTo[v]].addFlowTo(v, flow);
    }
public:
    Graph(int verticesCount) {
        g.resize(verticesCount);
        used.resize(verticesCount);
        edgeTo.resize(verticesCount);
    }
    void addEdge(int from, int to, int capacity) {
        edges.push_back(Edge(from, to, capacity));
        g[from].push_back(edges.size() - 1);
        g[to].push_back(edges.size() - 1);
    }
    long long maxFlow(int from, int to) {
        long long flow = 0;
        while (hasPath(from, to)) {
            int deltaFlow = bottleneckCapacity(from, to);
            addFlow(from, to, deltaFlow);
            flow += deltaFlow;
        }
        return flow;
    }
};

bool solve() {
    int h, w, limit;
    if (!(cin >> h >> w >> limit))
        return 0;

    vector<string> a(h);
    for (string &row : a)
        cin >> row;

    Graph graph(1 + h * w + h * w + 1);

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            static int dy[] = { -1, 0, 1, 0 };
            static int dx[] = { 0, 1, 0, -1 };

            if (a[y][x] == '*') {
                graph.addEdge(0, 1 + y * w + x, 1);
                graph.addEdge(1 + y * w + x, 1 + h * w + y * w + x, 1);
                for (int d = 0; d < 4; d++) {
                    int ty = y + dy[d], tx = x + dx[d];
                    if (0 <= ty && ty < h && 0 <= tx && tx < w && a[ty][tx] != '~')
                        graph.addEdge(1 + h * w + y * w + x, 1 + ty * w + tx, 1);
                }
            } else if (a[y][x] == '.') {
                graph.addEdge(1 + y * w + x, 1 + h * w + y * w + x, 1);
                for (int d = 0; d < 4; d++) {
                    int ty = y + dy[d], tx = x + dx[d];
                    if (0 <= ty && ty < h && 0 <= tx && tx < w && a[ty][tx] != '~')
                        graph.addEdge(1 + h * w + y * w + x, 1 + ty * w + tx, 1);
                }
            } else if (a[y][x] == '@') {
                for (int d = 0; d < 4; d++) {
                    int ty = y + dy[d], tx = x + dx[d];
                    if (0 <= ty && ty < h && 0 <= tx && tx < w && a[ty][tx] != '~')
                        graph.addEdge(1 + y * w + x, 1 + ty * w + tx, 1e9);
                }
            } else if (a[y][x] == '#') {
                for (int d = 0; d < 4; d++) {
                    int ty = y + dy[d], tx = x + dx[d];
                    if (0 <= ty && ty < h && 0 <= tx && tx < w && a[ty][tx] != '~')
                        graph.addEdge(1 + y * w + x, 1 + ty * w + tx, 1e9);
                }
                graph.addEdge(1 + y * w + x, 1 + h * w + h * w, limit);
            }
        }
    }

    cout << graph.maxFlow(0, 1 + h * w + h * w) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}