class DSU
{
public:
    vector<int> rank, parent, size;
    DSU(int n)
    {
       
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }    
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();

    int maxrow=0;
    int maxcol=0;
    for(auto it:stones){
        maxrow=max(maxrow,it[0]);
        maxcol=max(maxcol,it[1]);
    }
    DSU ds(maxrow+maxcol+1);
    unordered_map<int,int>stonenode;
    for(auto it:stones){
        int row =  it[0];
        int col = it[1]+maxrow+1;
        ds.unionBySize(row,col);
        stonenode[row] = 1;
        stonenode[col]=1;
    }
    int cnt=0;
    for(auto it:stonenode){
        if(ds.findUPar(it.first)==it.first)
        cnt++;
    }
    return n-cnt;
    }
};