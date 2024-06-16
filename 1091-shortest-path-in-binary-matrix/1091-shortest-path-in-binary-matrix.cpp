class Solution {
public:
    
    bool check(int i, int j, int n, int m,vector<vector<int>>& g,  vector<vector<bool>> &vis)
    {
        if(i>=n || j>=m |i<0 || j<0 || g[i][j]!=0 ||  vis[i][j])
            return false;
        return true;
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& g) {
        int n  = g.size();
        int m = g[0].size();
        
        vector<vector<bool>> vis(n+1,vector<bool>(m+1,0));
        int res = 0;

        queue<pair<int,int>> q;
        
        if(g[0][0] == 0)
        {
            q.push({0,0});
            vis[0][0]=1;
            
        }
        
        while(!q.empty())
        {
            int sz = q.size();
            res++;
            
            for(int ii=0;ii<sz;ii++)
            {
                auto p = q.front();
                int i = p.first;
                int j = p.second;
                q.pop();
                
                if(i==n-1 && j==m-1)
                    return res;

 
                if(check(i+1,j,n,m,g,vis))
                {
                    q.push({i+1,j});
                    vis[i+1][j]=1;
                }
                if(check(i-1,j,n,m,g,vis))
                {
                    q.push({i-1,j});
                    vis[i-1][j]=1;
                }
                
                if(check(i,j+1,n,m,g,vis))
                {
                    q.push({i,j+1});
                    vis[i][j+1]=1;
                }
                if(check(i,j-1,n,m,g,vis))
                {
                    q.push({i,j-1});
                    vis[i][j-1]=1;
                }
                
                
                
                if(check(i+1,j+1,n,m,g,vis))
                {
                    q.push({i+1,j+1});
                    vis[i+1][j+1]=1;
                }
                if(check(i+1,j-1,n,m,g,vis))
                {
                    q.push({i+1,j-1});
                    vis[i+1][j-1]=1;
                }
                if(check(i-1,j+1,n,m,g,vis))
                {
                    q.push({i-1,j+1});
                    vis[i-1][j+1]=1;
                }
                if(check(i-1,j-1,n,m,g,vis))
                {
                    q.push({i-1,j-1});
                    vis[i-1][j-1]=1;
                }

                
            }
        }
        return -1;
        
    }
};