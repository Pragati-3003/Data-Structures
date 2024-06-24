class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b)
    {
        if(a[0] == b[0])
        {
            return a[1] < b[1];
        }
        else
            return a[0] > b[0];
    }
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        
        int n = people.size();
        
        sort(people.begin(), people.end(), compare);
        
        
        vector<vector<int>> res;
        
        for(int i = 0; i < n; i++)
        {
            int pos = people[i][1];
            
            res.insert(res.begin() + pos, people[i]);
        }
        
        return res;
    }
};