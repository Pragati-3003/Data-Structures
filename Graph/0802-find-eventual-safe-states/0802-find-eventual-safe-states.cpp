class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
         int v = graph.size();
        vector<int>indegree(v,0);
        queue<int>q;
        vector<int>revadj[v];
        vector<int>safeNodes;
        
        for(int i =0;i<v;i++){
            for(auto it : graph[i]){
                revadj[it].push_back(i);
                indegree[i]++;
            }
        }
        
        for(int i =0;i<v;i++){
            if(indegree[i]==0)
                q.push(i);
        }
        
        while(!q.empty()){
             int front =  q.front();
            q.pop();
            safeNodes.push_back(front);
            for(auto nbr:revadj[front]){
                indegree[nbr]--;
                if(indegree[nbr]==0)
                    q.push(nbr);
            }
            
        }
        sort(safeNodes.begin(),safeNodes.end());
        return safeNodes;
    }
};