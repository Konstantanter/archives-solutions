#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<vector<int>> bfs(vector<string> &a, int startY, int startX) {
    vector<vector<int>> dist(a.size(), vector<int>(a[0].size(), 1e9));
    queue<pair<int, int>> q;

    dist[startY][startX] = 0;
    q.push({ startY, startX });

    vector<int> dy = { -1, 0, 1, 0 };
    vector<int> dx = { 0, 1, 0, -1 };

    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();

        for (int d = 0; d < dy.size(); d++) {
            int ty = y + dy[d];
            int tx = x + dx[d];

            if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() && a[ty][tx] != '1' && dist[ty][tx] > dist[y][x] + 1) {
                dist[ty][tx] = dist[y][x] + 1;
                q.push({ ty, tx });
            }
        }
    }

    return dist;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int h, w;
    cin >> h >> w;

    vector<string> a(h);
    int startY, startX;

    for (int y = 0; y < h; y++) {
        cin >> a[y];
        for (int x = 0; x < w; x++) {
            if (a[y][x] == '*') {
                startY = y;
                startX = x;
            }
        }
    }

    vector<vector<int>> dist = bfs(a, startY, startX);

    int finishCount;
    cin >> finishCount;

    int res = -1, resDist = 1e9;
    for (int i = 0; i < finishCount; i++) {
        int finishY, finishX;
        cin >> finishY >> finishX;
        finishY--;
        finishX--;

        if (dist[finishY][finishX] != 1e9 && (res == -1 || resDist > dist[finishY][finishX])) {
            res = i + 1;
            resDist = dist[finishY][finishX];
        }
    }

    cout << res;
}