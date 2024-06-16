class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,vector<pair<int,int>>> adj; 
        for(int i=0;i<flights.size();i++){
            int u= flights[i][0];
            int v= flights[i][1];
            int d= flights[i][2];
            adj[u].push_back({v,d});
        }
        queue<pair<int,int>> q;
        vector<int> dist(n,INT_MAX);
        q.push({src,0});
        dist[src]=0;
        
        while(!q.empty() && k-- >=0){
            int len = q.size();
            while(len--){
                auto temp = q.front();
                q.pop();
                int node = temp.first;
                int distance = temp.second;
                for(auto neigh:adj[node]){
                    if(dist[neigh.first]> distance + neigh.second){
                        dist[neigh.first] = distance + neigh.second;
                        q.push({neigh.first,dist[neigh.first]});
                    }
                }
            }
            
        }
        if(dist[dst]==INT_MAX)return -1;
        return dist[dst];
    }
};