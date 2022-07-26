class Solution {
    void dfs(vector<vector<int>> &a, int y, int x) {
        a[y][x] = 0;
        
        static vector<int> dy = { -1, 0, 1, 0 };
        static vector<int> dx = { 0, 1, 0, -1 };
        
        for (int d = 0; d < dy.size(); d++) {
            int ty = y + dy[d];
            int tx = x + dx[d];
            
            if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() && a[ty][tx])
                dfs(a, ty, tx);
        }
    }
    
public:
    int numEnclaves(vector<vector<int>> &a) {
        int h = a.size(), w = a[0].size();
        
        for (int y = 0; y < h; y++)
            for (int x : { 0, w - 1 })
                if (a[y][x])
                    dfs(a, y, x);
        
        for (int y : { 0, h - 1 })
            for (int x = 0; x < w; x++)
                if (a[y][x])
                    dfs(a, y, x);
        
        int res = 0;
        
        for (int y = 0; y < h; y++)
            for (int x = 0; x < w; x++)
                res += a[y][x];
        
        return res;
    }
};