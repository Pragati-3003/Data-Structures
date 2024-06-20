class Solution {
public:
    vector<pair<int, int>> dirc = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    int swimInWater(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));

        vector<vector<int>> level(n, vector<int>(m, 1e9));

        priority_queue<pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>> pq;

        pq.push({grid[0][0], {0, 0}});
        level[0][0] = grid[0][0];

        while (!pq.empty()) {

            auto it = pq.top();

            int depth = it.first;
            int row = it.second.first;
            int col = it.second.second;

            pq.pop();

            visited[row][col] = 1;

            if (row == n - 1 && col == n - 1)
                return depth;

            for (auto i : dirc) {
                int nrow = row + i.first;
                int ncol = col + i.second;

                if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m &&
                    !visited[nrow][ncol]) {

                        int newDepth = max(depth, grid[nrow][ncol]);

                        if(level[nrow][ncol] > newDepth){
                            level[nrow][ncol] = newDepth;
                            pq.push({level[nrow][ncol], {nrow, ncol}});
                        }
                        
                }
            }
        }

        return level[n-1][n-1];
    }
};