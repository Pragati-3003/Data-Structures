using Djikstra

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        queue<pair<int,pair<int,int>>> q;
        if(grid[0][0]==1 || grid[n-1][m-1]==1){return -1;}
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        q.push({1,{0,0}});
        dist[0][0]=1;
        vector<pair<int,int>> dir={{0,1},{0,-1},{-1,0},{1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

        while(!q.empty()){
            int dis=q.front().first;
            auto [i,j]=q.front().second;
            q.pop();

            for(auto it:dir){
                int x=i+it.first,y=j+it.second;
                if(x>=0 && x<n && y>=0 && y<m && grid[x][y]==0){
                    if(dis+1 < dist[x][y]){
                        dist[x][y]=dis+1;
                        q.push({dist[x][y],{x,y}});
                    }
                }
            }
        }

        if(dist[n-1][m-1]!=1e9){
            return dist[n-1][m-1];
        }
        return -1;
    }
};​
