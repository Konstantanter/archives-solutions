struct DSU {
    vector<int> id;
    int cc;

    DSU(int n) {
        for (int v = 0; v < n; v++)
            id.push_back(v);
        cc = n;
    }

    int find(int i) {
        return id[i] == i ? i : id[i] = find(id[i]);
    }

    bool connected(int i, int j) {
        return find(i) == find(j);
    }

    void merge(int i, int j) {
        int ri = find(i), rj = find(j);
        if (ri == rj)
            return;
        if (rand() % 2)
            id[ri] = rj;
        else
            id[rj] = ri;
        cc--;
    }
};

class Solution {
public:
    int earliestAcq(vector<vector<int>> &queries, int vertexCount) {
        sort(queries.begin(), queries.end());

        DSU dsu(vertexCount);
        for (vector<int> &query : queries) {
            dsu.merge(query[1], query[2]);
            if (dsu.cc == 1)
                return query[0];
        }

        return -1;
    }
};