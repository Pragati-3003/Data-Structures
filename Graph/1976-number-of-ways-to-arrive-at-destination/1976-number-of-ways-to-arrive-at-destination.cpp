class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const long long MOD = 1e9 + 7;
        vector<pair<int, int>> adj[n];

        for (int i = 0; i < roads.size(); i++) {
            adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }

        priority_queue<pair<long long, long long>, 
        vector<pair<long long, long long>>, 
        greater<pair<long long,long long>>>  pq;

        vector<long long> time_to_reach(n, LONG_MAX);
        vector<long long> ways(n, 0);

        pq.push({0, 0});
        time_to_reach[0] = 0;
        ways[0] = 1;

        while(!pq.empty()){
            long long time = pq.top().first;
            long long node = pq.top().second;

            pq.pop();
            if (time > time_to_reach[node]) continue;
            for(auto it : adj[node]){
                long long nxt_node = it.first;
                long long new_time = it.second;

                if(time_to_reach[nxt_node] > time + new_time){
                    time_to_reach[nxt_node] = time + new_time;
                    ways[nxt_node] = ways[node];
                    pq.push({time_to_reach[nxt_node], nxt_node});
                }
                 else if (time_to_reach[nxt_node] == time + new_time) {
                    ways[nxt_node] = (ways[nxt_node] + ways[node]) % MOD;

                }
            }
        }

        return ways[n-1]% MOD;
    }
};