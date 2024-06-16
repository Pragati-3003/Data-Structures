class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, list<int>> adj;
        vector<int> indegree(numCourses, 0);
        for (auto i : prerequisites) {
            adj[i[1]].push_back(i[0]);
            indegree[i[0]]++;
        }
        queue<int> q;
        for (int  i  = 0;i<numCourses;i++) {
            if (indegree[i] == 0)
                q.push(i);
        }
        int c =0;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            c++;
            for(auto nbr:adj[front]){
                indegree[nbr]--;
                if(indegree[nbr]==0){
                    q.push(nbr);
                }
            }
        }
        if(c == numCourses)
            return true;
        else return  false;
    }
};