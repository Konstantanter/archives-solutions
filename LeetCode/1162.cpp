class Solution {
    int bfs(vector<vector<int>> &a) {
        int h = a.size(), w = a[0].size();
        
        vector<vector<int>> dist(h, vector<int>(w, 1e9));
        queue<pair<int, int>> q;
        
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                if (a[y][x] == 1) {
                    dist[y][x] = 0;
                    q.push({ y, x });
                }
            }
        }
        
        vector<int> dy = { -1, 0, 1, 0 };
        vector<int> dx = { 0, 1, 0, -1 };
        
        int maxDist = -1;
        
        while (!q.empty()) {
            auto [y, x] = q.front();
            q.pop();
            
            for (int d = 0; d < dy.size(); d++) {
                int ty = y + dy[d];
                int tx = x + dx[d];
                if (0 <= ty && ty < h && 0 <= tx && tx < w && dist[ty][tx] == 1e9) {
                    dist[ty][tx] = dist[y][x] + 1;
                    q.push({ ty, tx });
                    maxDist = max(maxDist, dist[ty][tx]);
                }
            }
        }
        
        return maxDist;
    }
    
public:
    int maxDistance(vector<vector<int>> &a) {
        return bfs(a);
    }
};