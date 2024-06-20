class Disjointset {
public:
    vector<int> rank, parent;
    Disjointset(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findparent(int node) {
        if (parent[node] == node)
            return node;
        else
            return parent[node] = findparent(parent[node]);
    }

    void unionset(int node1, int node2) {
        int parent1 = findparent(node1);
        int parent2 = findparent(node2);
        if (parent1 == parent2)
            return;
        if (rank[parent1] < rank[parent2])
            parent[parent1] = parent2;
        else if (rank[parent2] < rank[parent1])
            parent[parent2] = parent1;
        else {
            parent[parent2] = parent1;
            rank[parent1]++;
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int extra = 0;
        int connected = 0;
        Disjointset ds(n);
        for (auto it : connections) {
            int u = it[0];
            int v = it[1];
            if (ds.findparent(u) == ds.findparent(v))
                extra++;
            else
                ds.unionset(u, v);
        }
        // count the number of the connected component
        for (int i = 0; i < n; i++) {
            if (ds.parent[i] == i)
                connected++;
        }

        if (connected - 1 <= extra)
            return connected - 1;
        else
            return -1;
    }
};